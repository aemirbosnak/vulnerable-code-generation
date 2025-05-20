//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: secure
#include <stdio.h>
#include <stdlib.h>

void generate_fibonacci(int n, long long **fibonacci_sequence) {
    *fibonacci_sequence = malloc(n * sizeof(long long));
    if (*fibonacci_sequence == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    (*fibonacci_sequence)[0] = 0;
    if (n > 1) {
        (*fibonacci_sequence)[1] = 1;
        for (int i = 2; i < n; i++) {
            (*fibonacci_sequence)[i] = (*fibonacci_sequence)[i-1] + (*fibonacci_sequence)[i-2];
        }
    }
}

void visualize_fibonacci(int n, long long *fibonacci_sequence) {
    for (int i = 0; i < n; i++) {
        printf("Fibonacci[%d]: %lld\n", i, fibonacci_sequence[i]);
    }

    printf("\nVisual Representation:\n");
    for (int i = 0; i < n; i++) {
        printf("Fibonacci[%d]: ", i);
        for (int j = 0; j < fibonacci_sequence[i]; j += 100000) { // Scale for larger numbers
            printf("*");
        }
        printf(" (%lld)\n", fibonacci_sequence[i]);
    }
}

void free_memory(long long *fibonacci_sequence) {
    free(fibonacci_sequence);
}

int main() {
    int n;
    printf("Enter the length of Fibonacci sequence to generate (greater than 0): ");
    while (1) {
        if (scanf("%d", &n) != 1 || n <= 0) {
            printf("Invalid input. Please enter a positive integer: ");
            while (getchar() != '\n'); // Clear the input buffer
        } else {
            break;
        }
    }

    long long *fibonacci_sequence = NULL;
    generate_fibonacci(n, &fibonacci_sequence);
    
    visualize_fibonacci(n, fibonacci_sequence);
    
    free_memory(fibonacci_sequence);
    return 0;
}