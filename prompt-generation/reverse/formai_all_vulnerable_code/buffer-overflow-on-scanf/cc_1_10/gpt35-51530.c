//FormAI DATASET v1.0 Category: Matrix operations ; Style: Dennis Ritchie
#include<stdio.h>

//Function to display the matrix
void displayMatrix(int mat[][100], int row, int col) {
    int i, j;
    for(i=0; i<row; i++) {
        for(j=0; j<col; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

//Function to add two matrices
void addMatrix(int mat1[][100], int mat2[][100], int res[][100], int row, int col) {
    int i, j;
    for(i=0; i<row; i++) {
        for(j=0; j<col; j++) {
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

//Function to subtract two matrices
void subMatrix(int mat1[][100], int mat2[][100], int res[][100], int row, int col) {
    int i, j;
    for(i=0; i<row; i++) {
        for(j=0; j<col; j++) {
            res[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

//Function to multiply two matrices
void mulMatrix(int mat1[][100], int mat2[][100], int res[][100], int row1, int col1, int row2, int col2) {
    int i,j,k,sum;
    for(i=0; i<row1; i++) {
        for(j=0; j<col2; j++) {
            sum=0;
            for(k=0; k<col1; k++) {
                sum = sum + mat1[i][k] * mat2[k][j];
            }
            res[i][j] = sum;
        }
    }
}

int main() {
    int mat1[100][100], mat2[100][100], res[100][100];
    int row1, col1, row2, col2;
    int choice;
    int i,j;

    printf("Enter the number of rows and columns of matrix 1: ");
    scanf("%d%d", &row1, &col1);

    printf("Enter the elements of matrix 1: ");
    for(i=0; i<row1; i++) {
        for(j=0; j<col1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter the number of rows and columns of matrix 2: ");
    scanf("%d%d", &row2, &col2);

    printf("Enter the elements of matrix 2: ");
    for(i=0; i<row2; i++) {
        for(j=0; j<col2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    printf("Enter your choice:\n1 to add matrices\n2 to subtract matrices\n3 to multiply matrices\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            if(row1!=row2 || col1!=col2) {
                printf("Matrices can't be added\n");
            }
            else {
                addMatrix(mat1, mat2, res, row1, col1);
                printf("Resultant matrix:\n");
                displayMatrix(res, row1, col1);
            }
            break;

        case 2:
            if(row1!=row2 || col1!=col2) {
                printf("Matrices can't be subtracted\n");
            }
            else {
                subMatrix(mat1, mat2, res, row1, col1);
                printf("Resultant matrix:\n");
                displayMatrix(res, row1, col1);
            }
            break;

        case 3:
            if(col1!=row2) {
                printf("Matrices can't be multiplied\n");
            }
            else {
                mulMatrix(mat1, mat2, res, row1, col1, row2, col2);
                printf("Resultant matrix:\n");
                displayMatrix(res, row1, col2);
            }
            break;

        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}