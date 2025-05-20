//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 5
#define PRIORITY_RANGE 10
#define MAX_PRIORITY 10
#define MIN_PRIORITY 1

int thread_id[NUM_THREADS];
int thread_priority[NUM_THREADS];

void* thread_function(void* arg) {
    int i = *((int*) arg);
    int priority = thread_priority[i];
    printf("Thread %d started with priority %d\n", i, priority);
    sleep(1);
    printf("Thread %d finished\n", i);
    return NULL;
}

int compare_priority(const void* a, const void* b) {
    int p1 = *(int*)a;
    int p2 = *(int*)b;
    return (p1 - p2);
}

int main() {
    pthread_t thread_id[NUM_THREADS];
    int priority[NUM_THREADS];
    int i;

    srand(time(NULL));
    for (i = 0; i < NUM_THREADS; i++) {
        thread_id[i] = i;
        priority[i] = rand() % PRIORITY_RANGE + MIN_PRIORITY;
    }

    qsort(priority, NUM_THREADS, sizeof(int), compare_priority);
    qsort(thread_id, NUM_THREADS, sizeof(pthread_t), compare_priority);

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&thread_id[i], NULL, thread_function, &thread_id[i]);
        printf("Thread %d created with priority %d\n", i, priority[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(thread_id[i], NULL);
    }

    return 0;
}