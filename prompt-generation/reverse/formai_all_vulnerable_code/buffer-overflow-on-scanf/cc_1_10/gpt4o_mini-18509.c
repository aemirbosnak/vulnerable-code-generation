//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: introspective
#include <stdio.h>

// Function to generate Fibonacci numbers
void generateFibonacci(int n, int fib[]) {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

// Function to print the pattern
void printPattern(int levels, int fib[]) {
    // Max height determined by the largest Fibonacci number below the max levels
    int height = fib[levels - 1];
    int mid = height / 2; // Mid-point for mirroring

    // Loop through each level
    for (int i = 0; i < levels; i++) {
        int currentFib = fib[i];
        int spaces = mid - (currentFib / 2);
        
        // Print leading spaces
        for (int s = 0; s < spaces; s++) {
            printf(" ");
        }
        
        // Print the Fibonacci characters
        for (int j = 0; j < currentFib; j++) {
            // Make it dynamic by changing characters
            char ch = (j % 2 == 0) ? '*' : '#';
            printf("%c", ch);
        }
        
        // New line for the next level
        printf("\n");
    }
}

int main() {
    int levels;

    // User prompt for the number of levels
    printf("Enter the number of levels for the Fibonacci Pattern (1-20): ");
    scanf("%d", &levels);

    // Ensure levels are within bounds
    if (levels < 1 || levels > 20) {
        printf("Please enter a valid number between 1 and 20.\n");
        return 1;
    }

    // Fibonacci array
    int fib[20]; // Keeping it to 20 as mentioned in conditions
    generateFibonacci(levels, fib);

    // Print the Fibonacci Pattern
    printf("\nFibonacci Pattern:\n");
    printPattern(levels, fib);

    return 0;
}