//Falcon-180B DATASET v1.0 Category: Error handling ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>

#define MAX_THREADS 10
#define STACK_SIZE 1024

typedef struct {
    int id;
    pthread_t thread;
} thread_t;

void *thread_func(void *arg) {
    int id = *(int *) arg;
    printf("Thread %d started\n", id);
    sleep(1);
    printf("Thread %d finished\n", id);
    return NULL;
}

void create_threads(int num_threads) {
    thread_t threads[MAX_THREADS];
    int i;

    for (i = 0; i < num_threads; i++) {
        threads[i].id = i + 1;
        if (pthread_create(&threads[i].thread, NULL, thread_func, &threads[i].id)!= 0) {
            printf("Error creating thread %d: %s\n", threads[i].id, strerror(errno));
            exit(1);
        }
        printf("Thread %d created\n", threads[i].id);
    }

    for (i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i].thread, NULL)!= 0) {
            printf("Error joining thread %d: %s\n", threads[i].id, strerror(errno));
            exit(1);
        }
        printf("Thread %d joined\n", threads[i].id);
    }
}

int main() {
    int num_threads;

    printf("Enter number of threads (1-10): ");
    scanf("%d", &num_threads);

    if (num_threads < 1 || num_threads > MAX_THREADS) {
        printf("Invalid number of threads\n");
        exit(1);
    }

    create_threads(num_threads);

    return 0;
}