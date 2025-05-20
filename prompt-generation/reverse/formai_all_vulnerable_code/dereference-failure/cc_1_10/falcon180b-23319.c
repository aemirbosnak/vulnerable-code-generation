//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

struct thread_data {
    int id;
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void *runner(void *param) {
    struct thread_data *data = (struct thread_data *) param;
    int i;

    for (i = 0; i < data->burst_time; i++) {
        printf("Thread %d is running...\n", data->id);
        sleep(1);
    }

    return NULL;
}

void schedule(struct thread_data threads[], int n) {
    int i, j, min_index;
    int completed_processes = 0;

    for (i = 0; i < n; i++) {
        threads[i].waiting_time = 0;
        threads[i].turnaround_time = 0;
    }

    while (completed_processes < n) {
        min_index = -1;
        for (i = 0; i < n; i++) {
            if (threads[i].waiting_time <= threads[min_index].waiting_time) {
                min_index = i;
            }
        }

        if (min_index == -1) {
            break;
        }

        pthread_join(threads[min_index].id, NULL);
        completed_processes++;

        for (j = 0; j < n; j++) {
            if (j == min_index) {
                continue;
            }

            threads[j].waiting_time += threads[min_index].burst_time;
        }
    }
}

int main() {
    pthread_t threads[NUM_THREADS];
    struct thread_data data[NUM_THREADS];

    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        data[i].id = i;
        data[i].priority = i;
        data[i].burst_time = 5 - i;
        data[i].waiting_time = 0;
        data[i].turnaround_time = 0;

        pthread_create(&threads[i], NULL, runner, (void *)&data[i]);
    }

    schedule(data, NUM_THREADS);

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}