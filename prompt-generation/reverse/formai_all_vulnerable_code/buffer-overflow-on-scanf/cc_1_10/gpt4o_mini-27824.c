//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: inquisitive
#include <stdio.h>

void printLine(int totalLines, int currentLine) {
    // Calculate the number of spaces
    for (int i = 0; i < totalLines - currentLine; i++) {
        printf(" ");
    }
    
    // Print stars and spaces
    for (int j = 0; j < (2 * currentLine - 1); j++) {
        if (j % 2 == 0) {
            printf("*");
        } else {
            printf(" ");
        }
    }
    
    // Move to the next line
    printf("\n");
}

int main() {
    int height;

    // Prompt user for input
    printf("Welcome to the Pyramid Pattern Generator!\n");
    printf("Please enter the height of the pyramid (between 1 and 20): ");
    
    // Get user input
    while (1) {
        scanf("%d", &height);
        
        // Validate the input
        if (height >= 1 && height <= 20) {
            break;
        } else {
            printf("Invalid input! Please enter a height between 1 and 20: ");
        }
    }

    // Print the pyramid pattern
    printf("\nHere is your pyramid pattern of height %d:\n", height);
    for (int i = 1; i <= height; i++) {
        printLine(height, i);
    }
    
    // Print a base line for visual closure
    printf("The pyramid above stands tall at a height of %d!\n", height);
    
    // Implement additional creativity: add a lullaby pattern at the bottom
    printf("\nAnd now, for a lullaby pattern:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < i; j++) {
            printf(" ");
        }
        printf("~ ~ ~ ~\n");
    }

    printf("\nThank you for using the Pyramid Pattern Generator!\n");
    return 0;
}