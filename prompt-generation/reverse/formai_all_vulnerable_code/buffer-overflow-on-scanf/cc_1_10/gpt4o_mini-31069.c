//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

void printColor(int num, int color) {
    // Set the color for terminal output
    printf("\033[%dm", color);
    printf("%d", num);
    // Reset to default color
    printf("\033[0m");
}

void printFibonacci(int terms) {
    long long int first = 0, second = 1, next;

    printf("\n");
    printf("   ..                                         ..   \n");
    printf("  /.|~\\~~   Fibonacci Sequence Visualizer   ~~/|.\\  \n");
    printf("  |  |~|                                     |~|  |  \n");
    printf("  |~~| |~~~~~~~~~~~~~~~~~~~~~~~~~~~~| |~~~~~~~| |~~|  \n");
    
    // Print the first two Fibonacci numbers
    printColor(first, 32); // Color green
    printf(", ");
    printColor(second, 34); // Color blue

    // Print the Fibonacci series
    for(int i = 2; i < terms; i++) {
        next = first + second;
        // Change colors based on the sequence index
        printColor(next, 35 + (i % 6)); // Colors 35 to 40
        if (i < terms - 1) {
            printf(", ");
        } else {
            printf("\n");
        }
        first = second;
        second = next;
    }

    printf("  |~~| |~~~~~~~~~~~~~~~~~~~~~~~~~~~~| |~~~~~~~| |~~|  \n");
    printf("  |  |~|                                     |~|  |  \n");
    printf("  \\.~|_/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|_|~./~./  \n");
    printf("   `~~'                                     `~~'  \n");
}

int main() {
    int terms;

    printf("Enter the number of terms in Fibonacci sequence (e.g., 10, 20): ");
    scanf("%d", &terms);

    if (terms < 1) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    printFibonacci(terms);
    return 0;
}