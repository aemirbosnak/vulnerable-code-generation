//FormAI DATASET v1.0 Category: Matrix operations ; Style: automated
#include<stdio.h>
int main()
{
    int matrix1[10][10], matrix2[10][10], result[10][10];
    int i, j, k, row1, column1, row2, column2;

    printf("Enter the number of rows of matrix 1: ");
    scanf("%d", &row1);
    printf("Enter the number of columns of matrix 1: ");
    scanf("%d", &column1);

    printf("Enter the elements of matrix 1:\n");
    for (i = 0; i < row1; i++) {
        for (j = 0; j < column1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the number of rows of matrix 2: ");
    scanf("%d", &row2);
    printf("Enter the number of columns of matrix 2: ");
    scanf("%d", &column2);

    if (column1 != row2){
        printf("Matrices cannot be multiplied with each other.\n");
        return 0;
    }

    printf("Enter the elements of matrix 2:\n");
    for (i = 0; i < row2; i++) {
        for (j = 0; j < column2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    for (i = 0; i < row1; i++) {
        for (j = 0; j < column2; j++) {
            result[i][j] = 0;
            for (k = 0; k < column1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printf("The resultant matrix is:\n");
    for (i = 0; i < row1; i++) {
        for (j = 0; j < column2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}