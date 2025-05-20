//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Mutex for synchronization
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to be executed by each thread
void *sum_array(void *arg) {
    // Get the array and its size from the argument
    int *arr = (int *) arg;
    int size = *(int *) (arg + sizeof(int *));

    // Sum up the array elements
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    // Print the result
    printf("Thread %d computed sum: %d\n", *(int *) arg, sum);

    // Exit the thread
    return NULL;
}

int main() {
    // Get the number of threads from the user
    int num_threads;
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    // Create an array to hold the thread IDs
    pthread_t threads[num_threads];

    // Create an array to hold the starting indices for each thread
    int starts[num_threads];

    // Initialize the starting indices
    int start = 0;
    for (int i = 0; i < num_threads; i++) {
        starts[i] = start;
        start += 10;
    }

    // Create the threads
    for (int i = 0; i < num_threads; i++) {
        // Allocate memory for the argument
        int *arg = (int *) malloc(sizeof(int) + sizeof(int *));
        *(int *) arg = i;
        *(int *)(arg + sizeof(int)) = 10;

        // Create the thread
        pthread_create(&threads[i], NULL, sum_array, arg);
    }

    // Join the threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}