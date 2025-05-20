//GEMINI-pro DATASET v1.0 Category: Traffic Light Controller ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

// Traffic light states
enum {
    RED,
    YELLOW,
    GREEN,
    OFF
};

// Traffic light timing (seconds)
const int TIMINGS[] = {
    30,  // RED
    5,   // YELLOW
    45   // GREEN
};

// Shared memory for traffic light state
int state = RED;

// Mutex for traffic light state
pthread_mutex_t state_mutex = PTHREAD_MUTEX_INITIALIZER;

// Initialize traffic light state and timing
void init_traffic_light() {
    // Initialize random seed
    srand(time(NULL));

    // Start traffic light in a random state
    state = rand() % 4;
}

// Change traffic light state to the next state
void change_state() {
    // Lock state mutex
    pthread_mutex_lock(&state_mutex);

    // Change state to the next one
    state = (state + 1) % 4;

    // Unlock state mutex
    pthread_mutex_unlock(&state_mutex);
}

// Get traffic light state
int get_state() {
    // Lock state mutex
    pthread_mutex_lock(&state_mutex);

    // Return traffic light state
    int result = state;

    // Unlock state mutex
    pthread_mutex_unlock(&state_mutex);

    return result;
}

// Thread function for traffic light control
void* traffic_light_control(void* args) {
    while (1) {
        // Get current state
        int current_state = get_state();

        // Wait for specified amount of time
        sleep(TIMINGS[current_state]);

        // Change state to the next one
        change_state();
    }

    return NULL;
}

int main() {
    // Initialize traffic light state and timing
    init_traffic_light();

    // Create thread for traffic light control
    pthread_t traffic_light_thread;
    pthread_create(&traffic_light_thread, NULL, traffic_light_control, NULL);

    // Main loop to simulate traffic light operation
    while (1) {
        // Get current state
        int current_state = get_state();

        // Print current state
        printf("Traffic light state: %s\n", current_state == RED ? "RED" : current_state == YELLOW ? "YELLOW" : current_state == GREEN ? "GREEN" : "OFF");

        // Wait for user input
        getchar();
    }

    return 0;
}