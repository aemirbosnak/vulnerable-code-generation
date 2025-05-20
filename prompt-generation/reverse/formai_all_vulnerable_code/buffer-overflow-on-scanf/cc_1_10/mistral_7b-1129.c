//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define MAX_INPUTS 100
#define INT_SIZE sizeof(int)

typedef struct {
    int value;
    char name[20];
} Number;

void bubbleSort(Number arr[], int n);
void printArray(Number arr[], int size);

int main() {
    Number inputNumbers[MAX_INPUTS];
    int numberOfInputs;

    // Seed the random number generator
    srand(time(NULL));

    // Get the number of inputs from the user
    printf("Enter the number of integers to input: ");
    scanf("%d", &numberOfInputs);

    // Initialize the array with random integers and names
    for (int i = 0; i < numberOfInputs; i++) {
        inputNumbers[i].value = rand() % 100;
        sprintf(inputNumbers[i].name, "Number%d", i + 1);
    }

    // Print the unsorted list
    printf("\nUnsorted list:\n");
    printArray(inputNumbers, numberOfInputs);

    // Sort the list using bubble sort
    bubbleSort(inputNumbers, numberOfInputs);

    // Print the sorted list
    printf("\nSorted list:\n");
    printArray(inputNumbers, numberOfInputs);

    return 0;
}

void bubbleSort(Number arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].value > arr[j + 1].value) {
                Number temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(Number arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", arr[i].name, arr[i].value);
    }
}