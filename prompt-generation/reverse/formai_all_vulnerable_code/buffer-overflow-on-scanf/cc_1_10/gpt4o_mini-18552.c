//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SIZE 1024  // Maximum size of the matrices
#define NUM_THREADS 4  // Number of threads to use

int A[MAX_SIZE][MAX_SIZE];   // First matrix
int B[MAX_SIZE][MAX_SIZE];   // Second matrix
int C[MAX_SIZE][MAX_SIZE];   // Result matrix
int N;                       // Dimension of the matrices

// Thread structure to pass data to each thread
typedef struct {
    int thread_id; // Thread ID
    int rows;      // Total rows to work with
} thread_data_t;

// Matrix multiplication function
void* multiply_matrices(void* arg) {
    thread_data_t* data = (thread_data_t*)arg;
    int thread_id = data->thread_id;
    int rows = data->rows;
    
    for (int i = thread_id * (rows / NUM_THREADS); i < (thread_id + 1) * (rows / NUM_THREADS); ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = 0; // Initialize C[i][j] to 0
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    pthread_exit(NULL);
}

int main() {
    // Input the dimension of the matrices
    printf("Enter the dimension of the matrices (N x N): ");
    scanf("%d", &N);
    
    // Limit the size to MAX_SIZE
    if (N > MAX_SIZE) {
        printf("Dimensions exceed maximum limit of %d\n", MAX_SIZE);
        return 1;
    }

    // Populate matrix A
    printf("Enter elements of matrix A (%dx%d):\n", N, N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &A[i][j]);
        }
    }

    // Populate matrix B
    printf("Enter elements of matrix B (%dx%d):\n", N, N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &B[i][j]);
        }
    }

    // Creating threads
    pthread_t threads[NUM_THREADS];
    thread_data_t thread_data[NUM_THREADS];

    // Launching NUM_THREADS threads for computation
    for (int i = 0; i < NUM_THREADS; ++i) {
        thread_data[i].thread_id = i;
        thread_data[i].rows = N;
        if (pthread_create(&threads[i], NULL, multiply_matrices, (void*)&thread_data[i])) {
            fprintf(stderr, "Error creating thread %d\n", i);
            return 1;
        }
    }

    // Joining threads
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Display the result
    printf("Resultant matrix C (%dx%d):\n", N, N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}