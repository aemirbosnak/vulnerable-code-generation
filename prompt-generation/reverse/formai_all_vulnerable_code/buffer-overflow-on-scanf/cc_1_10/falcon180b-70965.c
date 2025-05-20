//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define STACK_SIZE 4096

typedef struct {
    int id;
    void *(*func)(void *);
    void *arg;
} thread_data_t;

void *thread_func(void *data) {
    thread_data_t *tdata = (thread_data_t *)data;
    tdata->func(tdata->arg);
    return NULL;
}

int create_thread(thread_data_t *tdata) {
    pthread_t thread_id;
    int ret = pthread_create(&thread_id, NULL, thread_func, tdata);
    if (ret!= 0) {
        printf("Error: Failed to create thread, return code: %d\n", ret);
        return -1;
    }
    tdata->id = thread_id;
    return 0;
}

int join_thread(thread_data_t *tdata) {
    int ret = pthread_join(tdata->id, NULL);
    if (ret!= 0) {
        printf("Error: Failed to join thread, return code: %d\n", ret);
        return -1;
    }
    return 0;
}

int main() {
    thread_data_t threads[MAX_THREADS];
    int num_threads = 0;

    while (num_threads < MAX_THREADS) {
        printf("Enter thread ID (0 to exit): ");
        int id;
        scanf("%d", &id);
        if (id == 0) {
            break;
        }
        printf("Enter thread function: ");
        void *(*func)(void *) = (void *(*)(void *))malloc(sizeof(void *(*)(void *)));
        scanf("%p", &func);
        printf("Enter thread argument: ");
        void *arg = malloc(sizeof(void *));
        scanf("%p", &arg);
        threads[num_threads].id = -1;
        threads[num_threads].func = func;
        threads[num_threads].arg = arg;
        num_threads++;
    }

    for (int i = 0; i < num_threads; i++) {
        if (create_thread(&threads[i]) == -1) {
            return -1;
        }
    }

    for (int i = 0; i < num_threads; i++) {
        if (join_thread(&threads[i]) == -1) {
            return -1;
        }
    }

    return 0;
}