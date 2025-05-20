//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: future-proof
#include <stdio.h>

void printDiamond(int n) {
    int spaces, stars;

    // Print the upper part of the diamond
    for (int i = 0; i < n; i++) {
        spaces = n - i - 1;
        stars = 2 * i + 1;

        // Print spaces
        for (int j = 0; j < spaces; j++) {
            printf(" ");
        }

        // Print stars
        for (int j = 0; j < stars; j++) {
            printf("*");
        }

        // Move to the next line
        printf("\n");
    }

    // Print the lower part of the diamond
    for (int i = n - 2; i >= 0; i--) {
        spaces = n - i - 1;
        stars = 2 * i + 1;

        // Print spaces
        for (int j = 0; j < spaces; j++) {
            printf(" ");
        }

        // Print stars
        for (int j = 0; j < stars; j++) {
            printf("*");
        }

        // Move to the next line
        printf("\n");
    }
}

void printInvertedTriangle(int n) {
    for (int i = n; i > 0; i--) {
        // Printing stars
        for (int j = 0; j < i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printRightAngledTriangle(int n) {
    for (int i = 1; i <= n; i++) {
        // Printing stars
        for (int j = 0; j < i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printHollowSquare(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Print edge of the square
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void printPyramid(int n) {
    for (int i = 1; i <= n; i++) {
        // Print spaces
        for (int j = i; j < n; j++) {
            printf(" ");
        }

        // Print stars
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int choice, size;

    // Interactive menu for user to select pattern
    do {
        printf("\nPattern Printing Menu:\n");
        printf("1. Print Diamond Pattern\n");
        printf("2. Print Inverted Triangle Pattern\n");
        printf("3. Print Right-Angled Triangle Pattern\n");
        printf("4. Print Hollow Square Pattern\n");
        printf("5. Print Pyramid Pattern\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 5) {
            printf("Enter the size: ");
            scanf("%d", &size);
        }

        switch (choice) {
            case 1:
                printf("Diamond Pattern of size %d:\n", size);
                printDiamond(size);
                break;
            case 2:
                printf("Inverted Triangle Pattern of size %d:\n", size);
                printInvertedTriangle(size);
                break;
            case 3:
                printf("Right-Angled Triangle Pattern of size %d:\n", size);
                printRightAngledTriangle(size);
                break;
            case 4:
                printf("Hollow Square Pattern of size %d:\n", size);
                printHollowSquare(size);
                break;
            case 5:
                printf("Pyramid Pattern of size %d:\n", size);
                printPyramid(size);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}