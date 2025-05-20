#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define NUM_PAGES 10

int pages[NUM_THREADS];
pthread_mutex_t mutex;

void* read_book(void* arg) {
    int thread_id = *(int*)arg;
    pthread_mutex_lock(&mutex);
    printf("Thread %d is reading page %d\n", thread_id, pages[thread_id]);
    pages[thread_id]++;
    if (pages[thread_id] >= NUM_PAGES) {
        pages[thread_id] = 0;
    }
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < NUM_THREADS; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, read_book, &ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}
