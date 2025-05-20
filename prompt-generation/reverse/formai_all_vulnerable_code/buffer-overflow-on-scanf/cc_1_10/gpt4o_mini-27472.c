//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: scalable
#include <stdio.h>

// Function prototypes
void printDiamond(int n);
void printSpaces(int n);
void printStars(int n);

int main() {
    int size;

    printf("Enter the size of the diamond (number of rows): ");
    
    // Error checking for user input
    while (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid input. Please enter a positive integer: ");
        while(getchar() != '\n'); // Clear input buffer
    }

    printDiamond(size);
    return 0;
}

// Function to print a diamond based on a specified size
void printDiamond(int n) {
    // Upper part of the diamond
    for (int i = 1; i <= n; i++) {
        printSpaces(n - i);
        printStars(2 * i - 1);
        printf("\n");
    }

    // Lower part of the diamond
    for (int i = n - 1; i >= 1; i--) {
        printSpaces(n - i);
        printStars(2 * i - 1);
        printf("\n");
    }
}

// Function to print spaces
void printSpaces(int n) {
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
}

// Function to print stars
void printStars(int n) {
    for (int i = 0; i < n; i++) {
        printf("*");
    }
}