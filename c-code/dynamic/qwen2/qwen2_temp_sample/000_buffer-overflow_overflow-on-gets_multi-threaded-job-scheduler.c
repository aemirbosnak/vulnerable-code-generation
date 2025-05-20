#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define BUFFER_SIZE 16

void* worker(void* arg) {
    char buffer[BUFFER_SIZE];
    printf("Enter data: ");
    gets(buffer); // Vulnerability here
    return NULL;
}

int main() {
    pthread_t thread;
    if (pthread_create(&thread, NULL, worker, NULL) != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    if (pthread_join(thread, NULL) != 0) {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }
    return 0;
}
