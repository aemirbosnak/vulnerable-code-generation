//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_PRIORITY 100

typedef struct {
    int id;
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int start_time;
    int end_time;
} thread_t;

void *runner(void *param);

int main() {
    pthread_t threads[MAX_THREADS];
    thread_t thread_list[MAX_THREADS];
    int num_threads = 0;

    printf("Enter the number of threads (between 1 and %d): ", MAX_THREADS);
    scanf("%d", &num_threads);

    printf("Enter the thread IDs and priorities:\n");
    for (int i = 0; i < num_threads; i++) {
        int id;
        int priority;
        scanf("%d %d", &id, &priority);
        thread_list[i].id = id;
        thread_list[i].priority = priority;
        thread_list[i].burst_time = 0;
        thread_list[i].waiting_time = 0;
        thread_list[i].turnaround_time = 0;
        thread_list[i].start_time = 0;
        thread_list[i].end_time = 0;
    }

    printf("Enter the burst times for each thread (in milliseconds):\n");
    for (int i = 0; i < num_threads; i++) {
        scanf("%d", &thread_list[i].burst_time);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, runner, &thread_list[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *runner(void *param) {
    thread_t *thread = param;

    int start_time = 0;
    int end_time = 0;

    while (start_time == 0) {
        usleep(1000); // wait for 1ms
    }

    start_time += thread->burst_time;
    end_time = start_time;

    printf("Thread %d started at %dms and ended at %dms\n", thread->id, start_time, end_time);

    thread->start_time = start_time;
    thread->end_time = end_time;

    return NULL;
}