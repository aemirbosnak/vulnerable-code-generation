//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SIZE 1000  // Maximum size for matrices
#define NUM_THREADS 4  // Number of threads for matrix multiplication

int matrixA[MAX_SIZE][MAX_SIZE];
int matrixB[MAX_SIZE][MAX_SIZE];
int matrixC[MAX_SIZE][MAX_SIZE];
int n;  // Size of the matrices

typedef struct {
    int rowStart;
    int rowEnd;
} ThreadData;

void* multiply(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    for (int i = data->rowStart; i < data->rowEnd; i++) {
        for (int j = 0; j < n; j++) {
            matrixC[i][j] = 0;
            for (int k = 0; k < n; k++) {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return NULL;
}

int main() {
    printf("Enter the size of the square matrices (max %d): ", MAX_SIZE);
    scanf("%d", &n);
    
    if (n > MAX_SIZE) {
        fprintf(stderr, "Maximum size exceeded.\n");
        return 1;
    }

    // Initialize matrices A and B with random values
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            matrixA[i][j] = rand() % 100;
            matrixB[i][j] = rand() % 100;
        }

    // Display matrix A
    printf("Matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrixA[i][j]);
        }
        printf("\n");
    }

    // Display matrix B
    printf("Matrix B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrixB[i][j]);
        }
        printf("\n");
    }

    pthread_t threads[NUM_THREADS];
    ThreadData threadData[NUM_THREADS];
    int rowsPerThread = n / NUM_THREADS;

    // Create threads for matrix multiplication
    for (int i = 0; i < NUM_THREADS; i++) {
        threadData[i].rowStart = i * rowsPerThread;
        threadData[i].rowEnd = (i == NUM_THREADS - 1) ? n : (i + 1) * rowsPerThread;
        pthread_create(&threads[i], NULL, multiply, (void*)&threadData[i]);
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Display result matrix C
    printf("Result Matrix C = A * B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrixC[i][j]);
        }
        printf("\n");
    }

    return 0;
}