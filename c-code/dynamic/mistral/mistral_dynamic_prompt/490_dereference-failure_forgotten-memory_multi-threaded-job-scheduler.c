#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5

typedef struct {
    int id;
    int *data;
} ThreadArgs;

void *PrintData(void *args) {
    ThreadArgs *ta = (ThreadArgs *)args;
    printf("Thread %d: %d\n", ta->id, *ta->data);
    free(ta);
    return NULL;
}

int main() {
    pthread_t workers[NUM_THREADS];
    ThreadArgs args[NUM_THREADS];
    int nums[NUM_THREADS] = {1, 2, 3, 4, 5};

    for (int i = 0; i < NUM_THREADS; i++) {
        args[i].id = i;
        args[i].data = &nums[i];
        pthread_create(&workers[i], NULL, PrintData, &args[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(workers[i], NULL);
    }

    // Deliberate dereference failure by accessing freed memory
    printf("Main: %d\n", *args[0].data); // Accessing freed memory of args[0]

    return 0;
}
