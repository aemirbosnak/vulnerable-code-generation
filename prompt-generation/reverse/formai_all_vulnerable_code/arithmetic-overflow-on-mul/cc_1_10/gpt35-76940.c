//FormAI DATASET v1.0 Category: Math exercise ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_numbers(int arr[], int size) {
    // This function generates random numbers between 1 and 100 and stores
    // them in an array of size `size`
    srand(time(NULL)); // Seed random number generator
    for (int i=0; i<size; i++) {
        arr[i] = rand() % 100 + 1; // Generate random number between 1 and 100
    }
}

void get_sum(int arr[], int size, int* sum) {
    // This function calculates the sum of all elements in the array `arr`
    for (int i=0; i<size; i++) {
        *sum += arr[i]; // Add each element to the sum
    }
}

void get_product(int arr[], int size, int* product) {
    // This function calculates the product of all elements in the array `arr`
    *product = 1;
    for (int i=0; i<size; i++) {
        *product *= arr[i]; // Multiply each element to the product
    }
}

int main() {
    int arr[10];
    int sum = 0;
    int product = 0;

    // Generate random numbers and store them in the array `arr`
    generate_random_numbers(arr, 10);

    // Calculate the sum and product of all elements in the array `arr`
    get_sum(arr, 10, &sum);
    get_product(arr, 10, &product);

    // Print the array `arr`, sum, and product
    printf("Array: ");
    for (int i=0; i<10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nSum: %d\n", sum);
    printf("Product: %d\n", product);

    return 0;
}