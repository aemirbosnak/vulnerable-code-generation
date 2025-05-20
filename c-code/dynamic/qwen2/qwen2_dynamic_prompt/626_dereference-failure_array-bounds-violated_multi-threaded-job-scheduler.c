#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10

void* thread_func(void* arg) {
    int index = *(int*)arg;
    int array[5];
    array[index] = 42; // Dereference failure: out-of-bounds write
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int indices[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        indices[i] = i + 6; // Intentionally out-of-bounds access
        if (pthread_create(&threads[i], NULL, thread_func, &indices[i]) != 0) {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Thread join failed");
            exit(EXIT_FAILURE);
        }
    }

    printf("All threads completed.\n");
    return 0;
}
