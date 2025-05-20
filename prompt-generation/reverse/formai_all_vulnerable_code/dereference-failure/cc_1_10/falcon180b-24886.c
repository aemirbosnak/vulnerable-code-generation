//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10

typedef struct {
    int id;
    char *name;
    void *(*func)(void *arg);
    void *arg;
} thread_data_t;

void *thread_func(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    printf("Thread %d (%s) started\n", data->id, data->name);
    data->func(data->arg);
    printf("Thread %d (%s) finished\n", data->id, data->name);
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int i, max_threads = 0;
    thread_data_t *thread_data = (thread_data_t *) malloc(MAX_THREADS * sizeof(thread_data_t));
    char *names[] = {"Thread 1", "Thread 2", "Thread 3", "Thread 4", "Thread 5", "Thread 6", "Thread 7", "Thread 8", "Thread 9", "Thread 10"};
    void (*funcs[MAX_THREADS])(void *) = {thread_func, thread_func, thread_func, thread_func, thread_func, thread_func, thread_func, thread_func, thread_func, thread_func};
    void *args[MAX_THREADS] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

    for (i = 0; i < MAX_THREADS; ++i) {
        thread_data[i].id = i + 1;
        thread_data[i].name = names[i];
        thread_data[i].func = funcs[i];
        thread_data[i].arg = args[i];
        if (pthread_create(&threads[i], NULL, thread_func, &thread_data[i])!= 0) {
            printf("Error creating thread %d\n", i + 1);
            exit(1);
        }
        ++max_threads;
    }

    for (i = 0; i < max_threads; ++i) {
        if (pthread_join(threads[i], NULL)!= 0) {
            printf("Error joining thread %d\n", i + 1);
            exit(1);
        }
    }

    free(thread_data);
    return 0;
}