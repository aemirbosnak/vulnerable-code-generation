//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// Function prototypes
void generateRandomArray(int arr[], int size);
void printArray(int arr[], int size);
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);
void swap(int *a, int *b);
void menu();

int main() {
    int arr[MAX_SIZE];
    int size, choice;
    
    printf("Enter the number of elements in the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);
    
    if(size > MAX_SIZE || size <= 0) {
        printf("Invalid size! Must be between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    generateRandomArray(arr, size);
    printf("Generated Array: ");
    printArray(arr, size);

    while(1) {
        menu();
        printf("Choose sorting algorithm (1-4, 0 to exit): ");
        scanf("%d", &choice);

        // sort based on user's choice
        switch(choice) {
            case 1:
                bubbleSort(arr, size);
                printf("Array sorted using Bubble Sort: ");
                printArray(arr, size);
                break;
            case 2:
                selectionSort(arr, size);
                printf("Array sorted using Selection Sort: ");
                printArray(arr, size);
                break;
            case 3:
                insertionSort(arr, size);
                printf("Array sorted using Insertion Sort: ");
                printArray(arr, size);
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            case 0:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void generateRandomArray(int arr[], int size) {
    srand(time(0)); // Seed for random number generation
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // random number between 0-99
    }
}

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void selectionSort(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < size; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
    }
}

void insertionSort(int arr[], int size) {
    for(int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void menu() {
    printf("\nSorting Algorithms Menu:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Exit\n");
}