#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define NUM_BOOKS 5
#define PAGES_PER_BOOK 20

int books[NUM_BOOKS][PAGES_PER_BOOK];

void* read_page(void* arg) {
    int thread_id = *(int*)arg;
    int book_id = rand() % NUM_BOOKS;
    int page_id = rand() % (PAGES_PER_BOOK + 1); // Intentional out-of-bounds access

    printf("Thread %d attempting to read page %d of book %d\n", thread_id, page_id, book_id);
    if (page_id >= PAGES_PER_BOOK) {
        printf("Error: Out-of-bounds access by thread %d\n", thread_id);
    } else {
        printf("Thread %d successfully read page %d of book %d\n", thread_id, page_id, book_id);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    srand(time(NULL));

    if (NUM_THREADS <= 0 || NUM_BOOKS <= 0 || PAGES_PER_BOOK <= 0) {
        fprintf(stderr, "Invalid number of threads, books, or pages per book.\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        if (pthread_create(&threads[i], NULL, read_page, &thread_ids[i]) != 0) {
            perror("Failed to create thread");
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return EXIT_SUCCESS;
}
