//FormAI DATASET v1.0 Category: Matrix operations ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ROWS 3 
#define COLS 3 

int matrix1[ROWS][COLS], matrix2[ROWS][COLS], result[ROWS][COLS];

void *matrix_multiply(void *arg) {
    int *row = (int*)arg;

    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            result[*row][i] += matrix1[*row][j] * matrix2[j][i];
        }
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t tid[ROWS];

    printf("Enter the values of matrix 1: \n");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("Enter value for row %d, col %d: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("\nEnter the values of matrix 2: \n");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("Enter value for row %d, col %d: ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }

    for (int i = 0; i < ROWS; i++) {
        int *row = malloc(sizeof(int));
        *row = i;

        pthread_create(&tid[i], NULL, matrix_multiply, row);
    }

    for (int i = 0; i < ROWS; i++) {
        pthread_join(tid[i], NULL);
    }

    printf("\nResultant matrix: \n");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}