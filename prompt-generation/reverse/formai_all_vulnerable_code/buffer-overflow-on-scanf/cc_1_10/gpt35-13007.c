//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Declare constants
#define MAX_FIB_TERM 93
#define MIN_FIB_TERM 1

// Define function to check if input is within valid range of Fibonacci sequence
bool valid_term(int term) {
    return term >= MIN_FIB_TERM && term <= MAX_FIB_TERM;
}

// Define function to calculate nth term of Fibonacci sequence
long long fib(int term) {
    long long prev1 = 0, prev2 = 1, curr = 0;

    for (int i = 1; i <= term; i++) {
        if (i == 1) {
            curr = prev2;
        } else if (i == 2) {
            curr = prev1 + prev2;
        } else {
            curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }
    }

    return curr;
}

// Define function to print Fibonacci sequence up to n terms
void print_sequence(int n) {
    for (int i = 1; i <= n; i++) {
        printf("%lld ", fib(i));
    }
    printf("\n");
}

// Define function to print a visual representation of the Fibonacci sequence up to n terms
void print_visual(int n) {
    // Define constants for spacing and width of bars
    const int SPACING = 3;
    const int WIDTH = 5;

    // Calculate Fibonacci sequence up to n terms
    long long sequence[n];
    sequence[0] = 0;
    sequence[1] = 1;
    for (int i = 2; i < n; i++) {
        sequence[i] = sequence[i-2] + sequence[i-1];
    }

    // Print visual representation of sequence
    for (int i = 0; i < n; i++) {
        // Calculate length of bar based on value of current sequence term
        int bar_length = sequence[i] / 1000;
        if (bar_length == 0) {
            bar_length = 1;
        }

        // Print current term number
        printf("%d: ", i+1);

        // Print spaces for alignment
        for (int j = 0; j < SPACING*(n-i-1); j++) {
            printf(" ");
        }

        // Print bar
        for (int j = 0; j < WIDTH*bar_length; j++) {
            printf("*");
        }

        printf("\n");
    }
}

int main() {
    int n = 0;

    // Prompt user for input until valid input received
    while (true) {
        printf("Enter the number of terms in the Fibonacci sequence to display (1-%d): ", MAX_FIB_TERM);
        scanf("%d", &n);

        if (valid_term(n)) {
            break;
        }

        printf("Invalid input. Please enter a number between %d and %d.\n", MIN_FIB_TERM, MAX_FIB_TERM);
    }

    // Print visual representation of Fibonacci sequence
    printf("\nVisual representation of Fibonacci sequence:\n\n");
    print_visual(n);

    // Print raw sequence
    printf("\nRaw Fibonacci sequence:\n\n");
    print_sequence(n);

    return 0;
}