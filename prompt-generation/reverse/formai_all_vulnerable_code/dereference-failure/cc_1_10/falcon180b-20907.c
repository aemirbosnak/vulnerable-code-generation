//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int id;
    char *name;
} thread_data;

void *thread_func(void *arg) {
    thread_data *data = (thread_data *) arg;

    printf("Thread %d started: %s\n", data->id, data->name);

    // Do some work here

    printf("Thread %d finished\n", data->id);

    return NULL;
}

int main() {
    int num_threads = 5;
    pthread_t threads[num_threads];
    thread_data data[num_threads];

    int i;
    for (i = 0; i < num_threads; i++) {
        data[i].id = i + 1;
        data[i].name = (char *) malloc(10);
        sprintf(data[i].name, "Thread %d", i + 1);

        int rc = pthread_create(&threads[i], NULL, thread_func, (void *) &data[i]);
        if (rc) {
            printf("Error: Unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    for (i = 0; i < num_threads; i++) {
        void *retval;
        int rc = pthread_join(threads[i], &retval);
        if (rc) {
            printf("Error: Unable to join thread, %d\n", rc);
            exit(-1);
        }
    }

    return 0;
}