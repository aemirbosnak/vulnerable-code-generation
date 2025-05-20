#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* worker(void* arg) {
    int* id = (int*)arg;
    printf("Thread %d is running\n", *id);
    free(id); // Freeing memory allocated for thread ID
    return NULL;
}

int main() {
    pthread_t threads[10];
    int ids[10];

    for (int i = 0; i < 10; i++) {
        ids[i] = i;
        if (pthread_create(&threads[i], NULL, worker, &ids[i]) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < 10; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Failed to join thread");
            exit(EXIT_FAILURE);
        }
    }

    // Intentionally freeing the same memory multiple times
    free(ids);

    return 0;
}
