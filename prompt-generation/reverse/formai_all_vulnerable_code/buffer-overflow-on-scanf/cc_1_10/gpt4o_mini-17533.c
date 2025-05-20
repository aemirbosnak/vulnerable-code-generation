//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: Ada Lovelace
#include <stdio.h>

// A function that calculates Fibonacci numbers recursively.
// The Fibonacci sequence is a series of numbers where each number 
// (after the first two) is the sum of the two preceding ones.
// This elegant sequence starts with 0 and 1.
int fibonacci(int n) {
    // Base case: If n is 0, the Fibonacci number is 0.
    if (n == 0) {
        return 0;
    }
    // Base case: If n is 1, the Fibonacci number is 1.
    else if (n == 1) {
        return 1;
    }
    // Recursive case: For n greater than 1, sum the two preceding numbers.
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// A utility function to print Fibonacci numbers up to a certain limit.
// This function decorates the process of extraction from the sequence 
// while indulging our desire for visual representation.
void printFibonacciSequence(int limit) {
    printf("Fibonacci sequence up to %d terms:\n", limit);
    for (int i = 0; i < limit; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n"); // Time for a final flourish.
}

// The main function serves as the initiation point for our exploration 
// of the Fibonacci marvel.
int main() {
    int num_terms; // Variable to hold the input from the user.

    // Engaging with the user to understand how many Fibonacci terms 
    // they wish to manifest.
    printf("Enter the number of terms in the Fibonacci sequence you desire: ");
    scanf("%d", &num_terms);

    // A gentle reminder: Ensure the input is a positive integer.
    if (num_terms < 0) {
        printf("Please enter a non-negative integer.\n");
    } else {
        // With anticipation, we proceed to unveil the Fibonacci sequence.
        printFibonacciSequence(num_terms);
    }

    // A final note of appreciation for the beauty of numbers 
    // and the elegance of algorithms.
    printf("Through this sequence, we behold the wonders of computation.\n");
    return 0; // A graceful bow as the program concludes.
}