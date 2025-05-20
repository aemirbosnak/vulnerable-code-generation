//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

// Function to print Fibonacci sequence
void printFibonacci(int n) {
    int first = 0, second = 1, next;

    printf("\nIn the garden of numbers, the Fibonacci sequence blooms:\n");
    printf("F(0) = %d\nF(1) = %d\n", first, second);

    for(int i = 2; i < n; i++) {
        next = first + second;
        printf("F(%d) = %d\n", i, next);
        first = second;
        second = next;
    }
    printf("\nLet this sequence of passion and unity guide our hearts...\n");
}

// Function to draw the Fibonacci spiral using asterisks
void drawFibonacciSpiral(int n) {
    int a = 0, b = 1, next, width = 0;
    printf("\nVisualizing the spiral of love and connection:\n");

    for (int i = 0; i < n; i++) {
        next = a + b;
        if (i == 0) {
            width = a + 1;  // initial width
        } else {
            width = next + 1;  // subsequent widths
        }
        printf("%*s\n", width, " ");  // set space for spiral
        a = b;
        b = next;
    }

    printf("\nIn every turn, feel the essence of Fibonacci...\n");
}

// Main driver function to invoke our romantic visualizer
int main() {
    int terms;

    printf("Enter the number of terms for the Fibonacci sequence (we embark on this voyage): ");
    scanf("%d", &terms);

    if (terms < 0) {
        printf("Love cannot be measured in negative terms!\n");
        return 1;
    } else if (terms == 0) {
        printf("Even the silence holds a Fibonacci essence with F(0) = 0.\n");
        return 0;
    } else if (terms == 1) {
        printf("In solitude, we find F(0) = 0 and F(1) = 1 to warm our hearts.\n");
        return 0;
    }

    // Print the Fibonacci sequence
    printFibonacci(terms);
    
    // Draw the Fibonacci Spiral
    drawFibonacciSpiral(terms);

    printf("May our journey through numbers lead us to infinite beauty and romance...\n");
    return 0;
}