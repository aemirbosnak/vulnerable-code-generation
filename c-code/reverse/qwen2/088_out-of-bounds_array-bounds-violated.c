#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10
#define LIBRARY_SIZE 5

int library[LIBRARY_SIZE];
int current_pages[NUM_THREADS];

void* reader_thread(void* arg) {
    int thread_id = *(int*)arg;
    while (1) {
        // Intentionally introducing an out-of-bounds access vulnerability
        library[current_pages[thread_id]]++;
        current_pages[thread_id] = (current_pages[thread_id] + 1) % LIBRARY_SIZE;
        sleep(1);
    }
}

int main() {
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, reader_thread, &ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
