//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MAX 1024  // Maximum dimension for the matrices
#define NUM_THREADS 4 // Number of threads to create

typedef struct {
    int thread_id;
    int (*A)[MAX];
    int (*B)[MAX];
    int (*C)[MAX];
    int N;
} ThreadData;

void *multiply(void *arg) {
    ThreadData *data = (ThreadData *) arg;
    
    int chunk_size = data->N / NUM_THREADS;
    int start = data->thread_id * chunk_size;
    int end = (data->thread_id + 1) * chunk_size;

    if (data->thread_id == NUM_THREADS - 1) {
        end = data->N; // Last thread takes any remaining rows
    }

    for (int i = start; i < end; i++) {
        for (int j = 0; j < data->N; j++) {
            data->C[i][j] = 0;
            for (int k = 0; k < data->N; k++) {
                data->C[i][j] += data->A[i][k] * data->B[k][j];
            }
        }
    }
    pthread_exit(NULL);
}

void initialize_matrix(int (*matrix)[MAX], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 10;  // Populate with random integers from 0 to 9
        }
    }
}

void print_matrix(int (*matrix)[MAX], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int N;
    printf("Enter the dimension of the square matrices (<= %d): ", MAX);
    scanf("%d", &N);

    if (N > MAX || N <= 0) {
        fprintf(stderr, "Invalid size. Please enter size between 1 and %d.\n", MAX);
        return EXIT_FAILURE;
    }

    int (*A)[MAX] = malloc(N * sizeof(*A));
    int (*B)[MAX] = malloc(N * sizeof(*B));
    int (*C)[MAX] = malloc(N * sizeof(*C));

    if (A == NULL || B == NULL || C == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    srand(time(0));  // Seed the random number generator

    initialize_matrix(A, N);
    initialize_matrix(B, N);

    printf("Matrix A:\n");
    print_matrix(A, N);
    printf("\nMatrix B:\n");
    print_matrix(B, N);

    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];

    clock_t start_time = clock();

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].thread_id = i;
        thread_data[i].A = A;
        thread_data[i].B = B;
        thread_data[i].C = C;
        thread_data[i].N = N;

        pthread_create(&threads[i], NULL, multiply, (void *)&thread_data[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    clock_t end_time = clock();
    double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nResult Matrix C (A * B):\n");
    print_matrix(C, N);
    printf("\nTime taken for multiplication: %f seconds\n", duration);

    free(A);
    free(B);
    free(C);

    return EXIT_SUCCESS;
}