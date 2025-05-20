//Falcon-180B DATASET v1.0 Category: Error handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000

// Function to calculate the mean of an array
double calculate_mean(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double) sum / size;
}

// Function to calculate the variance of an array
double calculate_variance(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += pow(arr[i] - calculate_mean(arr, size), 2);
    }
    return (double) sum / size;
}

// Function to calculate the standard deviation of an array
double calculate_standard_deviation(int arr[], int size) {
    return sqrt(calculate_variance(arr, size));
}

// Function to generate a random array of integers
void generate_array(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

// Function to print an array of integers
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int size;

    // Get the size of the array from the user
    printf("Enter the size of the array (maximum %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Check if the size is valid
    if (size > MAX_SIZE) {
        printf("Error: Size of array is too large.\n");
        return 1;
    }

    // Generate the array
    generate_array(arr, size);

    // Calculate the mean, variance, and standard deviation of the array
    double mean = calculate_mean(arr, size);
    double variance = calculate_variance(arr, size);
    double standard_deviation = calculate_standard_deviation(arr, size);

    // Print the results
    printf("Mean: %.2f\n", mean);
    printf("Variance: %.2f\n", variance);
    printf("Standard Deviation: %.2f\n", standard_deviation);

    // Print the array
    printf("Array:\n");
    print_array(arr, size);

    return 0;
}