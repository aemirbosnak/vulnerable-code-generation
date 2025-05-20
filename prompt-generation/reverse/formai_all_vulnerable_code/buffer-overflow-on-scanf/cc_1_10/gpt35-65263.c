//FormAI DATASET v1.0 Category: Matrix operations ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ROWS 3
#define COLS 3

int matA[ROWS][COLS], matB[ROWS][COLS], matC[ROWS][COLS];

void *multiply(void *);

int main() {
    int i, j, k, res;
    pthread_t threads[ROWS];
    printf("Enter matrix A:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            scanf("%d", &matA[i][j]);
        }
    }
    printf("Enter matrix B:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            scanf("%d", &matB[i][j]);
        }
    }
    printf("A x B =\n");

    for (i = 0; i < ROWS; i++) {
        res = pthread_create(&threads[i], NULL, multiply, (void *) i);
        if (res != 0) {
            perror("Thread creation error");
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < ROWS; i++) {
        res = pthread_join(threads[i], NULL);
        if (res != 0) {
            perror("Thread join error");
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", matC[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void *multiply(void *arg) {
    int i, j, k;
    int row = (int) arg;
    for (i = 0; i < COLS; i++) {
        for (j = 0; j < ROWS; j++) {
            matC[row][i] += matA[row][j] * matB[j][i];
        }
    }
    pthread_exit(NULL);
}