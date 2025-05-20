//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define a structure for passing data to threads
typedef struct {
    int start;
    int end;
} thread_data_t;

// Function to be executed by each thread
void *sum_range(void *arg) {
    int i, sum = 0;
    thread_data_t *data = (thread_data_t *) arg;

    for (i = data->start; i <= data->end; i++) {
        sum += i;
    }

    pthread_exit((void *) sum);
}

int main() {
    int num_threads, i, max_value;
    pthread_t threads[10];
    thread_data_t data[10];

    // Get user input for number of threads and maximum value
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    printf("Enter the maximum value: ");
    scanf("%d", &max_value);

    // Divide the range into equal parts for each thread
    int range = max_value / num_threads;

    // Initialize thread data
    for (i = 0; i < num_threads; i++) {
        data[i].start = i * range;
        data[i].end = (i == num_threads - 1)? max_value : (i + 1) * range - 1;
    }

    // Create threads
    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, sum_range, (void *) &data[i]);
    }

    // Join threads
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}