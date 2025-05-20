//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: scalable
#include <stdio.h>

// Function to print the number pyramid
void printNumberPyramid(int rows) {
    int i, j, num;

    for (i = 1; i <= rows; i++) {
        num = 1; // Reset number for each row
        // Print leading spaces
        for (j = i; j < rows; j++) {
            printf(" ");
        }
        // Print the first half of numbers
        for (j = 1; j <= i; j++) {
            printf("%d ", num);
            num++;
        }
        // Print the second half of numbers
        num -= 2; // Decrement to avoid repeating the middle number
        for (j = 1; j < i; j++) {
            printf("%d ", num);
            num--;
        }
        printf("\n"); // Newline after each row
    }
}

// Function to print the diamond pattern
void printDiamond(int rows) {
    int i, j;

    // Upper Triangle
    for (i = 1; i <= rows; i++) {
        for (j = i; j < rows; j++)
            printf(" ");
        for (j = 1; j <= (2 * i - 1); j++)
            printf("*");
        printf("\n");
    }
    // Lower Triangle
    for (i = rows - 1; i >= 1; i--) {
        for (j = rows; j > i; j--)
            printf(" ");
        for (j = 1; j <= (2 * i - 1); j++)
            printf("*");
        printf("\n");
    }
}

// Function to print the Character and Number pyramid
void printCharAndNumberPyramid(int rows) {
    int i, j, num;

    for (i = 1; i <= rows; i++) {
        num = 1; // Resetting number for each row
        // Print leading spaces
        for (j = i; j < rows; j++) {
            printf(" ");
        }
        // Print the alphabets
        for (j = 1; j <= i; j++) {
            printf("%c ", 'A' + j - 1);
        }
        // Print the numbers
        for (j = 1; j <= i; j++) {
            printf("%d ", num);
            num++;
        }
        printf("\n"); // New line after each row
    }
}

// Main Function
int main() {
    int choice, rows;

    printf("Pattern Printing Program\n");
    printf("-------------------------\n");
    printf("Select a pattern to print:\n");
    printf("1. Number Pyramid\n");
    printf("2. Diamond Pattern\n");
    printf("3. Character and Number Pyramid\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    switch (choice) {
        case 1:
            printf("\nNumber Pyramid:\n");
            printNumberPyramid(rows);
            break;
        case 2:
            printf("\nDiamond Pattern:\n");
            printDiamond(rows);
            break;
        case 3:
            printf("\nCharacter and Number Pyramid:\n");
            printCharAndNumberPyramid(rows);
            break;
        default:
            printf("Invalid choice! Please select between 1-3.\n");
            break;
    }

    return 0;
}