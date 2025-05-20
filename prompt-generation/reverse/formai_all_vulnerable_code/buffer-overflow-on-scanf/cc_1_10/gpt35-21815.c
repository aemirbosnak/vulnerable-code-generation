//FormAI DATASET v1.0 Category: Matrix operations ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillMatrix(int n, int matrix[n][n]) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
    printf("Matrix filled with happiness!\n");
}

void printMatrix(int n, int matrix[n][n]) {
    int i, j;
    printf("Here is your delightful matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int sumMatrix(int n, int matrix[n][n]) {
    int i, j, sum = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            sum += matrix[i][j];
        }
    }
    printf("The sum of your matrix is %d\n", sum);
    return sum;
}

void multiplyMatrix(int n, int matrixA[n][n], int matrixB[n][n], int matrixR[n][n]) {
    int i, j, k;
    printf("Let's make some serious magic and multiply matrices!\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matrixR[i][j] = 0;
            for (k = 0; k < n; k++) {
                matrixR[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    printf("The resulting matrix is pure joy:\n");
    printMatrix(n, matrixR);
}

int main() {
    int n, matrixA[10][10], matrixB[10][10], matrixR[10][10];
    printf("Hi there! Let's play with matrices.\n");
    printf("What is the size of your matrix? (up to 10x10)\n");
    scanf("%d", &n);
    printf("Ok, let's create two matrices with random numbers!\n");
    fillMatrix(n, matrixA);
    printMatrix(n, matrixA);
    fillMatrix(n, matrixB);
    printMatrix(n, matrixB);
    printf("Now, let's calculate the sum of these two matrices.\n");
    int sumA = sumMatrix(n, matrixA);
    int sumB = sumMatrix(n, matrixB);
    int sumResult = sumA + sumB;
    printf("The sum of these two matrices is pure happiness: %d\n", sumResult);
    printf("And now, let's multiply these two lovely matrices.\n");
    multiplyMatrix(n, matrixA, matrixB, matrixR);
    printf("Thanks for playing! It was so much fun calculating matrices with you.\n");
    return 0;
}