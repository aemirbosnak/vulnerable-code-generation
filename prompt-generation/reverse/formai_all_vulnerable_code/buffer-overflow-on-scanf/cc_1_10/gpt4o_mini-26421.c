//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: light-weight
#include <stdio.h>

void printPattern(int rows) {
    int i, j, num;

    // Upper part of the pattern
    for (i = 1; i <= rows; i++) {
        // Printing spaces for alignment
        for (j = rows; j > i; j--) {
            printf("  ");
        }
        // Printing the left half of the pyramid
        num = 1;
        for (j = 1; j <= i; j++) {
            printf("%d ", num++);
        }
        // Printing the right half of the pyramid
        num -= 2;
        for (j = 1; j < i; j++) {
            printf("%d ", num--);
        }
        // Moving to the next line
        printf("\n");
    }
    
    // Lower part of the pattern (mirror of upper part)
    for (i = rows - 1; i >= 1; i--) {
        // Printing spaces for alignment
        for (j = rows; j > i; j--) {
            printf("  ");
        }
        // Printing the left half of the mirrored pyramid
        num = 1;
        for (j = 1; j <= i; j++) {
            printf("%d ", num++);
        }
        // Printing the right half of the mirrored pyramid
        num -= 2;
        for (j = 1; j < i; j++) {
            printf("%d ", num--);
        }
        // Moving to the next line
        printf("\n");
    }
}

int main() {
    int rows;

    // Prompting user for input
    printf("Enter the number of rows for the pattern (1-9): ");
    scanf("%d", &rows);

    // Input validation
    if (rows < 1 || rows > 9) {
        printf("Please enter a valid number between 1 and 9.\n");
        return 1;
    }

    // Print the pattern
    printPattern(rows);

    return 0;
}