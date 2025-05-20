//FormAI DATASET v1.0 Category: Matrix operations ; Style: active
#include <stdio.h>

//function to print a given matrix
void printMatrix(int r, int c, int arr[][c]) {
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

//function to add two matrices
void addMatrices(int r, int c, int arr1[][c], int arr2[][c]) {
    int result[r][c];
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            result[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    printf("Resultant Matrix after addition is:\n");
    printMatrix(r, c, result);
}

//function to subtract two matrices
void subtractMatrices(int r, int c, int arr1[][c], int arr2[][c]) {
    int result[r][c];
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            result[i][j] = arr1[i][j] - arr2[i][j];
        }
    }
    printf("Resultant Matrix after subtraction is:\n");
    printMatrix(r, c, result);
}

//function to multiply two matrices
void multiplyMatrices(int r1, int c1, int arr1[][c1], int r2, int c2, int arr2[][c2]) {
    if(c1 != r2) {
        printf("Invalid matrices dimensions for multiplication. Cannot be multiplied!\n");
        return;
    }
    int result[r1][c2];
    for(int i=0; i<r1; i++) {
        for(int j=0; j<c2; j++) {
            result[i][j] = 0;
            for(int k=0; k<c1; k++) {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    printf("Resultant Matrix after multiplication is:\n");
    printMatrix(r1, c2, result);
}

int main() {
    int r1, c1, r2, c2;
    printf("Enter dimensions for Matrix-1 (Rows, Columns): ");
    scanf("%d %d", &r1, &c1);
    printf("Enter dimensions for Matrix-2 (Rows, Columns): ");
    scanf("%d %d", &r2, &c2);
    
    int arr1[r1][c1], arr2[r2][c2];
    
    //taking inputs for Matrix-1
    printf("\nEnter Matrix-1:\n");
    for(int i=0; i<r1; i++) {
        for(int j=0; j<c1; j++) {
            printf("Enter element [%d][%d]: ", i+1, j+1);
            scanf("%d", &arr1[i][j]);
        }
    }
    
    //taking inputs for Matrix-2
    printf("\nEnter Matrix-2:\n");
    for(int i=0; i<r2; i++) {
        for(int j=0; j<c2; j++) {
            printf("Enter element [%d][%d]: ", i+1, j+1);
            scanf("%d", &arr2[i][j]);
        }
    }
    
    //printing Matrix-1 and Matrix-2
    printf("\nMatrix-1:\n");
    printMatrix(r1, c1, arr1);
    printf("\nMatrix-2:\n");
    printMatrix(r2, c2, arr2);
    
    //performing Matrix operations
    addMatrices(r1, c1, arr1, arr2);
    subtractMatrices(r1, c1, arr1, arr2);
    multiplyMatrices(r1, c1, arr1, r2, c2, arr2);
    
    return 0;
}