//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: immersive
#include <stdio.h>

void printSpaces(int spaces) {
    for (int i = 0; i < spaces; i++) {
        printf(" ");
    }
}

void printPyramid(int height) {
    printf("\nBuilding a Pyramid of Height %d:\n\n", height);
    for (int i = 0; i < height; i++) {
        printSpaces(height - i - 1); // Print leading spaces
        for (int j = 0; j < 2 * i + 1; j++) { // Print stars
            printf("*");
        }
        printf("\n");
    }
}

void printInvertedPyramid(int height) {
    printf("\nBuilding an Inverted Pyramid of Height %d:\n\n", height);
    for (int i = height - 1; i >= 0; i--) {
        printSpaces(height - i - 1); // Print leading spaces
        for (int j = 0; j < 2 * i + 1; j++) { // Print stars
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int height;

    printf("Welcome to the Pyramid Pattern Generator!\n");
    printf("Please enter the height of the pyramid (between 1 and 20): ");
    scanf("%d", &height);

    // Validate user input
    if (height < 1 || height > 20) {
        printf("Invalid height! Please restart the program and enter a number between 1 and 20.\n");
        return 1;
    }

    // Generate the pyramid
    printPyramid(height);
    
    // Generate the inverted pyramid
    printInvertedPyramid(height);
    
    printf("\nThank you for using the Pyramid Pattern Generator! Goodbye!\n");
    return 0;
}