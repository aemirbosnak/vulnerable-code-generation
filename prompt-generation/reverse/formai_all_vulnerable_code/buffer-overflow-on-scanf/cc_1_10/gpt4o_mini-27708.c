//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 100
#define NUM_THREADS 4

typedef struct {
    int (*A)[MAX];
    int (*B)[MAX];
    int (*C)[MAX];
    int row;
    int n;
} ThreadData;

void *multiply(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    int sum;

    for (int i = data->row; i < data->n; i += NUM_THREADS) {
        for (int j = 0; j < data->n; j++) {
            sum = 0;
            for (int k = 0; k < data->n; k++) {
                sum += data->A[i][k] * data->B[k][j];
            }
            data->C[i][j] = sum;
        }
    }

    pthread_exit(NULL);
}

void matrix_multiply(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n) {
    pthread_t threads[NUM_THREADS];
    ThreadData threadData[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        threadData[i].A = A;
        threadData[i].B = B;
        threadData[i].C = C;
        threadData[i].row = i;
        threadData[i].n = n;

        if (pthread_create(&threads[i], NULL, multiply, (void *)&threadData[i])) {
            fprintf(stderr, "Error creating thread\n");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
}

void print_matrix(int matrix[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int n;

    printf("Enter the size of the matrices (n x n): ");
    scanf("%d", &n);

    printf("Enter matrix A (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter matrix B (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    matrix_multiply(A, B, C, n);

    printf("Resulting matrix C (A * B):\n");
    print_matrix(C, n);

    return 0;
}