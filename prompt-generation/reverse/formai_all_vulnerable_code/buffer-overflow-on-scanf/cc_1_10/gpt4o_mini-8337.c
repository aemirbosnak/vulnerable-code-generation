//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: retro
#include <stdio.h>

void printSpaces(int n) {
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
}

void printStars(int n) {
    for (int i = 0; i < n; i++) {
        printf("* ");
    }
}

void printDiamond(int height) {
    int n = height / 2;  // Formula to determine the number of rows before the middle
    
    // Upper part of the diamond
    for (int i = 0; i < n; i++) {
        printSpaces(n - i);
        printStars(i + 1);
        printf("\n");
    }
    
    // Lower part of the diamond
    for (int i = n; i >= 0; i--) {
        printSpaces(n - i);
        printStars(i);
        printf("\n");
    }
}

void printHollowDiamond(int height) {
    int n = height / 2;  // The number of rows before the middle
    
    // Upper part of the hollow diamond
    for (int i = 0; i < n; i++) {
        printSpaces(n - i);
        if (i == 0) {
            printf("*\n");
        } else {
            printf("*");
            printSpaces(2 * i - 1);
            printf("*\n");
        }
    }
    
    // Lower part of the hollow diamond
    for (int i = n - 1; i >= 0; i--) {
        printSpaces(n - i);
        if (i == 0) {
            printf("*\n");
        } else {
            printf("*");
            printSpaces(2 * i - 1);
            printf("*\n");
        }
    }
}

void printTriangle(int height) {
    for (int i = 0; i < height; i++) {
        printSpaces(height - i - 1);
        printStars(i + 1);
        printf("\n");
    }
}

void printHollowTriangle(int height) {
    for (int i = 0; i < height; i++) {
        printSpaces(height - i - 1);
        if (i == 0) {
            printf("*\n");
        } else if (i == height - 1) {
            printStars(height);
            printf("\n");
        } else {
            printf("*");
            printSpaces(2 * i - 1);
            printf("*\n");
        }
    }
}

int main() {
    int choice, height;

    printf("Welcome to the Retro Pattern Printing Program!\n");
    printf("Choose a pattern to print:\n");
    printf("1. Diamond\n");
    printf("2. Hollow Diamond\n");
    printf("3. Triangle\n");
    printf("4. Hollow Triangle\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    
    printf("Enter the height of the pattern (must be an even number for diamonds/hollow diamonds): ");
    scanf("%d", &height);
    
    if (choice == 1) {
        printf("\nPrinting Diamond Pattern of height %d:\n", height);
        printDiamond(height);
    } else if (choice == 2) {
        printf("\nPrinting Hollow Diamond Pattern of height %d:\n", height);
        printHollowDiamond(height);
    } else if (choice == 3) {
        printf("\nPrinting Triangle Pattern of height %d:\n", height);
        printTriangle(height);
    } else if (choice == 4) {
        printf("\nPrinting Hollow Triangle Pattern of height %d:\n", height);
        printHollowTriangle(height);
    } else {
        printf("Invalid choice! Exiting the program.\n");
    }

    printf("Thank you for using the Retro Pattern Printing Program!\n");
    return 0;
}