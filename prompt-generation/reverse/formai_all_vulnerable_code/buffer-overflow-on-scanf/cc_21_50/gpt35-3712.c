//FormAI DATASET v1.0 Category: Matrix operations ; Style: shape shifting
#include <stdio.h>

int main() {
    int option=0;
    int rows=0, cols=0;
    printf("Welcome to Matrix Operations program\n");
    printf("Choose an option:\n");
    printf("1. Create a matrix\n2. Transpose a matrix\n3. Multiply two matrices\n");
    scanf("%d", &option);
    
    if(option==1) {
        printf("Enter number of rows: ");
        scanf("%d", &rows);
        printf("Enter number of columns: ");
        scanf("%d", &cols);
        
        int matrix[rows][cols];
        printf("Enter values for each element of the matrix:\n");
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }
        
        printf("Matrix you entered is:\n");
            for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                printf("%d\t", matrix[i][j]);
            }
            printf("\n");
        }
    } else if(option==2) {
        printf("Enter number of rows: ");
        scanf("%d", &rows);
        printf("Enter number of columns: ");
        scanf("%d", &cols);
        
        int matrix[rows][cols];
        printf("Enter values for each element of the matrix:\n");
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }
        
        printf("Transposed matrix is:\n");
            for(int i=0; i<cols; i++) {
            for(int j=0; j<rows; j++) {
                printf("%d\t", matrix[j][i]);
            }
            printf("\n");
        }
    } else if(option==3) {
        int rows1=0, cols1=0, rows2=0, cols2=0;
        printf("Enter number of rows for Matrix 1: ");
        scanf("%d", &rows1);
        printf("Enter number of columns for Matrix 1: ");
        scanf("%d", &cols1);
        
        int matrix1[rows1][cols1];
        printf("Enter values for each element of Matrix 1:\n");
        for(int i=0; i<rows1; i++) {
            for(int j=0; j<cols1; j++) {
                scanf("%d", &matrix1[i][j]);
            }
        }
        
        printf("Enter number of rows for Matrix 2: ");
        scanf("%d", &rows2);
        printf("Enter number of columns for Matrix 2: ");
        scanf("%d", &cols2);
        while(cols1!=rows2) {
            printf("Error: Matrix 1 column count should match Matrix 2 row count.\n");
            printf("Enter number of rows for Matrix 2: ");
            scanf("%d", &rows2);
            printf("Enter number of columns for Matrix 2: ");
            scanf("%d", &cols2);
        }
        
        int matrix2[rows2][cols2];
        printf("Enter values for each element of Matrix 2:\n");
        for(int i=0; i<rows2; i++) {
            for(int j=0; j<cols2; j++) {
                scanf("%d", &matrix2[i][j]);
            }
        }
        
        int result[rows1][cols2];
        for(int i=0; i<rows1; i++) {
            for(int j=0; j<cols2; j++) {
                result[i][j]=0;
                for(int k=0; k<cols1; k++) {
                    result[i][j]+=matrix1[i][k]*matrix2[k][j];
                }
            }
        }
        
        printf("Resultant matrix is:\n");
        for(int i=0; i<rows1; i++) {
            for(int j=0; j<cols2; j++) {
                printf("%d\t", result[i][j]);
            }
            printf("\n");
        }
    }
    
    return 0;
}