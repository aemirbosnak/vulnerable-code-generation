//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: systematic
#include <stdio.h>

void printSquare(int n) {
    printf("\nSquare Pattern:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printRightTriangle(int n) {
    printf("\nRight Triangle Pattern:\n");
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printPyramid(int n) {
    printf("\nPyramid Pattern:\n");
    for(int i = 1; i <= n; i++) {
        for(int j = i; j < n; j++) {
            printf(" "); // Print leading spaces
        }
        for(int j = 1; j <= (2 * i - 1); j++) {
            printf("*"); // Print stars
        }
        printf("\n");
    }
}

void printInvertedPyramid(int n) {
    printf("\nInverted Pyramid Pattern:\n");
    for(int i = n; i >= 1; i--) {
        for(int j = n; j - i; j++) {
            printf(" "); // Print leading spaces
        }
        for(int j = 1; j <= (2 * i - 1); j++) {
            printf("*"); // Print stars
        }
        printf("\n");
    }
}

void printDiamond(int n) {
    printf("\nDiamond Pattern:\n");
    // Upper part of diamond
    for(int i = 1; i <= n; i++) {
        for(int j = i; j < n; j++) {
            printf(" "); // Print leading spaces
        }
        for(int j = 1; j <= (2 * i - 1); j++) {
            printf("*"); // Print stars
        }
        printf("\n");
    }
    
    // Lower part of diamond
    for(int i = n - 1; i >= 1; i--) {
        for(int j = n; j > i; j--) {
            printf(" "); // Print leading spaces
        }
        for(int j = 1; j <= (2 * i - 1); j++) {
            printf("*"); // Print stars
        }
        printf("\n");
    }
}

void printHollowSquare(int n) {
    printf("\nHollow Square Pattern:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 || i == n-1 || j == 0 || j == n-1) {
                printf("* "); // Print border stars
            } else {
                printf("  "); // Print spaces in hollow part
            }
        }
        printf("\n");
    }
}

void printHourglass(int n) {
    printf("\nHourglass Pattern:\n");
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= (n - i); j++) {
            printf(" "); // Print leading spaces
        }
        for(int j = 1; j <= (2 * i - 1); j++) {
            printf("*"); // Print stars
        }
        printf("\n");
    }
}

int main() {
    int choice, n;
    
    printf("Pattern Printing Program\n");
    printf("Select a pattern to print:\n");
    printf("1. Square Pattern\n");
    printf("2. Right Triangle Pattern\n");
    printf("3. Pyramid Pattern\n");
    printf("4. Inverted Pyramid Pattern\n");
    printf("5. Diamond Pattern\n");
    printf("6. Hollow Square Pattern\n");
    printf("7. Hourglass Pattern\n");
    printf("Enter your choice (1-7): ");
    scanf("%d", &choice);

    printf("Enter the size of the pattern: ");
    scanf("%d", &n);

    switch (choice) {
        case 1:
            printSquare(n);
            break;
        case 2:
            printRightTriangle(n);
            break;
        case 3:
            printPyramid(n);
            break;
        case 4:
            printInvertedPyramid(n);
            break;
        case 5:
            printDiamond(n);
            break;
        case 6:
            printHollowSquare(n);
            break;
        case 7:
            printHourglass(n);
            break;
        default:
            printf("Invalid choice! Please select a valid option.\n");
            break;
    }

    return 0;
}