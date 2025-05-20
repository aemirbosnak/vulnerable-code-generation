//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Donald Knuth
// Fibonacci Sequence Visualizer, in tribute to Donald Knuth
// Complexity: O(log F)

#include <stdio.h>
#include <stdlib.h>

// Knuth's golden ratio
#define PHI 1.618033988749895

// Array of Fibonacci numbers
int fib_array[101];

// Precalculate Fibonacci sequence up to F100
void init_fib_array() {
    fib_array[0] = 0;
    fib_array[1] = 1;
    for (int i = 2; i < 101; i++)
        fib_array[i] = fib_array[i - 1] + fib_array[i - 2];
}

// Convert a decimal number to a Fibonacci representation
void dec_to_fib(int n, char *fib_rep) {
    int i = 100;
    while (n > 1) {
        if (n % fib_array[i] == 0) {
            fib_rep[i] = '1';
            n -= fib_array[i];
        }
        i--;
    }
}

// Draw a horizontal Fibonacci spiral
void draw_spiral(int n) {
    char fib_rep[101];
    for (int i = 0; i < 101; i++)
        fib_rep[i] = '0';

    dec_to_fib(n, fib_rep);

    // Draw the spiral
    for (int i = 1; i < 101; i++) {
        if (fib_rep[i] == '1')
            printf("%c", '*');
        else
            printf("%c", ' ');
    }
    printf("\n");
}

int main() {
    init_fib_array();

    // Draw Fibonacci spirals for the first 20 numbers
    for (int n = 1; n <= 20; n++)
        draw_spiral(n);

    return 0;
}