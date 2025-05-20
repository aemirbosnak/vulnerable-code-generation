//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the nth term of the Fibonacci sequence
int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1 || n == 2) {
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

// Function to print the Fibonacci sequence up to a given number of terms
void printFibonacci(int n) {
    int i;
    printf("Fibonacci sequence up to %d terms:\n", n);
    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

int main() {
    int n;

    // Get the number of terms to print from the user
    printf("Enter the number of terms to print: ");
    scanf("%d", &n);

    // Print the Fibonacci sequence
    printFibonacci(n);

    // Prompt the user to enter another number of terms
    printf("Would you like to print another sequence? (Y/N): ");
    char choice;
    scanf(" %c", &choice);

    while (choice!= 'N' && choice!= 'n') {
        // Get the new number of terms to print
        printf("Enter the number of terms to print: ");
        scanf("%d", &n);

        // Print the Fibonacci sequence
        printFibonacci(n);

        // Prompt the user to enter another number of terms
        printf("Would you like to print another sequence? (Y/N): ");
        scanf(" %c", &choice);
    }

    return 0;
}