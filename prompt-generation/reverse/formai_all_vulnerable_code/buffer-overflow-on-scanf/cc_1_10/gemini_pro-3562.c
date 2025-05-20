//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the nth Fibonacci number
int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

// Function to print the Fibonacci sequence up to the nth term
void printFib(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", fib(i));
    }
    printf("\n");
}

// Function to plot the Fibonacci spiral
void plotFibSpiral(int n) {
    // Create a 2D array to store the Fibonacci numbers
    int **fibArray = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        fibArray[i] = (int *)malloc(n * sizeof(int));
    }

    // Initialize the Fibonacci array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fibArray[i][j] = 0;
        }
    }

    // Calculate the Fibonacci numbers and store them in the array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fibArray[i][j] = fib(i + j);
        }
    }

    // Plot the Fibonacci spiral
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (fibArray[i][j] > 0) {
                printf("%d ", fibArray[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    // Free the memory allocated for the Fibonacci array
    for (int i = 0; i < n; i++) {
        free(fibArray[i]);
    }
    free(fibArray);
}

// Main function
int main() {
    int n;

    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &n);

    printf("The Fibonacci sequence up to the %dth term is: ", n);
    printFib(n);

    printf("\nThe Fibonacci spiral for the first %d terms is: \n", n);
    plotFibSpiral(n);

    return 0;
}