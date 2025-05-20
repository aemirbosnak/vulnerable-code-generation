//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define NUM_THREADS 4
#define MAX_SIZE 1000

// Global data shared by all threads
int size;
int **matrix;
int num_threads;

// Function to perform matrix multiplication
void *multiply_matrices(void *arg) {
    int i, j, k;
    int start_row, end_row;

    // Calculate the starting and ending rows for this thread
    start_row = ((int) arg) / num_threads;
    end_row = (start_row + 1) * num_threads - 1;

    // Perform matrix multiplication for assigned rows
    for (i = start_row; i <= end_row; i++) {
        for (j = 0; j < size; j++) {
            matrix[i][j] = 0;
            for (k = 0; k < size; k++) {
                matrix[i][j] += matrix[i][k] * matrix[k][j];
            }
        }
    }

    return NULL;
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Get matrix size from user
    printf("Enter matrix size: ");
    scanf("%d", &size);

    // Initialize matrices with random values
    matrix = (int **) malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int *) malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 100;
        }
    }

    // Initialize number of threads
    num_threads = NUM_THREADS;

    // Create threads
    pthread_t threads[num_threads];
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, multiply_matrices, (void *) i);
    }

    // Join threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print result
    printf("Result:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}