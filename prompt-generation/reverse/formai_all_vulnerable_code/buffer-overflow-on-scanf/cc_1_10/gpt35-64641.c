//FormAI DATASET v1.0 Category: Math exercise ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// function to generate random integers
int generateRandomInteger(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// function to calculate the mean of an array of integers
float calculateMean(int arr[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (float)sum/size;
}

// function to calculate the standard deviation of an array of integers
float calculateStdDeviation(int arr[], int size, float mean) {
    float sum = 0;
    for(int i = 0; i < size; i++) {
        sum += pow(arr[i] - mean, 2);
    }
    return sqrt(sum/size);
}

int main() {
    int size, min, max;

    // get user input for array size, minimum value, and maximum value
    printf("Enter the size of the integer array: ");
    scanf("%d", &size);

    printf("Enter the minimum value of the array: ");
    scanf("%d", &min);

    printf("Enter the maximum value of the array: ");
    scanf("%d", &max);

    // create an array of integers and fill it with random values
    int arr[size];
    srand(time(NULL));
    for(int i = 0; i < size; i++) {
        arr[i] = generateRandomInteger(min, max);
    }

    // calculate the mean and standard deviation of the array
    float mean = calculateMean(arr, size);
    float stdDev = calculateStdDeviation(arr, size, mean);

    // print the array and its mean and standard deviation
    printf("\nThe generated integer array is: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\nThe mean of the array is: %f\n", mean);
    printf("The standard deviation of the array is: %f\n", stdDev);

    return 0;
}