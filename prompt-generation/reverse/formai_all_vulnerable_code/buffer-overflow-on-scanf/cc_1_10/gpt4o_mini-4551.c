//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: energetic
#include <stdio.h>

void printTriangle(int n);
void printSpaces(int spaces);
void printAsterisks(int asterisks);

int main() {
    int rows;

    // Welcome Message
    printf("🌟 Welcome to the Energetic Triangle Pattern Printer! 🌟\n");
    printf("How many rows of stars would you like to see? Enter a number: ");
    scanf("%d", &rows);

    // Input Validation
    while (rows <= 0) {
        printf("🚫 Please enter a positive integer greater than 0: ");
        scanf("%d", &rows);
    }

    // Print Triangle Pattern
    printTriangle(rows);

    // Completion Message
    printf("🎉 Wow! You've just created a beautiful pattern with %d rows! 🎉\n", rows);
    printf("Thank you for playing! 😊\n");

    return 0;
}

// Function to print the triangle pattern
void printTriangle(int n) {
    for (int i = 1; i <= n; i++) {
        printSpaces(n - i);      // Print spaces for alignment
        printAsterisks(2 * i - 1); // Print odd number of asterisks
        printf("\n");            // Move to the next line
    }
}

// Function to print spaces
void printSpaces(int spaces) {
    for (int j = 0; j < spaces; j++) {
        printf(" ");            // Printing space character
    }
}

// Function to print asterisks
void printAsterisks(int asterisks) {
    for (int k = 0; k < asterisks; k++) {
        printf("*");            // Printing asterisk character
    }
}