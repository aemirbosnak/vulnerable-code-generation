//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

void print_fibonacci(int n) {
    long long int a = 0, b = 1, next;  
    printf("Fibonacci Sequence:\n");
    printf("%lld ", a);  
    printf("%lld ", b); 

    for (int i = 2; i < n; i++) {  
        next = a + b;  
        printf("%lld ", next);
        a = b;  
        b = next;  
    }
    printf("\n");
}

void visualize_fibonacci(int terms) {
    long long int a = 0, b = 1, next;

    printf("Visual Representation of the Fibonacci Sequence:\n");
    printf("Index:  Fibonacci Number:\n");
    
    for (int i = 0; i < terms; i++) {
        if (i == 0) {
            printf("%3d: %lld ", i, a);
        } else if (i == 1) {
            printf("%3d: %lld ", i, b);
        } else {
            next = a + b; 
            printf("%3d: %lld ", i, next);
            a = b;  
            b = next;  
        }
        // Visualization with blocks
        for (int j = 0; j < next / 100000000; j++) {
            printf("█");
        }
        printf("\n");
    }
}

int main() {
    int terms;

    printf("Enter the number of terms in the Fibonacci Sequence to visualize: ");
    if (scanf("%d", &terms) != 1 || terms <= 0) {
        fprintf(stderr, "Invalid input! Please enter a positive integer.\n");
        return EXIT_FAILURE;
    }

    print_fibonacci(terms);
    visualize_fibonacci(terms);

    return EXIT_SUCCESS;
}