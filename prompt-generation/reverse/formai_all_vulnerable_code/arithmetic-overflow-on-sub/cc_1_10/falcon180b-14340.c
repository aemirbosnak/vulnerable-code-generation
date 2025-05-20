//Falcon-180B DATASET v1.0 Category: Sorting ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Defining the structure of an element
typedef struct element{
    int value;
    int index;
}ELEMENT;

//Defining the structure of a heap
typedef struct heap{
    ELEMENT *elements;
    int size;
    int capacity;
}HEAP;

//Function to swap two elements
void swap(ELEMENT *a,ELEMENT *b){
    ELEMENT temp = *a;
    *a = *b;
    *b = temp;
}

//Function to get the parent index of an element
int getParentIndex(int index){
    return (index - 1) / 2;
}

//Function to get the left child index of an element
int getLeftChildIndex(int index){
    return 2 * index + 1;
}

//Function to get the right child index of an element
int getRightChildIndex(int index){
    return 2 * index + 2;
}

//Function to heapify a subtree rooted at a given index
void heapify(HEAP *heap,int index){
    int largest = index;
    int leftChild = getLeftChildIndex(index);
    int rightChild = getRightChildIndex(index);

    if(leftChild < heap->size && heap->elements[leftChild].value > heap->elements[largest].value){
        largest = leftChild;
    }

    if(rightChild < heap->size && heap->elements[rightChild].value > heap->elements[largest].value){
        largest = rightChild;
    }

    if(largest!= index){
        swap(&heap->elements[index],&heap->elements[largest]);
        heapify(heap,largest);
    }
}

//Function to build a heap from an array
void buildHeap(HEAP *heap){
    int n = heap->size;
    for(int i = n / 2 - 1;i >= 0;i--){
        heapify(heap,i);
    }
}

//Function to heap sort an array
void heapSort(HEAP *heap){
    int n = heap->size;
    int last = n - 1;

    for(int i = n - 1;i >= 0;i--){
        swap(&heap->elements[0],&heap->elements[i]);
        heapify(heap,0);
    }

    while(last > 0){
        swap(&heap->elements[0],&heap->elements[last]);
        heapify(heap,0);
        last--;
    }
}

//Function to print the heap
void printHeap(HEAP *heap){
    int n = heap->size;
    for(int i = 0;i < n;i++){
        printf("%d\t",heap->elements[i].value);
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter the number of elements to sort:\n");
    scanf("%d",&n);

    ELEMENT *elements = (ELEMENT*)malloc(n * sizeof(ELEMENT));

    printf("Enter the elements:\n");
    for(int i = 0;i < n;i++){
        scanf("%d",&elements[i].value);
        elements[i].index = i;
    }

    HEAP heap;
    heap.elements = elements;
    heap.size = n;
    heap.capacity = n;

    buildHeap(&heap);
    heapSort(&heap);

    printf("Sorted elements:\n");
    for(int i = 0;i < n;i++){
        printf("%d\t",heap.elements[i].value);
    }
    printf("\n");

    return 0;
}