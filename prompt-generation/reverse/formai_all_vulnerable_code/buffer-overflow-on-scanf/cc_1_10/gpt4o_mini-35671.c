//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: calm
#include <stdio.h>

void printPyramid(int height) {
    for (int i = 1; i <= height; i++) {
        // Print leading spaces
        for (int j = height; j > i; j--) {
            printf(" ");
        }
        // Print stars
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printNumbers(int height) {
    // Print the numbers below the pyramid
    for (int i = 1; i <= height; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

void printInvertedTriangle(int height) {
    for (int i = height; i >= 1; i--) {
        // Print leading spaces
        for (int j = height; j > i; j--) {
            printf(" ");
        }
        // Print stars
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printDiamond(int height) {
    printPyramid(height);
    printInvertedTriangle(height - 1); // No need to print the bottom line
}

int main() {
    int height;

    // Prompting user for height of the pyramid
    printf("Enter the height of the pyramid (positive integer): ");
    scanf("%d", &height);

    // Check if the input is valid
    if(height <= 0) {
        printf("Please enter a valid positive integer.\n");
        return 1; // Exit the program with a non-zero value
    }

    // Print the diamond shape consisting of a pyramid and its inverted counterpart
    printf("\nHere's the diamond pattern:\n");
    printDiamond(height);
    
    // Print the numbers below the pyramid
    printf("Here are the numbers below the pyramid:\n");
    printNumbers(height);

    return 0;
}