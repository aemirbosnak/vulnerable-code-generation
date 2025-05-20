//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: ultraprecise
#include <stdio.h>

// Function prototypes
void printDiamond(int n);
void printPyramid(int n);
void printReversePyramid(int n);
void printHollowSquare(int n);
void printSolidSquare(int n);
void printRightAngledTriangle(int n);
void printInvertedRightAngledTriangle(int n);
void printNumberPyramid(int n);
void printCharacterPyramid(int n);
void printHollowTriangle(int n);

// Main function to run the pattern examples
int main() {
    int choice, size;

    // Welcome message
    printf("Welcome to Pattern Printing Program!\n");
    printf("Select the pattern you want to see:\n");
    printf("1. Diamond\n");
    printf("2. Pyramid\n");
    printf("3. Reverse Pyramid\n");
    printf("4. Hollow Square\n");
    printf("5. Solid Square\n");
    printf("6. Right Angled Triangle\n");
    printf("7. Inverted Right Angled Triangle\n");
    printf("8. Number Pyramid\n");
    printf("9. Character Pyramid\n");
    printf("10. Hollow Triangle\n");
    printf("Enter your choice (1-10): ");
    scanf("%d", &choice);

    // Taking size input based on the pattern choice
    printf("Enter the size: ");
    scanf("%d", &size);

    switch (choice) {
        case 1:
            printDiamond(size);
            break;
        case 2:
            printPyramid(size);
            break;
        case 3:
            printReversePyramid(size);
            break;
        case 4:
            printHollowSquare(size);
            break;
        case 5:
            printSolidSquare(size);
            break;
        case 6:
            printRightAngledTriangle(size);
            break;
        case 7:
            printInvertedRightAngledTriangle(size);
            break;
        case 8:
            printNumberPyramid(size);
            break;
        case 9:
            printCharacterPyramid(size);
            break;
        case 10:
            printHollowTriangle(size);
            break;
        default:
            printf("Invalid choice! Please select a number between 1 and 10.\n");
    }

    return 0;
}

// Function to print a diamond pattern
void printDiamond(int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = i; j < n; j++)
            printf(" ");
        for (j = 1; j <= (2 * i - 1); j++)
            printf("*");
        printf("\n");
    }
    for (i = n - 1; i >= 1; i--) {
        for (j = n; j > i; j--)
            printf(" ");
        for (j = 1; j <= (2 * i - 1); j++)
            printf("*");
        printf("\n");
    }
}

// Function to print a pyramid pattern
void printPyramid(int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++)
            printf(" ");
        for (j = 0; j < 2 * i + 1; j++)
            printf("*");
        printf("\n");
    }
}

// Function to print a reverse pyramid pattern
void printReversePyramid(int n) {
    int i, j;
    for (i = n; i > 0; i--) {
        for (j = 0; j < n - i; j++)
            printf(" ");
        for (j = 0; j < 2 * i - 1; j++)
            printf("*");
        printf("\n");
    }
}

// Function to print a hollow square pattern
void printHollowSquare(int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

// Function to print a solid square pattern
void printSolidSquare(int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Function to print a right-angled triangle pattern
void printRightAngledTriangle(int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++)
            printf("*");
        printf("\n");
    }
}

// Function to print an inverted right-angled triangle pattern
void printInvertedRightAngledTriangle(int n) {
    int i, j;
    for (i = n; i >= 1; i--) {
        for (j = 1; j <= i; j++)
            printf("*");
        printf("\n");
    }
}

// Function to print a number pyramid
void printNumberPyramid(int n) {
    int i, j, num;
    for (i = 1; i <= n; i++) {
        num = 1;
        for (j = 1; j <= n - i; j++)
            printf(" ");
        for (j = 1; j <= 2 * i - 1; j++) {
            if (j <= i)
                printf("%d", num++);
            else
                printf("%d", --num);
        }
        printf("\n");
    }
}

// Function to print a character pyramid
void printCharacterPyramid(int n) {
    int i, j;
    char ch;
    for (i = 0; i < n; i++) {
        ch = 'A';
        for (j = 0; j < n - i - 1; j++)
            printf(" ");
        for (j = 0; j < 2 * i + 1; j++) {
            printf("%c", ch);
            if (j < i) ch++;
            else ch--;
        }
        printf("\n");
    }
}

// Function to print a hollow triangle pattern
void printHollowTriangle(int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (i == n - 1 || j == 0 || j == i)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}