//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void generateRandomArray(int *arr, int size);
void printArray(int *arr, int size);
double calculateSum(int *arr, int size);

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    generateRandomArray(arr, size);
    printArray(arr, size);

    double sum = calculateSum(arr, size);
    printf("The sum of the array is: %.2f\n", sum);

    free(arr);
    return 0;
}

void generateRandomArray(int *arr, int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

double calculateSum(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double)sum / size;
}