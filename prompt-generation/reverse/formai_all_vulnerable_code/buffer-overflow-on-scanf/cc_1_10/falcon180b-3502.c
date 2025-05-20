//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MIN_SIZE 10

// Function to generate a random array of integers
int* generate_array(int size) {
    int* arr = (int*) malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    return arr;
}

// Function to sort an array using quicksort
void quicksort(int* arr, int size) {
    if (size <= 1) {
        return;
    }

    int pivot = arr[size / 2];
    int* left = (int*) malloc(size / 2 * sizeof(int));
    int* right = (int*) malloc(size - size / 2 * sizeof(int));

    int left_size = 0, right_size = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] < pivot) {
            left[left_size++] = arr[i];
        } else {
            right[right_size++] = arr[i];
        }
    }

    quicksort(left, left_size);
    quicksort(right, right_size);

    free(left);
    free(right);
}

// Function to calculate the median of an array
double calculate_median(int* arr, int size) {
    quicksort(arr, size);

    if (size % 2 == 0) {
        return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    } else {
        return arr[size / 2];
    }
}

int main() {
    int size;

    // Prompt user for array size
    printf("Enter array size (between %d and %d): ", MIN_SIZE, MAX_SIZE);
    scanf("%d", &size);

    // Check if array size is valid
    if (size < MIN_SIZE || size > MAX_SIZE) {
        printf("Error: Invalid array size!\n");
        return 1;
    }

    // Generate random array
    int* arr = generate_array(size);

    // Calculate median
    double median = calculate_median(arr, size);

    // Print result
    printf("Median of array: %.2f\n", median);

    free(arr);
    return 0;
}