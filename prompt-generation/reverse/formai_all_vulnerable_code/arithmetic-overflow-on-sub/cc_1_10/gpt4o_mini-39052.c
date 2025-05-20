//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: realistic
#include <stdio.h>

// Function to print a right triangle pattern
void printRightTriangle(int n) {
    printf("Right Triangle Pattern:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a square pattern
void printSquare(int n) {
    printf("Square Pattern:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("* ");
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a pyramid pattern
void printPyramid(int n) {
    printf("Pyramid Pattern:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            printf("  "); // Print spaces
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("* "); // Print stars
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print a diamond pattern
void printDiamond(int n) {
    printf("Diamond Pattern:\n");
    // Upper half
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("* ");
        }
        printf("\n");
    }
    // Lower half
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("* ");
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print an inverted triangle pattern
void printInvertedTriangle(int n) {
    printf("Inverted Triangle Pattern:\n");
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    printf("\n");
}

// Function to print an hourglass pattern
void printHourglass(int n) {
    printf("Hourglass Pattern:\n");
    // Upper half
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    // Lower half
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

// Main function to take user input and display patterns
int main() {
    int choice, n;

    printf("Pattern Printing Program\n");
    printf("1. Right Triangle\n");
    printf("2. Square\n");
    printf("3. Pyramid\n");
    printf("4. Diamond\n");
    printf("5. Inverted Triangle\n");
    printf("6. Hourglass\n");
    printf("Choose a pattern from 1 to 6: ");
    scanf("%d", &choice);

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    switch (choice) {
        case 1: 
            printRightTriangle(n);
            break;
        case 2: 
            printSquare(n);
            break;
        case 3: 
            printPyramid(n);
            break;
        case 4: 
            printDiamond(n);
            break;
        case 5: 
            printInvertedTriangle(n);
            break;
        case 6: 
            printHourglass(n);
            break;
        default: 
            printf("Invalid choice!\n");
    }

    return 0;
}