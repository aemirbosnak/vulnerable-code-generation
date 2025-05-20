//GEMINI-pro DATASET v1.0 Category: Educational ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

// Function to print the pyramid of numbers
void printPyramid(int n) {
    // Iterate over each row
    for (int i = 0; i < n; i++) {
        // Iterate over each column
        for (int j = 0; j <= i; j++) {
            // Print the number
            printf("%d ", i + 1);
        }
        // Move to the next line
        printf("\n");
    }
}

// Function to print the inverted pyramid of numbers
void printInvertedPyramid(int n) {
    // Iterate over each row
    for (int i = n - 1; i >= 0; i--) {
        // Iterate over each column
        for (int j = 0; j <= i; j++) {
            // Print the number
            printf("%d ", i + 1);
        }
        // Move to the next line
        printf("\n");
    }
}

// Function to print the hollow pyramid of numbers
void printHollowPyramid(int n) {
    // Iterate over each row
    for (int i = 0; i < n; i++) {
        // Iterate over each column
        for (int j = 0; j <= i; j++) {
            // If it is the first or last column
            if (j == 0 || j == i) {
                // Print the number
                printf("%d ", i + 1);
            } else {
                // Print a space
                printf("  ");
            }
        }
        // Move to the next line
        printf("\n");
    }
}

// Function to print the Floyd's triangle
void printFloydsTriangle(int n) {
    // Iterate over each row
    int number = 1;
    for (int i = 0; i < n; i++) {
        // Iterate over each column
        for (int j = 0; j <= i; j++) {
            // Print the number
            printf("%d ", number);
            number++;
        }
        // Move to the next line
        printf("\n");
    }
}

// Function to print the Pascal's triangle
void printPascalsTriangle(int n) {
    // Iterate over each row
    for (int i = 0; i < n; i++) {
        // Iterate over each column
        for (int j = 0; j <= i; j++) {
            // Calculate the value of the current cell
            int value = 1;
            for (int k = 0; k < j; k++) {
                value = value * (i - k) / (k + 1);
            }
            // Print the value
            printf("%d ", value);
        }
        // Move to the next line
        printf("\n");
    }
}

// Function to print the Sierpinski triangle
void printSierpinskiTriangle(int n) {
    // Create a 2D array to store the triangle
    char triangle[n][MAX_SIZE];
    // Initialize the triangle with spaces
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            triangle[i][j] = ' ';
        }
    }
    // Draw the triangle
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            // If it is the first or last column
            if (j == 0 || j == i) {
                // Draw a filled triangle
                triangle[i][j] = '*';
            } else {
                // Draw a hollow triangle
                triangle[i][j] = ' ';
            }
        }
    }
    // Print the triangle
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            printf("%c", triangle[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("\nPyramid of numbers:\n");
    printPyramid(n);
    printf("\nInverted pyramid of numbers:\n");
    printInvertedPyramid(n);
    printf("\nHollow pyramid of numbers:\n");
    printHollowPyramid(n);
    printf("\nFloyd's triangle:\n");
    printFloydsTriangle(n);
    printf("\nPascal's triangle:\n");
    printPascalsTriangle(n);
    printf("\nSierpinski triangle:\n");
    printSierpinskiTriangle(n);
    return 0;
}