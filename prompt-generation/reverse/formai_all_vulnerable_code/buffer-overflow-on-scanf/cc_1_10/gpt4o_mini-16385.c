//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: systematic
#include <stdio.h>

// Function to generate Fibonacci numbers
void generateFibonacci(int n, long long *fibonacci) {
    if (n >= 1) {
        fibonacci[0] = 0;
    }
    if (n >= 2) {
        fibonacci[1] = 1;
    }
    for (int i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
}

// Function to visualize the Fibonacci sequence
void visualizeFibonacci(int n, long long *fibonacci) {
    printf("\nFibonacci Sequence Visualization:\n");
    printf("-----------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%lld: ", fibonacci[i]);
        for (long long j = 0; j < fibonacci[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("-----------------------------------\n");
}

int main() {
    int count;

    // Get user input for the number of Fibonacci numbers to display
    printf("Enter the number of Fibonacci numbers to visualize: ");
    scanf("%d", &count);

    if (count <= 0) {
        printf("Please enter a positive integer greater than 0.\n");
        return 1;
    }

    // Array to hold Fibonacci numbers
    long long fibonacci[count];

    // Generate Fibonacci numbers up to the specified count
    generateFibonacci(count, fibonacci);

    // Visualize the Fibonacci sequence
    visualizeFibonacci(count, fibonacci);

    return 0;
}