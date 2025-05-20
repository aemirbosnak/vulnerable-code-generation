//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: scientific
#include <stdio.h>

// Function to print a pyramid pattern of specified height
void printPyramid(int height) {
    int i, j, spaces;

    // Loop through each level of the pyramid
    for(i = 1; i <= height; i++) {
        // Print spaces before the asterisks
        for(spaces = height; spaces > i; spaces--) {
            printf(" ");
        }
        
        // Print the asterisks in the current level
        for(j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        
        // Move to the next line after each level
        printf("\n");
    }
}

// Function to print a diamond shape pattern of specified height
void printDiamond(int height) {
    int i, j, spaces;

    // Print the upper part of the diamond
    for(i = 1; i <= height; i++) {
        // Print spaces before the asterisks
        for(spaces = height; spaces > i; spaces--) {
            printf(" ");
        }
        
        // Print the asterisks in the current level
        for(j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        
        // Move to the next line after each level
        printf("\n");
    }
    
    // Print the lower part of the diamond
    for(i = height - 1; i >= 1; i--) {
        // Print spaces before the asterisks
        for(spaces = height; spaces > i; spaces--) {
            printf(" ");
        }
        
        // Print the asterisks in the current level
        for(j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        
        // Move to the next line after each level
        printf("\n");
    }
}

// Function to print a hollow square pattern of specified height
void printHollowSquare(int height) {
    int i, j;
    
    for(i = 1; i <= height; i++) {
        for(j = 1; j <= height; j++) {
            // Print '*', except for the inner part of the square
            if(i == 1 || i == height || j == 1 || j == height) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Function to print a reversed pyramid pattern of specified height
void printReversedPyramid(int height) {
    int i, j, spaces;

    // Loop through each level of the pyramid in reverse
    for(i = height; i >= 1; i--) {
        // Print spaces before the asterisks
        for(spaces = height; spaces > i; spaces--) {
            printf(" ");
        }
        
        // Print the asterisks in the current level
        for(j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        
        // Move to the next line after each level
        printf("\n");
    }
}

int main() {
    int height;

    // Prompt user for height selection
    printf("Enter the height of the pyramid (1-10): ");
    scanf("%d", &height);

    // Input validation for height
    if(height < 1 || height > 10) {
        printf("Height must be between 1 and 10. Exiting program.\n");
        return 1;
    }

    // Print the desired patterns based on user input
    printf("\nPyramid Pattern:\n");
    printPyramid(height);
    
    printf("\nDiamond Pattern:\n");
    printDiamond(height);
    
    printf("\nHollow Square Pattern:\n");
    printHollowSquare(height);
    
    printf("\nReversed Pyramid Pattern:\n");
    printReversedPyramid(height);

    return 0;
}