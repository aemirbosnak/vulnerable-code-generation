#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NUM_THREADS 10
#define PAGE_SIZE 100
#define BOOK_SIZE (PAGE_SIZE * NUM_THREADS)

char book[BOOK_SIZE];
pthread_mutex_t lock;

void *reader(void *arg) {
    int id = (int)arg;
    int page = id % (BOOK_SIZE / NUM_THREADS);
    int lines_per_page = PAGE_SIZE / 10;

    for (int line = 0; line < lines_per_page; ++line) {
        pthread_mutex_lock(&lock);
        printf("Thread %d reading line %d on page %d: %c\n", id, line, page, book[page * lines_per_page + line]);
        pthread_mutex_unlock(&lock);
        usleep(100000); // Simulate reading time

        // Intentionally out-of-bounds access
        if (line == lines_per_page - 1) {
            printf("Thread %d trying to read beyond the page: %c\n", id, book[(page + 1) * lines_per_page]);
        }
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    memset(book, 'A' + (rand() % 26), BOOK_SIZE);

    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_create(&threads[i], NULL, reader, (void *)i);
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);

    return 0;
}
