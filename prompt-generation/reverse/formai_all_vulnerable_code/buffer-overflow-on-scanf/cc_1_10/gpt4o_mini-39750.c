//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: complete
#include <stdio.h>

// Function to print the pyramid pattern
void printPyramid(int rows) {
    printf("Pyramid Pattern:\n");
    for (int i = 1; i <= rows; i++) {
        for (int j = i; j < rows; j++)
            printf(" ");
        for (int k = 1; k <= (2 * i - 1); k++)
            printf("*");
        printf("\n");
    }
}

// Function to print the inverted pyramid pattern
void printInvertedPyramid(int rows) {
    printf("Inverted Pyramid Pattern:\n");
    for (int i = rows; i >= 1; i--) {
        for (int j = rows; j > i; j--)
            printf(" ");
        for (int k = 1; k <= (2 * i - 1); k++)
            printf("*");
        printf("\n");
    }
}

// Function to print the diamond pattern
void printDiamond(int rows) {
    printf("Diamond Pattern:\n");
    // Print the upper part of the diamond
    for (int i = 1; i <= rows; i++) {
        for (int j = i; j < rows; j++)
            printf(" ");
        for (int k = 1; k <= (2 * i - 1); k++)
            printf("*");
        printf("\n");
    }
    // Print the lower part of the diamond
    for (int i = rows - 1; i >= 1; i--) {
        for (int j = rows; j > i; j--)
            printf(" ");
        for (int k = 1; k <= (2 * i - 1); k++)
            printf("*");
        printf("\n");
    }
}

// Function to print the menu
void printMenu() {
    printf("Choose a pattern to print:\n");
    printf("1. Pyramid Pattern\n");
    printf("2. Inverted Pyramid Pattern\n");
    printf("3. Diamond Pattern\n");
    printf("4. Exit\n");
}

int main() {
    int choice, rows;

    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        printf("Enter the number of rows: ");
        scanf("%d", &rows);

        switch (choice) {
            case 1:
                printPyramid(rows);
                break;
            case 2:
                printInvertedPyramid(rows);
                break;
            case 3:
                printDiamond(rows);
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
        printf("\n");
    }

    return 0;
}