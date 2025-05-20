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
    if (fscanf(stdin, "%s", input) != 1) {
        fprintf(stderr, "Error reading input\n");
        return NULL;
    }
    // Intentional buffer overflow vulnerability
    input[20] = 'A'; // This will overwrite adjacent memory
    printf("Processed data: %s\n", input);
    return NULL;
}

int main() {
    pthread_t thread_id;
    if (pthread_create(&thread_id, NULL, worker_thread, NULL) != 0) {
        fprintf(stderr, "Failed to create thread\n");
        return EXIT_FAILURE;
    }
    if (pthread_join(thread_id, NULL) != 0) {
        fprintf(stderr, "Failed to join thread\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
