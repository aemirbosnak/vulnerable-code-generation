//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

void printFibonacci(int n) {
    long long int first = 0, second = 1, next;
    printf("Fibonacci Sequence:\n");
    
    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i;
        } else {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%lld ", next);
    }
    printf("\n");
}

void visualizeFibonacci(int n) {
    long long int first = 0, second = 1, next;
    printf("Visualization of Fibonacci Sequence:\n");

    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i;
        } else {
            next = first + second;
            first = second;
            second = next;
        }
        
        // Visualization
        printf("%lld: ", next);
        for (long long int j = 0; j < next; j++) {
            printf("#");
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the number of Fibonacci terms to generate (greater than 0): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid input. Please enter a positive integer.\n");
        return EXIT_FAILURE;
    }

    printFibonacci(n);
    visualizeFibonacci(n);

    return EXIT_SUCCESS;
}