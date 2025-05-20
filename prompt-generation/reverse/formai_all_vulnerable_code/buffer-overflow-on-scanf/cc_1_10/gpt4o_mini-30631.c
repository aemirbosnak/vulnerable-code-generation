//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_TERMS 20

void print_fibonacci(int terms);
void visualize_fibonacci(int fibonacci[], int terms, int max_value);

int main() {
    int terms;
    
    printf("Fibonacci Sequence Visualizer\n");
    printf("Enter the number of terms (max %d): ", MAX_TERMS);
    scanf("%d", &terms);

    if (terms < 1 || terms > MAX_TERMS) {
        printf("Number of terms must be between 1 and %d.\n", MAX_TERMS);
        return 1;
    }

    int fibonacci[MAX_TERMS];
    fibonacci[0] = 0; // F(0)
    if (terms > 1) {
        fibonacci[1] = 1; // F(1)
    }
    
    for (int i = 2; i < terms; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    printf("Fibonacci Sequence:\n");
    for (int i = 0; i < terms; i++) {
        printf("%d ", fibonacci[i]);
    }
    printf("\n\n");

    // Visualize the Fibonacci sequence
    visualize_fibonacci(fibonacci, terms, fibonacci[terms - 1]);

    return 0;
}

void visualize_fibonacci(int fibonacci[], int terms, int max_value) {
    int scale = 50; // Number of characters to represent the largest Fibonacci number
    printf("Visualization of the Fibonacci sequence:\n");

    for (int i = 0; i < terms; i++) {
        int bar_length = (fibonacci[i] * scale) / max_value; // Scale the bar length
        printf("F(%d): ", i);
        for (int j = 0; j < bar_length; j++) {
            putchar('#'); // Print bars with hashes
        }
        printf(" (%d)\n", fibonacci[i]);
        usleep(500000); // Sleep for half a second for better visualization
    }
}