#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_INPUT_SIZE 1024

void* worker_thread(void* arg) {
    char input[MAX_INPUT_SIZE];
    int id = *(int*)arg;

    printf("Thread %d: Enter your command: ", id);
    fgets(input, sizeof(input), stdin);

    // Vulnerability: Buffer overflow due to use of sscanf with unbounded input
    int num;
    sscanf(input, "%d", &num); // This can lead to buffer overflow if input is too large

    printf("Thread %d processed number: %d\n", id, num);

    return NULL;
}

int main() {
    pthread_t threads[5];
    int thread_ids[5];

    for (int i = 0; i < 5; i++) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, worker_thread, &thread_ids[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
