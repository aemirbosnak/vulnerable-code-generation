//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int i, j, n, m, k;
    int **matrix;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("Enter the number of columns: ");
    scanf("%d", &m);

    matrix = (int **) malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        matrix[i] = (int *) malloc(m * sizeof(int));
    }

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Enter the number of iterations: ");
    scanf("%d", &k);

    start = clock();
    for (i = 0; i < k; i++) {
        for (j = 0; j < n; j++) {
            for (m = 0; m < m; m++) {
                matrix[j][m] += matrix[j][m];
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("The sum of the elements in the matrix is: %d\n", matrix[0][0]);
    printf("Time taken for %d iterations: %lf seconds\n", k, cpu_time_used);

    for (i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}