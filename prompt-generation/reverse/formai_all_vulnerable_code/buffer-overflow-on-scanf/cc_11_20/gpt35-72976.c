//FormAI DATASET v1.0 Category: Matrix operations ; Style: careful
#include <stdio.h>

int main() {
    int m1[10][10], m2[10][10], res[10][10], r1, c1, r2, c2, i, j, k;

    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter the elements of the first matrix: \n");
    for(i=0; i<r1; i++) {
        for(j=0; j<c1; j++) {
            scanf("%d", &m1[i][j]);
        }
    }

    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &r2, &c2);

    if(c1 != r2) {
        printf("Error! Number of columns of first matrix does not match the number of rows of second matrix.\n");
        return 0;
    }

    printf("Enter the elements of the second matrix: \n");
    for(i=0; i<r2; i++) {
        for(j=0; j<c2; j++) {
            scanf("%d", &m2[i][j]);
        }
    }

    //matrix multiplication
    for(i=0; i<r1; i++) {
        for(j=0; j<c2; j++) {
            res[i][j] = 0;
            for(k=0; k<c1; k++) {
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    //print the result
    printf("Resultant matrix: \n");
    for(i=0; i<r1; i++) {
        for(j=0; j<c2; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}