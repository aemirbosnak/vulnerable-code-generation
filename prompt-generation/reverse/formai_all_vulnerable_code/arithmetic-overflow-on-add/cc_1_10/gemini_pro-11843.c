//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define FIB_MAX 100  // Who needs more than 100 Fib numbers? We're not NASA!

// Declare our Fib sequence array
int fib[FIB_MAX];

// Function to calculate the Fibonacci sequence
void fib_calc() {
    fib[0] = 0;  // Fib starts with 0, that's just how it rolls.
    fib[1] = 1;  // And then it's 1, because... math.

    // Now let's dance!
    for (int i = 2; i < FIB_MAX; i++) {
        // Each Fib number is just the sum of the two before it.
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

// Function to print the Fibonacci sequence
void fib_print() {
    // Let's show off our beautiful Fib sequence!
    printf("Behold, the majestic Fibonacci sequence: \n");
    for (int i = 0; i < FIB_MAX; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");
}

// Function to plot the Fibonacci sequence
void fib_plot() {
    // Time for some visual magic!
    printf("Visualizing the Fib sequence, hold your breath: \n");

    // Create a histogram of our Fib numbers
    for (int i = 0; i < FIB_MAX; i++) {
        // Each Fib number is represented by a line of asterisks.
        for (int j = 0; j < fib[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    // Get ready for some Fib fun!
    fib_calc();  // Calculate our Fib sequence

    fib_print();  // Show off the sequence
    fib_plot();   // Plot the sequence

    // That's all, folks! We're done with our Fib extravaganza.
    return 0;
}