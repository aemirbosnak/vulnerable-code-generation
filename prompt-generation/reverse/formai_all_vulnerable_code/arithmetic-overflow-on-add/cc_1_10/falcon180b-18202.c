//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the Fibonacci sequence
void printFibonacci(int n) {
    int i, t, fib1 = 0, fib2 = 1, fib3;

    for (i = 0; i < n; i++) {
        printf("%d ", fib1);
        fib3 = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib3;
    }
}

// Function to generate a random color
char *getRandomColor() {
    int r = rand() % 256;
    int g = rand() % 256;
    int b = rand() % 256;
    return malloc(9 * sizeof(char))? sprintf(malloc(9 * sizeof(char)), "#%02X%02X%02X", r, g, b) : 0;
}

int main() {
    int n, i;
    char *color;

    srand(time(NULL));

    printf("Enter the number of Fibonacci numbers to print: ");
    scanf("%d", &n);

    // Print the Fibonacci sequence
    printf("\nFibonacci sequence:\n");
    for (i = 0; i < n; i++) {
        color = getRandomColor();
        printf("\e[1;%sm%d\e[0m ", color, i + 1);
        free(color);
    }

    // Print the sequence in reverse order
    printf("\n\nFibonacci sequence in reverse order:\n");
    for (i = n - 1; i >= 0; i--) {
        color = getRandomColor();
        printf("\e[1;%sm%d\e[0m ", color, i + 1);
        free(color);
    }

    return 0;
}