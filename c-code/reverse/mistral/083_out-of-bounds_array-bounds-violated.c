#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

#define NUM_THREADS 5
#define NUM_PAGES 100

sem_t mutex;
int pages[NUM_PAGES];

void *reader(void *arg) {
    int id = (int)arg;
    int page = id * (NUM_PAGES / NUM_THREADS);

    for (int i = 0; i < NUM_PAGES; ++i) {
        sem_wait(&mutex);
        pages[page]++;
        sem_post(&mutex);
        printf("Thread %d read page %d: %d\n", id, page, pages[page]);
        sleep(rand() % 5);
    }

    return NULL;
}

int main() {
    sem_init(&mutex, 0, 1);

    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_create(&threads[i], NULL, reader, (void *)i);
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&mutex);

    return 0;
}
