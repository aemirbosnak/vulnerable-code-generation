//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

void print_fibonacci(int n) {
    long long a = 0, b = 1, temp;

    printf("\nFibonacci Sequence (%d terms):\n", n);
    printf("Term:     Value:\n");
    printf("------------------\n");
    
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%-9d %lld\n", 1, a);
            continue;
        }
        if (i == 1) {
            printf("%-9d %lld\n", 2, b);
            continue;
        }
        temp = a + b;
        a = b;
        b = temp;
        printf("%-9d %lld\n", i + 1, b);
    }
}

void print_visualization(int n) {
    long long a = 0, b = 1, temp;

    printf("\nFibonacci Visualization (%d terms):\n", n);
    
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("0: ");
            printf("*\n");
            continue;
        }
        if (i == 1) {
            printf("1: ");
            printf("*\n");
            continue;
        }
        
        temp = a + b;
        a = b;
        b = temp;

        printf("%lld: ", b);
        for (long long j = 0; j < b; j++) {
            putchar('*');
        }
        putchar('\n');
    }
}

int main() {
    int terms;

    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("How many terms of the Fibonacci sequence would you like to see? ");
    
    // Check user input for validity
    if (scanf("%d", &terms) != 1 || terms <= 0) {
        fprintf(stderr, "Invalid input! Please enter a positive integer.\n");
        return EXIT_FAILURE;
    }

    // Check for a reasonable limit for visualization
    if (terms > 93) {
        printf("The Fibonacci sequence grows quickly! Displaying top 93 terms for visualization. \n");
        terms = 93;  // Limit to prevent overflow in visualization
    }

    print_fibonacci(terms);
    print_visualization(terms);

    printf("\nThank you for using the Fibonacci Sequence Visualizer!\n");
    return EXIT_SUCCESS;
}