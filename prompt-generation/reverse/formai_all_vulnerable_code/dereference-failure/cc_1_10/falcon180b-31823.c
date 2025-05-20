//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 10
#define STACK_SIZE 4096

void *thread_func(void *param);

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    int i;
    time_t start_time, end_time;

    srand(time(NULL));

    start_time = time(NULL);

    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, thread_func, (void *)i);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    end_time = time(NULL);

    printf("Time taken: %ld seconds\n", end_time - start_time);

    return 0;
}

void *thread_func(void *param) {
    int thread_id = *(int *)param;
    int i;

    for (i = 0; i < 10; i++) {
        printf("Thread %d: %d\n", thread_id, rand() % 100);
        sleep(1);
    }

    return NULL;
}