//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

// Function to print the fibonacci series up to n terms
void printFibonacciSeries(int n) {
    int first = 0, second = 1, nextTerm;

    // Print the first two terms
    printf("Fibonacci Series: ");
    printf("%d ", first);
    printf("%d ", second);

    // Calculate and print the remaining terms
    for (int i = 2; i < n; i++) {
        nextTerm = first + second;
        first = second;
        second = nextTerm;
        printf("%d ", nextTerm);
    }
    printf("\n");
}

// Function to generate a random number between min and max
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    int n;

    // Get the number of terms from the user
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Validate the input
    if (n <= 0 || n > MAX) {
        printf("Invalid input. Please enter a number between 1 and %d.\n", MAX);
        return 1;
    }

    // Print the fibonacci series
    printFibonacciSeries(n);

    // Generate a random number within the range of the fibonacci series
    int randomNumber = generateRandomNumber(1, n - 1);

    // Check if the random number is in the fibonacci series
    if (isFibonacci(randomNumber)) {
        printf("The number %d is in the Fibonacci series.\n", randomNumber);
    } else {
        printf("The number %d is not in the Fibonacci series.\n", randomNumber);
    }

    return 0;
}

// Function to check if a number is in the Fibonacci series
int isFibonacci(int n) {
    int first = 0, second = 1, nextTerm;

    // Calculate the Fibonacci series up to the n-th term
    while (nextTerm = first + second, nextTerm <= n) {
        first = second;
        second = nextTerm;
    }

    if (nextTerm == n) {
        return 1;
    }

    return 0;
}