#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define BOOK_SIZE 100

int book[BOOK_SIZE];
pthread_mutex_t mutex;

void* read_book(void* arg) {
    int thread_id = *(int*)arg;
    int start = thread_id * (BOOK_SIZE / MAX_THREADS);
    int end = start + (BOOK_SIZE / MAX_THREADS);

    pthread_mutex_lock(&mutex);
    for (int i = start; i < end; i++) {
        if (book[i] > 100 || book[i] < 0) {
            printf("Thread %d: Out of bounds access at index %d\n", thread_id, i);
        }
    }
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_threads>\n", argv[0]);
        return 1;
    }

    int num_threads = atoi(argv[1]);
    if (num_threads > MAX_THREADS) {
        fprintf(stderr, "Number of threads cannot exceed %d\n", MAX_THREADS);
        return 1;
    }

    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];

    pthread_mutex_init(&mutex, NULL);

    // Initialize book with random values
    srand(time(NULL));
    for (int i = 0; i < BOOK_SIZE; i++) {
        book[i] = rand() % 201 - 100; // Random value between -100 and 100
    }

    for (int i = 0; i < num_threads; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, read_book, &thread_ids[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}
