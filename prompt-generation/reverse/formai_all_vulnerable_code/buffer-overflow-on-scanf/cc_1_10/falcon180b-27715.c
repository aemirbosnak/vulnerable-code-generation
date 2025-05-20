//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_ROWS 100

int rows = 0;
int cols = 0;
int num_threads = 0;
int thread_id = 0;

void *print_pattern(void *arg) {
    int start_row = rows * thread_id / num_threads;
    int end_row = (thread_id == num_threads - 1)? rows : rows * (thread_id + 1) / num_threads;

    for (int i = start_row; i < end_row; i++) {
        for (int j = 0; j < cols; j++) {
            printf("*");
        }
        printf("\n");
    }

    return NULL;
}

int main() {
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    pthread_t threads[MAX_THREADS];
    int ids[MAX_THREADS];

    for (int i = 0; i < num_threads; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, print_pattern, (void *)&ids[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}