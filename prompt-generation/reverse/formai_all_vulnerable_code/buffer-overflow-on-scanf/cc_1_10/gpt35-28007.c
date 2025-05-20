//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Function to compute the nth Fibonacci number
int fibonacci(int n) {
    int a = 0, b = 1, c, i;

    if (n == 0)
        return a;

    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

// Function to print the Fibonacci sequence up to n terms
void fibonacci_visualizer(int n) {
    int i;

    printf("The Fibonacci sequence for %d terms is:\n\n", n);

    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }

    printf("\n");
}

int main() {
    int n;

    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("Please enter the number of terms you would like to see: ");

    if (scanf("%d", &n) != 1) {
        printf("Invalid input. Please try again.\n");
        return 1;
    }

    if (n < 1 || n > 100) {
        printf("Invalid input. Please enter a number between 1 and 100.\n");
        return 1;
    }

    fibonacci_visualizer(n);

    printf("Thank you for using the Fibonacci Sequence Visualizer!\n");

    return 0;
}