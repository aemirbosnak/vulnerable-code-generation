//FormAI DATASET v1.0 Category: Searching algorithm ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Irregular Style C Searching Algorithm Example

// Function to generate random numbers
void randomNumbers(int arr[], int arrSize) {
    srand(time(0)); // Seeding rand() function with time

    // Generating random numbers for the array
    for(int i=0; i<arrSize; i++) {
        arr[i] = rand() % 100;
    }
}

// Function to print the array
void printArray(int arr[], int arrSize) {
    printf("[ ");

    for(int i=0; i<arrSize; i++) {
        printf("%d ", arr[i]);
    }

    printf("]\n");
}

// Function to reverse the array
void reverseArray(int arr[], int arrSize) {
    int temp;

    for(int i=0; i<(arrSize/2); i++) {
        temp = arr[i];
        arr[i] = arr[arrSize-1-i];
        arr[arrSize-1-i] = temp;
    }
}

// Function to linear search an element in the array
int linearSearch(int arr[], int arrSize, int key) {
    for(int i=0; i<arrSize; i++) {
        if(arr[i] == key) {
            return i;
        }
    }

    return -1; // Element not found
}

// Function to binary search an element in the array
int binarySearch(int arr[], int arrSize, int key) {
    int low = 0, high = arrSize-1, mid;

    while(low <= high) {
        mid = (low + high) / 2;

        if(arr[mid] == key) {
            return mid;
        } else if(arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // Element not found
}

int main() {
    int arrSize, key, pos;
    printf("Enter the size of the array: ");
    scanf("%d", &arrSize);

    int arr[arrSize]; // Creating the array

    randomNumbers(arr, arrSize); // Generating random numbers
    printf("The initial array: ");
    printArray(arr, arrSize);

    reverseArray(arr, arrSize); // Reversing the array
    printf("The reversed array: ");
    printArray(arr, arrSize);

    printf("Enter an element to search in the array: ");
    scanf("%d", &key);

    pos = linearSearch(arr, arrSize, key); // Linear search
    if(pos != -1) {
        printf("The element %d is found at position %d using Linear Search.\n", key, pos+1);
    } else {
        printf("The element %d is not found in the array using Linear Search.\n", key);
    }

    pos = binarySearch(arr, arrSize, key); // Binary Search
    if(pos != -1) {
        printf("The element %d is found at position %d using Binary Search.\n", key, pos+1);
    } else {
        printf("The element %d is not found in the array using Binary Search.\n", key);
    }

    return 0;
}