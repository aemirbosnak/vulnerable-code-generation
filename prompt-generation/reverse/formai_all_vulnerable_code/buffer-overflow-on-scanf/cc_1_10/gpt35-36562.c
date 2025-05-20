//FormAI DATASET v1.0 Category: Matrix operations ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void printMatrix(int matrix[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int matrixOne[ROWS][COLS], int matrixTwo[ROWS][COLS]) {
    int result[ROWS][COLS];

    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            result[i][j] = matrixOne[i][j] + matrixTwo[i][j];
        }
    }

    printf("Matrix One: \n");
    printMatrix(matrixOne);

    printf("\nMatrix Two: \n");
    printMatrix(matrixTwo);

    printf("\nResult: \n");
    printMatrix(result);
}

void multiplyMatrix(int matrixOne[ROWS][COLS], int matrixTwo[ROWS][COLS]) {
    int result[ROWS][COLS];

    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            result[i][j] = 0;
            for(int k=0; k<COLS; k++) {
                result[i][j] += matrixOne[i][k] * matrixTwo[k][j];
            }
        }
    }

    printf("Matrix One: \n");
    printMatrix(matrixOne);

    printf("\nMatrix Two: \n");
    printMatrix(matrixTwo);

    printf("\nResult: \n");
    printMatrix(result);
}

int main() {
    int matrixOne[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrixTwo[ROWS][COLS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    printf("Enter an option:\n");
    printf("1- Add matrices\n");
    printf("2- Multiply matrices\n");
    int option;
    scanf("%d", &option);

    if(option == 1) {
        addMatrix(matrixOne, matrixTwo);
    } else if(option == 2) {
        multiplyMatrix(matrixOne, matrixTwo);
    } else {
        printf("Invalid option");
    }

    return 0;
}