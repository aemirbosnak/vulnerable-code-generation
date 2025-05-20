//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

void printFibonacci(int n) {
    unsigned long long *fibonacci = (unsigned long long *)malloc(n * sizeof(unsigned long long));
    if (fibonacci == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Initializing the first two Fibonacci numbers
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    // Generating Fibonacci sequence
    printf("Fibonacci Sequence: \n");
    printf("%llu, %llu", fibonacci[0], fibonacci[1]);

    for (int i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        printf(", %llu", fibonacci[i]);
    }
    printf("\n");

    free(fibonacci); // Don't forget to free allocated memory
}

/* Function to visualize the Fibonacci numbers in a formatted manner */
void visualizeFibonacci(int n) {
    printf("\nVisualizing the Fibonacci sequence:\n");
    for (int i = 0; i < n; i++) {
        // Calculate the current Fibonacci number
        unsigned long long fibNum = (i == 0) ? 0 : (i == 1) ? 1 : 0;

        if (i > 1) {
            unsigned long long a = 0, b = 1;
            for (int j = 2; j <= i; j++) {
                fibNum = a + b;
                a = b;
                b = fibNum;
            }
        }
        
        // Visualization - Simple character-based representation
        printf("%2d: ", i);
        for (unsigned long long j = 0; j < fibNum; j++) {
            putchar('*');
        }
        printf(" (%llu)\n", fibNum);
    }
}

/* Function to get user input */
int getUserInput() {
    int n;
    printf("Enter the number of Fibonacci terms you want to visualize: ");
    while (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer: ");
        while(getchar() != '\n'); // clear input buffer
    }
    return n;
}

int main() {
    int n = getUserInput();

    // Generate and visualize Fibonacci numbers
    printFibonacci(n);
    visualizeFibonacci(n);

    return 0;
}