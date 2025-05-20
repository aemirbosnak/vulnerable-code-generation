//Falcon-180B DATASET v1.0 Category: Educational ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the input array
#define MAX_SIZE 100

// Function to calculate the sum of even numbers in an array
int sum_even(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            sum += arr[i];
        }
    }
    return sum;
}

// Function to calculate the product of odd numbers in an array
int product_odd(int arr[], int size) {
    int product = 1;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2!= 0) {
            product *= arr[i];
        }
    }
    return product;
}

// Function to calculate the average of all numbers in an array
double average(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double) sum / size;
}

int main() {
    // Initialize an array of integers
    int arr[MAX_SIZE];
    int size = 0;

    // Prompt the user to enter integers
    printf("Enter integers (enter -1 to stop):\n");
    while (scanf("%d", &arr[size])!= EOF) {
        size++;
        if (size >= MAX_SIZE) {
            printf("Error: input array is full.\n");
            exit(1);
        }
    }

    // Calculate the sum of even numbers, product of odd numbers, and average of all numbers in the array
    int sum_even_result = sum_even(arr, size);
    int product_odd_result = product_odd(arr, size);
    double average_result = average(arr, size);

    // Print the results
    printf("Sum of even numbers: %d\n", sum_even_result);
    printf("Product of odd numbers: %d\n", product_odd_result);
    printf("Average of all numbers: %.2f\n", average_result);

    return 0;
}