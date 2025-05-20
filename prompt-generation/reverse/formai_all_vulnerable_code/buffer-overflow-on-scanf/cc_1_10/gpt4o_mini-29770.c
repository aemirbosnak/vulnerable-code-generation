//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: energetic
#include <stdio.h>

void printSpaces(int count) {
    for (int i = 0; i < count; i++) {
        printf(" ");
    }
}

void printStars(int count) {
    for (int i = 0; i < count; i++) {
        printf("* ");
    }
}

void printDiamond(int n) {
    // Print the top half of the diamond
    for (int i = 1; i <= n; i++) {
        printSpaces(n - i);
        printStars(i);
        printf("\n");
    }

    // Print the bottom half of the diamond
    for (int i = n - 1; i >= 1; i--) {
        printSpaces(n - i);
        printStars(i);
        printf("\n");
    }
}

void printTree(int levels) {
    // Print the tree levels
    for (int i = 1; i <= levels; i++) {
        printSpaces(levels - i);
        printStars(2 * i - 1);
        printf("\n");
    }

    // Print the trunk of the tree
    printSpaces(levels - 1);
    printf("|\n");
}

void printPyramid(int rows) {
    for (int i = 1; i <= rows; i++) {
        printSpaces(rows - i);
        printStars(2 * i - 1);
        printf("\n");
    }
}

void printTriangle(int height) {
    for (int i = 1; i <= height; i++) {
        printStars(i);
        printf("\n");
    }
}

int main() {
    int choice, n;

    printf("Welcome to the Energetic Pattern Printing Program!\n");
    printf("Get ready to unleash some fun patterns! 🎉\n");
    
    do {
        printf("\nChoose a pattern to print:\n");
        printf("1. Diamond\n");
        printf("2. Christmas Tree\n");
        printf("3. Pyramid\n");
        printf("4. Right-Angle Triangle\n");
        printf("0. Exit\n");
        printf("Enter your choice (0-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the number of rows for the diamond: ");
                scanf("%d", &n);
                printf("\nHere comes your diamond! 💎\n");
                printDiamond(n);
                break;

            case 2:
                printf("Enter the number of levels for the Christmas Tree: ");
                scanf("%d", &n);
                printf("\nHere comes your beautiful Christmas Tree! 🎄\n");
                printTree(n);
                break;

            case 3:
                printf("Enter the number of rows for the pyramid: ");
                scanf("%d", &n);
                printf("\nPrepare to see a marvelous pyramid! ⛰️\n");
                printPyramid(n);
                break;

            case 4:
                printf("Enter the height for the right-angle triangle: ");
                scanf("%d", &n);
                printf("\nHere's your fantastic right-angle triangle! 🔺\n");
                printTriangle(n);
                break;

            case 0:
                printf("Thank you for printing patterns with us! Goodbye! 👋\n");
                break;

            default:
                printf("Oops! That's not a valid choice. Please try again! 🚫\n");
                break;
        }

    } while (choice != 0);

    return 0;
}