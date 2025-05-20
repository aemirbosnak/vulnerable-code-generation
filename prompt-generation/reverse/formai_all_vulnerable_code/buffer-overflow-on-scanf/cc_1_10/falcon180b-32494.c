//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Function to print the Fibonacci sequence up to n terms
void printFibonacci(int n) {
    int first = 0, second = 1, next;

    printf("Fibonacci sequence up to %d terms:\n", n);
    printf("0 1 ");

    // Print the remaining terms of the sequence
    for (int i = 2; i < n; i++) {
        next = first + second;
        printf("%d ", next);
        first = second;
        second = next;
    }
}

// Function to visualize the Fibonacci sequence using ASCII art
void visualizeFibonacci(int n) {
    int first = 0, second = 1, next;

    printf("Visualizing the Fibonacci sequence up to %d terms:\n", n);

    // Print the first two terms
    printf("0\n1\n");

    // Print the remaining terms with ASCII art
    for (int i = 2; i < n; i++) {
        next = first + second;
        printf("%d ", next);

        // Print the ASCII art for the current term
        for (int j = 0; j < i; j++) {
            printf(" ");
        }
        for (int j = 0; j < next; j++) {
            printf("*");
        }
        printf("\n");

        first = second;
        second = next;
    }
}

int main() {
    int n;

    // Get the number of terms from the user
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Print the Fibonacci sequence
    printFibonacci(n);

    // Visualize the Fibonacci sequence
    visualizeFibonacci(n);

    return 0;
}