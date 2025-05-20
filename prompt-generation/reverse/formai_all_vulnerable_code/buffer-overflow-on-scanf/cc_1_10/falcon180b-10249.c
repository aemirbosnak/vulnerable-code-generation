//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_NUM_THREADS 100
#define MAX_NUM_TERMS 1000

int num_threads;
int num_terms;
int terms[MAX_NUM_TERMS];
int thread_ids[MAX_NUM_THREADS];

void *print_fibonacci_sequence(void *arg) {
    int id = *(int *) arg;
    int start = id * num_terms / num_threads;
    int end = (id + 1) * num_terms / num_threads - 1;

    for (int i = start; i <= end; i++) {
        printf("%d ", terms[i]);
    }

    return NULL;
}

int main() {
    srand(time(NULL));

    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    printf("Enter the number of terms: ");
    scanf("%d", &num_terms);

    for (int i = 0; i < num_threads; i++) {
        thread_ids[i] = i;
    }

    for (int i = 0; i < num_terms; i++) {
        terms[i] = rand() % 100;
    }

    pthread_t threads[num_threads];

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, print_fibonacci_sequence, &thread_ids[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}