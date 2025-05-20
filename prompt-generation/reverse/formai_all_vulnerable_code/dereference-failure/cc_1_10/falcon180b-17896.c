//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* thread_func(void* arg) {
    int id = *(int*)arg;
    printf("Thread %d started.\n", id);

    pthread_mutex_lock(&lock);
    struct node* temp = head;
    while (temp!= NULL) {
        printf("Thread %d: %d\n", id, temp->data);
        temp = temp->next;
    }
    pthread_mutex_unlock(&lock);

    printf("Thread %d finished.\n", id);
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];

    head = (struct node*)malloc(sizeof(struct node));
    head->data = 1;
    head->next = NULL;

    int i;
    for (i = 0; i < MAX_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_func, (void*)&thread_ids[i]);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}