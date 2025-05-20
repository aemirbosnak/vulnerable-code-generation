//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

void generate_fibonacci(int n, long long *fibonacci) {
    fibonacci[0] = 0;
    if (n > 1) {
        fibonacci[1] = 1;
        for (int i = 2; i < n; i++) {
            fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        }
    }
}

void visualize_fibonacci(int n, long long *fibonacci) {
    for (int i = 0; i < n; i++) {
        // Print leading spaces for indentation
        for (int j = 0; j < i; j++) {
            printf("   ");  // 3 spaces for each indentation level
        }
        printf("%lld\n", fibonacci[i]);
    }
}

int main() {
    int terms = 0;
    
    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("Enter the number of Fibonacci terms (max 50): ");
    
    while (1) {
        scanf("%d", &terms);
        if (terms > 0 && terms <= 50) {
            break;
        } else {
            printf("Please enter a positive integer between 1 and 50: ");
        }
    }
    
    long long *fibonacci = malloc(terms * sizeof(long long));
    if (fibonacci == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    
    generate_fibonacci(terms, fibonacci);
    
    printf("\nHere is the Fibonacci sequence:\n");
    visualize_fibonacci(terms, fibonacci);
    
    free(fibonacci);
    return 0;
}