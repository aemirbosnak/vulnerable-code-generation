//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MAX 512  // Adjust size for your needs
#define THREADS 4  // Number of threads

int A[MAX][MAX]; // Matrix A
int B[MAX][MAX]; // Matrix B
int C[MAX][MAX]; // Result Matrix C
int rows_A, cols_A, rows_B, cols_B;

// Structure for passing multiple arguments to the thread function
typedef struct {
    int row;
    int cols_A;
} ThreadData;

// Function to multiply a single row of matrix A with matrix B
void *multiply_row(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    int row = data->row;
    int cols_A = data->cols_A;

    for (int j = 0; j < cols_B; j++) {
        C[row][j] = 0;
        for (int k = 0; k < cols_A; k++) {
            C[row][j] += A[row][k] * B[k][j];
        }
    }

    pthread_exit(NULL);
}

// Function to populate matrices A and B with random values
void initialize_matrices(int rows_A, int cols_A, int rows_B, int cols_B) {
    srand(time(0));
    for (int i = 0; i < rows_A; i++)
        for (int j = 0; j < cols_A; j++)
            A[i][j] = rand() % 10;

    for (int i = 0; i < rows_B; i++)
        for (int j = 0; j < cols_B; j++)
            B[i][j] = rand() % 10;
}

// Main function to execute matrix multiplication
int main() {
    printf("Enter number of rows and columns for matrix A: ");
    scanf("%d %d", &rows_A, &cols_A);
    
    printf("Enter number of rows and columns for matrix B: ");
    scanf("%d %d", &rows_B, &cols_B);
    
    // Check for valid matrix multiplication
    if (cols_A != rows_B) {
        fprintf(stderr, "Error: Number of columns in A must equal number of rows in B.\n");
        return EXIT_FAILURE;
    }

    initialize_matrices(rows_A, cols_A, rows_B, cols_B);
    
    // Create threads for matrix multiplication
    pthread_t threads[THREADS];
    ThreadData thread_data[THREADS];

    for (int i = 0; i < rows_A; i++) {
        thread_data[i % THREADS].row = i;
        thread_data[i % THREADS].cols_A = cols_A;

        if (i % THREADS == THREADS - 1 || i == rows_A - 1) {
            for (int j = 0; j < THREADS; j++) {
                if (i >= j) {
                    pthread_create(&threads[j], NULL, multiply_row, (void *)&thread_data[j]);
                }
            }
            for (int j = 0; j < THREADS; j++) {
                if (i >= j) {
                    pthread_join(threads[j], NULL);
                }
            }
        }
    }

    // Display the resulting matrix C
    printf("Resultant Matrix C:\n");
    for (int i = 0; i < rows_A; i++) {
        for (int j = 0; j < cols_B; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}