//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 50 // Limit the number of terms
#define DELIM ' '    // Character used for spacing in output visualization

void generateFibonacci(int *fibs, int n) {
    fibs[0] = 0; 
    fibs[1] = 1; 
    for (int i = 2; i < n; i++) {
        fibs[i] = fibs[i-1] + fibs[i-2];
    }
}

void visualizeFibonacci(int *fibs, int n) {
    int max_value = fibs[n-1];
    int scale = max_value / MAX_TERMS; // Scaling factor for visualization

    for (int i = 0; i < n; i++) {
        int bar_length = fibs[i] / scale; // Determine the bar length
        printf("%d: ", fibs[i]);
        for (int j = 0; j < bar_length; j++) {
            printf("#"); // Representing the value as a bar
        }
        printf("\n");
    }
}

void displayInstructions() {
    printf("Welcome to the Cryptic Fibonacci Sequence Visualizer!\n");
    printf("This program will generate and visualize the first %d terms of the Fibonacci sequence.\n", MAX_TERMS);
    printf("Press Enter to create this stunning visualization! \n");
}

int main() {
    int fibs[MAX_TERMS];
    int num_terms;

    displayInstructions(); // Show instructions
    getchar(); // Wait for user input

    printf("How many terms of the Fibonacci sequence? (Max %d): ", MAX_TERMS);
    scanf("%d", &num_terms);

    if (num_terms < 1 || num_terms > MAX_TERMS) {
        printf("Invalid number of terms. Should be between 1 and %d.\n", MAX_TERMS);
        return 1; // Exit if input is out of bounds
    }

    generateFibonacci(fibs, num_terms); // Fill Fibonacci array
    printf("\nFibonacci Sequence Visualization:\n");
    visualizeFibonacci(fibs, num_terms); // Visualize the generated Fibonacci numbers

    return 0; // Successfully end program
}