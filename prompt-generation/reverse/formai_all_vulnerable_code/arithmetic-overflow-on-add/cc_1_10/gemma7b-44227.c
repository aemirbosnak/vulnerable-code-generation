//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {

    int **a = NULL;
    int i, j, k, l, m, n, o, p, q;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    a = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++) {
        a[i] = (int*)malloc(m * sizeof(int));
    }

    printf("Enter the elements of the matrix: ");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("The matrix is: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("Enter the number of rows to be added: ");
    scanf("%d", &o);

    printf("Enter the number of columns to be added: ");
    scanf("%d", &p);

    a = reshape(a, n + o, m + p);

    printf("The reshaped matrix is: \n");
    for (i = 0; i < n + o; i++) {
        for (j = 0; j < m + p; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    free(a);

    return 0;
}

int reshape(int **a, int n, int m) {
    int i, j, k, l, o, p, q;
    int **b = NULL;

    b = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++) {
        b[i] = (int*)malloc(m * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            b[i][j] = a[i][j];
        }
    }

    free(a);

    return b;
}