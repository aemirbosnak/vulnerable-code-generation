//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREADS 16
#define MAX_ARRAY_SIZE 1000000

int *array;
int array_size;
int num_threads;

void *sum_thread(void *arg) {
    int start, end;
    int sum = 0;
    int i;

    start = *((int *) arg) * array_size / num_threads;
    end = (*((int *) arg) + 1) * array_size / num_threads;

    for (i = start; i < end; i++) {
        sum += array[i];
    }

    return (void *) sum;
}

int main() {
    int i;
    int *thread_ids;
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;
    int max_threads = 0;
    struct timespec start, end;

    srand(time(NULL));

    array = (int *) malloc(MAX_ARRAY_SIZE * sizeof(int));

    for (i = 0; i < MAX_ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }

    array_size = MAX_ARRAY_SIZE;
    num_threads = 1;

    while (num_threads <= MAX_THREADS) {
        thread_ids = (int *) malloc(num_threads * sizeof(int));

        for (i = 0; i < num_threads; i++) {
            thread_ids[i] = i;
        }

        clock_gettime(CLOCK_REALTIME, &start);
        for (i = 0; i < num_threads; i++) {
            pthread_create(&threads[i], NULL, sum_thread, &thread_ids[i]);
            thread_count++;
        }

        for (i = 0; i < num_threads; i++) {
            pthread_join(threads[i], (void **) &thread_ids[i]);
        }

        clock_gettime(CLOCK_REALTIME, &end);
        max_threads = thread_count > max_threads? thread_count : max_threads;

        if (max_threads == num_threads) {
            break;
        }

        num_threads++;
    }

    printf("Max threads: %d\n", max_threads);

    free(thread_ids);
    free(array);

    return 0;
}