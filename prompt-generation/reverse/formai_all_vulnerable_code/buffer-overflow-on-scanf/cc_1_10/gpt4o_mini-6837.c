//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100   // Maximum length of string elements
#define MAX_SIZE 100     // Maximum size of array

// Function prototypes
void printArray(char arr[][MAX_LENGTH], int size);
void bubbleSort(char arr[][MAX_LENGTH], int size);
void selectionSort(char arr[][MAX_LENGTH], int size);
void insertionSort(char arr[][MAX_LENGTH], int size);
void quickSort(char arr[][MAX_LENGTH], int low, int high);
int partition(char arr[][MAX_LENGTH], int low, int high);

// Main function
int main() {
    int choice, size;

    printf("Enter number of strings to sort (max %d): ", MAX_SIZE);
    scanf("%d", &size);
    if(size < 1 || size > MAX_SIZE) {
        printf("Invalid size. Please restart and enter a value between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    char strings[MAX_SIZE][MAX_LENGTH];

    printf("Enter %d strings (one per line):\n", size);
    for(int i = 0; i < size; i++) {
        scanf("%s", strings[i]);
    }

    printf("Choose sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Quick Sort\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            bubbleSort(strings, size);
            break;
        case 2:
            selectionSort(strings, size);
            break;
        case 3:
            insertionSort(strings, size);
            break;
        case 4:
            quickSort(strings, 0, size - 1);
            break;
        default:
            printf("Invalid choice. Please run the program again.\n");
            return 1;
    }

    printf("Sorted strings:\n");
    printArray(strings, size);

    return 0;
}

// Function to print the array of strings
void printArray(char arr[][MAX_LENGTH], int size) {
    for(int i = 0; i < size; i++) {
        printf("%s\n", arr[i]);
    }
}

// Bubble Sort implementation
void bubbleSort(char arr[][MAX_LENGTH], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(strcmp(arr[j], arr[j + 1]) > 0) {
                char temp[MAX_LENGTH];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}

// Selection Sort implementation
void selectionSort(char arr[][MAX_LENGTH], int size) {
    for(int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < size; j++) {
            if(strcmp(arr[j], arr[minIndex]) < 0) {
                minIndex = j;
            }
        }
        if(minIndex != i) {
            char temp[MAX_LENGTH];
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[minIndex]);
            strcpy(arr[minIndex], temp);
        }
    }
}

// Insertion Sort implementation
void insertionSort(char arr[][MAX_LENGTH], int size) {
    for(int i = 1; i < size; i++) {
        char key[MAX_LENGTH];
        strcpy(key, arr[i]);
        int j = i - 1;
        while(j >= 0 && strcmp(arr[j], key) > 0) {
            strcpy(arr[j + 1], arr[j]);
            j--;
        }
        strcpy(arr[j + 1], key);
    }
}

// Quick Sort implementation
void quickSort(char arr[][MAX_LENGTH], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(char arr[][MAX_LENGTH], int low, int high) {
    char pivot[MAX_LENGTH];
    strcpy(pivot, arr[high]);
    int i = (low - 1);
    for(int j = low; j < high; j++) {
        if(strcmp(arr[j], pivot) < 0) {
            i++;
            char temp[MAX_LENGTH];
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[j]);
            strcpy(arr[j], temp);
        }
    }
    char temp[MAX_LENGTH];
    strcpy(temp, arr[i + 1]);
    strcpy(arr[i + 1], arr[high]);
    strcpy(arr[high], temp);
    return (i + 1);
}