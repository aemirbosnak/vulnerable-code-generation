//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, i, j;
    int **A, **B, **C;

    printf("Enter the number of rows and columns of the matrices: ");
    scanf("%d %d", &n, &m);

    A = (int**) malloc(n * sizeof(int*));
    for (i = 0; i < n; i++) {
        A[i] = (int*) malloc(m * sizeof(int));
    }

    B = (int**) malloc(n * sizeof(int*));
    for (i = 0; i < n; i++) {
        B[i] = (int*) malloc(m * sizeof(int));
    }

    C = (int**) malloc(n * sizeof(int*));
    for (i = 0; i < n; i++) {
        C[i] = (int*) malloc(m * sizeof(int));
    }

    printf("Enter the elements of the first matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter the elements of the second matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("The sum of the two matrices is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}