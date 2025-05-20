#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10

void* thread_func(void* arg) {
    int* ptr = malloc(sizeof(int));
    *ptr = *(int*)arg;
    free(ptr);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int args[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        args[i] = i;
        if (pthread_create(&threads[i], NULL, thread_func, &args[i]) != 0) {
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

    // Dereference freed memory
    printf("%d\n", *(int*)NULL);

    return 0;
}
