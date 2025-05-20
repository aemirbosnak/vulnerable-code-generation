#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 10

void *worker(void *arg) {
    int *ptr = (int *) malloc(sizeof(int));
    *ptr = 42;
    printf("Thread %ld: Stored value at %p is %d\n", pthread_self(), ptr, *ptr);
    free(ptr);
    printf("Thread %ld: Deleted value at %p\n", pthread_self(), ptr);
    // Dereference the freed memory
    printf("Thread %ld: Tried to access value at %p\n", pthread_self(), ptr);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_create(&threads[i], NULL, worker, NULL);
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
