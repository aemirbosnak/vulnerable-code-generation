//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, cols, i, j, k, l;
    int **matrix;
    int *p;
    int choice;
    char ch;
    int sum;

    srand(time(0));
    rows = rand() % 10 + 1;
    cols = rand() % 10 + 1;
    matrix = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    do {
        printf("\nEnter your choice:\n1. Transpose\n2. Sum of elements\n3. Exit");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            for (i = 0; i < cols; i++) {
                for (j = 0; j < rows; j++) {
                    p = matrix[j];
                    matrix[j] = matrix[i];
                    matrix[i] = p;
                }
            }
            printf("\nTransposed Matrix:\n");
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    printf("%d ", matrix[i][j]);
                }
                printf("\n");
            }
            break;
        case 2:
            sum = 0;
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    sum += matrix[i][j];
                }
            }
            printf("\nSum of elements: %d", sum);
            break;
        case 3:
            printf("\nExiting...");
            exit(0);
        default:
            printf("\nInvalid choice!");
        }
    } while (choice!= 3);

    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}