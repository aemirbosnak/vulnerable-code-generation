//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: multi-threaded
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/resource.h>

// Global variables
long long total_ram;
pthread_mutex_t lock;

// Thread function
void *thread_function(void *arg) {
    // Get thread ID
    int id = (int)arg;

    // Allocate memory
    char *buf = malloc(1024 * 1024);
    if (buf == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    // Use memory
    for (long long i = 0; i < 1024 * 1024; i++) {
        buf[i] = 'a';
    }

    // Lock mutex
    pthread_mutex_lock(&lock);

    // Update total RAM usage
    total_ram += 1024 * 1024;

    // Unlock mutex
    pthread_mutex_unlock(&lock);

    // Print thread ID and RAM usage
    printf("Thread %d: %lld bytes\n", id, 1024 * 1024);

    // Exit thread
    pthread_exit(NULL);
}

int main() {
    // Get total RAM
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    total_ram = usage.ru_maxrss * 1024;

    // Initialize mutex
    pthread_mutex_init(&lock, NULL);

    // Create threads
    pthread_t threads[4];
    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, thread_function, (void *)i);
    }

    // Join threads
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy mutex
    pthread_mutex_destroy(&lock);

    // Print total RAM usage
    printf("Total RAM usage: %lld bytes\n", total_ram);

    return 0;
}