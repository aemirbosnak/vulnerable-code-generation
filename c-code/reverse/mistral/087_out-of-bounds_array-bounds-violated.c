#include <string.h>
#include <stdint.h>
#include <stddef.h>

#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

#define NUM_THREADS 10
#define PAGE_SIZE 4096
#define BOOK_SIZE (NUM_THREADS * PAGE_SIZE)

char *book;
pthread_mutex_t lock;

void *reader(void *arg) {
    int id = *(int *)arg;
    int page_index = id % NUM_THREADS;

    for (int i = 0; i < 10; ++i) {
        pthread_mutex_lock(&lock);
        printf("Thread %d reading page %d\n", id, page_index);
        book[page_index] = 'R';
        sleep(rand() % 5);
        book[page_index] = book[page_index]; // No update, just reading
        pthread_mutex_unlock(&lock);
        sleep(1);
    }

    return NULL;
}

int main() {
    srand(time(NULL));

    book = mmap(NULL, BOOK_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (book == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; ++i) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, reader, &ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    munmap(book, BOOK_SIZE);

    return 0;
}
