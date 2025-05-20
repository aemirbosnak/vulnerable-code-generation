//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

// Define the maximum number of threads
#define MAX_THREADS 10

// Define the thread data structure
typedef struct thread_data {
    int id;
    int *sum;
    int *array;
    int start;
    int end;
} thread_data_t;

// Define the thread function
void *thread_function(void *arg) {
    // Get the thread data
    thread_data_t *data = (thread_data_t *)arg;

    // Calculate the partial sum
    int partial_sum = 0;
    for (int i = data->start; i < data->end; i++) {
        partial_sum += data->array[i];
    }

    // Update the shared sum
    *data->sum += partial_sum;

    // Return NULL
    return NULL;
}

// Main function
int main() {
    // Get the number of threads from the user
    int num_threads;
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    // Check if the number of threads is valid
    if (num_threads <= 0 || num_threads > MAX_THREADS) {
        printf("Invalid number of threads\n");
        return 1;
    }

    // Get the size of the array from the user
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Check if the size of the array is valid
    if (size <= 0) {
        printf("Invalid size of array\n");
        return 1;
    }

    // Allocate memory for the array
    int *array = (int *)malloc(size * sizeof(int));

    // Get the elements of the array from the user
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    // Allocate memory for the shared sum
    int *sum = (int *)malloc(sizeof(int));
    *sum = 0;

    // Create an array of thread data
    thread_data_t data[num_threads];

    // Create the threads
    pthread_t threads[num_threads];
    for (int i = 0; i < num_threads; i++) {
        // Calculate the start and end indices for the thread
        int start = i * (size / num_threads);
        int end = (i + 1) * (size / num_threads);

        // Initialize the thread data
        data[i].id = i;
        data[i].sum = sum;
        data[i].array = array;
        data[i].start = start;
        data[i].end = end;

        // Create the thread
        if (pthread_create(&threads[i], NULL, thread_function, &data[i]) != 0) {
            printf("Error creating thread\n");
            return 1;
        }
    }

    // Join the threads
    for (int i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            printf("Error joining thread\n");
            return 1;
        }
    }

    // Print the sum of the array
    printf("The sum of the array is: %d\n", *sum);

    // Free the memory
    free(array);
    free(sum);

    return 0;
}