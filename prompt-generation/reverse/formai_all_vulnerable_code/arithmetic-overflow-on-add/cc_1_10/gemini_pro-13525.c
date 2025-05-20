//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 4

// Thread function
void *thread_function(void *arg) {
    // Get the thread ID
    int thread_id = *(int *)arg;

    // Generate a random number
    srand(time(NULL) + thread_id);
    int random_number = rand() % 100;

    // Print the thread ID and the random number
    printf("Thread %d: %d\n", thread_id, random_number);

    // Return the random number
    return (void *)random_number;
}

int main() {
    // Create an array of thread IDs
    int thread_ids[NUM_THREADS];

    // Create an array of thread handles
    pthread_t threads[NUM_THREADS];

    // Create the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
    }

    // Wait for the threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the sum of the random numbers
    int sum = 0;
    for (int i = 0; i < NUM_THREADS; i++) {
        sum += (int)threads[i];
    }
    printf("Sum of the random numbers: %d\n", sum);

    return 0;
}