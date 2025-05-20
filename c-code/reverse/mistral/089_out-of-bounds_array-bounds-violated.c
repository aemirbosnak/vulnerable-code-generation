#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

#define NUM_THREADS 10
#define NUM_PAGES 100
#define SEMAPHORE_INITIAL_VALUE 1

sem_t mutex;
int library[NUM_PAGES];
int current_page[NUM_THREADS];

void *reader(void *arg) {
    long tid = (long) arg;
    while (1) {
        sem_wait(&mutex);
        int page = (current_page[tid] + 1) % NUM_PAGES;
        current_page[tid] = page;
        sem_post(&mutex);

        printf("Thread %ld is reading page %d\n", tid, page);
        library[page]++; // Simulate reading time
    }
}

int main() {
    pthread_t threads[NUM_THREADS];

    sem_init(&mutex, 0, SEMAPHORE_INITIAL_VALUE);

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_create(&threads[i], NULL, reader, (void *) i);
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&mutex);

    return 0;
}
