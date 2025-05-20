//Falcon-180B DATASET v1.0 Category: Sorting ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MIN 1

// function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// function to print an array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// function to generate a random array
int generateRandomArray(int arr[], int size) {
    srand(time(0)); // seed the random number generator with the current time
    int i;
    for (i = 0; i < size; i++)
        arr[i] = rand() % (MAX - MIN + 1) + MIN; // generate random numbers between MIN and MAX (inclusive)
    return 0;
}

// function to perform bubble sort
void bubbleSort(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]); // swap the elements if they are in the wrong order
            }
        }
    }
}

int main() {
    int arr[MAX]; // declare an array of maximum size
    int size; // declare a variable to store the size of the array
    printf("Enter the size of the array (between 1 and %d): ", MAX);
    scanf("%d", &size); // read the size of the array from the user
    if (size < MIN || size > MAX) {
        printf("Invalid size of array!\n");
        return 0;
    }
    generateRandomArray(arr, size); // generate a random array of the given size
    printf("Unsorted array:\n");
    printArray(arr, size); // print the unsorted array
    bubbleSort(arr, size); // sort the array using bubble sort
    printf("Sorted array:\n");
    printArray(arr, size); // print the sorted array
    return 0;
}