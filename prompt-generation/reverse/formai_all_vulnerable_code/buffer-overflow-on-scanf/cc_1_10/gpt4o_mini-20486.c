//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MAX 100
#define NUM_THREADS 4

typedef struct {
    int (*A)[MAX];
    int (*B)[MAX];
    int (*C)[MAX];
    int row_start;
    int row_end;
    int n;
} thread_data;

void* multiply_matrices(void* arg) {
    thread_data *data = (thread_data*) arg;
    int (*A)[MAX] = data->A;
    int (*B)[MAX] = data->B;
    int (*C)[MAX] = data->C;
    int row_start = data->row_start;
    int row_end = data->row_end;
    int n = data->n;

    for (int i = row_start; i < row_end; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return NULL;
}

void print_matrix(int (*matrix)[MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the size of the matrices (max %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX) {
        printf("Size exceeds maximum limit of %d.\n", MAX);
        return -1;
    }

    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX] = {0};
    
    // Initialize matrices A and B with random values
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    // Print the input matrices
    printf("Matrix A:\n");
    print_matrix(A, n);
    
    printf("Matrix B:\n");
    print_matrix(B, n);

    pthread_t threads[NUM_THREADS];
    thread_data td[NUM_THREADS];

    int rows_per_thread = n / NUM_THREADS;

    // Create threads to multiply matrices
    for (int i = 0; i < NUM_THREADS; i++) {
        td[i].A = A;
        td[i].B = B;
        td[i].C = C;
        td[i].row_start = i * rows_per_thread;
        td[i].row_end = (i == NUM_THREADS - 1) ? n : (i + 1) * rows_per_thread;
        td[i].n = n;

        pthread_create(&threads[i], NULL, multiply_matrices, (void*) &td[i]);
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the result matrix
    printf("Resultant Matrix C (A * B):\n");
    print_matrix(C, n);

    return 0;
}