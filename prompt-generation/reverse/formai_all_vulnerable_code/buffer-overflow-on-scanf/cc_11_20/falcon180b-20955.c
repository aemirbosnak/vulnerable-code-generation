//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int n, m;
    int **matrix;
    int **result;
    int i, j, k;
    int sum, max_sum;

    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("Enter the number of columns: ");
    scanf("%d", &m);

    matrix = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(m * sizeof(int));
        printf("Enter the elements of row %d: ", i + 1);
        for (j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    result = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        result[i] = (int *)malloc(m * sizeof(int));
        for (j = 0; j < m; j++) {
            result[i][j] = 0;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            sum = 0;
            for (k = 0; k < m; k++) {
                if (k!= j) {
                    sum += matrix[i][k];
                }
            }
            result[i][j] = sum;
        }
    }

    max_sum = result[0][0];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (result[i][j] > max_sum) {
                max_sum = result[i][j];
            }
        }
    }

    printf("The maximum sum of each row is: %d\n", max_sum);

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    for (i = 0; i < n; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}