//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Function to generate Fibonacci sequence
void generateFibonacci(int n, int *fibArray) {
    fibArray[0] = 0;
    fibArray[1] = 1;
    for (int i = 2; i < n; i++) {
        fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
    }
}

// Function to visualize the Fibonacci sequence
void visualizeFibonacci(int n, int *fibArray) {
    printf("Fibonacci Sequence up to %d terms:\n", n);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", fibArray[i]);
        
        // Visualizing the numbers with a simple bar chart
        for (int j = 0; j < fibArray[i]; j += 1000) { // Scale down by 1000 for better visual representation
            printf("#");
        }
        printf("\n");
    }
}

int main() {
    int terms;
    
    printf("Enter the number of terms in the Fibonacci sequence you want to visualize: ");
    scanf("%d", &terms);
    
    if (terms <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    } else if (terms == 1) {
        printf("Fibonacci Sequence up to 1 term:\n0\n#\n");
        return 0;
    } else if (terms == 2) {
        printf("Fibonacci Sequence up to 2 terms:\n0 1\n#\n#\n");
        return 0;
    }

    // Allocate memory for the Fibonacci array
    int *fibArray = (int *)malloc(terms * sizeof(int)); 
    if (fibArray == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Exit if memory allocation fails
    }

    // Generate Fibonacci sequence
    generateFibonacci(terms, fibArray);
    
    // Visualize Fibonacci sequence
    visualizeFibonacci(terms, fibArray);
    
    // Free allocated memory
    free(fibArray);
    
    return 0;
}