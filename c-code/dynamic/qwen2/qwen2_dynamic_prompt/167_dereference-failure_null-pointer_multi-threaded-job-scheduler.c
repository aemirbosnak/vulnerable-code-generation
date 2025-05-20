#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* thread_func(void* arg) {
    int* ptr = NULL;
    *ptr = 42; // Dereference null pointer
    return NULL;
}

int main() {
    pthread_t thread;
    if (pthread_create(&thread, NULL, thread_func, NULL) != 0) {
        perror("Failed to create thread");
        exit(EXIT_FAILURE);
    }
    if (pthread_join(thread, NULL) != 0) {
        perror("Failed to join thread");
        exit(EXIT_FAILURE);
    }
    return 0;
}
