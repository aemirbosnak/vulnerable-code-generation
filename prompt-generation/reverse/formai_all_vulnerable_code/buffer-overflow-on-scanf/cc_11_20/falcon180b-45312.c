//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, m, i, j, k, l, c, d, u, v, count = 0;
    char a[100][100], b[100][100];
    char temp[100][100];

    // Reading the input matrices
    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d%d", &n, &m);
    printf("Enter the elements of the first matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%c", &a[i][j]);
        }
    }

    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d%d", &n, &m);
    printf("Enter the elements of the second matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%c", &b[i][j]);
        }
    }

    // Copying the input matrices to temporary matrices
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            temp[i][j] = a[i][j];
        }
    }

    // Merging the input matrices
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (temp[i][j] == b[i][j]) {
                c = 1;
            } else {
                c = 0;
            }
            u = temp[i][j];
            v = b[i][j];
            if (c == 1) {
                d = u;
            } else {
                d = v;
            }
            a[i][j] = d;
        }
    }

    // Printing the merged matrix
    printf("The merged matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%c ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}