//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREADS 10

struct thread_data {
    int thread_id;
    int num_terms;
};

void *print_fibonacci_sequence(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    int thread_id = data->thread_id;
    int num_terms = data->num_terms;

    printf("Thread %d printing Fibonacci sequence with %d terms:\n", thread_id, num_terms);

    int first_term = 0, second_term = 1, next_term;

    for (int i = 0; i < num_terms; i++) {
        printf("%d ", first_term);
        next_term = first_term + second_term;
        first_term = second_term;
        second_term = next_term;
    }

    printf("\n");

    pthread_exit(0);
}

int main() {
    int num_threads;
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    if (num_threads > MAX_THREADS || num_threads <= 0) {
        printf("Invalid number of threads.\n");
        return 1;
    }

    pthread_t threads[MAX_THREADS];
    struct thread_data data[MAX_THREADS];

    for (int i = 0; i < num_threads; i++) {
        data[i].thread_id = i + 1;
        data[i].num_terms = 10; // Change this value to print more or fewer terms

        pthread_create(&threads[i], NULL, print_fibonacci_sequence, (void *)&data[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}