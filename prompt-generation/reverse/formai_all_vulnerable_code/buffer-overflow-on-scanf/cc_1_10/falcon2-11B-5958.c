//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

void print_matrix(int m, int n, int **matrix) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m, n, *p, *q;
    int i, j, k;

    printf("Enter the number of rows and columns for matrix 1: ");
    scanf("%d %d", &m, &n);

    int **matrix1 = (int**)malloc(m * sizeof(int*));
    for (i = 0; i < m; i++) {
        matrix1[i] = (int*)malloc(n * sizeof(int));
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the number of rows and columns for matrix 2: ");
    scanf("%d %d", &m, &n);

    int **matrix2 = (int**)malloc(m * sizeof(int*));
    for (i = 0; i < m; i++) {
        matrix2[i] = (int*)malloc(n * sizeof(int));
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("Enter the operation to perform (1: addition, 2: subtraction, 3: multiplication, 4: division): ");
    scanf("%d", &k);

    switch (k) {
        case 1:
            for (i = 0; i < m; i++) {
                for (j = 0; j < n; j++) {
                    matrix1[i][j] += matrix2[i][j];
                }
            }
            break;
        case 2:
            for (i = 0; i < m; i++) {
                for (j = 0; j < n; j++) {
                    matrix1[i][j] -= matrix2[i][j];
                }
            }
            break;
        case 3:
            for (i = 0; i < m; i++) {
                for (j = 0; j < n; j++) {
                    matrix1[i][j] *= matrix2[i][j];
                }
            }
            break;
        case 4:
            for (i = 0; i < m; i++) {
                for (j = 0; j < n; j++) {
                    matrix1[i][j] /= matrix2[i][j];
                }
            }
            break;
    }

    printf("\nResulting matrix:\n");
    print_matrix(m, n, matrix1);

    free(matrix1);
    free(matrix2);

    return 0;
}