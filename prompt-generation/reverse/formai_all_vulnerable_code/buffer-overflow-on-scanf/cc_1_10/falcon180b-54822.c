//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_NUMBERS 1000000

int numbers[MAX_NUMBERS];
int num_threads = 0;

void *generate_fibonacci(void *arg) {
    int start = *(int *) arg;
    int end = start + MAX_NUMBERS / num_threads;

    for (int i = start; i < end; i++) {
        if (i == 0) {
            numbers[i] = 0;
        } else if (i == 1) {
            numbers[i] = 1;
        } else {
            numbers[i] = numbers[i - 1] + numbers[i - 2];
        }
    }

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];

    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    for (int i = 0; i < num_threads; i++) {
        int start = i * MAX_NUMBERS / num_threads;
        int end = (i + 1) * MAX_NUMBERS / num_threads;

        pthread_create(&threads[i], NULL, generate_fibonacci, &start);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("The Fibonacci sequence up to %d numbers:\n", MAX_NUMBERS);
    for (int i = 0; i < MAX_NUMBERS; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}