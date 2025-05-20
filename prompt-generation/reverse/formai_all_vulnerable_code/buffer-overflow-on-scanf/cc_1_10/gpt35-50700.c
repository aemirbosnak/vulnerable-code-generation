//FormAI DATASET v1.0 Category: Educational ; Style: expert-level
#include <stdio.h>

int main() {
    // Declare variables
    int n, m, i, j;
    int Matrix1[10][10], Matrix2[10][10], Result[10][10];
    
    // Read dimensions of matrix 1 and matrix 2
    printf("Enter the number of rows and columns of matrix 1: ");
    scanf("%d %d", &n, &m);
    printf("Enter the number of rows and columns of matrix 2: ");
    scanf("%d %d", &m, &n);
    
    // Read elements of matrix 1
    printf("Enter the elements of matrix 1:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            scanf("%d", &Matrix1[i][j]);
        }
    }
    
    // Read elements of matrix 2
    printf("Enter the elements of matrix 2:\n");
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            scanf("%d", &Matrix2[i][j]);
        }
    }
    
    // Multiply two matrices
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            Result[i][j] = 0;
            for(int k=0; k<m; k++) {
                Result[i][j] += Matrix1[i][k] * Matrix2[k][j];
            }
        }
    }
    
    // Display the result
    printf("The resulting matrix is:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("%d ", Result[i][j]);
        }
        printf("\n");
    }
    
    // Exit program
    return 0;
}