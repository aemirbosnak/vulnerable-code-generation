//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define NUM_THREADS 4

struct v {
    int i;
    int j;
};

void *runner(void *param); // runner function for threads

int main() {
    int i, j, k;
    pthread_t threads[NUM_THREADS];
    struct v *data = malloc(NUM_THREADS * sizeof(struct v));

    // Initialize data for threads
    for (i = 0; i < NUM_THREADS; i++) {
        data[i].i = i;
        data[i].j = i + 1;
    }

    // Create threads
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, runner, &data[i]);
    }

    // Join threads
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *runner(void *param) {
    struct v *data = param;
    int i = data->i;
    int j = data->j;
    int sum = 0;

    // Calculate sum of squares from i to j
    for (int k = i; k <= j; k++) {
        sum += k * k;
    }

    // Print result
    printf("Thread %d calculated sum of squares from %d to %d: %d\n", i, i, j, sum);

    return NULL;
}