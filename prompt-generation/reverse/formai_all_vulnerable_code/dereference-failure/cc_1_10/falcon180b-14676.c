//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define SEQUENCE_LENGTH 1000000

char *sequence = NULL;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int *result = NULL;

void *thread_func(void *arg) {
    int start = *(int *)arg;
    int end = start + SEQUENCE_LENGTH / NUM_THREADS;

    for (int i = start; i < end; i++) {
        pthread_mutex_lock(&mutex);
        sequence[i] = 'A';
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main() {
    sequence = (char *)malloc(SEQUENCE_LENGTH * sizeof(char));
    result = (int *)malloc(NUM_THREADS * sizeof(int));

    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        int *value = (int *)malloc(sizeof(int));
        *value = i * SEQUENCE_LENGTH / NUM_THREADS;
        pthread_create(&threads[i], NULL, thread_func, value);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Sequencing complete!\n");

    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        printf("%c", sequence[i]);
    }

    free(sequence);
    free(result);

    return 0;
}