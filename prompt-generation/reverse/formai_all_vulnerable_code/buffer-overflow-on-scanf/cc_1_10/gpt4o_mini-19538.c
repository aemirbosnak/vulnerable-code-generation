//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

void generateFibonacci(int n, long long int *fibonacci) {
    fibonacci[0] = 0;
    if (n > 1) {
        fibonacci[1] = 1;

        for (int i = 2; i < n; i++) {
            fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        }
    }
}

void displayFibonacci(int n, long long int *fibonacci) {
    printf("Fibonacci Sequence Visualization:\n");
    printf("---------------------------------\n");
    
    for (int i = 0; i < n; i++) {
        printf("%lld: ", fibonacci[i]);
        
        // Create a bar representation of the Fibonacci number
        int bar_length = fibonacci[i] / 1000000; // Scale down for visualization
        for (int j = 0; j < bar_length; j++) {
            printf("█");
        }
        
        printf(" (%lld)\n", fibonacci[i]);
    }
    
    printf("---------------------------------\n");
}

int main() {
    int n;
    
    printf("Enter the number of terms in the Fibonacci sequence to display: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer greater than zero.\n");
        return 1;
    }

    long long int *fibonacci = (long long int*)malloc(n * sizeof(long long int));

    if (!fibonacci) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    generateFibonacci(n, fibonacci);
    displayFibonacci(n, fibonacci);

    free(fibonacci);
    return 0;
}