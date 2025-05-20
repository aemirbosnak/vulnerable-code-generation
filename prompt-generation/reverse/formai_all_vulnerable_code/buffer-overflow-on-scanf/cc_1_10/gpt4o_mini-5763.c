//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Function to print a character-based pyramid
void printCharPyramid(int height, char ch) {
    int spaces, i, j;
    for (i = 0; i < height; i++) {
        // Calculate spaces for the current row
        spaces = height - i - 1;
        // Print leading spaces
        for (j = 0; j < spaces; j++) {
            printf(" ");
        }
        // Print characters
        for (j = 0; j <= i; j++) {
            printf("%c ", ch);
        }
        printf("\n"); // Move to the next line after each row
    }
}

// Function that serves as the main logic for the program
void runPyramidPattern() {
    int height;
    char ch;
    
    // Prompt user for height of the pyramid
    printf("Enter height of the pyramid (1-20): ");
    if (scanf("%d", &height) != 1 || height < 1 || height > 20) {
        fprintf(stderr, "Error: Please enter a valid height between 1 and 20.\n");
        return;
    }
    
    // Prompt user for the character to use
    printf("Enter a character to build the pyramid: ");
    scanf(" %c", &ch);
    
    // Invoke the function to print the pyramid
    printCharPyramid(height, ch);
}

int main() {
    // Introduce the program to the user
    printf("Welcome to the Character Pyramid Pattern Generator!\n");
    printf("This program creates a pyramid using a character of your choice.\n");
    printf("-------------------------------------------------------\n");
    
    runPyramidPattern(); // Executes the main logic
    
    printf("\nThank you for using the Pyramid Pattern Generator!\n");
    return 0; // Exit the program
}