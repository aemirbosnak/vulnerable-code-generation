//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printFibonacci(int terms) {
    long long int first = 0, second = 1, next;

    printf("Fibonacci Sequence:\n");
    for (int i = 0; i < terms; i++) {
        if (i <= 1) {
            next = i;
        } else {
            next = first + second;
            first = second;
            second = next;
        }

        // Visualization part: making it exciting!
        for (int j = 0; j < next; j++) {
            printf("■");
        }
        printf(" (%lld)\n", next);
        usleep(500000); // Sleep for half a second for a dramatic effect
    }
}

void displayInstructions() {
    printf("\nWelcome to the Fibonacci Sequence Visualizer!\n");
    printf("=============================================\n");
    printf("This program will show you the first 'n' terms of the Fibonacci sequence.\n");
    printf("Where each term is visualized as blocks of squares '■'.\n");
    printf("You can watch the sequence grow!\n");
    printf("=============================================\n");
}

int main() {
    int terms;

    displayInstructions();

    printf("Enter the number of terms you want to see (Up to 50 for best visualization): ");
    scanf("%d", &terms);

    // Validate input
    if (terms < 1 || terms > 50) {
        printf("Please enter a valid number of terms (1 to 50).\n");
        return 1;
    }

    printf("\nGenerating Fibonacci Sequence...\n");
    printFibonacci(terms);

    printf("\nThank you for using the Fibonacci Sequence Visualizer!\n");

    return 0;
}