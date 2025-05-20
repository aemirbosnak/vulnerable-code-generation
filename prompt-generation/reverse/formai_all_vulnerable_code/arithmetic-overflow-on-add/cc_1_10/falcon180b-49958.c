//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 10
#define THREAD_STACK_SIZE 4096
#define NUM_TRIALS 1000000

int shared_data[NUM_THREADS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_function(void *param) {
    int thread_id = *(int *) param;
    int count = 0;

    srand(time(NULL) + thread_id);

    for (int i = 0; i < NUM_TRIALS; i++) {
        int rand_num = rand() % 100;
        if (rand_num == 42) {
            count++;
        }
    }

    pthread_mutex_lock(&mutex);
    shared_data[thread_id] = count;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    int rc;

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        rc = pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    int total_count = 0;

    for (int i = 0; i < NUM_THREADS; i++) {
        total_count += shared_data[i];
    }

    double probability = ((double) total_count / (NUM_TRIALS * NUM_THREADS)) * 100;

    printf("Alien invasion probability: %.2f%%\n", probability);

    return 0;
}