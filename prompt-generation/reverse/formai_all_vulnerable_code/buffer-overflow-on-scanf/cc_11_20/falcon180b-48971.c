//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int m, n, i, j, k, l, sum = 0;
    int first[MAX][MAX], second[MAX][MAX], multiply[MAX][MAX], transpose[MAX][MAX], temp[MAX][MAX];

    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d%d", &m, &n);

    printf("Enter the elements of the first matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &first[i][j]);
        }
    }

    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d%d", &k, &l);

    if (n!= k) {
        printf("The matrices cannot be multiplied.\n");
        exit(0);
    }

    printf("Enter the elements of the second matrix:\n");
    for (i = 0; i < k; i++) {
        for (j = 0; j < l; j++) {
            scanf("%d", &second[i][j]);
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < l; j++) {
            for (k = 0; k < n; k++) {
                temp[i][j] += first[i][k] * second[k][j];
            }
        }
    }

    printf("Product of the matrices:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < l; j++) {
            printf("%d\t", temp[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            transpose[j][i] = first[i][j];
        }
    }

    printf("Transpose of the first matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d\t", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}