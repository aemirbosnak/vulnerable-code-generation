//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the struct for the array
typedef struct {
    int *arr;
    int size;
} Array;

// Function to initialize the array
void init(Array *arr) {
    arr->arr = (int *)malloc(MAX_SIZE * sizeof(int));
    arr->size = 0;
}

// Function to add an element to the array
void add(Array *arr, int val) {
    if (arr->size == MAX_SIZE) {
        printf("Array is full.\n");
        return;
    }
    arr->arr[arr->size++] = val;
}

// Function to display the array
void display(Array arr) {
    printf("Array: ");
    for (int i = 0; i < arr.size; i++) {
        printf("%d ", arr.arr[i]);
    }
    printf("\n");
}

// Function to search for a value in the array
int search(Array arr, int val) {
    for (int i = 0; i < arr.size; i++) {
        if (arr.arr[i] == val) {
            return i;
        }
    }
    return -1;
}

// Main function to test the array operations
int main() {
    Array arr;
    init(&arr);
    add(&arr, 10);
    add(&arr, 20);
    add(&arr, 30);
    display(arr);
    int index = search(arr, 20);
    if (index!= -1) {
        printf("Value found at index %d.\n", index);
    } else {
        printf("Value not found.\n");
    }
    return 0;
}