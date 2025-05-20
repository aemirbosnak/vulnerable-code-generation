//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: visionary
#include <stdio.h>

// Function to illustrate the beauty of recursion
void printRecursivePattern(int n, int level) {
    // Base case
    if (level > n) {
        return;
    }
    
    // Print leading spaces for indentation
    for(int i = 0; i < n - level; i++) {
        printf("  ");
    }

    // Print stars based on the current level
    for(int j = 0; j < (2 * level - 1); j++) {
        printf("* ");
    }
    
    // Move to the next line after completing the current level
    printf("\n");

    // Recursive call to the next level
    printRecursivePattern(n, level + 1);
}

// Function to create a mystical mirror effect
void printMirrorPattern(int n, int level) {
    // Base case
    if (level < 1) {
        return;
    }
    
    // Print leading spaces for indentation
    for(int i = 0; i < n - level; i++) {
        printf("  ");
    }

    // Print stars based on the current level
    for(int j = 0; j < (2 * level - 1); j++) {
        printf("* ");
    }
    
    // Move to the next line after completing the current level
    printf("\n");

    // Recursive call to create the mirror effect
    printMirrorPattern(n, level - 1);
}

// The main function of the program
int main() {
    int height;

    // Asking user for the height of the pyramid
    printf("Enter the height of the pyramid: ");
    scanf("%d", &height);

    printf("\nCreating a magical pyramid:\n");
    // Print the upper part of the pyramid using recursion
    printRecursivePattern(height, 1);

    // Print the lower part of the pyramid (mirror effect) using recursion
    printf("\nCreating a mystical mirror of the pyramid:\n");
    printMirrorPattern(height, height);
    
    // Finishing note
    printf("\nThank you for joining this journey of recursion and patterns!\n");
    return 0;
}