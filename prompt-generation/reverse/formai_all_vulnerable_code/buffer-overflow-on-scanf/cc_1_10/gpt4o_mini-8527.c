//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: creative
#include <stdio.h>

// Function to print the pattern recursively
void printPattern(int n, int line) {
    // Base case
    if (line > n) {
        return;
    }

    // Print leading spaces
    for (int i = 0; i < n - line; i++) {
        printf(" ");
    }
    
    // Print stars for the current line
    for (int j = 1; j <= (2 * line - 1); j++) {
        printf("*");
    }

    // Move to the next line
    printf("\n");

    // Recursive call for the next line
    printPattern(n, line + 1);
}

// Function to display the tree
void displayTree(int height) {
    if (height < 1) {
        printf("Height must be at least 1.\n");
        return;
    }

    printf("\nHere is your beautiful Christmas Tree:\n\n");
    printPattern(height, 1);
    
    printf("   |||   \n"); // Tree trunk
    printf("   |||   \n"); // Tree trunk
    printf("   |||   \n"); // Tree trunk
}

int main() {
    int height;

    printf("Welcome to the Christmas Tree Generator!\n");
    
    // Get height from user
    printf("Please enter the height of the tree (positive integer): ");
    
    // Input validation
    while (1) {
        scanf("%d", &height);
        if (height > 0) {
            break;
        }
        printf("Invalid input. Please enter a positive integer: ");
    }

    // Display the tree
    displayTree(height);

    printf("\nWishing you a Merry Christmas and a Happy New Year!\n");
    return 0;
}