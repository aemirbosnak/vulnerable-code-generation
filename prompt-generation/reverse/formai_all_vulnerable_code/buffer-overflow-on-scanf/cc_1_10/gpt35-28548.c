//FormAI DATASET v1.0 Category: Matrix operations ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

#define ROW_SIZE 3
#define COLUMN_SIZE 3

void printMatrix(int matrix[ROW_SIZE][COLUMN_SIZE])
{
    int row, column;
    printf("Matrix:\n");
    for(row = 0; row < ROW_SIZE; row++) {
        for(column = 0; column < COLUMN_SIZE; column++) {
            printf("%d ", matrix[row][column]);
        }
        printf("\n");
    }
}

void addMatrices(int matrix1[ROW_SIZE][COLUMN_SIZE], int matrix2[ROW_SIZE][COLUMN_SIZE])
{
    int row, column;
    int resultMatrix[ROW_SIZE][COLUMN_SIZE];
    for(row = 0; row < ROW_SIZE; row++) {
        for(column = 0; column < COLUMN_SIZE; column++) {
            resultMatrix[row][column] = matrix1[row][column] + matrix2[row][column];
        }
    }
    printMatrix(resultMatrix);
}

void subtractMatrices(int matrix1[ROW_SIZE][COLUMN_SIZE], int matrix2[ROW_SIZE][COLUMN_SIZE])
{
    int row, column;
    int resultMatrix[ROW_SIZE][COLUMN_SIZE];
    for(row = 0; row < ROW_SIZE; row++) {
        for(column = 0; column < COLUMN_SIZE; column++) {
            resultMatrix[row][column] = matrix1[row][column] - matrix2[row][column];
        }
    }
    printMatrix(resultMatrix);
}

void multiplyMatrices(int matrix1[ROW_SIZE][COLUMN_SIZE], int matrix2[ROW_SIZE][COLUMN_SIZE])
{
    int row, column, inner;
    int resultMatrix[ROW_SIZE][COLUMN_SIZE];
    for(row = 0; row < ROW_SIZE; row++) {
        for(column = 0; column < COLUMN_SIZE; column++) {
            resultMatrix[row][column] = 0;
            for(inner = 0; inner < COLUMN_SIZE; inner++) {
                resultMatrix[row][column] += matrix1[row][inner] * matrix2[inner][column];
            }
        }
    }
    printMatrix(resultMatrix);
}

int main()
{
    int matrix1[ROW_SIZE][COLUMN_SIZE] = {{1, 2, 3},
                                           {4, 5, 6},
                                           {7, 8, 9}};
    int matrix2[ROW_SIZE][COLUMN_SIZE] = {{9, 8, 7},
                                           {6, 5, 4},
                                           {3, 2, 1}};

    printf("1. Addition\n2. Subtraction\n3. Multiplication\nEnter your choice: ");
    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            addMatrices(matrix1, matrix2);
            break;
        case 2:
            subtractMatrices(matrix1, matrix2);
            break;
        case 3:
            multiplyMatrices(matrix1, matrix2);
            break;
        default:
            printf("Invalid choice.\n");
            exit(0);
    }

    return 0;
}