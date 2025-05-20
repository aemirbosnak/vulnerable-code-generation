#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5

int data[10];

void* worker(void* arg) {
    int i = *(int*)arg;
    data[i] = data[i] * 2; // Unchecked array access
    printf("Thread %ld modified data[%d] = %d\n", pthread_self(), i, data[i]);
    pthread_exit(0);
}

int main() {
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; ++i) {
        int* t_id = (int*)malloc(sizeof(int));
        *t_id = i;
        pthread_create(&threads[i], NULL, worker, (void*)t_id);
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < 10; ++i) {
        printf("main: data[%d] = %d\n", i, data[i]);
    }

    return 0;
}
