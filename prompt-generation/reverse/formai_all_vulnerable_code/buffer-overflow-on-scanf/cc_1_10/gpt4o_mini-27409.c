//GPT-4o-mini DATASET v1.0 Category: Traffic Light Controller ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Define color states for the traffic light
typedef enum { RED, YELLOW, GREEN } TrafficLightState;

// Structure to hold traffic light information
typedef struct {
    TrafficLightState state;
    int duration;  // Duration for each state in seconds
} TrafficLight;

// Function to simulate traffic light control
void* controlTrafficLight(void* arg) {
    TrafficLight* light = (TrafficLight*)arg;

    while (1) {
        // Set traffic light to RED
        light->state = RED;
        printf("Traffic Light: RED\n");
        sleep(light->duration);

        // Set traffic light to GREEN
        light->state = GREEN;
        printf("Traffic Light: GREEN\n");
        sleep(light->duration);

        // Set traffic light to YELLOW
        light->state = YELLOW;
        printf("Traffic Light: YELLOW\n");
        sleep(light->duration);
    }

    return NULL;
}

// Function to allow user to override the traffic light
void* userOverride(void* arg) {
    TrafficLight* light = (TrafficLight*)arg;
    char command;

    while (1) {
        printf("Enter 'r' to force RED, 'g' for GREEN, 'y' for YELLOW (or 'q' to quit): ");
        scanf(" %c", &command);

        switch (command) {
            case 'r':
                light->state = RED;
                printf("Traffic Light manually set to RED\n");
                break;
            case 'g':
                light->state = GREEN;
                printf("Traffic Light manually set to GREEN\n");
                break;
            case 'y':
                light->state = YELLOW;
                printf("Traffic Light manually set to YELLOW\n");
                break;
            case 'q':
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid command. Please try again.\n");
        }
    }

    return NULL;
}

int main() {
    TrafficLight light;
    light.duration = 5;  // Default duration for each state is 5 seconds

    pthread_t lightThread, overrideThread;

    // Create thread to control traffic light
    pthread_create(&lightThread, NULL, controlTrafficLight, (void*)&light);

    // Create thread for user input override
    pthread_create(&overrideThread, NULL, userOverride, (void*)&light);

    // Wait for threads to finish (this will not happen, but just for safety)
    pthread_join(lightThread, NULL);
    pthread_join(overrideThread, NULL);

    return 0;
}