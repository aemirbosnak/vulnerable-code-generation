//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 1000

// Function to generate Fibonacci sequence up to n terms
void generateFibonacciSequence(int n) {
    int firstTerm = 0, secondTerm = 1, nextTerm;

    // Print the first two terms of the sequence
    printf("Fibonacci Sequence:\n");
    printf("Term\tValue\n");
    printf("1\t%d\n", firstTerm);
    printf("2\t%d\n", secondTerm);

    // Generate the remaining terms of the sequence
    for (int i = 2; i < n; i++) {
        nextTerm = firstTerm + secondTerm;
        firstTerm = secondTerm;
        secondTerm = nextTerm;
        printf("%d\t%d\n", i, nextTerm);
    }
}

// Function to visualize the Fibonacci sequence using ASCII characters
void visualizeFibonacciSequence(int n) {
    int firstTerm = 0, secondTerm = 1, nextTerm;

    // Print the first two terms of the sequence
    printf("Fibonacci Sequence:\n");
    printf("+");
    for (int i = 0; i < firstTerm; i++) {
        printf("-");
    }
    printf("+");
    for (int i = 0; i < secondTerm - firstTerm - 1; i++) {
        printf("-");
    }
    printf("\n");

    // Generate the remaining terms of the sequence
    for (int i = 2; i < n; i++) {
        nextTerm = firstTerm + secondTerm;
        firstTerm = secondTerm;
        secondTerm = nextTerm;

        printf("+");
        for (int j = 0; j < firstTerm; j++) {
            printf("-");
        }
        printf("+");
        for (int j = 0; j < secondTerm - firstTerm - 1; j++) {
            printf("-");
        }
        printf("\n");
    }
}

int main() {
    int n;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Get the number of terms from the user
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Generate and print the Fibonacci sequence
    generateFibonacciSequence(n);
    printf("\n");

    // Visualize the Fibonacci sequence
    visualizeFibonacciSequence(n);

    return 0;
}