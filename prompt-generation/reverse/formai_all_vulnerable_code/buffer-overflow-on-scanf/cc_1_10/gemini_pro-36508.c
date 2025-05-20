//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>

#define NUM_THREADS 10

struct thread_data {
    int thread_id;
    int start_index;
    int end_index;
    int *fibonacci_sequence;
};

void *calculate_fibonacci(void *arg) {
    struct thread_data *data = (struct thread_data *)arg;

    for (int i = data->start_index; i <= data->end_index; i++) {
        if (i <= 1) {
            data->fibonacci_sequence[i] = i;
        } else {
            data->fibonacci_sequence[i] = data->fibonacci_sequence[i - 1] + data->fibonacci_sequence[i - 2];
        }
    }

    pthread_exit(NULL);
}

void print_fibonacci_sequence(int *fibonacci_sequence, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci_sequence[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &n);

    int fibonacci_sequence[n];

    pthread_t threads[NUM_THREADS];
    struct thread_data thread_data[NUM_THREADS];

    int chunk_size = n / NUM_THREADS;
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].thread_id = i;
        thread_data[i].start_index = i * chunk_size;
        thread_data[i].end_index = (i + 1) * chunk_size - 1;
        thread_data[i].fibonacci_sequence = fibonacci_sequence;

        pthread_create(&threads[i], NULL, calculate_fibonacci, (void *)&thread_data[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    print_fibonacci_sequence(fibonacci_sequence, n);

    return 0;
}