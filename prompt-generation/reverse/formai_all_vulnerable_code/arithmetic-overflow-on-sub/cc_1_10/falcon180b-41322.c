//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 5
#define STACK_SIZE (1024 * 1024)

void *thread_func(void *arg) {
    int id = *(int *) arg;
    printf("Thread %d started\n", id);
    sleep(1);
    printf("Thread %d finished\n", id);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS] = {1, 2, 3, 4, 5};
    int rc;
    struct timespec start_time, end_time;

    rc = clock_gettime(CLOCK_REALTIME, &start_time);
    if (rc!= 0) {
        perror("clock_gettime");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, thread_func, &thread_ids[i]);
        if (rc!= 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc!= 0) {
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
    }

    rc = clock_gettime(CLOCK_REALTIME, &end_time);
    if (rc!= 0) {
        perror("clock_gettime");
        exit(EXIT_FAILURE);
    }

    double elapsed_time = (end_time.tv_sec - start_time.tv_sec) +
        (end_time.tv_nsec - start_time.tv_nsec) / 1000000000.0;

    printf("Elapsed time: %.6f seconds\n", elapsed_time);

    return 0;
}