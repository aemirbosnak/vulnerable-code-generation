//FormAI DATASET v1.0 Category: Digital signal processing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 256
#define NUM_THREADS 2

int input_buffer[BUFFER_SIZE];
int output_buffer[BUFFER_SIZE];

pthread_mutex_t input_mutex;
pthread_mutex_t output_mutex;

void *process_input(void *arg) {
    int *input_index = (int *) arg;
    int i;

    for (i = *input_index; i < *input_index + BUFFER_SIZE/2; i++) {
        // Apply digital signal processing algorithm to input buffer
        output_buffer[i] = input_buffer[i] * 2;
    }

    pthread_mutex_unlock(&input_mutex);

    pthread_exit(NULL);
}

void *process_output(void *arg) {
    int *output_index = (int *) arg;
    int i;

    for (i = *output_index; i < *output_index + BUFFER_SIZE/2; i++) {
        // Print contents of output buffer
        printf("%d ", output_buffer[i]);
    }

    pthread_mutex_unlock(&output_mutex);

    pthread_exit(NULL);
}

int main() {
    int i, j;
    void *status;

    pthread_t threads[NUM_THREADS];

    // Initialize buffers to random values
    for (i = 0; i < BUFFER_SIZE; i++) {
        input_buffer[i] = rand();
    }

    // Initialize mutexes
    pthread_mutex_init(&input_mutex, NULL);
    pthread_mutex_init(&output_mutex, NULL);

    // Start threads
    for (i = 0, j = NUM_THREADS/2; i < NUM_THREADS/2; i++, j++) {
        int input_index = i * BUFFER_SIZE/2;
        int output_index = j * BUFFER_SIZE/2;

        pthread_mutex_lock(&input_mutex);
        pthread_create(&threads[i], NULL, process_input, &input_index);

        pthread_mutex_lock(&output_mutex);
        pthread_create(&threads[j], NULL, process_output, &output_index);
    }

    // Wait for threads to complete
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], &status);
    }

    return 0;
}