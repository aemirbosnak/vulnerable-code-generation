//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: satisfied
#include <stdio.h>

// Function to print spaces
void printSpaces(int n) {
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
}

// Function to print a diamond pattern
void printDiamond(int height) {
    int n = height; // Store height for easier access

    // Print upper part of diamond
    for (int i = 1; i <= n; i++) {
        printSpaces(n - i);
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }

    // Print lower part of diamond
    for (int i = n - 1; i >= 1; i--) {
        printSpaces(n - i);
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Function to print square pattern
void printSquare(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

// Function to print triangle pattern
void printTriangle(int height) {
    for (int i = 1; i <= height; i++) {
        printSpaces(height - i);
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

// Function to print inverted triangle
void printInvertedTriangle(int height) {
    for (int i = height; i >= 1; i--) {
        printSpaces(height - i);
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

// Function to display menu options
void displayMenu() {
    printf("\n*** Pattern Printing Menu ***\n");
    printf("1. Print Diamond Pattern\n");
    printf("2. Print Square Pattern\n");
    printf("3. Print Triangle Pattern\n");
    printf("4. Print Inverted Triangle Pattern\n");
    printf("5. Exit\n");
    printf("Select an option (1-5): ");
}

// Main function
int main() {
    int choice, height, size;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the height of the diamond: ");
                scanf("%d", &height);
                printDiamond(height);
                break;

            case 2:
                printf("Enter the size of the square: ");
                scanf("%d", &size);
                printSquare(size);
                break;

            case 3:
                printf("Enter the height of the triangle: ");
                scanf("%d", &height);
                printTriangle(height);
                break;

            case 4:
                printf("Enter the height of the inverted triangle: ");
                scanf("%d", &height);
                printInvertedTriangle(height);
                break;

            case 5:
                printf("Exiting the program...\n");
                return 0;

            default:
                printf("Invalid choice, please select a valid option.\n");
                break;
        }
    }

    return 0;
}