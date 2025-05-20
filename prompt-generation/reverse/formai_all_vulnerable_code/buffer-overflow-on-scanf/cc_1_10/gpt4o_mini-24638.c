//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void drawBox(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void fibonacciVisualizer(int n) {
    if (n < 1) {
        printf("Please enter a positive integer greater than 0.\n");
        return;
    }

    long long a = 0, b = 1, temp;
    printf("Fibonacci Sequence Visualization:\n");

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("Fibonacci Number %d: %lld\n", i, a);
            drawBox(1);
        } else if (i == 1) {
            printf("Fibonacci Number %d: %lld\n", i, b);
            drawBox(1);
        } else {
            temp = a + b;
            printf("Fibonacci Number %d: %lld\n", i, temp);
            drawBox(temp % 10 + 1); // Use mod 10 to keep sizes manageable
            a = b;
            b = temp;
        }
        usleep(500000); // Sleep for half a second for visual effect
    }
}

int main() {
    int n;

    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("Enter the number of Fibonacci numbers to visualize: ");
    scanf("%d", &n);

    fibonacciVisualizer(n);
    
    printf("Thank you for using the Fibonacci Visualizer!\n");
    return 0;
}