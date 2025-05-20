//FormAI DATASET v1.0 Category: Matrix operations ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#define ROW 2
#define COL 2

int main()
{
    int mat1[ROW][COL], mat2[ROW][COL], result[ROW][COL], i, j, option;
    printf("Enter the values of first matrix: \n");
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("\nEnter the values of second matrix: \n");
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }
    printf("\nSelect the matrix operation to perform: \n");
    printf("1. Addition \n");
    printf("2. Subtraction \n");
    printf("3. Multiplication \n");
    printf("4. Transpose of Matrix 1 \n");
    printf("5. Transpose of Matrix 2 \n");
    scanf("%d", &option);
    switch (option) {
    case 1:
        // Addition
        for (i = 0; i < ROW; i++) {
            for (j = 0; j < COL; j++) {
                result[i][j] = mat1[i][j] + mat2[i][j];
            }
        }
        printf("\nThe sum of the two matrices is: \n");
        for (i = 0; i < ROW; i++) {
            for (j = 0; j < COL; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
        break;
    case 2:
        // Subtraction
        for (i = 0; i < ROW; i++) {
            for (j = 0; j < COL; j++) {
                result[i][j] = mat1[i][j] - mat2[i][j];
            }
        }
        printf("\nThe difference of the two matrices is: \n");
        for (i = 0; i < ROW; i++) {
            for (j = 0; j < COL; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
        break;
    case 3:
        // Multiplication
        for (i = 0; i < ROW; i++) {
            for (j = 0; j < COL; j++) {
                result[i][j] = 0;
                for (int k = 0; k < COL; k++) {
                    result[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
        printf("\nThe product of the two matrices is: \n");
        for (i = 0; i < ROW; i++) {
            for (j = 0; j < COL; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
        break;
    case 4:
        // Transpose of matrix 1
        for (i = 0; i < ROW; i++) {
            for (j = 0; j < COL; j++) {
                result[j][i] = mat1[i][j];
            }
        }
        printf("\nThe transpose of Matrix 1 is: \n");
        for (i = 0; i < COL; i++) {
            for (j = 0; j < ROW; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
        break;
    case 5:
        // Transpose of matrix 2
        for (i = 0; i < ROW; i++) {
            for (j = 0; j < COL; j++) {
                result[j][i] = mat2[i][j];
            }
        }
        printf("\nThe transpose of Matrix 2 is: \n");
        for (i = 0; i < COL; i++) {
            for (j = 0; j < ROW; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
        break;
    default:
        printf("\nInvalid option selected. Please try again.\n");
        break;
    }
    return 0;
}