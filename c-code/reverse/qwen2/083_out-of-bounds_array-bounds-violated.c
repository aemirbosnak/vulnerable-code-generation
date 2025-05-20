#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define NUM_PAGES 10

int book[NUM_PAGES] = {0};
pthread_mutex_t mutex;

void* read_book(void* arg) {
    int thread_id = *(int*)arg;
    int start_page = (thread_id * NUM_PAGES / NUM_THREADS);
    int end_page = ((thread_id + 1) * NUM_PAGES / NUM_THREADS);

    for (int i = start_page; i < end_page; i++) {
        pthread_mutex_lock(&mutex);
        book[i]++;
        printf("Thread %d read page %d\n", thread_id, i);
        pthread_mutex_unlock(&mutex);
    }

    free(arg);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        if (pthread_create(&threads[i], NULL, read_book, &thread_ids[i]) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Failed to join thread");
            exit(EXIT_FAILURE);
        }
    }

    pthread_mutex_destroy(&mutex);

    printf("Final state of the book: ");
    for (int i = 0; i < NUM_PAGES; i++) {
        printf("%d ", book[i]);
    }
    printf("\n");

    return 0;
}
