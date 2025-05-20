#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define BOOK_TITLE_SIZE 100
#define THREAD_COUNT 5

typedef struct {
    char title[BOOK_TITLE_SIZE];
    int id;
} Book;

Book books[MAX_BOOKS];
pthread_t threads[THREAD_COUNT];

void *print_book(void *arg) {
    int thread_id = (int)arg;
    printf("Thread %d: %s\n", thread_id, books[thread_id].title);
    return NULL;
}

int main() {
    int i, j;
    for (i = 0; i < THREAD_COUNT; ++i) {
        snprintf(books[i].title, BOOK_TITLE_SIZE, "Book %d", i);
        books[i].id = i;
    }

    for (i = 0; i < THREAD_COUNT; ++i) {
        pthread_create(&threads[i], NULL, print_book, (void *)i);
    }

    for (i = 0; i < THREAD_COUNT; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Intentionally accessing memory beyond allocated array bounds
    for (j = THREAD_COUNT; j < 2 * THREAD_COUNT; ++j) {
        printf("Book %d: %s\n", j, books[j].title);
    }

    return 0;
}
