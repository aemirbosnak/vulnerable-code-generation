//Falcon-180B DATASET v1.0 Category: Sorting ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// Struct to hold information about each character
typedef struct {
    char name[20];
    int age;
    int height;
} Character;

// Function to initialize the array with random characters
void initArray(Character arr[], int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        sprintf(arr[i].name, "Character %d", i + 1);
        arr[i].age = rand() % 100;
        arr[i].height = rand() % 200;
    }
}

// Function to print the contents of the array
void printArray(Character arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Name: %s, Age: %d, Height: %d\n", arr[i].name, arr[i].age, arr[i].height);
    }
}

// Function to swap two elements in the array
void swap(Character* a, Character* b) {
    Character temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bubble sort on the array
void bubbleSort(Character arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].age > arr[j + 1].age) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    Character arr[MAX_SIZE];
    int size;

    // Get the size of the array from the user
    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Initialize the array with random characters
    initArray(arr, size);

    // Print the unsorted array
    printf("Unsorted array:\n");
    printArray(arr, size);

    // Sort the array using bubble sort
    bubbleSort(arr, size);

    // Print the sorted array
    printf("\nSorted array by age:\n");
    printArray(arr, size);

    return 0;
}