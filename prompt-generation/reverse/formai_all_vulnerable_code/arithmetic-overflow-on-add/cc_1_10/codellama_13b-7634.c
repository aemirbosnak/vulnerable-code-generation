//Code Llama-13B DATASET v1.0 Category: Traffic Light Controller ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <sys/time.h>

#define MAX_LIGHTS 5

// Structure to represent a traffic light
typedef struct {
    int id;
    char* name;
    int state; // 0: red, 1: yellow, 2: green
    struct timespec next_change;
} TrafficLight;

// Function to generate a random integer between 0 and 2
int random_light(void) {
    return rand() % 3;
}

// Function to generate a random time between 0 and 10 seconds
int random_time(void) {
    return rand() % 10;
}

// Function to update the state of a traffic light
void update_light(TrafficLight* light) {
    // Get the current time
    struct timespec now;
    clock_gettime(CLOCK_REALTIME, &now);

    // Check if it's time to change the state
    if (now.tv_sec >= light->next_change.tv_sec) {
        // Choose a random new state
        int new_state = random_light();

        // Set the new state
        light->state = new_state;

        // Calculate the next change time
        struct timespec next_change;
        next_change.tv_sec = now.tv_sec + random_time();
        next_change.tv_nsec = 0;
        light->next_change = next_change;
    }
}

// Function to print the state of a traffic light
void print_light(TrafficLight* light) {
    printf("Traffic light %d: %s\n", light->id, light->name);
    switch (light->state) {
        case 0:
            printf("Red\n");
            break;
        case 1:
            printf("Yellow\n");
            break;
        case 2:
            printf("Green\n");
            break;
    }
}

int main(void) {
    // Create an array of traffic lights
    TrafficLight lights[MAX_LIGHTS];

    // Initialize the lights
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i].id = i;
        lights[i].name = "Traffic Light";
        lights[i].state = random_light();
        struct timespec next_change;
        next_change.tv_sec = 0;
        next_change.tv_nsec = 0;
        lights[i].next_change = next_change;
    }

    // Main loop
    while (1) {
        // Update the state of each light
        for (int i = 0; i < MAX_LIGHTS; i++) {
            update_light(&lights[i]);
        }

        // Print the state of each light
        for (int i = 0; i < MAX_LIGHTS; i++) {
            print_light(&lights[i]);
        }

        // Sleep for 1 second
        sleep(1);
    }

    return 0;
}