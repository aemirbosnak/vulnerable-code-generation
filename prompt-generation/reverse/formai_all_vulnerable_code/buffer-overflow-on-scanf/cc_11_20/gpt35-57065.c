//FormAI DATASET v1.0 Category: Matrix operations ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    printf("Enter the number of rows and columns of the matrix:\n");
    scanf("%d %d", &n, &m);
    int a[n][m], sum = 0, product = 1;

    printf("\nEnter the elements of the matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nThe matrix is:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    // Find the sum and product of the elements in the matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            sum += a[i][j];
            product *= a[i][j];
        }
    }

    printf("\nThe sum of the elements in the matrix is: %d\n", sum);
    printf("The product of the elements in the matrix is: %d\n", product);

    // Find the transpose of the matrix
    int transpose[m][n];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            transpose[i][j] = a[j][i];
        }
    }

    printf("\nThe transpose of the matrix is:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d\t", transpose[i][j]);
        }
        printf("\n");
    }

    // Check if the matrix is symmetric
    int is_symmetric = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] != a[j][i]) {
                is_symmetric = 0;
                break;
            }
        }
    }

    if(is_symmetric) {
        printf("\nThe matrix is symmetric.\n");
    } else {
        printf("\nThe matrix is not symmetric.\n");
    }

    return 0;
}