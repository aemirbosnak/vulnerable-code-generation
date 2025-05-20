#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define TOTAL_PAGES 100

int library_pages[TOTAL_PAGES];
pthread_mutex_t mutex;

void* read_page(void* arg) {
    int thread_id = *(int*)arg;
    int start_page = (thread_id * TOTAL_PAGES / NUM_THREADS);
    int end_page = ((thread_id + 1) * TOTAL_PAGES / NUM_THREADS);

    for (int i = start_page; i < end_page; i++) {
        pthread_mutex_lock(&mutex);
        printf("Thread %d is reading page %d\n", thread_id, i);
        library_pages[i]++;
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, read_page, &thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}
