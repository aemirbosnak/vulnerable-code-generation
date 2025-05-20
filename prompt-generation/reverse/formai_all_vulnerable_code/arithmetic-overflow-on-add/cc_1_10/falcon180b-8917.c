//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_VALUE 100

int value[MAX_THREADS];
int greedy[MAX_THREADS];

void* thread_func(void* arg) {
    int i = *(int*) arg;

    srand(time(NULL) + i);
    int sum = 0;
    int count = 0;

    while (sum <= MAX_VALUE) {
        int rand_val = rand() % 10 + 1;
        if (sum + rand_val <= MAX_VALUE) {
            sum += rand_val;
            count++;
        }
    }

    value[i] = sum;
    greedy[i] = count;

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int i;

    srand(time(NULL));
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void*) i);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    int max_value = value[0];
    int max_count = greedy[0];

    for (i = 1; i < MAX_THREADS; i++) {
        if (value[i] > max_value) {
            max_value = value[i];
            max_count = greedy[i];
        }
    }

    printf("Maximum value: %d\n", max_value);
    printf("Maximum count: %d\n", max_count);

    return 0;
}