//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print the Fibonacci sequence up to n terms
void print_fibonacci(int n) {
    int i, a = 0, b = 1, c;
    printf("Fibonacci sequence up to %d terms:\n", n);
    printf("0 ");
    for (i = 1; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
        printf("%d ", c);
    }
}

// Function to visualize the Fibonacci sequence using ASCII art
void visualize_fibonacci(int n) {
    int i, a = 0, b = 1, c;
    printf("Visualizing the Fibonacci sequence up to %d terms:\n", n);
    for (i = 0; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
        printf(" %d ", c);
    }
}

int main() {
    int n;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Prompt the user for the number of terms to generate
    printf("Enter the number of terms to generate: ");
    scanf("%d", &n);

    // Generate a random number of terms between 1 and 10
    n = rand_num(1, 10);

    // Print the Fibonacci sequence up to n terms
    printf("\n");
    print_fibonacci(n);

    // Visualize the Fibonacci sequence up to n terms
    printf("\n");
    visualize_fibonacci(n);

    return 0;
}