//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: dynamic
#include <stdio.h>

void printTriangle(int rows) {
    // Loop through each row
    for (int i = 1; i <= rows; i++) {
        // Print leading spaces
        for (int j = i; j < rows; j++) {
            printf(" ");
        }
        // Print characters based on the row number
        for (int k = 1; k <= (2 * i - 1); k++) {
            if (i % 2 == 0) {
                // For even rows, print '@'
                printf("@");
            } else {
                // For odd rows, print '*'
                printf("*");
            }
        }
        // Move to the next line
        printf("\n");
    }
}

void printInvertTriangle(int rows) {
    // Loop through each row for inverted triangle
    for (int i = rows; i >= 1; i--) {
        // Print leading spaces
        for (int j = rows; j > i; j--) {
            printf(" ");
        }
        // Print characters in inverted order
        for (int k = 1; k <= (2 * i - 1); k++) {
            if (i % 2 == 0) {
                // For even rows, print '#'
                printf("#");
            } else {
                // For odd rows, print '&'
                printf("&");
            }
        }
        // Move to the next line
        printf("\n");
    }
}

void printDiamond(int rows) {
    // Print upper part of the diamond
    for (int i = 1; i <= rows; i++) {
        // Print leading spaces
        for (int j = i; j < rows; j++) {
            printf(" ");
        }
        // Print diamond pattern
        for (int k = 1; k <= (2 * i - 1); k++) {
            if (i % 2 == 0) {
                printf("%c", 64 + i); // ASCII value for uppercase letters
            } else {
                printf("%c", 64 + (i + 2)); // Skip letters for even cases
            }
        }
        printf("\n");
    }
    // Print lower part of the diamond
    for (int i = rows - 1; i >= 1; i--) {
        for (int j = rows; j > i; j--) {
            printf(" ");
        }
        for (int k = 1; k <= (2 * i - 1); k++) {
            if (i % 2 == 0) {
                printf("%c", 64 + i);
            } else {
                printf("%c", 64 + (i + 2));
            }
        }
        printf("\n");
    }
}

int main() {
    int choice, rows;

    // Menu for user choice
    while (1) {
        printf("Choose a pattern to print:\n");
        printf("1. Right-Angled Triangle\n");
        printf("2. Inverted Triangle\n");
        printf("3. Diamond Pattern\n");
        printf("4. Quit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Exiting the program.\n");
            break; // Exit from the loop if user chooses to quit
        }

        printf("Enter the number of rows: ");
        scanf("%d", &rows);

        switch (choice) {
            case 1:
                printf("\nRight-Angled Triangle:\n");
                printTriangle(rows);
                break;
            case 2:
                printf("\nInverted Triangle:\n");
                printInvertTriangle(rows);
                break;
            case 3:
                printf("\nDiamond Pattern:\n");
                printDiamond(rows);
                break;
            default:
                printf("Invalid choice, please select again.\n");
        }
        printf("\n");
    }

    return 0;
}