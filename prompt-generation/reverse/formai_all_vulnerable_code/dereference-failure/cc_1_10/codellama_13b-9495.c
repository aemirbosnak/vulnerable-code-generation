//Code Llama-13B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: detailed
// Fibonacci Sequence Visualizer
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to generate the Fibonacci sequence
int *fib(int n) {
    int *seq = (int *)malloc(n * sizeof(int));
    seq[0] = 0;
    seq[1] = 1;
    for (int i = 2; i < n; i++) {
        seq[i] = seq[i - 1] + seq[i - 2];
    }
    return seq;
}

// Function to print the Fibonacci sequence
void print_fib(int *seq, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", seq[i]);
    }
    printf("\n");
}

// Function to print the Fibonacci sequence in a visual format
void visualize_fib(int *seq, int n) {
    int width = 70;
    int height = 10;
    int mid = width / 2;
    for (int i = 0; i < n; i++) {
        int x = mid + (seq[i] * width / (2 * n));
        int y = height - (i * height / n);
        printf("%c", seq[i] % 2 == 0 ? ' ' : '*');
        if (x > mid) {
            printf("%*c", x - mid, ' ');
        } else {
            printf("%*c", mid - x, ' ');
        }
        printf("\n");
    }
}

int main() {
    int n = 20;
    int *seq = fib(n);
    print_fib(seq, n);
    visualize_fib(seq, n);
    free(seq);
    return 0;
}