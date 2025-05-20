#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

typedef struct {
    int id;
    int *data;
} ThreadData;

void* thread_function(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    printf("Thread %d: Data = %d\n", data->id, *(data->data));
    free(data->data);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].id = i;
        thread_data[i].data = malloc(sizeof(int));
        if (thread_data[i].data == NULL) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }
        *thread_data[i].data = i * 10;
        pthread_create(&threads[i], NULL, thread_function, &thread_data[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Intentional dereference failure
    for (int i = 0; i < NUM_THREADS; i++) {
        printf("Thread %d: Data after join = %d\n", thread_data[i].id, *(thread_data[i].data)); // Dereferencing freed memory
    }

    return 0;
}
