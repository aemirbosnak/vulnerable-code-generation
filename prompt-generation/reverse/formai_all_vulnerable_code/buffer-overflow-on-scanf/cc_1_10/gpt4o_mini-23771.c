//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 50

// Function to calculate Fibonacci sequence
void calculateFibonacci(int n, long long fibonacci[]) {
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    for (int i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
}

// Function to visualize the Fibonacci sequence
void visualizeFibonacci(int n, long long fibonacci[]) {
    printf("\nFibonacci Sequence Visualization:\n");
    printf("Term\tValue\tGraphic\n");
    printf("---------------------------\n");
    
    for (int i = 0; i < n; i++) {
        printf("%3d\t%lld\t", i, fibonacci[i]);
        
        // Generate a graphic representation
        for (long long j = 0; j < fibonacci[i] / 100000; j++) { // Scale it down for visualization
            printf("\033[0;32m*\033[0m"); // Green stars
        }
        
        printf("\n");
    }
}

// Function to handle user input for the number of terms
int getNumberOfTerms() {
    int terms;
    printf("How many terms of the Fibonacci sequence would you like to visualize (up to %d)? ", MAX_TERMS);
    scanf("%d", &terms);
    
    while (terms < 1 || terms > MAX_TERMS) {
        printf("Please enter a number between 1 and %d: ", MAX_TERMS);
        scanf("%d", &terms);
    }
    
    return terms;
}

// Function to print a friendly goodbye message
void goodbye() {
    printf("\nThank you for using the Fibonacci Sequence Visualizer! Have a great day! 🌟\n");
}

int main() {
    long long fibonacci[MAX_TERMS]; // Array to store Fibonacci numbers
    int numberOfTerms = getNumberOfTerms(); // Get user input

    // Calculate the Fibonacci sequence
    calculateFibonacci(numberOfTerms, fibonacci);

    // Visualize the sequence
    visualizeFibonacci(numberOfTerms, fibonacci);
    
    // Send the goodbye message
    goodbye();

    return 0;
}