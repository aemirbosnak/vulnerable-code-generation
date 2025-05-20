//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum size of the input array
#define MAX_SIZE 1000

// Function to calculate the sum of the elements in the input array
double sum(double arr[], int size) {
    int i;
    double sum = 0.0;

    for (i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum;
}

// Function to calculate the average of the elements in the input array
double average(double arr[], int size) {
    return sum(arr, size) / size;
}

// Function to calculate the standard deviation of the elements in the input array
double std_dev(double arr[], int size) {
    int i;
    double mean = average(arr, size);
    double sum_squares = 0.0;

    for (i = 0; i < size; i++) {
        sum_squares += pow(arr[i] - mean, 2.0);
    }

    return sqrt(sum_squares / size);
}

int main() {
    int size;
    double arr[MAX_SIZE];

    printf("Enter the size of the array (maximum %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid array size.\n");
        return 1;
    }

    printf("Enter the elements of the array:\n");

    for (int i = 0; i < size; i++) {
        scanf("%lf", &arr[i]);
    }

    printf("The sum of the elements is: %lf\n", sum(arr, size));
    printf("The average of the elements is: %lf\n", average(arr, size));
    printf("The standard deviation of the elements is: %lf\n", std_dev(arr, size));

    return 0;
}