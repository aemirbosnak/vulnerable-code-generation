//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000 // maximum size of array

// function prototypes
void fillArray(int arr[], int size);
void printArray(int arr[], int size);
void sortArray(int arr[], int size);
void reverseArray(int arr[], int size);

// main function
int main() {
    int arr[MAX_SIZE];
    int size;

    printf("Enter the size of the array (up to %d): ", MAX_SIZE);
    scanf("%d", &size);

    fillArray(arr, size);
    printArray(arr, size);
    sortArray(arr, size);
    reverseArray(arr, size);

    return 0;
}

// function to fill the array with random numbers
void fillArray(int arr[], int size) {
    srand(time(NULL)); // seed the random number generator with current time

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // generate random number between 0 and 99
    }
}

// function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// function to sort the array in ascending order
void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// function to reverse the array
void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}