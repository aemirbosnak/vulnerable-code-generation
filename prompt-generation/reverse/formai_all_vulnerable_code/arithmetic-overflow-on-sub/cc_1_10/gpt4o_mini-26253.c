//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: multivariable
#include <stdio.h>

void printPyramid(int rows, int cols) {
    int i, j;

    // Loop through each row
    for(i = 0; i < rows; i++) {
        // Print leading spaces
        for(j = 0; j < rows - i - 1; j++) {
            printf("  "); // Two spaces for better visibility
        }
        
        // Print the pyramid pattern
        for(j = 0; j <= i; j++) {
            printf("* "); // Printing star
        }

        printf("\n"); // New line for the next row
    }
}

void printReversePyramid(int rows, int cols) {
    int i, j;

    // Loop through each row
    for(i = 0; i < rows; i++) {
        // Print leading spaces
        for(j = 0; j < i; j++) {
            printf("  "); // Two spaces for better visibility
        }
        
        // Print the pyramid pattern
        for(j = 0; j < rows - i; j++) {
            printf("* "); // Printing star
        }

        printf("\n"); // New line for the next row
    }
}

void printHollowSquare(int size) {
    int i, j;

    // Loop through each row
    for(i = 0; i < size; i++) {
        // Loop through each column
        for(j = 0; j < size; j++) {
            // Print boundary of square
            if(i == 0 || i == size - 1 || j == 0 || j == size - 1) {
                printf("* ");
            } else {
                printf("  "); // Print space in between for hollow effect
            }
        }
        printf("\n"); // New line for the next row
    }
}

void printRightAngledTriangle(int rows) {
    int i, j;

    // Loop through each row
    for(i = 0; i < rows; i++) {
        // Print stars corresponding to the row number
        for(j = 0; j <= i; j++) {
            printf("* ");
        }
        printf("\n"); // New line for next row
    }
}

void printDiamond(int rows) {
    int i, j, space;

    // Upper part of diamond
    for(i = 0; i < rows; i++) {
        // Print leading spaces
        for(space = 0; space < rows - i - 1; space++) {
            printf("  ");
        }
        
        // Print stars
        for(j = 0; j <= i; j++) {
            printf("* "); // Print star
        }

        printf("\n"); // New line for next row
    }

    // Lower part of diamond
    for(i = rows - 2; i >= 0; i--) {
        // Print leading spaces
        for(space = 0; space < rows - i - 1; space++) {
            printf("  ");
        }
        
        // Print stars
        for(j = 0; j <= i; j++) {
            printf("* "); // Print star
        }

        printf("\n"); // New line for next row
    }
}

int main() {
    int choice;
    int size;
    
    printf("Pattern Printing Program\n");
    printf("-------------------------\n");
    printf("Choose a pattern to print:\n");
    printf("1. Pyramid\n");
    printf("2. Reverse Pyramid\n");
    printf("3. Hollow Square\n");
    printf("4. Right Angled Triangle\n");
    printf("5. Diamond\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);
    
    // Ask for size
    if (choice >= 1 && choice <= 5) {
        printf("Enter the size: ");
        scanf("%d", &size);
    }

    // Print the chosen pattern based on user input
    switch(choice) {
        case 1:
            printPyramid(size, size);
            break;
        case 2:
            printReversePyramid(size, size);
            break;
        case 3:
            printHollowSquare(size);
            break;
        case 4:
            printRightAngledTriangle(size);
            break;
        case 5:
            printDiamond(size);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}