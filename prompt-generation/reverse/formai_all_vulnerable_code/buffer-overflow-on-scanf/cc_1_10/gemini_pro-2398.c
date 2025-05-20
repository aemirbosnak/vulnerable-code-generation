//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: configurable
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

struct thread_args {
    int start;
    int end;
    int *sum;
};

void *sum_range(void *args) {
    struct thread_args *arg = (struct thread_args *)args;

    for (int i = arg->start; i <= arg->end; i++) {
        *(arg->sum) += i;
    }

    return NULL;
}

int main() {
    int num_threads;
    int range;
    int sum = 0;

    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    printf("Enter the range of numbers to sum: ");
    scanf("%d", &range);

    pthread_t threads[num_threads];
    struct thread_args args[num_threads];

    for (int i = 0; i < num_threads; i++) {
        args[i].start = i * (range / num_threads);
        args[i].end = (i + 1) * (range / num_threads) - 1;
        args[i].sum = &sum;

        pthread_create(&threads[i], NULL, sum_range, &args[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("The sum of numbers from 1 to %d is: %d\n", range, sum);

    return 0;
}