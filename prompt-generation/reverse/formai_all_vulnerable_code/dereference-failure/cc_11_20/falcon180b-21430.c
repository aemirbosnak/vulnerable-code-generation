//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int main() {
    int n, m, i, j, k, l;
    int **matrix;
    int **L;
    int *w;
    int *mark;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the number of knapsacks: %d\n", m);
    matrix = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the number of rows for the matrix:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &matrix[i][0]);
        for (j = 1; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Enter the number of knapsacks:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &L[i][0]);
    }

    for (i = 1; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (matrix[j][0] <= i && matrix[j][0] > L[j][0]) {
                L[j][0] = matrix[j][0];
            }
        }
    }

    printf("The number of knapsacks after updating:\n");
    for (i = 0; i < m; i++) {
        printf("%d\n", L[i][0]);
    }

    w = (int *)malloc(m * sizeof(int));
    mark = (int *)malloc(n * sizeof(int));

    for (i = 0; i < m; i++) {
        w[i] = 0;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (matrix[j][i] > 0 && L[j][0] > i) {
                if (w[j] + matrix[j][i] > L[j][0]) {
                    w[j] += matrix[j][i];
                }
            }
        }
    }

    printf("The maximum value that can be obtained is: %d\n", w[0]);

    return 0;
}