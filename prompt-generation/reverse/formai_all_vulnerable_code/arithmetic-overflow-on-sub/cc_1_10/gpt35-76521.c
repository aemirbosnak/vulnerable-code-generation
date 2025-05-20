//FormAI DATASET v1.0 Category: Benchmarking ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between start and end
int rand_num(int start, int end) {
    return (rand() % (end - start + 1)) + start;
}

// Function to find the maximum value of an array
int max_value(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to find the minimum value of an array
int min_value(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Function to perform bubble sort on an array
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    srand(time(0)); // Seed random number generator with current time

    printf("Welcome to the Sherlock Holmes Benchmarking Program.\n");
    printf("We will be generating a large array of random numbers and performing several benchmarking tests on it.\n");

    int n; // Size of array
    printf("Please enter the size of the array: ");
    scanf("%d", &n);

    // Allocate memory for array
    int* arr = (int*)malloc(n * sizeof(int));

    // Generate random numbers and store them in the array
    for (int i = 0; i < n; i++) {
        arr[i] = rand_num(1, 1000);
    }

    // Find and print the maximum and minimum values in the array
    int max = max_value(arr, n);
    int min = min_value(arr, n);
    printf("The maximum value in the array is %d.\n", max);
    printf("The minimum value in the array is %d.\n", min);

    // Perform bubble sort on the array and measure the time taken
    clock_t start_bubble = clock();
    bubble_sort(arr, n);
    clock_t end_bubble = clock();
    double time_bubble = (double)(end_bubble - start_bubble) / CLOCKS_PER_SEC;
    printf("The array has been sorted using bubble sort in %f seconds.\n", time_bubble);

    // Free memory allocated for array
    free(arr);

    printf("Thank you for using the Sherlock Holmes Benchmarking Program.\n");

    return 0;
}