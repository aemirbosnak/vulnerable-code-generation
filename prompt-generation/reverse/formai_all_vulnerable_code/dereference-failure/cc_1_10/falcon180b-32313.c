//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define NUM_DISKS 6
#define MAX_THREADS 10
#define STACK_SIZE 100

typedef struct {
    int id;
    int from;
    int to;
    int top;
    int *stack;
} thread_data;

void *move_disk(void *arg) {
    thread_data *data = (thread_data *) arg;

    pthread_mutex_lock(&data->top);
    printf("Thread %d moving disk from %d to %d\n", data->id, data->from, data->to);
    pthread_mutex_unlock(&data->top);

    if (data->from!= data->to) {
        pthread_mutex_lock(&data->top);
        memmove(&data->stack[data->from], &data->stack[data->to],
                (NUM_DISKS - data->from) * sizeof(int));
        pthread_mutex_unlock(&data->top);
    }

    pthread_mutex_lock(&data->top);
    data->top--;
    pthread_mutex_unlock(&data->top);

    pthread_exit(0);
}

int main() {
    int i;
    pthread_t threads[MAX_THREADS];
    thread_data data[MAX_THREADS];

    for (i = 0; i < MAX_THREADS; i++) {
        data[i].id = i;
        data[i].from = 0;
        data[i].to = NUM_DISKS - 1;
        data[i].top = NUM_DISKS - 1;
        data[i].stack = (int *) malloc(STACK_SIZE * sizeof(int));
        memset(data[i].stack, 0, STACK_SIZE * sizeof(int));
    }

    for (i = 0; i < NUM_DISKS; i++) {
        data[0].stack[i] = i + 1;
    }

    for (i = 1; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, move_disk, &data[i]);
    }

    move_disk(&data[0]);

    for (i = 1; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}