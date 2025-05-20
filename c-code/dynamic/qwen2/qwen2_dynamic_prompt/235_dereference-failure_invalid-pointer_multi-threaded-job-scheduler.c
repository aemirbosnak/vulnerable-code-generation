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
    free(data); // Freeing the allocated memory
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    int* data1 = malloc(sizeof(int));
    int* data2 = malloc(sizeof(int));

    if (!data1 || !data2) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    *data1 = 42;
    *data2 = 99;

    pthread_create(&thread1, NULL, worker, data1);
    pthread_create(&thread2, NULL, worker, data2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Dereferencing freed memory
    printf("Dereferenced freed memory: %d\n", *data1); // Invalid pointer access

    free(data1);
    free(data2);

    return 0;
}
