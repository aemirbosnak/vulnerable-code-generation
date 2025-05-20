//FormAI DATASET v1.0 Category: Matrix operations ; Style: unmistakable
#include <stdio.h>

void printMatrix(int arr[][10], int row, int column) {
    // A function to print the matrix
    for(int i = 0; i<row; i++) {
        for(int j = 0; j<column; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int arr1[][10], int arr2[][10], int row, int column) {
    // A function to add two matrices
    int sum[10][10];
    for(int i = 0; i<row; i++) {
        for(int j = 0; j<column; j++) {
            sum[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    printf("\nResultant matrix is:\n");
    printMatrix(sum, row, column);
}

void multiplyMatrix(int arr1[][10], int arr2[][10], int row1, int column1, int row2, int column2) {
    // A function to multiply two matrices
    int product[10][10];
    if(column1 != row2) {
        printf("\nMatrices cannot be multiplied\n");
    }
    else {
        for(int i = 0; i<row1; i++) {
            for(int j = 0; j<column2; j++) {
                product[i][j] = 0;
                for(int k = 0; k<column1; k++) {
                    product[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }
        printf("\nResultant matrix is:\n");
        printMatrix(product, row1, column2);
    }
}

int main() {
    int row1, column1, row2, column2;
    int arr1[10][10], arr2[10][10];
    
    printf("Enter number of rows and columns of first matrix: ");
    scanf("%d %d", &row1, &column1);
    printf("Enter elements of first matrix: ");
    for(int i = 0; i<row1; i++) {
        for(int j = 0; j<column1; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("\nEnter number of rows and columns of second matrix: ");
    scanf("%d %d", &row2, &column2);
    printf("Enter elements of second matrix: ");
    for(int i = 0; i<row2; i++) {
        for(int j = 0; j<column2; j++) {
            scanf("%d", &arr2[i][j]);
        }
    }

    printf("\nFirst matrix is:\n");
    printMatrix(arr1, row1, column1);

    printf("\nSecond matrix is:\n");
    printMatrix(arr2, row2, column2);

    if(row1 == row2 && column1 == column2) {
        addMatrix(arr1, arr2, row1, column1);
    }
    else {
        printf("\nMatrices cannot be added\n");
    }

    multiplyMatrix(arr1, arr2, row1, column1, row2, column2);
    return 0;
}