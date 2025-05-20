//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: statistical
#include <stdio.h>

// Function to print the statistical pattern for a given number of rows
void printStatisticalPattern(int rows) {
    int i, j, k;

    // Loop for each row
    for (i = 1; i <= rows; i++) {
        // Print leading spaces for alignment
        for (j = i; j < rows; j++) {
            printf("  ");
        }

        // Print the ascending part of the pattern
        for (k = 1; k <= i; k++) {
            printf("%d ", k);
        }

        // Print the descending part of the pattern
        for (k = i - 1; k >= 1; k--) {
            printf("%d ", k);
        }

        // Move to the next line
        printf("\n");
    }
}

// Function to print additional statistics about the pattern
void printStatistics(int rows) {
    printf("\nStatistics of the Printed Pattern:\n");
    printf("Total Rows: %d\n", rows);
    printf("Maximum Width: %d characters\n", (rows - 1) * 2 + (2 * rows - 1));

    // Calculate the maximum number printed
    int maxNum = (rows * (rows + 1)) / 2; // Sum of series 1, 2, ... , rows
    printf("Maximum Number Printed: %d\n", maxNum);
}

int main() {
    int rows;

    // Input: Get number of rows from user
    printf("Enter the number of rows for the statistical pattern (1-20): ");
    scanf("%d", &rows);

    // Ensure the number of rows is within a valid range
    if (rows < 1 || rows > 20) {
        printf("Please enter a valid number of rows between 1 and 20.\n");
        return 1;
    }

    // Print the statistical pattern
    printStatisticalPattern(rows);

    // Print additional statistics
    printStatistics(rows);

    return 0;
}