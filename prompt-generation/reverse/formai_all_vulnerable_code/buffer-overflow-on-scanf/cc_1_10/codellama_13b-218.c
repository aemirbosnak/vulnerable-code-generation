//Code Llama-13B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: optimized
// Fibonacci Sequence Visualizer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_TERMS 100
#define WIDTH 80
#define HEIGHT 20

void draw_fibonacci_sequence(int n) {
    int x, y;
    int term1 = 0, term2 = 1, next_term;
    int fib_seq[MAX_TERMS];

    // Initialize the fibonacci sequence
    for (x = 0; x < MAX_TERMS; x++) {
        fib_seq[x] = 0;
    }

    // Calculate the fibonacci sequence
    for (x = 0; x < n; x++) {
        next_term = term1 + term2;
        fib_seq[x] = next_term;
        term1 = term2;
        term2 = next_term;
    }

    // Draw the fibonacci sequence
    for (x = 0; x < n; x++) {
        for (y = 0; y < HEIGHT; y++) {
            if (y < fib_seq[x]) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    draw_fibonacci_sequence(n);

    return 0;
}