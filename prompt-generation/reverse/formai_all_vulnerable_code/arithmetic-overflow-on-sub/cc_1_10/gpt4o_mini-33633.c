//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: active
#include <stdio.h>

void printSpaces(int n) {
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
}

void printAsterisks(int n) {
    for (int i = 0; i < n; i++) {
        printf("* ");
    }
}

void printPyramid(int rows) {
    // The outer loop for each row
    for (int i = 1; i <= rows; i++) {
        // Printing spaces for pyramid shape
        printSpaces(rows - i);
        // Printing asterisks for the current row
        printAsterisks(i);
        // Move to the next line after each row
        printf("\n");
    }
}

void printInversePyramid(int rows) {
    // The outer loop for each row
    for (int i = rows; i >= 1; i--) {
        // Printing spaces for inverse pyramid shape
        printSpaces(rows - i);
        // Printing asterisks for the current row
        printAsterisks(i);
        // Move to the next line after each row
        printf("\n");
    }
}

void printDiamond(int rows) {
    // Print the upper part of the diamond
    printPyramid(rows);
    // Print the lower part of the diamond (inverse pyramid)
    printInversePyramid(rows - 1);
}

void printHollowDiamond(int rows) {
    // Top part of the diamond
    for (int i = 1; i <= rows; i++) {
        printSpaces(rows - i);
        if (i == 1) {
            printf("*");
        } else {
            printf("*");
            printSpaces((i - 1) * 2 - 1);
            printf("*");
        }
        printf("\n");
    }

    // Bottom part of the diamond
    for (int i = rows - 1; i >= 1; i--) {
        printSpaces(rows - i);
        if (i == 1) {
            printf("*");
        } else {
            printf("*");
            printSpaces((i - 1) * 2 - 1);
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int choice, rows;

    printf("Welcome to the Pattern Printing Program!\n");
    printf("Choose a pattern to print:\n");
    printf("1. Pyramid\n");
    printf("2. Inverse Pyramid\n");
    printf("3. Diamond\n");
    printf("4. Hollow Diamond\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 4) {
        printf("Invalid choice! Please run the program again.\n");
        return 1;
    }

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    switch (choice) {
        case 1:
            printf("Pyramid Pattern:\n");
            printPyramid(rows);
            break;
        case 2:
            printf("Inverse Pyramid Pattern:\n");
            printInversePyramid(rows);
            break;
        case 3:
            printf("Diamond Pattern:\n");
            printDiamond(rows);
            break;
        case 4:
            printf("Hollow Diamond Pattern:\n");
            printHollowDiamond(rows);
            break;
        default:
            printf("This should not happen!\n");
            break;
    }

    printf("Thank you for using the Pattern Printing Program!\n");
    return 0;
}