//FormAI DATASET v1.0 Category: Matrix operations ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 3

int matA[N][N], matB[N][N], matC[N][N];

void *multiply(void *arg) {
    int *row = (int*) arg;
    int i, j, sum;

    for (i = 0; i < N; i++) {
        sum = 0;
        for (j = 0; j < N; j++) {
            sum += matA[*row][j] * matB[j][i];
        }
        matC[*row][i] = sum;
    }
    pthread_exit(NULL);
}

int main() {
    int i, j, rc;
    pthread_t threads[N];

    printf("Enter values for A: \n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &matA[i][j]);
        }
    }

    printf("Enter values for B: \n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &matB[i][j]);
        }
    }

    printf("Matrix A:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", matA[i][j]);
        }
        printf("\n");
    }

    printf("Matrix B:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", matB[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < N; i++) {
        rc = pthread_create(&threads[i], NULL, multiply, (void*) &i);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    for (i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Result Matrix:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", matC[i][j]);
        }
        printf("\n");
    }

    return 0;
}