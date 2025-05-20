//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: scalable
#include <stdio.h>

// Function to print a diamond pattern of a given size
void printDiamond(int size) {
    int i, j, space;

    // Upper part of the diamond
    for (i = 1; i <= size; i++) {
        // Printing leading spaces
        for (space = 1; space <= size - i; space++) {
            printf(" ");
        }
        // Printing stars
        for (j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n"); // Move to the next line
    }

    // Lower part of the diamond
    for (i = size - 1; i >= 1; i--) {
        // Printing leading spaces
        for (space = 1; space <= size - i; space++) {
            printf(" ");
        }
        // Printing stars
        for (j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n"); // Move to the next line
    }
}

// Function to get user input for the size of the diamond
int getInput() {
    int size;

    printf("Enter the size of the diamond (1-20): ");
    // Validate input
    while (1) {
        scanf("%d", &size);
        if (size >= 1 && size <= 20) {
            break;
        } else {
            printf("Invalid input! Please enter a number between 1 and 20: ");
        }
    }

    return size;
}

// Main function to execute the program
int main() {
    int size;

    // Get size from user
    size = getInput();

    // Print the diamond pattern
    printDiamond(size);
    
    return 0; // Successful execution
}