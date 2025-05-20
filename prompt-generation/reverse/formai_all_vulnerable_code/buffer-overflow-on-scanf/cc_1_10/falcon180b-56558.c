//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 50
#define MAX_COLS 50

int main() {
    int rows, cols, i, j, k;
    char pattern[MAX_ROWS][MAX_COLS];
    char input[MAX_ROWS][MAX_COLS];

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    printf("Enter the pattern:\n");
    for (i = 0; i < rows; i++) {
        scanf("%s", pattern[i]);
    }

    printf("Enter the input:\n");
    for (i = 0; i < rows; i++) {
        scanf("%s", input[i]);
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (pattern[i][j] == '*') {
                for (k = 0; k < rows; k++) {
                    if (input[k][j] == '*') {
                        printf("*");
                    } else {
                        printf(" ");
                    }
                }
            } else {
                for (k = 0; k < rows; k++) {
                    if (input[k][j] == '*') {
                        printf(" ");
                    } else {
                        printf("*");
                    }
                }
            }
        }
        printf("\n");
    }

    return 0;
}