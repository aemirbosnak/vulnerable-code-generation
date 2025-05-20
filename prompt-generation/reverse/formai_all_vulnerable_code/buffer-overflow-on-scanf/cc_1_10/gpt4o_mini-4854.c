//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Function to print spaces
void printSpaces(int count) {
    for(int i = 0; i < count; i++) {
        printf(" ");
    }
}

// Recursive function to draw the Sierpinski triangle
void drawTriangle(int order, int x, int y) {
    if (order == 0) {
        // Base case: Print a single '*'
        printf("*");
    } else {
        // Draw the triangle's left half
        drawTriangle(order - 1, x, y);
        // Print space for the hollow middle part
        printSpaces(1 << (order - 1)); // 2^(order-1) spaces
        // Draw the triangle's right half
        drawTriangle(order - 1, x, y + (1 << (order - 1)));
    }
}

// Function to print the Sierpinski triangle
void printSierpinski(int order) {
    // Height of the triangle
    int height = 1 << order; // 2^order
    int width = (1 << (order + 1)) - 1; // 2^(order+1) - 1

    // Print each level of the triangle
    for(int i = 0; i < height; i++) {
        // Print leading spaces
        printSpaces(width / 2 - (1 << i) / 2);
        // Draw the triangle
        drawTriangle(i, 0, 0);
        printf("\n");
    }
}

int main() {
    int order;

    printf("Welcome to the ASCII Art Sierpinski Triangle!\n");
    printf("Enter the order of the Sierpinski Triangle (0 to 8): ");
    scanf("%d", &order);

    // Check if the order is within the allowed range
    if (order < 0 || order > 8) {
        printf("Order must be between 0 and 8.\n");
        return 1;
    }

    // Print the Sierpinski triangle
    printSierpinski(order);

    printf("\nEnjoy your fractal!\n");
    return 0;
}