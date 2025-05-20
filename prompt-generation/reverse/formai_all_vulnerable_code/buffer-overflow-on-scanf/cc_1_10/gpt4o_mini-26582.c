//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_TERMS 20

void print_fibonacci(int n, int fibonacci[]) {
    for(int i = 0; i < n; i++) {
        printf("%d ", fibonacci[i]);
    }
    printf("\n");
}

void visualize_fibonacci(int n, int fibonacci[]) {
    printf("\nFibonacci Sequence Visualization:\n");
    
    int max_width = fibonacci[n-1] * 2;  // Visualization width scaling factor

    for(int i = 0; i < n; i++) {
        // Calculate the number of spaces before the asterisks
        int spaces = (max_width - (fibonacci[i] * 2)) / 2;

        // Print the leading spaces
        for(int j = 0; j < spaces; j++) {
            printf(" ");
        }

        // Print asterisks to represent Fibonacci number
        for(int k = 0; k < fibonacci[i]; k++) {
            printf("*");
        }

        printf("\n");
        usleep(300000);  // Pause for a moment for better visualization
    }
}

void generate_fibonacci(int n, int fibonacci[]) {
    if (n >= 1) fibonacci[0] = 0;
    if (n >= 2) fibonacci[1] = 1;

    for(int i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
}

int main() {
    int fibonacci[MAX_TERMS];
    int n;

    printf("Enter the number of terms in the Fibonacci sequence (1 - %d): ", MAX_TERMS);
    scanf("%d", &n);

    while(n < 1 || n > MAX_TERMS) {
        printf("Invalid input. Please enter a number between 1 and %d: ", MAX_TERMS);
        scanf("%d", &n);
    }

    generate_fibonacci(n, fibonacci);

    printf("Fibonacci Sequence: ");
    print_fibonacci(n, fibonacci);

    visualize_fibonacci(n, fibonacci);

    return 0;
}