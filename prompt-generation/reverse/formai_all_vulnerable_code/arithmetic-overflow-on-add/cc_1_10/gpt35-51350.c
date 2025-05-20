//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define NUM_THREADS 4

typedef struct {
    char* buffer;
    int start;
    int end;
    int checksum;
} ThreadArgs;

// Calculate the checksum for a given buffer range
void* calculateChecksum(void* ptr) {
    ThreadArgs* args = (ThreadArgs*) ptr;
    int i, x;
    for (i = args->start; i < args->end; i++) {
        x = args->buffer[i];
        args->checksum = (args->checksum + x) % (INT_MAX + 1);
    }
    return NULL;
}

int main() {
    char buffer[BUFFER_SIZE];
    int totalChecksum = 0, i, argPos = 0;
    pthread_t threads[NUM_THREADS];
    ThreadArgs args[NUM_THREADS];

    // Open the file
    FILE* file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    // Read the file into buffer in chunks
    int readCount;
    while ((readCount = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        // Spawn threads for each chunk
        int chunkSize = readCount / NUM_THREADS;
        for (i = 0; i < NUM_THREADS; i++) {
            args[i].buffer = buffer;
            args[i].start = i * chunkSize;
            args[i].end = (i == NUM_THREADS - 1) ? readCount : (i + 1) * chunkSize;
            args[i].checksum = 0;
            pthread_create(&threads[i], NULL, calculateChecksum, (void*) &args[i]);
        }

        // Wait for the threads to finish
        for (i = 0; i < NUM_THREADS; i++) {
            pthread_join(threads[i], NULL);
            totalChecksum = (totalChecksum + args[i].checksum) % (INT_MAX + 1);
        }
    }

    // Close the file
    fclose(file);

    printf("Checksum: %d\n", totalChecksum);
    return 0;
}