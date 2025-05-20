//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the number of lights
#define NUM_LIGHTS 3

// Define the states of a light
enum light_state {
    OFF,
    ON
};

// Create a mutex to protect the shared data
pthread_mutex_t light_mutex = PTHREAD_MUTEX_INITIALIZER;

// Create a condition variable to signal when a light has changed state
pthread_cond_t light_cond = PTHREAD_COND_INITIALIZER;

// Create an array of lights
struct light {
    int id;
    enum light_state state;
} lights[NUM_LIGHTS];

// Create a thread function to control a light
void *light_control_thread(void *arg) {
    // Get the light ID
    int id = *(int *)arg;

    // Loop forever
    while (1) {
        // Acquire the mutex
        pthread_mutex_lock(&light_mutex);

        // Wait until the light state has changed
        pthread_cond_wait(&light_cond, &light_mutex);

        // Get the current light state
        enum light_state state = lights[id].state;

        // Toggle the light state
        lights[id].state = (state == OFF) ? ON : OFF;

        // Print the new light state
        printf("Light %d is now %s\n", id, (state == OFF) ? "off" : "on");

        // Release the mutex
        pthread_mutex_unlock(&light_mutex);
    }

    return NULL;
}

// Create a main function
int main() {
    // Initialize the lights
    for (int i = 0; i < NUM_LIGHTS; i++) {
        lights[i].id = i;
        lights[i].state = OFF;
    }

    // Create an array of thread IDs
    pthread_t light_threads[NUM_LIGHTS];

    // Create a thread for each light
    for (int i = 0; i < NUM_LIGHTS; i++) {
        pthread_create(&light_threads[i], NULL, light_control_thread, &lights[i].id);
    }

    // Loop forever
    while (1) {
        // Get user input
        char input[10];
        printf("Enter a light ID (0-%d) to toggle its state: ", NUM_LIGHTS - 1);
        scanf("%s", input);

        // Convert the input to an integer
        int id = atoi(input);

        // Check if the input is valid
        if (id < 0 || id >= NUM_LIGHTS) {
            printf("Invalid input. Please enter a valid light ID.\n");
            continue;
        }

        // Acquire the mutex
        pthread_mutex_lock(&light_mutex);

        // Toggle the light state
        lights[id].state = (lights[id].state == OFF) ? ON : OFF;

        // Signal that the light state has changed
        pthread_cond_signal(&light_cond);

        // Release the mutex
        pthread_mutex_unlock(&light_mutex);
    }

    return 0;
}