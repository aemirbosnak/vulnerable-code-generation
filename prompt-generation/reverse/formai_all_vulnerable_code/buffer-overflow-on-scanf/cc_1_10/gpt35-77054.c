//FormAI DATASET v1.0 Category: Matrix operations ; Style: active
#include<stdio.h>
#include<stdlib.h>

//global variable declaration
int mat1[10][10], mat2[10][10], mat3[10][10];
int row1, col1, row2, col2;

//function to read matrix
void readMatrix(int mat[][10], int row, int col) {
    int i, j;

    printf("\nEnter the elements of matrix:\n");

    for(i=0; i<row; i++) {
        for(j=0; j<col; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

//function to display matrix
void displayMatrix(int mat[][10], int row, int col) {
    int i, j;

    printf("\nMatrix:\n");

    for(i=0; i<row; i++) {
        for(j=0; j<col; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

//function to add two matrices
void addMatrix(int mat1[][10], int mat2[][10], int mat3[][10], int row, int col) {
    int i, j;

    for(i=0; i<row; i++) {
        for(j=0; j<col; j++) {
            mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

//function to subtract two matrices
void subMatrix(int mat1[][10], int mat2[][10], int mat3[][10], int row, int col) {
    int i, j;

    for(i=0; i<row; i++) {
        for(j=0; j<col; j++) {
            mat3[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

//function to multiply two matrices
void mulMatrix(int mat1[][10], int mat2[][10], int mat3[][10], int row1, int col1, int row2, int col2) {
    int i, j, k;

    for(i=0; i<row1; i++) {
        for(j=0; j<col2; j++) {
            mat3[i][j] = 0;
            for(k=0; k<col1; k++) {
                mat3[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int choice;

    printf("\nEnter number of rows and columns of matrix 1:\n");
    scanf("%d %d", &row1, &col1);
    readMatrix(mat1, row1, col1);

    printf("\nEnter number of rows and columns of matrix 2:\n");
    scanf("%d %d", &row2, &col2);
    readMatrix(mat2, row2, col2);

    while(1) {
        printf("\nChoose one option:\n");
        printf("1. Add matrices\n2. Subtract matrices\n3. Multiply matrices\n4. Exit program\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(row1==row2 && col1==col2) {
                    addMatrix(mat1, mat2, mat3, row1, col1);
                    printf("\nResultant matrix after addition:\n");
                    displayMatrix(mat3, row1, col1);
                }
                else {
                    printf("\nMatrices cannot be added!\n");
                }
                break;

            case 2:
                if(row1==row2 && col1==col2) {
                    subMatrix(mat1, mat2, mat3, row1, col1);
                    printf("\nResultant matrix after subtraction:\n");
                    displayMatrix(mat3, row1, col1);
                }
                else {
                    printf("\nMatrices cannot be subtracted!\n");
                }
                break;

            case 3:
                if(col1==row2) {
                    mulMatrix(mat1, mat2, mat3, row1, col1, row2, col2);
                    printf("\nResultant matrix after multiplication:\n");
                    displayMatrix(mat3, row1, col2);
                }
                else {
                    printf("\nMatrices cannot be multiplied!\n");
                }
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}