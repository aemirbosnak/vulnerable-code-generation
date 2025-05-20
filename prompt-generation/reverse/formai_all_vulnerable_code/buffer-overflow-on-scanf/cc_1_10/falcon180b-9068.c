//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_DATA_SIZE 100

struct data {
    int index;
    int size;
    char data[MAX_DATA_SIZE];
};

struct thread_data {
    struct data *data;
    int start_index;
    int end_index;
};

void *thread_func(void *arg) {
    struct thread_data *thread_data = (struct thread_data *) arg;
    struct data *data = thread_data->data;
    int start_index = thread_data->start_index;
    int end_index = thread_data->end_index;

    for (int i = start_index; i <= end_index; i++) {
        printf("Thread %d processing data at index %d with size %d\n", i, data[i].index, data[i].size);
    }

    return NULL;
}

int main() {
    struct data data[MAX_THREADS];
    int num_threads = 0;

    for (int i = 0; i < MAX_THREADS; i++) {
        printf("Enter data for thread %d (index and size): ", i);
        scanf("%d %d", &data[i].index, &data[i].size);
        strncpy(data[i].data, "Thread data", MAX_DATA_SIZE);
        num_threads++;
    }

    pthread_t threads[MAX_THREADS];
    struct thread_data thread_data[MAX_THREADS];

    int data_size = sizeof(struct data);
    int thread_stack_size = 1024 * 1024; // 1 MB

    for (int i = 0; i < num_threads; i++) {
        thread_data[i].data = &data[i];
        thread_data[i].start_index = i;
        thread_data[i].end_index = i;

        pthread_create(&threads[i], NULL, thread_func, (void *)&thread_data[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}