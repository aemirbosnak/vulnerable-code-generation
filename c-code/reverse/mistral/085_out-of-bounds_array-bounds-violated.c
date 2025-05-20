#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_THREADS 100
#define BOOK_SIZE 100

typedef struct {
    char book[BOOK_SIZE];
    int reader_count;
    pthread_mutex_t lock;
} Book;

void* reader(void* arg) {
    int id = *(int*)arg;
    Book* book = (Book*)((char*)arg + sizeof(int));

    while (1) {
        pthread_mutex_lock(&book->lock);
        if (book->reader_count < MAX_THREADS) {
            printf("Thread %d: Start reading at position %d\n", id, book->reader_count);
            book->reader_count++;
        } else {
            printf("Thread %d: Cannot read, too many readers\n", id);
        }
        pthread_mutex_unlock(&book->lock);

        sleep(1);

        pthread_mutex_lock(&book->lock);
        if (--book->reader_count <= 0) {
            printf("Thread %d: Finished reading\n", id);
            break;
        }
        pthread_mutex_unlock(&book->lock);
    }

    return NULL;
}

int main() {
    Book book = {"The C Programming Language", 0};
    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; ++i) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, reader, &thread_ids[i]);
    }

    for (int i = 0; i < MAX_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
