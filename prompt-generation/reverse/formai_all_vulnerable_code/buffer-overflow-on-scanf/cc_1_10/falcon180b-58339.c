//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define STACK_SIZE (1024 * 1024)

typedef struct {
    int id;
    int num;
} thread_data_t;

void *thread_func(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    int num1 = 0, num2 = 1, next_term;

    for (int i = 0; i < data->num; i++) {
        printf("Thread %d: %d ", data->id, num1);
        next_term = num1 + num2;
        num1 = num2;
        num2 = next_term;
    }

    pthread_exit(0);
}

int main() {
    int num_threads, num_terms;

    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    printf("Enter the number of terms to print: ");
    scanf("%d", &num_terms);

    pthread_t threads[MAX_THREADS];
    thread_data_t data[MAX_THREADS];

    for (int i = 0; i < num_threads; i++) {
        data[i].id = i + 1;
        data[i].num = num_terms;
        pthread_create(&threads[i], NULL, thread_func, (void *) &data[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}