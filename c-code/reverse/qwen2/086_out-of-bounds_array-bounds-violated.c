#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 5

typedef struct {
    int id;
    int* books;
} ThreadData;

void* thread_func(void* arg) {
    ThreadData* td = (ThreadData*)arg;
    int index = td->id * 2; // Vulnerability: Out-of-bounds access if id > MAX_THREADS/2
    printf("Thread %d reading book at index %d\n", td->id, index);
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    ThreadData td[MAX_THREADS];

    int num_threads = 6; // Intentionally set higher than MAX_THREADS to trigger vulnerability

    for (int i = 0; i < num_threads; i++) {
        td[i].id = i;
        td[i].books = malloc(sizeof(int) * 10); // Allocate memory for books
        pthread_create(&threads[i], NULL, thread_func, &td[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
        free(td[i].books); // Free allocated memory
    }

    return 0;
}
