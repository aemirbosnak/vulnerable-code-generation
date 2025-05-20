//FormAI DATASET v1.0 Category: Digital signal processing ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the signal buffer
#define MAX_SIZE 100

// Function to read the signal values
void readSignal(float signal[], int n) {
    printf("Enter the signal values:\n");
    for(int i = 0; i < n; i++) {
        scanf("%f", &signal[i]);
    }
}

// Function to calculate the average of the signal values
float calculateAverage(float signal[], int n) {
    float sum = 0;
    for(int i = 0; i < n; i++) {
        sum += signal[i];
    }
    return sum/n;
}

// Function to calculate the mean squared error between two signals
float calculateMSE(float signal1[], float signal2[], int n) {
    float sum = 0;
    for(int i = 0; i < n; i++) {
        sum += (signal1[i] - signal2[i])*(signal1[i] - signal2[i]);
    }
    return sum/n;
}

// Function to add two signals
void addSignals(float signal1[], float signal2[], float result[], int n) {
    for(int i = 0; i < n; i++) {
        result[i] = signal1[i] + signal2[i];
    }
}

// Function to subtract two signals
void subtractSignals(float signal1[], float signal2[], float result[], int n) {
    for(int i = 0; i < n; i++) {
        result[i] = signal1[i] - signal2[i];
    }
}

int main() {
    float signal1[MAX_SIZE], signal2[MAX_SIZE], result[MAX_SIZE];
    int n;

    // Read the number of signal values
    printf("Enter the number of signal values (less than or equal to %d):\n", MAX_SIZE);
    scanf("%d", &n);

    // Read the signal values
    readSignal(signal1, n);
    readSignal(signal2, n);

    // Calculate the average of the signal values
    float avg = calculateAverage(signal1, n);
    printf("The average of signal 1 is: %f\n", avg);

    // Calculate the mean squared error between the two signals
    float mse = calculateMSE(signal1, signal2, n);
    printf("The mean squared error between the two signals is: %f\n", mse);

    // Add the two signals
    addSignals(signal1, signal2, result, n);
    printf("The sum of the two signals is:\n");
    for(int i = 0; i < n; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");

    // Subtract the two signals
    subtractSignals(signal1, signal2, result, n);
    printf("The difference between the two signals is:\n");
    for(int i = 0; i < n; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");

    return 0;
}