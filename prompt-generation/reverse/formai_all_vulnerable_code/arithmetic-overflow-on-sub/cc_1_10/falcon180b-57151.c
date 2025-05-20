//Falcon-180B DATASET v1.0 Category: Educational ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int generateRandom(int min, int max);
int *createArray(int size);
void printArray(int *arr, int size);
void sortArray(int *arr, int size);
void searchElement(int *arr, int size, int target);

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = createArray(size);
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = generateRandom(1, 100);
    }

    printf("\nUnsorted array:\n");
    printArray(arr, size);

    sortArray(arr, size);

    printf("\nSorted array:\n");
    printArray(arr, size);

    int target;
    printf("\nEnter the element to search: ");
    scanf("%d", &target);
    searchElement(arr, size, target);

    free(arr);
    return 0;
}

int generateRandom(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int *createArray(int size) {
    return (int *)malloc(size * sizeof(int));
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sortArray(int *arr, int size) {
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

void searchElement(int *arr, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("\nElement found at index %d\n", i);
            return;
        }
    }
    printf("\nElement not found\n");
}