//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the structure for thread data
struct thread_data {
    int thread_id;
    int sum;
};

// Function to be executed by each thread
void *sum_thread(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    int i;

    // Calculate the sum for the given range
    for (i = data->thread_id * 10000; i < (data->thread_id + 1) * 10000; i++) {
        data->sum += i;
    }

    return NULL;
}

int main() {
    int num_threads, i;
    pthread_t threads[10];
    struct thread_data thread_data[10];

    // Get the number of threads from user input
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    // Initialize thread data
    for (i = 0; i < num_threads; i++) {
        thread_data[i].thread_id = i;
        thread_data[i].sum = 0;
    }

    // Create threads
    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, sum_thread, (void *) &thread_data[i]);
    }

    // Join threads
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the final sum
    printf("Final sum: %d\n", thread_data[0].sum);

    return 0;
}