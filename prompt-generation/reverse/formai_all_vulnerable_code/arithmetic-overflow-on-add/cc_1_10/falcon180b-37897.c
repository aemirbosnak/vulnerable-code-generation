//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10

typedef struct {
    int id;
    int start;
    int end;
} thread_data;

void *print_fibonacci(void *arg) {
    thread_data *data = (thread_data *) arg;
    int i;

    for (i = data->start; i <= data->end; i++) {
        printf("%d ", fibonacci(i));
    }

    return NULL;
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int num_threads, i;
    pthread_t threads[MAX_THREADS];
    thread_data data[MAX_THREADS];

    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    printf("Enter the start number: ");
    scanf("%d", &data[0].start);
    data[0].end = data[0].start + 10;
    data[0].id = 0;

    for (i = 1; i < num_threads; i++) {
        data[i].start = data[i - 1].end + 1;
        data[i].end = data[i].start + 10;
        data[i].id = i;
    }

    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, print_fibonacci, (void *) &data[i]);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}