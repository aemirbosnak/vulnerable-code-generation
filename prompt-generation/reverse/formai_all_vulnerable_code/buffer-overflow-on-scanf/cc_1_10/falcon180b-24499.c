//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREADS 20
#define MAX_PRIORITY 10
#define MAX_TIME_QUANTA 100

int thread_count = 0;
int thread_id[MAX_THREADS];
int thread_priority[MAX_THREADS];
int thread_time_quanta[MAX_THREADS];

void *thread_function(void *param) {
    int i = *(int *) param;
    int time_quanta = thread_time_quanta[i];

    printf("Thread %d is running with priority %d and time quanta %d\n", i, thread_priority[i], time_quanta);

    for (int j = 0; j < time_quanta; j++) {
        printf("Thread %d is executing task %d\n", i, j);
        sleep(1);
    }

    return NULL;
}

int main() {
    int i;

    printf("Enter the number of threads (maximum %d): ", MAX_THREADS);
    scanf("%d", &i);

    if (i > MAX_THREADS) {
        printf("Invalid number of threads\n");
        exit(1);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        thread_id[i] = i;
        thread_priority[i] = rand() % MAX_PRIORITY;
        thread_time_quanta[i] = rand() % MAX_TIME_QUANTA + 1;
    }

    pthread_t threads[MAX_THREADS];

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_function, (void *) &i);
        printf("Thread %d created with priority %d and time quanta %d\n", i, thread_priority[i], thread_time_quanta[i]);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}