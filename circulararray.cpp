#include <iostream>
#include <string>
#include "circulararray.h"
using namespace std;

template <class T>
void CircularArray<T>::push_front(T data)
{
    if (is_full()){
        resize(this->capacity + 4);
        push_front(data);
    } else {
        this->front = prev(this->front);
        this->array[this->front] = data;
    };
    this->empty = false;
}

template <class T>
void CircularArray<T>::push_back(T data) {
    if(is_full()){
        resize(this->capacity +4);
        push_back(data);
    }else {
        this->array[this->back] = data;
        this->back = next(this->back);
    };
    this->empty = false;
}

template <class T>
void CircularArray<T>::resize(int new_capacity) {
    if(new_capacity < size()){
        cout<<"The new capacity of the array is less than his size";
        return;
    };
    T *temp = new T[new_capacity];
    for(int i = 0; i < size(); i++){
        temp[i] = this->array[i];
    };
    this->capacity = new_capacity;
    this->front = 0;
    this->back = size();
    delete []this->array;
    this->array = temp;
    temp = nullptr;
}

template <class T>
void CircularArray<T>::insert(T data, int pos) {
    T temp;
    for(int i = pos; i < size(); i++){
        temp = this->array[(this->front + i + 1)%this->capacity];
        this->array[(this->front + i + 1)%this->capacity] = this->array[(this->front + i)%this->capacity];
    };
    pos = this->front + pos - 1;
    this->array[pos] = data;
}