//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: introspective
#include <stdio.h>

// Function to generate the Fibonacci sequence
void generateFibonacci(int n, long long fibonacci[]) {
    fibonacci[0] = 0;
    if (n > 1) {
        fibonacci[1] = 1;
        for (int i = 2; i < n; i++) {
            fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
        }
    } else if (n == 1) {
        fibonacci[1] = 0;
    }
}

// Function to visualize the Fibonacci numbers
void visualizeFibonacci(int n, long long fibonacci[]) {
    printf("\nFibonacci Sequence Visualization:\n");
    printf("----------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("F(%d) = %lld: ", i, fibonacci[i]);

        // Calculate size for visualization (limit to a max length of 70 for display)
        int size = fibonacci[i] > 0 ? fibonacci[i] / 10000 : 0;
        if (size > 70) {
            size = 70; // cap for very large numbers
        }

        // Print asterisks based on the size
        for (int j = 0; j < size; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n;

    // Ask the user for the number of Fibonacci numbers to generate and visualize
    printf("Enter the number of Fibonacci numbers to visualize: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer greater than zero.\n");
        return 1;
    }
  
    long long fibonacci[n];

    // Generate the Fibonacci sequence
    generateFibonacci(n, fibonacci);

    // Visualize the Fibonacci sequence
    visualizeFibonacci(n, fibonacci);

    return 0;
}