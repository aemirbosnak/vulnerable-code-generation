//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the RC car's state
typedef struct {
    int speed;
    int direction;
} car_state;

// Define the remote control's state
typedef struct {
    int throttle;
    int steering;
} remote_state;

// Create a mutex to protect the shared state
pthread_mutex_t state_mutex = PTHREAD_MUTEX_INITIALIZER;

// Create a condition variable to signal when the state has changed
pthread_cond_t state_cond = PTHREAD_COND_INITIALIZER;

// Create a thread to simulate the RC car
void *car_thread(void *arg) {
    // Get a pointer to the shared state
    car_state *state = (car_state *)arg;

    // Continuously update the car's state based on the remote control's input
    while (1) {
        // Lock the mutex to protect the shared state
        pthread_mutex_lock(&state_mutex);

        // Wait for the remote control's input to change
        pthread_cond_wait(&state_cond, &state_mutex);

        // Get the remote control's input
        remote_state remote;
        scanf("%d %d", &remote.throttle, &remote.steering);

        // Update the car's speed and direction
        state->speed += remote.throttle;
        state->direction += remote.steering;

        // Unlock the mutex
        pthread_mutex_unlock(&state_mutex);
    }

    return NULL;
}

// Create a thread to simulate the remote control
void *remote_thread(void *arg) {
    // Get a pointer to the shared state
    car_state *state = (car_state *)arg;

    // Continuously get input from the user and update the remote control's state
    while (1) {
        // Lock the mutex to protect the shared state
        pthread_mutex_lock(&state_mutex);

        // Get the user's input
        int throttle, steering;
        scanf("%d %d", &throttle, &steering);

        // Update the remote control's state
        remote_state remote;
        remote.throttle = throttle;
        remote.steering = steering;

        // Signal that the remote control's input has changed
        pthread_cond_signal(&state_cond);

        // Unlock the mutex
        pthread_mutex_unlock(&state_mutex);
    }

    return NULL;
}

// Create a thread to print the car's state
void *print_thread(void *arg) {
    // Get a pointer to the shared state
    car_state *state = (car_state *)arg;

    // Continuously print the car's state
    while (1) {
        // Lock the mutex to protect the shared state
        pthread_mutex_lock(&state_mutex);

        // Print the car's state
        printf("Speed: %d, Direction: %d\n", state->speed, state->direction);

        // Unlock the mutex
        pthread_mutex_unlock(&state_mutex);
    }

    return NULL;
}

int main() {
    // Create the shared state
    car_state state;
    state.speed = 0;
    state.direction = 0;

    // Create the threads
    pthread_t car_tid, remote_tid, print_tid;
    pthread_create(&car_tid, NULL, car_thread, &state);
    pthread_create(&remote_tid, NULL, remote_thread, &state);
    pthread_create(&print_tid, NULL, print_thread, &state);

    // Join the threads
    pthread_join(car_tid, NULL);
    pthread_join(remote_tid, NULL);
    pthread_join(print_tid, NULL);

    return 0;
}