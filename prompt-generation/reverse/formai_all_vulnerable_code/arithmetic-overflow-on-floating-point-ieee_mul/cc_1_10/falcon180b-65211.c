//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define NUM_THREADS 4
#define PI 3.14159265359

typedef struct {
    int id;
    double start;
    double end;
} thread_data;

void *runner(void *arg) {
    thread_data *data = (thread_data *) arg;
    int id = data->id;
    double start = data->start;
    double end = data->end;

    double step = (end - start) / NUM_THREADS;
    for (int i = 0; i < NUM_THREADS; i++) {
        if (i == id) {
            double integral = 0;
            for (double x = start; x <= end; x += step) {
                integral += 4 / (1 + pow(x, 2));
            }
            printf("Thread %d computed integral: %lf\n", id, integral);
        }
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    pthread_t threads[NUM_THREADS];
    thread_data data[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        data[i].id = i;
        data[i].start = -10 + i * 10;
        data[i].end = 10 + i * 10;

        pthread_create(&threads[i], NULL, runner, (void *) &data[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}