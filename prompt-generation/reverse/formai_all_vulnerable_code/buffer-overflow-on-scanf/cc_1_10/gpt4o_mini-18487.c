//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_fibonacci(int n, int *fibonacci) {
    printf("Fibonacci Sequence up to %d terms:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci[i]);
    }
    printf("\n");
}

void visualize_fibonacci(int n, int *fibonacci) {
    printf("\nFibonacci Sequence Visualization:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < fibonacci[i]; j++) {
            printf("*");
        }
        printf(" (%d)\n", fibonacci[i]);
        usleep(500000); // Sleep for 0.5 seconds for better visualization
    }
}

void generate_fibonacci(int n, int *fibonacci) {
    if (n <= 0) return;
    fibonacci[0] = 0;
    if (n == 1) return;
    fibonacci[1] = 1;
    for (int i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
}

int main() {
    int n;
    printf("Enter the number of terms in the Fibonacci sequence you want to generate: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    int *fibonacci = (int *)malloc(n * sizeof(int)); // Allocate memory for Fibonacci sequence
    if (fibonacci == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    generate_fibonacci(n, fibonacci);
    print_fibonacci(n, fibonacci);
    visualize_fibonacci(n, fibonacci);

    free(fibonacci); // Clean up allocated memory
    return 0;
}