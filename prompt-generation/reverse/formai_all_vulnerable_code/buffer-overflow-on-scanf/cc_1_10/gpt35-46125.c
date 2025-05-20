//FormAI DATASET v1.0 Category: Matrix operations ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
    This program demonstrates various matrix operations in C, 
    including addition, subtraction, multiplication,
    transpose, and determinant calculation.
*/

#define MAX_SIZE 10

int matrix[MAX_SIZE][MAX_SIZE];
int result[MAX_SIZE][MAX_SIZE];

void addMatrix(int M1[][MAX_SIZE], int M2[][MAX_SIZE], int size) {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            result[i][j] = M1[i][j] + M2[i][j];
        }
    }
}

void subMatrix(int M1[][MAX_SIZE], int M2[][MAX_SIZE], int size) {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            result[i][j] = M1[i][j] - M2[i][j];
        }
    }
}

void mulMatrix(int M1[][MAX_SIZE], int M2[][MAX_SIZE], int size) {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            result[i][j] = 0;
            for(int k=0; k<size; k++) {
                result[i][j] += M1[i][k] * M2[k][j];
            }
        }
    }
}

void transpose(int M[][MAX_SIZE], int size) {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            result[i][j] = M[j][i];
        }
    }
}

int determinant(int M[][MAX_SIZE], int size) {
    int det = 0;
    if(size == 1) {
        det = M[0][0];
    } else if(size == 2) {
        det = M[0][0]*M[1][1] - M[0][1]*M[1][0];
    } else {
        for(int i=0; i<size; i++) {
            int temp[MAX_SIZE][MAX_SIZE];
            for(int j=1; j<size; j++) {
                int c=0;
                for(int k=0; k<size; k++) {
                    if(k == i) {
                        continue;
                    }
                    temp[j-1][c] = M[j][k];
                    c++;
                }
            }
            det += pow(-1, i) * M[0][i] * determinant(temp, size-1);
        }
    }
    return det;
}

int main() {
    int size;
    printf("Enter the size of the matrix: ");
    scanf("%d", &size);

    // input matrix elements
    printf("Enter the matrix elements: \n");
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Matrix addition
    printf("Matrix addition:\n");
    addMatrix(matrix, matrix, size);
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Matrix subtraction
    printf("\nMatrix subtraction:\n");
    subMatrix(matrix, matrix, size);
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Matrix multiplication
    printf("\nMatrix multiplication:\n");
    mulMatrix(matrix, matrix, size);
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Matrix transpose
    printf("\nMatrix transpose:\n");
    transpose(matrix, size);
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Matrix determinant
    printf("\nMatrix determinant:\n");
    int det = determinant(matrix, size);
    printf("%d\n", det);

    return 0;
}