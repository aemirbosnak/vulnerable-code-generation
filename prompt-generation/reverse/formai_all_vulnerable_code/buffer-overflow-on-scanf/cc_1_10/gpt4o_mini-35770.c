//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void clearScreen() {
    // Clear the terminal screen
    printf("\033[H\033[J");
}

void printFibonacci(int count) {
    int first = 0, second = 1, next, i;

    printf("Fibonacci Sequence:\n");
    for (i = 0; i < count; i++) {
        if (i <= 1) {
            next = i;  // The first two Fibonacci numbers are 0 and 1
        } else {
            next = first + second;  // Compute the next Fibonacci number
            first = second;          // Update first and second
            second = next;
        }
        
        // Visualize the current Fibonacci number
        printf("%d: ", next);
        for (int j = 0; j < next; j++) {
            putchar('*');  // Print '*' for each value in the sequence
        }
        printf("\n");
        usleep(500000);  // Pause for half a second
    }
}

void drawFibonacciVisual(int num) {
    int first = 0, second = 1, next;

    printf("\nDrawing Fibonacci Squares:\n");
    for (int i = 0; i < num; i++) {
        if (i == 0) {
            next = first;  // The first Fibonacci number is 0
        } else if (i == 1) {
            next = second;  // The second Fibonacci number is 1
        } else {
            next = first + second;  // Compute Fibonacci number
            first = second;  // Update first and second
            second = next;
        }
        
        // Draw a square of side length 'next'
        for (int row = 0; row < next; row++) {
            for (int col = 0; col < next; col++) {
                putchar('#');  // Visualize the square with '#'
            }
            putchar('\n');
        }
        printf("\n");
        usleep(500000);  // Pause for half a second
        clearScreen();   // Clear the screen before the next square
    }
}

int main() {
    int count;

    printf("Enter the number of Fibonacci numbers to visualize (up to 15): ");
    scanf("%d", &count);

    if (count < 1 || count > 15) {
        printf("Please enter a number between 1 and 15.\n");
        return -1;
    }

    clearScreen();
    printFibonacci(count);
    usleep(1000000);  // Wait a second before the next part
    clearScreen();
    drawFibonacciVisual(count);

    return 0;
}