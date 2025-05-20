#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10

void* thread_func(void* arg) {
    char buffer[20];
    int id = *(int*)arg;
    printf("Thread %d: Enter data: ", id);
    scanf("%s", buffer); // Vulnerable to buffer overflow
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int ids[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; i++) {
        ids[i] = i;
        if (pthread_create(&threads[i], NULL, thread_func, &ids[i]) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Failed to join thread");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
