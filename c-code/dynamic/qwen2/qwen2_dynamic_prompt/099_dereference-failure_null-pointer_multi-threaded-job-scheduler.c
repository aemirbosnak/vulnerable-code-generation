#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* worker(void* arg) {
    int* data = (int*)arg;
    printf("Thread received data: %d\n", *data);
    return NULL;
}

int main() {
    pthread_t thread;
    int* data = NULL;

    if (pthread_create(&thread, NULL, worker, data) != 0) {
        perror("Failed to create thread");
        exit(EXIT_FAILURE);
    }

    // Simulate some work
    sleep(1);

    // Dereference null pointer
    printf("Dereferencing null pointer...\n");
    int value = *data; // This will cause a segmentation fault

    pthread_join(thread, NULL);
    free(data); // Freeing already freed memory

    return 0;
}
