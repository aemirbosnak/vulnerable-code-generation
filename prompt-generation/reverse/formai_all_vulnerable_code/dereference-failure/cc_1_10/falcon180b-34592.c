//Falcon-180B DATASET v1.0 Category: Data mining ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

#define MAX_DATA 1000
#define NUM_THREADS 4

struct data {
    int x;
    int y;
    float z;
};

struct data_set {
    int size;
    struct data *data;
};

void *thread_func(void *param);

int main() {
    int i;
    struct data_set data_set;
    pthread_t threads[NUM_THREADS];

    // Generate random data
    srand(time(NULL));
    data_set.size = MAX_DATA;
    data_set.data = malloc(data_set.size * sizeof(struct data));
    for (i = 0; i < data_set.size; i++) {
        data_set.data[i].x = rand() % 10;
        data_set.data[i].y = rand() % 10;
        data_set.data[i].z = rand() % 10;
    }

    // Start threads
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *)&data_set);
    }

    // Join threads
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *thread_func(void *param) {
    struct data_set *data_set = param;
    int thread_id = pthread_self();
    int start_index = thread_id * (data_set->size / NUM_THREADS);
    int end_index = (thread_id + 1) * (data_set->size / NUM_THREADS) - 1;
    int i;
    float sum_z = 0;

    for (i = start_index; i <= end_index; i++) {
        sum_z += data_set->data[i].z;
    }

    printf("Thread %d computed sum_z = %.2f\n", thread_id, sum_z);

    return NULL;
}