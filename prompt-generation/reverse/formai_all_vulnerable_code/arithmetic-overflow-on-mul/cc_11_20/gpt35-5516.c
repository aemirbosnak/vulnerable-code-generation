//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdbool.h>

int main() {

    int n, m;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &n, &m);

    int matrix[n][m];

    printf("Enter the matrix elements: \n");

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Original matrix: \n");

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("Shifting matrix...\n");

    int rotations;

    printf("Enter the number of rotations: ");
    scanf("%d", &rotations);

    bool isClockwise;

    printf("Enter 1 for clockwise or 0 for counterclockwise: ");
    scanf("%d", &isClockwise);

    rotations = rotations % (2 * (n + m - 2));

    for(int k=0; k<rotations; k++) {
        if(isClockwise) {
            for(int i=0; i<(n/2); i++) {
                for(int j=i; j<(m-i-1); j++) {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[m-j-1][i];
                    matrix[m-j-1][i] = matrix[n-i-1][m-j-1];
                    matrix[n-i-1][m-j-1] = matrix[j][n-i-1];
                    matrix[j][n-i-1] = temp;
                }
            }
        }
        else {
            for(int i=0; i<(n/2); i++) {
                for(int j=i; j<(m-i-1); j++) {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][n-i-1];
                    matrix[j][n-i-1] = matrix[n-i-1][m-j-1];
                    matrix[n-i-1][m-j-1] = matrix[m-j-1][i];
                    matrix[m-j-1][i] = temp;
                }
            }
        }
    }

    printf("Shifted matrix: \n");

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}