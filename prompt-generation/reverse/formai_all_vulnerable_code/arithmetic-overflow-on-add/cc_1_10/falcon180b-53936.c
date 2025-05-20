//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 1000
#define HEIGHT 800

// Function to generate Fibonacci sequence
void generateFibonacci(int n, int a, int b) {
    int i, j, k;
    int fib[n];

    // Initialize the first two terms of the sequence
    fib[0] = a;
    fib[1] = b;

    // Generate the rest of the sequence
    for (i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    // Print the sequence
    for (i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }
}

// Function to visualize the Fibonacci sequence
void visualizeFibonacci(int n, int a, int b) {
    int i, j, k;
    int fib[n];

    // Initialize the first two terms of the sequence
    fib[0] = a;
    fib[1] = b;

    // Generate the rest of the sequence
    for (i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    // Print the sequence
    for (i = 0; i < n; i++) {
        // Calculate the x and y coordinates for each term
        int x = i * (HEIGHT / n);
        int y = (int) (log(fib[i]) / log(2) * (WIDTH / n));

        // Draw a circle at each term's coordinates
        for (j = 0; j < 10; j++) {
            for (k = 0; k < 10; k++) {
                if (sqrt(pow(k - x, 2) + pow(j - y, 2)) <= 5) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
}

int main() {
    int n, a, b;

    // Get user input for sequence length, starting terms, and visualization
    printf("Enter the length of the Fibonacci sequence: ");
    scanf("%d", &n);

    printf("Enter the first term of the sequence: ");
    scanf("%d", &a);

    printf("Enter the second term of the sequence: ");
    scanf("%d", &b);

    // Generate the sequence
    generateFibonacci(n, a, b);

    // Visualize the sequence
    printf("\n\nVisualizing the Fibonacci sequence...\n");
    visualizeFibonacci(n, a, b);

    return 0;
}