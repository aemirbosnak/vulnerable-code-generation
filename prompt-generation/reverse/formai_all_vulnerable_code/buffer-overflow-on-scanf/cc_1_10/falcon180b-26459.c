//Falcon-180B DATASET v1.0 Category: Educational ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define the number of terms to be used in the Fibonacci sequence
#define MAX_TERMS 1000

// Define the function to generate the Fibonacci sequence
void generateFibonacciSequence(int n) {
    int i, t1, t2, nextTerm;

    // Initialize the first two terms
    t1 = 0;
    t2 = 1;

    // Print the first term
    printf("Fibonacci Sequence: %d\n", t1);

    // Generate the remaining terms
    for (i = 2; i < n; i++) {
        nextTerm = t1 + t2;

        // Print the next term
        printf(" %d", nextTerm);

        // Update the terms
        t1 = t2;
        t2 = nextTerm;
    }
}

// Define the function to calculate the sum of the Fibonacci sequence
int calculateSum(int n) {
    int i, sum = 0;

    // Calculate the sum of the terms
    for (i = 0; i < n; i++) {
        sum += i;
    }

    return sum;
}

// Define the function to calculate the average of the Fibonacci sequence
double calculateAverage(int n) {
    int sum = calculateSum(n);
    double average = (double) sum / n;

    return average;
}

// Define the function to calculate the standard deviation of the Fibonacci sequence
double calculateStandardDeviation(int n) {
    int sum = calculateSum(n);
    double average = calculateAverage(n);
    double deviation = 0;
    int i;

    // Calculate the deviation of each term from the average
    for (i = 0; i < n; i++) {
        deviation += pow((double) i - average, 2);
    }

    // Calculate the standard deviation
    deviation = sqrt(deviation / n);

    return deviation;
}

// Define the main function
int main() {
    int n;

    // Get the number of terms from the user
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Check if the number of terms is valid
    if (n <= 0 || n > MAX_TERMS) {
        printf("Invalid number of terms.\n");
        return 1;
    }

    // Generate the Fibonacci sequence
    printf("\nFibonacci Sequence:\n");
    generateFibonacciSequence(n);

    // Calculate the sum of the Fibonacci sequence
    printf("\nSum of the Fibonacci Sequence: %d\n", calculateSum(n));

    // Calculate the average of the Fibonacci sequence
    printf("Average of the Fibonacci Sequence: %.2f\n", calculateAverage(n));

    // Calculate the standard deviation of the Fibonacci sequence
    printf("Standard Deviation of the Fibonacci Sequence: %.2f\n", calculateStandardDeviation(n));

    return 0;
}