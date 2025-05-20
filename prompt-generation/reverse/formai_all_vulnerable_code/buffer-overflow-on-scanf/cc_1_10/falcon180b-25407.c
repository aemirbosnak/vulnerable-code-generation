//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 100

// Function to generate a random number between min and max (inclusive)
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate an array of n random numbers between min and max (inclusive)
int* generateRandomArray(int n, int min, int max) {
    int* array = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        array[i] = generateRandomNumber(min, max);
    }
    return array;
}

// Function to print an array of integers
void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to calculate the sum of an array of integers using bitwise operations
int calculateSum(int* array, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum |= array[i];
    }
    return sum;
}

int main() {
    int n, min, max;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the minimum value: ");
    scanf("%d", &min);
    printf("Enter the maximum value: ");
    scanf("%d", &max);

    int* array = generateRandomArray(n, min, max);
    printf("Generated array: ");
    printArray(array, n);

    int sum = calculateSum(array, n);
    printf("Sum of array elements: %d\n", sum);

    free(array);
    return 0;
}