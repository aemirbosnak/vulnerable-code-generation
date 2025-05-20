//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define STACK_SIZE 1024

typedef struct thread_data {
    int id;
    void* (*func)(void*);
    void* arg;
} thread_data_t;

void* thread_start(void* arg) {
    thread_data_t* data = (thread_data_t*) arg;
    data->func(data->arg);
    return NULL;
}

int create_thread(pthread_t* thread, void*(*start_routine)(void*), void* arg) {
    if (pthread_create(thread, NULL, start_routine, arg)!= 0) {
        return -1;
    }
    return 0;
}

int join_thread(pthread_t thread) {
    if (pthread_join(thread, NULL)!= 0) {
        return -1;
    }
    return 0;
}

int main() {
    pthread_t threads[MAX_THREADS];
    thread_data_t data[MAX_THREADS];

    int i;
    for (i = 0; i < MAX_THREADS; i++) {
        data[i].id = i;
        data[i].func = thread_start;
        data[i].arg = (void*) i;

        int ret = create_thread(&threads[i], thread_start, &data[i]);
        if (ret!= 0) {
            printf("Error creating thread %d\n", i);
            exit(1);
        }
    }

    for (i = 0; i < MAX_THREADS; i++) {
        int ret = join_thread(threads[i]);
        if (ret!= 0) {
            printf("Error joining thread %d\n", i);
            exit(1);
        }
    }

    return 0;
}