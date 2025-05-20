#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_BOOKS 5
#define NUM_PAGES 100
#define NUM_USERS 10

pthread_mutex_t page_lock[NUM_BOOKS];
int users[NUM_USERS];
int pages[NUM_BOOKS][NUM_PAGES];

void *reader(void *arg) {
    int book = rand() % NUM_BOOKS;
    int page = 0;

    while (page < NUM_PAGES) {
        pthread_mutex_lock(&page_lock[book]);
        page++;
        users[*(int*)arg] = page;
        printf("User %d is reading page %d of book %d\n", *(int*)arg, page, book);
        pthread_mutex_unlock(&page_lock[book]);

        sleep(rand() % 5); // Simulate reading time
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_USERS];
    int ids[NUM_USERS];

    for (int i = 0; i < NUM_BOOKS; ++i)
        pthread_mutex_init(&page_lock[i], NULL);

    for (int i = 0; i < NUM_USERS; ++i) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, reader, &ids[i]);
    }

    for (int i = 0; i < NUM_USERS; ++i)
        pthread_join(threads[i], NULL);

    for (int i = 0; i < NUM_BOOKS; ++i)
        pthread_mutex_destroy(&page_lock[i]);

    return 0;
}
