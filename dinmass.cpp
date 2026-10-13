#include <iostream>

 struct Dinarray{
    int *data;     
    int size;     
    int capacity; 
};
Dinarray* create(){

    Dinarray *a = new Dinarray;
    a->data = nullptr;
    a->size = 0;
    a->capacity = 0;
    return a;
}
void push(Dinarray *a, int value){
    if(a->size <  a->capacity){
        a->data[a->size++]= value;
        return;
    }
    int newcap;
    if(a->capacity==0){
        newcap = 1;
    }
    else{
        newcap = a->capacity*10;
    }

int *tmp = new int[newcap];
for(int i =0;i < a->size;i++)
    tmp[i]=a->data[i];
delete[] a->data;
a -> data=tmp ;
a -> capacity = newcap;
a->data[a->size++] = value;
}
bool pop(Dinarray *a, int &out){
    if(a->size == 0)
        return false;
    out = a->data[--a->size];
    return true;
}
void destroy(Dinarray *a) {
    delete[] a->data;
    delete a;
}
void swap(int &x, int &y) {
    int t = x;
    x = y;
    y = t;
}
void siftDown(int *data, int size, int i) {
    while (true) {
int left    = 2 * i + 1;
 int right   = 2 * i + 2;
int largest = i;

if (left  < size && data[left]  > data[largest]) largest = left;
if (right < size && data[right] > data[largest]) largest = right;

if (largest == i) break;

 swap(data[i], data[largest]);
i = largest;
}

}
void heapsort(Dinarray *a){
    int n = a->size;
    for (int i = n; i >= 0; i--)
    siftDown(a->data, n, i);
  for (int i = n - 1; i > 0; i--) {
        swap(a->data[0], a->data[i]);
        siftDown(a->data, i, 0);
    }
  

}
