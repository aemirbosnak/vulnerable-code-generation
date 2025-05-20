//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 100

// Function to initialize an array with random values
void init_array(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

// Function to print an array
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to sort an array using bitonic sort
void bitonic_sort(int arr[], int size) {
    int n = size;
    int m = (n + 1) / 2;
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n - m; j++) {
            if (arr[i + j] > arr[i + j + m]) {
                int temp = arr[i + j];
                arr[i + j] = arr[i + j + m];
                arr[i + j + m] = temp;
            }
        }
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < n - m; j++) {
            if (arr[i + j] > arr[i + j + m]) {
                int temp = arr[i + j];
                arr[i + j] = arr[i + j + m];
                arr[i + j + m] = temp;
            }
        }
    }
}

// Function to perform bitwise operations on an array
void bitwise_operations(int arr[], int size) {
    int sum = 0;
    int product = 1;
    int i;
    for (i = 0; i < size; i++) {
        sum += arr[i];
        product *= arr[i];
    }
    printf("Sum: %d\n", sum);
    printf("Product: %d\n", product);
}

int main() {
    int arr[MAX_SIZE];
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    init_array(arr, size);
    print_array(arr, size);
    bitonic_sort(arr, size);
    print_array(arr, size);
    bitwise_operations(arr, size);
    return 0;
}