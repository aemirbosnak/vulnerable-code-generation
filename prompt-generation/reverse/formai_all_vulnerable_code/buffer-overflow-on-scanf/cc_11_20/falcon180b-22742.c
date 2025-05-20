//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 20
#define NUM_COLS 40

void print_pattern(int row, int col) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    srand(time(NULL));
    int pattern_type = rand() % 5;

    switch (pattern_type) {
        case 0:
            printf("Pattern 1:\n");
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    printf("*");
                }
                printf("\n");
            }
            break;

        case 1:
            printf("Pattern 2:\n");
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if ((i + j) % 2 == 0) {
                        printf("*");
                    } else {
                        printf(" ");
                    }
                }
                printf("\n");
            }
            break;

        case 2:
            printf("Pattern 3:\n");
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if ((i + j) % 2 == 0) {
                        printf(" ");
                    } else {
                        printf("*");
                    }
                }
                printf("\n");
            }
            break;

        case 3:
            printf("Pattern 4:\n");
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (i % 2 == 0 && j % 2 == 0) {
                        printf("*");
                    } else {
                        printf(" ");
                    }
                }
                printf("\n");
            }
            break;

        case 4:
            printf("Pattern 5:\n");
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if ((i + j) % 3 == 0) {
                        printf("*");
                    } else {
                        printf(" ");
                    }
                }
                printf("\n");
            }
            break;
    }

    return 0;
}