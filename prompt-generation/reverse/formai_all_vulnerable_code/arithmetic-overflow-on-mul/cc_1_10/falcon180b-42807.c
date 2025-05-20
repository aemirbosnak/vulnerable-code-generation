//Falcon-180B DATASET v1.0 Category: Educational ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 10
#define MAX_NUM 1000000

int shared_data[MAX_NUM];
int num_threads = NUM_THREADS;
int num_operations = 0;
int done = 0;

void *thread_func(void *arg) {
    int i, j, k;
    int thread_id = *(int *) arg;

    for (i = thread_id * MAX_NUM / num_threads; i < (thread_id + 1) * MAX_NUM / num_threads; i++) {
        for (j = 0; j < MAX_NUM; j++) {
            shared_data[i * MAX_NUM + j] = i * j;
        }
    }

    for (k = 0; k < MAX_NUM; k++) {
        shared_data[k] += 1;
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i;
    struct timespec start_time, end_time;

    srand(time(NULL));

    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *) &i);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    clock_gettime(CLOCK_REALTIME, &start_time);
    for (i = 0; i < MAX_NUM; i++) {
        shared_data[i] *= 2;
    }
    clock_gettime(CLOCK_REALTIME, &end_time);

    printf("Elapsed time: %ld.%09ld seconds\n", end_time.tv_sec - start_time.tv_sec, end_time.tv_nsec - start_time.tv_nsec);

    return 0;
}