//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MATRIX_SIZE 1000

// Matrix A and B
int A[MATRIX_SIZE][MATRIX_SIZE];
int B[MATRIX_SIZE][MATRIX_SIZE];

// Result matrix C
int C[MATRIX_SIZE][MATRIX_SIZE];

// Number of threads
int num_threads;

// Mutex to protect the result matrix
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Thread function to multiply two matrices
void* matrix_multiply(void* arg) {
    int tid = *(int*)arg;
    int start_row = tid * MATRIX_SIZE / num_threads;
    int end_row = (tid + 1) * MATRIX_SIZE / num_threads;

    for (int i = start_row; i < end_row; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            for (int k = 0; k < MATRIX_SIZE; k++) {
                pthread_mutex_lock(&mutex);
                C[i][j] += A[i][k] * B[k][j];
                pthread_mutex_unlock(&mutex);
            }
        }
    }

    return NULL;
}

int main() {
    // Get the number of threads from the user
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    // Create the threads
    pthread_t* threads = malloc(sizeof(pthread_t) * num_threads);

    // Initialize the matrices
    srand(time(NULL));
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
            C[i][j] = 0;
        }
    }

    // Create the threads
    int thread_ids[num_threads];
    for (int i = 0; i < num_threads; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, matrix_multiply, &thread_ids[i]);
    }

    // Wait for the threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the result matrix
    printf("Result matrix C:\n");
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}