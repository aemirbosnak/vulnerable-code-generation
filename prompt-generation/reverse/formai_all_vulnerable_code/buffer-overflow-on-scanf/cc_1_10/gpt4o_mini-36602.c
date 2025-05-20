//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_TERMS 20

void print_fibonacci(int n) {
    long long int fib[MAX_TERMS];
    fib[0] = 0;
    fib[1] = 1;
    
    for(int i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    printf("\nFibonacci Sequence (first %d terms):\n", n);
    for (int i = 0; i < n; i++) {
        printf("%lld ", fib[i]);
        if ((i + 1) % 5 == 0) printf("\n");
    }
    printf("\n");
}

void display_visualization(int terms) {
    long long int a = 0, b = 1, next;
    printf("\nVisualization of the Fibonacci Sequence:\n\n");
    
    for(int i = 0; i < terms; i++) {
        printf("%*lld ", (i + 1) * 2, a);
        if (i > 0) {
            printf("\033[0;32m");  // Change text color to green for visualization
            printf("%*lld ", (i + 1) * 2, b);
            printf("\033[0m"); // Reset to default color
        }
        next = a + b;
        a = b;
        b = next;

        // Sleep to visualize the progression
        usleep(500000);
    }
    printf("\n");
}

int main() {
    int terms;

    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("Enter the number of terms to display (max %d): ", MAX_TERMS);
    scanf("%d", &terms);

    if (terms < 1 || terms > MAX_TERMS) {
        printf("Please enter a valid number of terms (1 to %d).\n", MAX_TERMS);
        return EXIT_FAILURE;
    }

    print_fibonacci(terms);
    display_visualization(terms);

    printf("Thank you for using the Fibonacci Sequence Visualizer!\n");
    return EXIT_SUCCESS;
}