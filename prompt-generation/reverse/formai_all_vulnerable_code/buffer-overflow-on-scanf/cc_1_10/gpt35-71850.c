//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_REPEATS 10

// Define global variables
int vehicle_x = 0;
int vehicle_y = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Define thread function for remote control
void* remote_control(void* arg) {
    // Loop for user input
    for(int i = 0; i < MAX_REPEATS; i++) {
        // Get user input for direction
        printf("\nEnter direction (u for up, d for down, l for left, r for right): ");
        char direction; 
        scanf(" %c", &direction); 

        // Update vehicle position based on direction
        switch(direction) {
            case 'u':
                pthread_mutex_lock(&mutex);
                vehicle_y++;
                pthread_mutex_unlock(&mutex);
                break;
            case 'd':
                pthread_mutex_lock(&mutex);
                vehicle_y--;
                pthread_mutex_unlock(&mutex);
                break;
            case 'l':
                pthread_mutex_lock(&mutex);
                vehicle_x--;
                pthread_mutex_unlock(&mutex);
                break;
            case 'r':
                pthread_mutex_lock(&mutex);
                vehicle_x++;
                pthread_mutex_unlock(&mutex);
                break;
            default:
                printf("\nInvalid direction. Try again.");
        }
    }
    pthread_exit(NULL);
}

// Define thread function for vehicle position display
void* position_display(void* arg) {
    // Loop for displaying position
    for(int i = 0; i < MAX_REPEATS; i++) {
        pthread_mutex_lock(&mutex);
        printf("\nCurrent vehicle position: (%d, %d)", vehicle_x, vehicle_y);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    pthread_exit(NULL);
}

int main() {
    // Declare thread ids
    pthread_t remote_control_thread;
    pthread_t position_display_thread;

    // Create threads
    pthread_create(&remote_control_thread, NULL, remote_control, NULL);
    pthread_create(&position_display_thread, NULL, position_display, NULL);

    // Wait for threads to finish
    pthread_join(remote_control_thread, NULL);
    pthread_join(position_display_thread, NULL);

    // Clean up
    pthread_exit(NULL);
    return 0;
}