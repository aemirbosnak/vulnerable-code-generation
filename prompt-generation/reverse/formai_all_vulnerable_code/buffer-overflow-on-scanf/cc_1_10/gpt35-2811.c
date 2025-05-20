//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: complete
#include <stdio.h>

// Function to print the Fibonacci sequence
// up to a given number of terms
void fibonacciSequence(int n) {
    // Initialize the first two terms of the sequence
    int term1 = 0;
    int term2 = 1;

    // Loop through the sequence and print out each term
    printf("Fibonacci Sequence:");
    for (int i = 1; i <= n; i++) {
        printf(" %d", term1);

        // Calculate the next term in the sequence
        int nextTerm = term1 + term2;
        term1 = term2;
        term2 = nextTerm;
    }
    printf("\n");
}

// Function to print the Fibonacci sequence with a visual representation
void fibonacciVisualizer(int n) {
    // Initialize the first two terms of the sequence
    int term1 = 0;
    int term2 = 1;

    // Print out the initial visualization
    printf("0\n");
    printf("1\n");

    // Loop through the sequence and print out each term with a visual representation
    for (int i = 3; i <= n; i++) {
        // Calculate the next term in the sequence
        int nextTerm = term1 + term2;
        term1 = term2;
        term2 = nextTerm;

        // Print out the visual representation of the current term in the sequence
        for (int j = 0; j < nextTerm; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int numTerms;

    // Prompt the user to enter the number of terms they want in the sequence
    printf("Enter the number of terms you want in the Fibonacci sequence: ");
    scanf("%d", &numTerms);

    // Print out the Fibonacci sequence without the visual representation
    fibonacciSequence(numTerms);

    // Print out the Fibonacci sequence with the visual representation
    fibonacciVisualizer(numTerms);

    return 0;
}