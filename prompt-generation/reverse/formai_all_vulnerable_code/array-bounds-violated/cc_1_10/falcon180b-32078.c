//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_THREADS 10
#define MAX_ITEMS 100

typedef struct {
    int thread_id;
    int item_id;
} thread_data;

int items[MAX_ITEMS];
int n_items = 0;

sem_t mutex;
sem_t empty;
sem_t full;

void init_semaphores() {
    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, 0);
    sem_init(&full, 0, MAX_THREADS - 1);
}

void push(int item) {
    sem_wait(&empty);
    sem_wait(&mutex);

    items[n_items++] = item;

    sem_post(&mutex);
    sem_post(&full);
}

int pop() {
    int item;
    sem_wait(&full);
    sem_wait(&mutex);

    item = items[--n_items];

    sem_post(&mutex);
    sem_post(&empty);

    return item;
}

void* thread_func(void* arg) {
    thread_data* data = arg;
    int sum = 0;

    for (int i = 0; i < 10; i++) {
        int item = pop();
        sum += item;
        push(item);
    }

    printf("Thread %d: Sum of items = %d\n", data->thread_id, sum);

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    thread_data data[MAX_THREADS];

    init_semaphores();

    for (int i = 0; i < MAX_THREADS; i++) {
        data[i].thread_id = i;
        data[i].item_id = i;
        pthread_create(&threads[i], NULL, thread_func, &data[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}