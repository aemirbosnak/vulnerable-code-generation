//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 10

struct thread_data {
    int thread_id;
    int sum;
};

void *sum_thread(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    int i;

    for (i = 0; i < 100000; i++) {
        data->sum += i;
    }

    printf("Thread %d computed sum: %d\n", data->thread_id, data->sum);

    pthread_exit(0);
}

int main() {
    pthread_t threads[NUM_THREADS];
    struct thread_data data[NUM_THREADS];
    int i, rc;
    void *status;

    srand(time(NULL));

    for (i = 0; i < NUM_THREADS; i++) {
        data[i].thread_id = i;
        rc = pthread_create(&threads[i], NULL, sum_thread, &data[i]);

        if (rc!= 0) {
            fprintf(stderr, "Error creating thread: %d\n", rc);
            exit(1);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], &status);

        if (rc!= 0) {
            fprintf(stderr, "Error joining thread: %d\n", rc);
            exit(1);
        }
    }

    return 0;
}