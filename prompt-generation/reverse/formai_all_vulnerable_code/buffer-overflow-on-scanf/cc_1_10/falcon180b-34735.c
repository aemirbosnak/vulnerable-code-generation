//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: scientific
/*
 * This program prints out various patterns using nested loops and conditional statements.
 *
 * Author: [Your Name]
 * Date: [Date]
 */

#include <stdio.h>
#include <stdlib.h>

/* Function to print a pattern */
void print_pattern(int rows, int cols, int start_row, int end_row, int start_col, int end_col) {
    int i, j;

    /* Loop through each row and column */
    for (i = start_row; i <= end_row; i++) {
        for (j = start_col; j <= end_col; j++) {
            /* Check if the current cell is part of the pattern */
            if ((i >= start_row && i <= end_row) && (j >= start_col && j <= end_col)) {
                /* Print the pattern character */
                printf("*");
            } else {
                /* Print a space character */
                printf(" ");
            }
        }
        /* Move to the next line */
        printf("\n");
    }
}

/* Main function */
int main() {
    int rows, cols, start_row, end_row, start_col, end_col;

    /* Get user input for the pattern dimensions */
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    printf("Enter the starting row: ");
    scanf("%d", &start_row);

    printf("Enter the ending row: ");
    scanf("%d", &end_row);

    printf("Enter the starting column: ");
    scanf("%d", &start_col);

    printf("Enter the ending column: ");
    scanf("%d", &end_col);

    /* Print the pattern */
    print_pattern(rows, cols, start_row, end_row, start_col, end_col);

    return 0;
}