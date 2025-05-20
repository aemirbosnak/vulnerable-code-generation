//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TERMS 1000

// Function to generate Fibonacci sequence
void generateFibonacci(int numTerms) {
    int firstTerm = 0, secondTerm = 1, nextTerm;

    // Print first two terms
    printf("Fibonacci Sequence:\n");
    printf("Term %d: %d\n", 0, firstTerm);
    printf("Term %d: %d\n", 1, secondTerm);

    // Generate remaining terms
    for (int i = 2; i < numTerms; i++) {
        nextTerm = firstTerm + secondTerm;
        firstTerm = secondTerm;
        secondTerm = nextTerm;
        printf("Term %d: %d\n", i, nextTerm);
    }
}

// Function to visualize Fibonacci sequence using ASCII art
void visualizeFibonacci(int numTerms) {
    int firstTerm = 0, secondTerm = 1, nextTerm;

    // Print first two terms
    printf("Fibonacci Sequence:\n");
    printf("+----+----+\n");
    printf("| %d | %d |\n", firstTerm, secondTerm);
    printf("+----+----+\n");

    // Generate remaining terms
    for (int i = 2; i < numTerms; i++) {
        nextTerm = firstTerm + secondTerm;
        firstTerm = secondTerm;
        secondTerm = nextTerm;
        printf("+----+----+\n");
        printf("| %d | %d |\n", firstTerm, secondTerm);
        printf("+----+----+\n");
    }
}

// Function to get user input for number of terms
int getNumTerms() {
    int numTerms;

    printf("Enter the number of terms to generate: ");
    scanf("%d", &numTerms);

    return numTerms;
}

int main() {
    srand(time(NULL));

    // Get number of terms from user
    int numTerms = getNumTerms();

    // Generate Fibonacci sequence
    generateFibonacci(numTerms);

    // Visualize Fibonacci sequence
    visualizeFibonacci(numTerms);

    return 0;
}