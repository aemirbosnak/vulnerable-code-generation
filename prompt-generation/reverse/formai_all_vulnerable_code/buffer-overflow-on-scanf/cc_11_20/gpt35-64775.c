//FormAI DATASET v1.0 Category: Matrix operations ; Style: light-weight
#include <stdio.h>

int main() {
    int rows, cols, i, j, choice;
    
    printf("Enter the number of rows and columns:\n");
    scanf("%d %d", &rows, &cols);

    int matrix1[rows][cols], matrix2[rows][cols], result[rows][cols];
    
    printf("\nEnter the elements of the first matrix:\n");
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    
    printf("\nEnter the elements of the second matrix:\n");
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("\nChoose the operation:\n1. Addition\n2. Subtraction\n3. Multiplication\n");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("\nAddition:\n");
        for(i=0; i<rows; i++) {
            for(j=0; j<cols; j++) {
                result[i][j] = matrix1[i][j] + matrix2[i][j];
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    }
    else if(choice == 2) {
        printf("\nSubtraction:\n");
        for(i=0; i<rows; i++) {
            for(j=0; j<cols; j++) {
                result[i][j] = matrix1[i][j] - matrix2[i][j];
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    }
    else if(choice == 3) {
        printf("\nMultiplication:\n");
        for(i=0; i<rows; i++) {
            for(j=0; j<cols; j++) {
                result[i][j] = 0;
                for(int k=0; k<cols; k++) {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    }
    else {
        printf("\nInvalid choice!");
    }

    return 0;
}