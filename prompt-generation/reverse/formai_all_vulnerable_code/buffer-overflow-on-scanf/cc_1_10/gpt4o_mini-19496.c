//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 50
#define HEIGHT 20

// Function prototypes
void initializeCanvas(char canvas[HEIGHT][WIDTH]);
void drawFibonacciSequence(int n, char canvas[HEIGHT][WIDTH]);
void displayCanvas(char canvas[HEIGHT][WIDTH]);
void printFibonacci(int n);
void printInstructions();

int main() {
    int n;
    char canvas[HEIGHT][WIDTH];

    printInstructions();

    while (1) {
        printf("Enter the number of Fibonacci terms to visualize (or -1 to exit): ");
        scanf("%d", &n);
        
        if (n == -1) {
            break; // Exit loop if user enters -1
        } else if (n < 0) {
            printf("Please enter a non-negative number or -1 to exit.\n");
            continue; // Handle invalid input
        }

        // Initialize the canvas for visualization
        initializeCanvas(canvas);
        
        // Draw Fibonacci sequence on canvas
        drawFibonacciSequence(n, canvas);
        
        // Display the canvas
        displayCanvas(canvas);
        
        // Print the actual Fibonacci numbers for reference
        printFibonacci(n);
    }
    
    return 0;
}

// Function to initialize the canvas with spaces
void initializeCanvas(char canvas[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            canvas[i][j] = ' '; // Fill canvas with spaces
        }
    }
}

// Function to draw the Fibonacci sequence in a visual format
void drawFibonacciSequence(int n, char canvas[HEIGHT][WIDTH]) {
    int fib1 = 0, fib2 = 1, nextFib;
    int x = 1, y = HEIGHT / 2; // Start position in the canvas
    int maxFib = 0; // Keep track of maximum Fibonacci number

    // Calculate Fibonacci numbers and plot on canvas
    for (int i = 0; i < n; i++) {
        nextFib = fib1 + fib2;

        // Update maximum Fibonacci length
        if (nextFib > maxFib) {
            maxFib = nextFib;
        }

        // Plot Fibonacci numbers visually in the canvas
        if (i > 0) {
            // Draw a horizontal bar (approximation) for the current Fibonacci number
            for (int j = 0; j < nextFib / (maxFib / (WIDTH - 2)); j++) {
                if (x + j < WIDTH - 1) {
                    canvas[y][x + j] = '*';
                }
            }
            x += nextFib / (maxFib / (WIDTH - 2)) + 1; // Move to the next position
        }

        // Update Fibonacci values for the next iteration
        fib1 = fib2;
        fib2 = nextFib;
    }
}

// Function to display the canvas
void displayCanvas(char canvas[HEIGHT][WIDTH]) {
    printf("\nFibonacci Sequence Visualizer:\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            putchar(canvas[i][j]);
        }
        putchar('\n');
    }
    printf("\n");
}

// Function to calculate and print the Fibonacci sequence values
void printFibonacci(int n) {
    int fib1 = 0, fib2 = 1, nextFib;
    printf("Fibonacci numbers: ");
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%d ", fib1);
            continue;
        }
        if (i == 1) {
            printf("%d ", fib2);
            continue;
        }
        nextFib = fib1 + fib2;
        printf("%d ", nextFib);
        fib1 = fib2;
        fib2 = nextFib;
    }
    printf("\n\n");
}

// Function to print instructions for the user
void printInstructions() {
    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("You will be able to visualize the Fibonacci sequence visually\n");
    printf("in a simple interface. You can enter the number of terms you\n");
    printf("wish to visualize (up to %d), or enter -1 to exit.\n", (HEIGHT - 2) * 2);
    printf("Let's get started!\n");
}