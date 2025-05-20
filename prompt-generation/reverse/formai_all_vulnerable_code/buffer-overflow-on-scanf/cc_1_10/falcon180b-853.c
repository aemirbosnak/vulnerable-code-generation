//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_BOOKS 1000
#define MAX_THREADS 10

typedef struct {
    char title[100];
    char author[100];
    int year;
} Book;

Book library[MAX_BOOKS];
int num_books = 0;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void add_book(char* title, char* author, int year) {
    pthread_mutex_lock(&lock);
    if (num_books < MAX_BOOKS) {
        strcpy(library[num_books].title, title);
        strcpy(library[num_books].author, author);
        library[num_books].year = year;
        num_books++;
    }
    pthread_mutex_unlock(&lock);
}

void search_book(char* title) {
    pthread_mutex_lock(&lock);
    int i;
    for (i = 0; i < num_books; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("Book found: %s by %s (%d)\n", library[i].title, library[i].author, library[i].year);
        }
    }
    pthread_mutex_unlock(&lock);
}

void* thread_func(void* arg) {
    char* operation = (char*) arg;
    if (strcmp(operation, "add") == 0) {
        char title[100];
        char author[100];
        int year;
        scanf("%s %s %d", title, author, &year);
        add_book(title, author, year);
    } else if (strcmp(operation, "search") == 0) {
        char title[100];
        scanf("%s", title);
        search_book(title);
    }
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int i;
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void*) "add");
    }
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void*) "search");
    }
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}