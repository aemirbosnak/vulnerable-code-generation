#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_INPUT_SIZE 10

void* worker_thread(void* arg) {
    char input[MAX_INPUT_SIZE];
    printf("Enter data: ");
    fscanf(stdin, "%s", input); // Vulnerable to buffer overflow
    printf("Received: %s\n", input);
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
