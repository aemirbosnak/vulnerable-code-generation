//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 10

// Mutex for critical section
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
int m, n, p, q;

void *sum_matrices(void *arg) {
    int i, j, k;
    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++) {
            for (k = 0; k < q; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return NULL;
}

int main() {
    int i, j;
    printf("Enter the number of rows and columns for first matrix: ");
    scanf("%d %d", &m, &n);
    printf("Enter the number of rows and columns for second matrix: ");
    scanf("%d %d", &p, &q);

    if (n!= p) {
        printf("Matrices cannot be multiplied.\n");
        exit(0);
    }

    printf("Enter elements of first matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < q; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    int num_threads = 4;
    pthread_t threads[num_threads];

    int rows_per_thread = m / num_threads;

    for (i = 0; i < num_threads; i++) {
        int start_row = i * rows_per_thread;
        int end_row = (i == num_threads - 1)? m - 1 : start_row + rows_per_thread - 1;

        pthread_create(&threads[i], NULL, sum_matrices, (void *) &start_row);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Resultant Matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}