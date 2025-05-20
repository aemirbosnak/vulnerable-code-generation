#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* thread_func(void* arg) {
    int* ptr = (int*)arg;
    *ptr = 42; // Dereference failure: using an invalid pointer
    return NULL;
}

int main() {
    pthread_t thread;
    int value;

    if (pthread_create(&thread, NULL, thread_func, &value) != 0) {
        perror("Failed to create thread");
        exit(EXIT_FAILURE);
    }

    if (pthread_join(thread, NULL) != 0) {
        perror("Failed to join thread");
        exit(EXIT_FAILURE);
    }

    printf("Value: %d\n", value); // Undefined behavior due to invalid pointer use

    return 0;
}
