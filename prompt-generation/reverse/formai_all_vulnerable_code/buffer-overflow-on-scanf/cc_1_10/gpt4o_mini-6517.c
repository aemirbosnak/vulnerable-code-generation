//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: single-threaded
#include <stdio.h>

void printSpaces(int count) {
    for (int i = 0; i < count; i++) {
        printf(" ");
    }
}

void printNumbers(int row) {
    int number = 1;
    for (int i = 1; i <= row; i++) {
        printf("%d ", number);
        number++;
    }
}

void printInvertedPyramid(int rows) {
    for (int i = rows; i >= 1; i--) {
        printSpaces(rows - i);
        printNumbers(i);
        printf("\n");
    }
}

void printPyramid(int rows) {
    for (int i = 1; i <= rows; i++) {
        printSpaces(rows - i);
        printNumbers(i);
        printf("\n");
    }
}

void printDiamond(int rows) {
    printPyramid(rows);
    printInvertedPyramid(rows - 1);
}

void printSeparationLine(int width) {
    for (int i = 0; i < width; i++) {
        printf("-");
    }
    printf("\n");
}

void printWelcomeMessage() {
    printf("Welcome to the Creative Pattern Printing Program!\n");
    printf("This program will print a unique diamond pattern using numbers.\n\n");
}

void printPatternWithHeader(int rows) {
    printWelcomeMessage();
    int width = rows * 2 + 1; // Width of the diamond for separation
    printSeparationLine(width);
    printf("Diamond Pattern:\n");
    printSeparationLine(width);
    printDiamond(rows);
    printSeparationLine(width);
    printf("Thank you for using the Pattern Printing Program!\n");
}

int main() {
    int numberOfRows;

    printf("Enter the number of rows for the diamond pattern (1-9): ");
    scanf("%d", &numberOfRows);

    if (numberOfRows < 1 || numberOfRows > 9) {
        printf("Please enter a valid number between 1 and 9.\n");
        return 1; // Exit with an error code
    }

    printPatternWithHeader(numberOfRows);

    return 0; // Successful termination
}