//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int id;
    void *(*func)(void *);
    void *arg;
} thread_data_t;

void *thread_func(void *arg) {
    thread_data_t *data = arg;
    printf("Thread %d started\n", data->id);
    data->func(data->arg);
    printf("Thread %d finished\n", data->id);
    return NULL;
}

int create_threads(int num_threads, void *(*func)(void *), void *arg) {
    pthread_t threads[num_threads];
    thread_data_t data[num_threads];

    for (int i = 0; i < num_threads; i++) {
        data[i].id = i + 1;
        data[i].func = func;
        data[i].arg = arg;

        if (pthread_create(&threads[i], NULL, thread_func, &data[i])!= 0) {
            printf("Error creating thread %d\n", i + 1);
            return -1;
        }
    }

    for (int i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], NULL)!= 0) {
            printf("Error joining thread %d\n", i + 1);
            return -1;
        }
    }

    return 0;
}

int main() {
    int num_threads = 5;
    void *(*func)(void *) = &thread_func;
    void *arg = NULL;

    if (create_threads(num_threads, func, arg)!= 0) {
        printf("Error creating threads\n");
        return -1;
    }

    return 0;
}