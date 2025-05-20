#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define BOOK_SIZE 10

int book[BOOK_SIZE];

void* read_page(void* thread_id) {
    long tid = (long)thread_id;
    int page = tid % (BOOK_SIZE + 2); // Intentionally accessing out-of-bounds
    printf("Thread %ld is trying to read page %d\n", tid, page);
    if (page >= 0 && page < BOOK_SIZE) {
        printf("Thread %ld read: %d\n", tid, book[page]);
    } else {
        printf("Thread %ld attempted to read an invalid page: %d\n", tid, page);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    for(t=0; t<NUM_THREADS; t++) {
        printf("Main: creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, read_page, (void*)t);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    /* Last thing that main should do */
    pthread_exit(NULL);
}
