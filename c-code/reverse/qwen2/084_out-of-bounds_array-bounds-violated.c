#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define BOOKS 3

typedef struct {
    int id;
    char title[256];
} Book;

Book books[BOOKS] = {{1, "Book One"}, {2, "Book Two"}, {3, "Book Three"}};

void* read_book(void* arg) {
    int thread_id = *(int*)arg;
    if (thread_id >= 0 && thread_id < BOOKS) {
        printf("Thread %d reading: %s\n", thread_id, books[thread_id].title);
    } else {
        printf("Thread %d attempted to access invalid book index!\n", thread_id);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, read_book, &ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
