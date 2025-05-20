#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10

void* thread_function(void* arg) {
    int thread_id = *(int*)arg;
    int* array = malloc(10 * sizeof(int));
    if (array == NULL) {
        perror("Failed to allocate memory");
        pthread_exit(NULL);
    }
    for (int i = 0; i <= 10; i++) { // Dereference failure: out-of-bounds write
        array[i] = i * thread_id;
    }
    printf("Thread %d finished\n", thread_id);
    free(array);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        if (pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]) != 0) {
            perror("Failed to create thread");
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Failed to join thread");
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}
