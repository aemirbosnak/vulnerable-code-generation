//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// function to create a bucket and initialize it with zeros
void createBucket(int bucket[], int size) {
    for(int i=0; i<size; i++) {
        bucket[i] = 0;
    }
}

// function to insert an element into the correct bucket
void insertElement(int arr[], int size, int element) {
    int index = element * size / (MAX_SIZE - 1);
    if(index == size) {
        index--;
    }
    arr[index]++;
}

// function to sort the array using bucket sort
void bucketSort(int arr[], int size) {
    int bucket[MAX_SIZE];
    createBucket(bucket, MAX_SIZE);

    for(int i=0; i<size; i++) {
        insertElement(bucket, MAX_SIZE, arr[i]);
    }

    int index = 0;
    for(int i=0; i<MAX_SIZE; i++) {
        for(int j=0; j<bucket[i]; j++) {
            arr[index++] = i * (MAX_SIZE - 1) / MAX_SIZE + 1;
        }
    }
}

// function to print the sorted array
void printArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// main function to run the program
int main() {
    int arr[MAX_SIZE];
    int size;

    // get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // get the elements of the array from the user
    printf("Enter the elements of the array:\n");
    for(int i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }

    // sort the array using bucket sort
    bucketSort(arr, size);

    // print the sorted array
    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}