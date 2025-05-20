//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// Function to initialize the array with random numbers
void initializeArray(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

// Function to calculate the mean of an array
double calculateMean(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double) sum / size;
}

// Function to calculate the standard deviation of an array
double calculateStdDev(int arr[], int size) {
    double mean = calculateMean(arr, size);
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += pow(arr[i] - mean, 2);
    }
    return sqrt(sum / size);
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[size];
    initializeArray(arr, size);

    double mean = calculateMean(arr, size);
    double stdDev = calculateStdDev(arr, size);

    printf("The array is:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("The mean is: %.2f\n", mean);
    printf("The standard deviation is: %.2f\n", stdDev);

    return 0;
}