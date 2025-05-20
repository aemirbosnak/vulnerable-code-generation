//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

void printFibonacci(int n);
void visualizeFibonacci(int n);
void updateFibonacci(int current, int previous);
void displayVisual(int number, int numeration);

int main() {
    int n;

    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("Enter the number of terms you want to visualize (greater than 0): ");
    
    while (1) {
        scanf("%d", &n);
        if (n > 0) {
            break;
        }
        printf("Please enter a valid positive integer: ");
    }

    printf("\nGenerating Fibonacci Sequence...\n\n");
    visualizeFibonacci(n);

    printf("\nThank you for using the Fibonacci Visualizer! Goodbye.\n");
    return 0;
}

void visualizeFibonacci(int n) {
    int current = 0, previous = 1, next;

    printf("Fibonacci Sequence Visualization:\n");
    printf("Term\tValue\tVisual Representation\n");
    
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            current = 0;
        } else if (i == 1) {
            current = 1;
        } else {
            next = current + previous;
            previous = current;
            current = next;
        }
        
        displayVisual(current, i + 1);
        updateFibonacci(current, previous);
    }
}

void displayVisual(int number, int numeration) {
    printf("%d\t%d\t", numeration, number);
    
    for (int i = 0; i < number; i++) {
        printf("*");
    }
    printf("\n");
}

void updateFibonacci(int current, int previous) {
    // This function encapsulates the update logic for any future extensions.
    // Currently does nothing as the values are directly used in the visualize function.
}