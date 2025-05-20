#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10
#define NUM_PAGES 5

int book[NUM_PAGES];
pthread_mutex_t mutexes[NUM_PAGES];

void* read_page(void* arg) {
    int thread_id = *(int*)arg;
    int page = rand() % NUM_PAGES;

    pthread_mutex_lock(&mutexes[page]);
    printf("Thread %d is reading page %d\n", thread_id, page);
    // Simulate reading time
    sleep(1);
    printf("Thread %d finished reading page %d\n", thread_id, page);
    pthread_mutex_unlock(&mutexes[page]);

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];

    for (int i = 0; i < NUM_PAGES; i++) {
        pthread_mutex_init(&mutexes[i], NULL);
    }

    srand(time(NULL));

    for (int i = 0; i < NUM_THREADS; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, read_page, &ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < NUM_PAGES; i++) {
        pthread_mutex_destroy(&mutexes[i]);
    }

    return 0;
}
