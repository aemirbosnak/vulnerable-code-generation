//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define a structure for thread data
struct thread_data {
    int id;
    void *(*func)(void *);
    void *arg;
};

// Function to be executed by each thread
void *thread_func(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    printf("Thread %d started\n", data->id);
    data->func(data->arg);
    printf("Thread %d finished\n", data->id);
    return NULL;
}

// Create a new thread
int create_thread(int id, void *(*func)(void *), void *arg) {
    pthread_t thread_id;
    struct thread_data *data = (struct thread_data *) malloc(sizeof(struct thread_data));
    if (data == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }
    data->id = id;
    data->func = func;
    data->arg = arg;
    if (pthread_create(&thread_id, NULL, thread_func, data)!= 0) {
        printf("Thread creation failed\n");
        free(data);
        return -1;
    }
    return 0;
}

// Join all threads
void join_threads() {
    pthread_t thread_id;
    while (pthread_join(thread_id, NULL)!= 0) {
        printf("Thread join failed\n");
    }
}

int main() {
    create_thread(1, &thread_func, NULL);
    create_thread(2, &thread_func, NULL);
    create_thread(3, &thread_func, NULL);
    join_threads();
    return 0;
}