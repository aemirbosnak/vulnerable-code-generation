//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100

// Function to generate Fibonacci series up to n terms
void generateFibonacciSeries(int n) {
    int firstTerm = 0, secondTerm = 1, nextTerm;

    // Print first two terms of the series
    printf("Fibonacci Series:\n");
    printf("Term\tValue\n");
    printf("1\t%d\n", firstTerm);
    printf("2\t%d\n", secondTerm);

    // Generate rest of the series
    for (int i = 2; i < n; i++) {
        nextTerm = firstTerm + secondTerm;
        printf("%d\t%d\n", i, nextTerm);
        firstTerm = secondTerm;
        secondTerm = nextTerm;
    }
}

// Function to visualize Fibonacci series using ASCII characters
void visualizeFibonacciSeries(int n) {
    int firstTerm = 0, secondTerm = 1, nextTerm;

    // Print first two terms of the series
    printf("Fibonacci Series:\n");
    printf("+");
    for (int i = 1; i < (n - 1) / 2; i++)
        printf("-");
    printf("+\n");

    // Generate rest of the series
    for (int i = 2; i < n; i++) {
        nextTerm = firstTerm + secondTerm;
        printf("+");
        for (int j = 1; j < i - 1; j++)
            printf("-");
        printf("+\n");
        firstTerm = secondTerm;
        secondTerm = nextTerm;
    }
}

int main() {
    int n;

    // Get number of terms from user
    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &n);

    // Validate input
    if (n <= 0 || n > MAX_TERMS) {
        printf("Invalid input. Please enter a number between 1 and %d.\n", MAX_TERMS);
        return 1;
    }

    // Generate Fibonacci series
    generateFibonacciSeries(n);

    // Visualize Fibonacci series
    printf("\n");
    visualizeFibonacciSeries(n);

    return 0;
}