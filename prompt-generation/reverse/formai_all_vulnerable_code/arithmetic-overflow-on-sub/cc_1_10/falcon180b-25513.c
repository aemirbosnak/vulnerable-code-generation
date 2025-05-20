//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the structure for each element in the array
typedef struct {
    int value;
    int index;
} Element;

// Define the structure for the array
typedef struct {
    Element* elements;
    int size;
} Array;

// Function to generate a random number between 0 and n-1
int randInt(int n) {
    return rand() % n;
}

// Function to swap two elements in the array
void swapElements(Array* array, int index1, int index2) {
    Element temp = array->elements[index1];
    array->elements[index1] = array->elements[index2];
    array->elements[index2] = temp;
}

// Function to print the array
void printArray(Array* array) {
    printf("Array:\n");
    for (int i = 0; i < array->size; i++) {
        printf("%d (%d)\n", array->elements[i].value, array->elements[i].index);
    }
}

// Function to sort the array using bubble sort
void bubbleSort(Array* array) {
    int n = array->size;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (array->elements[j].value > array->elements[j+1].value) {
                swapElements(array, j, j+1);
            }
        }
    }
}

// Function to generate a random array of integers
void generateRandomArray(Array* array) {
    srand(time(0));
    for (int i = 0; i < array->size; i++) {
        array->elements[i].value = randInt(100);
        array->elements[i].index = i;
    }
}

// Main function
int main() {
    Array array;
    array.elements = (Element*) malloc(MAX_SIZE * sizeof(Element));
    array.size = 0;

    // Prompt the user for the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &array.size);

    // Generate a random array of integers
    generateRandomArray(&array);

    // Print the unsorted array
    printf("Unsorted array:\n");
    printArray(&array);

    // Sort the array using bubble sort
    bubbleSort(&array);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(&array);

    return 0;
}