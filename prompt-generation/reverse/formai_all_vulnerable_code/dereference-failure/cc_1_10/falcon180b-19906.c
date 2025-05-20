//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define STACK_SIZE 1024

typedef struct {
    int id;
    void* (*function)(void*);
    void* arg;
} thread_data_t;

void* thread_function(void* data) {
    thread_data_t* thread_data = (thread_data_t*)data;
    void* result = NULL;

    result = thread_data->function(thread_data->arg);

    pthread_exit(result);
}

int create_thread(pthread_t* thread_id, void* (*function)(void*), void* arg) {
    int ret;
    thread_data_t thread_data;

    thread_data.id = *thread_id;
    thread_data.function = function;
    thread_data.arg = arg;

    ret = pthread_create(thread_id, NULL, thread_function, &thread_data);

    if(ret!= 0) {
        printf("Error: unable to create thread, %d\n", ret);
        return ret;
    }

    return 0;
}

int join_thread(pthread_t thread_id, void** result) {
    int ret;

    ret = pthread_join(thread_id, result);

    if(ret!= 0) {
        printf("Error: unable to join thread, %d\n", ret);
        return ret;
    }

    return 0;
}

int main() {
    int i;
    pthread_t threads[MAX_THREADS];
    void* result[MAX_THREADS];
    int ret;

    for(i = 0; i < MAX_THREADS; i++) {
        ret = create_thread(&threads[i], &thread_function, &i);

        if(ret!= 0) {
            return ret;
        }
    }

    for(i = 0; i < MAX_THREADS; i++) {
        ret = join_thread(threads[i], &result[i]);

        if(ret!= 0) {
            return ret;
        }

        printf("Thread %d returned: %d\n", i, *(int*)result[i]);
    }

    return 0;
}