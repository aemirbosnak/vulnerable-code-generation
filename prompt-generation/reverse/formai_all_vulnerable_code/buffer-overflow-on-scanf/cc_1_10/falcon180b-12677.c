//Falcon-180B DATASET v1.0 Category: Recursive ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>

#define MAX_THREADS 10

typedef struct thread_data {
    int thread_id;
    int count;
    int max_count;
} thread_data_t;

void *count_thread(void *arg) {
    thread_data_t *thread_data = (thread_data_t *) arg;
    int i;

    for (i = 0; i < thread_data->max_count; i++) {
        printf("Thread %d counted %d\n", thread_data->thread_id, i);
        fflush(stdout);
        usleep(100000);
    }

    return NULL;
}

int create_threads(int num_threads, int max_count) {
    pthread_t threads[MAX_THREADS];
    thread_data_t thread_data[MAX_THREADS];
    int i;

    for (i = 0; i < num_threads; i++) {
        thread_data[i].thread_id = i + 1;
        thread_data[i].count = 0;
        thread_data[i].max_count = max_count;

        if (pthread_create(&threads[i], NULL, count_thread, (void *) &thread_data[i])!= 0) {
            printf("Error creating thread %d\n", i + 1);
            return -1;
        }
    }

    for (i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], NULL)!= 0) {
            printf("Error joining thread %d\n", i + 1);
            return -1;
        }
    }

    return 0;
}

int main() {
    int num_threads, max_count;

    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    printf("Enter maximum count for each thread: ");
    scanf("%d", &max_count);

    if (create_threads(num_threads, max_count)!= 0) {
        printf("Error creating threads\n");
        return 1;
    }

    return 0;
}