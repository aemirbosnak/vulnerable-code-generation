//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define STACK_SIZE 1024

typedef struct {
    int thread_id;
    int num_terms;
    int start_index;
} thread_data_t;

void *print_fibonacci_sequence(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    int i, j, k;

    for (i = 0; i < data->num_terms; i++) {
        printf("Thread %d: ", data->thread_id);
        for (j = 0; j < i; j++) {
            printf("%d ", 0);
        }
        for (k = 0; k < data->start_index - 1; k++) {
            printf("%d ", 1);
        }
        printf("\n");
    }

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int i, num_threads, num_terms;
    thread_data_t data[MAX_THREADS];

    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    printf("Enter the number of terms for each thread: ");
    scanf("%d", &num_terms);

    for (i = 0; i < num_threads; i++) {
        data[i].thread_id = i + 1;
        data[i].num_terms = num_terms;
        data[i].start_index = i * num_terms;

        pthread_create(&threads[i], NULL, print_fibonacci_sequence, &data[i]);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}