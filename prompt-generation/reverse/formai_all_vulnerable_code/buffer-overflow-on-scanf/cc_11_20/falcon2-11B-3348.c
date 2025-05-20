//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int main() {
    int rows, cols;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Allocate memory for the table
    int **table = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        table[i] = (int *)malloc(cols * sizeof(int));
    }

    // Print the table header
    printf("\nTable:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d", i + 1);
            if (j < cols - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Fill the table
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter the value at position (%d, %d): ", i + 1, j + 1);
            scanf("%d", &table[i][j]);
        }
    }

    // Print the filled table
    printf("\nFilled Table:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d", table[i][j]);
            if (j < cols - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(table[i]);
    }
    free(table);

    return 0;
}