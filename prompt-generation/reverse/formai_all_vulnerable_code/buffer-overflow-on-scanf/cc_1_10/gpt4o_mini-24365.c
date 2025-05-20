//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_TERMS 50

void display_fibonacci(int *fibonacci, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", fibonacci[i]);
        fflush(stdout); // Ensure output is displayed immediately
        usleep(500000); // Pause for half a second
    }
    printf("\n");
}

void print_fibonacci_visual(int *fibonacci, int length) {
    for (int i = 0; i < length; i++) {
        printf("%*s", fibonacci[i], "*"); // Print asterisks according to the Fibonacci number
        printf("\n");
        fflush(stdout); // Ensure output is displayed immediately
        usleep(500000); // Pause for half a second
    }
}

void generate_fibonacci(int *fibonacci, int length) {
    if (length > 0) {
        fibonacci[0] = 0;
    }
    if (length > 1) {
        fibonacci[1] = 1;
    }
    for (int i = 2; i < length; i++) {
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }
}

int main() {
    int fibonacci[MAX_TERMS];
    int terms;

    printf("Enter the number of terms you want in the Fibonacci sequence (up to %d): ", MAX_TERMS);
    scanf("%d", &terms);

    if (terms < 1 || terms > MAX_TERMS) {
        printf("Please enter a number between 1 and %d.\n", MAX_TERMS);
        return 1;
    }

    generate_fibonacci(fibonacci, terms);

    printf("\nFibonacci Sequence:\n");
    display_fibonacci(fibonacci, terms);

    printf("\nFibonacci Visual Representation:\n");
    print_fibonacci_visual(fibonacci, terms);

    return 0;
}