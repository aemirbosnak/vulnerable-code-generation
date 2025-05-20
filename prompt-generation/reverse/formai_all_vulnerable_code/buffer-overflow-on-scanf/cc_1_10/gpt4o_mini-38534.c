//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FIB 20 // Maximum Fibonacci numbers to display
#define DELAY 500000 // Delay time in microseconds for visual effect

// Function to clear the terminal screen
void clearScreen() {
    printf("\033[H\033[J");
}

// Function to generate and display Fibonacci numbers
void visualizeFibonacci(int count) {
    unsigned long long fib[MAX_FIB];
    fib[0] = 0;
    fib[1] = 1;

    if (count >= 1) {
        printf("Fibonacci Sequence Visualization\n");
        printf("================================\n");
        printf("Index\tFibonacci\tVisualization\n");
        printf("================================\n");
        printf("0\t0\t");
        for (int i = 0; i < fib[0]; i++) printf("*");
        printf("\n");

        for (int i = 1; i < count; i++) {
            if (i > 1) {
                fib[i] = fib[i - 1] + fib[i - 2];
            }

            clearScreen(); // Clear screen for visual effect

            printf("Fibonacci Sequence Visualization\n");
            printf("================================\n");
            printf("Index\tFibonacci\tVisualization\n");
            printf("================================\n");
            for (int j = 0; j <= i; j++) {
                printf("%d\t%llu\t", j, fib[j]);
                for (unsigned long long k = 0; k < fib[j]; k++) {
                    printf("*");
                }
                printf("\n");
            }
            usleep(DELAY); // Delay for visual effect
        }
    }
}

int main() {
    int n;

    printf("Enter the number of Fibonacci terms to visualize (max %d): ", MAX_FIB);
    scanf("%d", &n);

    if (n < 1 || n > MAX_FIB) {
        printf("Please enter a number between 1 and %d.\n", MAX_FIB);
        return 1;
    }

    visualizeFibonacci(n);
    return 0;
}