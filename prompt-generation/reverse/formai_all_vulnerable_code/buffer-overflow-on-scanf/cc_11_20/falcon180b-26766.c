//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int m, n, i, j, k, l, p, q;
    int choice, flag;
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    printf("Enter the number of rows and columns for first matrix: ");
    scanf("%d %d", &m, &n);

    printf("Enter the elements of first matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter the number of rows and columns for second matrix: ");
    scanf("%d %d", &p, &q);

    if (n!= p) {
        printf("Matrices cannot be multiplied.\n");
        exit(0);
    }

    printf("Enter the elements of second matrix:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < q; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    printf("Enter the operation you want to perform:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            for (i = 0; i < m; i++) {
                for (j = 0; j < n; j++) {
                    C[i][j] = A[i][j] + B[i][j];
                }
            }
            break;
        case 2:
            for (i = 0; i < m; i++) {
                for (j = 0; j < n; j++) {
                    C[i][j] = A[i][j] - B[i][j];
                }
            }
            break;
        case 3:
            for (i = 0; i < m; i++) {
                for (j = 0; j < q; j++) {
                    C[i][j] = 0;
                    for (k = 0; k < n; k++) {
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
            break;
        default:
            printf("Invalid choice.\n");
            exit(0);
    }

    printf("Result:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}