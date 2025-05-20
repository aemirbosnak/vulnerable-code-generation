//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100
#define FILE_NAME "numbers.txt"

void bubbleSort(int arr[], int n);
bool isSorted(int arr[], int n);

int main() {
    int arr[MAX_SIZE];
    int n, i;
    FILE *file;

    // Check if file exists
    if ((file = fopen(FILE_NAME, "r")) == NULL) {
        printf("Error opening file %s\n", FILE_NAME);
        exit(1);
    }

    // Read integers from file
    fscanf(file, "%d", &n);

    if (n > MAX_SIZE) {
        printf("Array size exceeded. Max size is %d.\n", MAX_SIZE);
        fclose(file);
        exit(1);
    }

    for (i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);

    // Check if any integers were read
    if (n == 0) {
        printf("No integers found in the file.\n");
        exit(1);
    }

    printf("Unsorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubbleSort(arr, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void bubbleSort(int arr[], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

bool isSorted(int arr[], int n) {
    int i;

    for (i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }

    return true;
}