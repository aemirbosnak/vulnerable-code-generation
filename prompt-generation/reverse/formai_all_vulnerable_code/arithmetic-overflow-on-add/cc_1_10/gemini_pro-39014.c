//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Shared data
int event_count = 0;
pthread_mutex_t event_count_lock;

// Thread function
void *event_logger(void *arg) {
    // Get the player ID
    int player_id = *(int *)arg;

    // Initialize random event generator
    srand(time(NULL) + player_id);

    // Generate events
    while (1) {
        // Lock the mutex
        pthread_mutex_lock(&event_count_lock);

        // Increment the event count
        event_count++;

        // Unlock the mutex
        pthread_mutex_unlock(&event_count_lock);

        // Log the event
        printf("Player %d: Event %d\n", player_id, event_count);

        // Sleep for a random amount of time
        usleep(rand() % 1000000);
    }

    return NULL;
}

int main() {
    // Initialize the mutex
    pthread_mutex_init(&event_count_lock, NULL);

    // Create the threads
    pthread_t threads[10];
    int player_ids[10];
    for (int i = 0; i < 10; i++) {
        player_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, event_logger, &player_ids[i]);
    }

    // Join the threads
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&event_count_lock);

    return 0;
}