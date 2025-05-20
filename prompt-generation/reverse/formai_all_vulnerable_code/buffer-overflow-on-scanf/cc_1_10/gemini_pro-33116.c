//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the remote control vehicle struct
typedef struct rcv {
    int x;
    int y;
    int speed;
    int direction;
} rcv_t;

// Define the mutex
pthread_mutex_t mutex;

// Define the condition variable
pthread_cond_t cond;

// Create the remote control vehicle
rcv_t rcv;

// Create the thread function
void *thread_func(void *arg) {
    while (1) {
        // Lock the mutex
        pthread_mutex_lock(&mutex);

        // Wait for the condition variable to be signaled
        pthread_cond_wait(&cond, &mutex);

        // Unlock the mutex
        pthread_mutex_unlock(&mutex);

        // Update the remote control vehicle
        switch (rcv.direction) {
            case 0:
                rcv.y--;
                break;
            case 1:
                rcv.x++;
                break;
            case 2:
                rcv.y++;
                break;
            case 3:
                rcv.x--;
                break;
        }

        // Print the remote control vehicle's position
        printf("(%d, %d)\n", rcv.x, rcv.y);
    }

    return NULL;
}

// Main function
int main() {
    // Initialize the remote control vehicle
    rcv.x = 0;
    rcv.y = 0;
    rcv.speed = 1;
    rcv.direction = 0;

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Initialize the condition variable
    pthread_cond_init(&cond, NULL);

    // Create the thread
    pthread_t thread;
    pthread_create(&thread, NULL, thread_func, NULL);

    // Loop forever
    while (1) {
        // Get the user input
        char input;
        scanf(" %c", &input);

        // Lock the mutex
        pthread_mutex_lock(&mutex);

        // Update the remote control vehicle
        switch (input) {
            case 'w':
                rcv.direction = 0;
                break;
            case 'd':
                rcv.direction = 1;
                break;
            case 's':
                rcv.direction = 2;
                break;
            case 'a':
                rcv.direction = 3;
                break;
            case 'q':
                exit(0);
        }

        // Signal the condition variable
        pthread_cond_signal(&cond);

        // Unlock the mutex
        pthread_mutex_unlock(&mutex);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    // Destroy the condition variable
    pthread_cond_destroy(&cond);

    return 0;
}