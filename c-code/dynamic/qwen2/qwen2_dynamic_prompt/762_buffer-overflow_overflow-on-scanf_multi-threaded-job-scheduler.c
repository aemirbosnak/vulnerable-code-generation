#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 16

void* worker_thread(void* arg) {
    char buffer[BUFFER_SIZE];
    printf("Enter data: ");
    scanf("%s", buffer); // Vulnerability here
    return NULL;
}

int main() {
    pthread_t thread_id;
    if (pthread_create(&thread_id, NULL, worker_thread, NULL) != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    if (pthread_join(thread_id, NULL) != 0) {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }
    return 0;
}
