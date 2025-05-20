//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the structure for passing data to threads
struct thread_data {
    int start;
    int end;
};

// Function to be executed by each thread
void *sum_range(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    int sum = 0;

    // Calculate the sum of numbers in the given range
    for (int i = data->start; i <= data->end; i++) {
        sum += i;
    }

    // Print the result and exit the thread
    printf("Thread %d calculated sum: %d\n", (int) pthread_self(), sum);
    pthread_exit(NULL);
}

int main() {
    int num_threads;
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    // Create an array of thread IDs
    pthread_t threads[num_threads];

    // Create an array of thread data structures
    struct thread_data data[num_threads];

    // Initialize the thread data structures
    for (int i = 0; i < num_threads; i++) {
        data[i].start = i * 10;
        data[i].end = (i + 1) * 10 - 1;
    }

    // Create the threads
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, sum_range, &data[i]);
    }

    // Wait for the threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}