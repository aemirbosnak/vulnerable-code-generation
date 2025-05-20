//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

// Define the traffic light states
#define RED_LIGHT 0
#define YELLOW_LIGHT 1
#define GREEN_LIGHT 2

// Define the duration of each light in seconds
#define RED_LIGHT_DURATION 10
#define YELLOW_LIGHT_DURATION 5
#define GREEN_LIGHT_DURATION 15

// Define the number of intersections
#define NUM_INTERSECTIONS 4

// Define the intersection structures
typedef struct {
    char* name;
    int current_light;
    pthread_t thread;
} Intersection;

// Function to run the traffic light controller for an intersection
void* traffic_light_controller(void* arg) {
    Intersection* intersection = (Intersection*) arg;

    // Initialize the traffic light
    intersection->current_light = RED_LIGHT;

    // Loop indefinitely
    while(1) {
        // Sleep for the duration of the current light
        switch(intersection->current_light) {
            case RED_LIGHT:
                sleep(RED_LIGHT_DURATION);
                break;
            case YELLOW_LIGHT:
                sleep(YELLOW_LIGHT_DURATION);
                break;
            case GREEN_LIGHT:
                sleep(GREEN_LIGHT_DURATION);
                break;
        }

        // Rotate to the next light
        switch(intersection->current_light) {
            case RED_LIGHT:
                intersection->current_light = GREEN_LIGHT;
                break;
            case YELLOW_LIGHT:
                intersection->current_light = RED_LIGHT;
                break;
            case GREEN_LIGHT:
                intersection->current_light = YELLOW_LIGHT;
                break;
        }
    }

    return NULL;
}

// Function to create the intersections and start the traffic light controllers
void create_intersections() {
    Intersection intersections[NUM_INTERSECTIONS];

    // Set up the intersection structures
    intersections[0].name = "Intersection 1";
    intersections[0].current_light = RED_LIGHT;
    intersections[1].name = "Intersection 2";
    intersections[1].current_light = RED_LIGHT;
    intersections[2].name = "Intersection 3";
    intersections[2].current_light = RED_LIGHT;
    intersections[3].name = "Intersection 4";
    intersections[3].current_light = RED_LIGHT;

    // Create the intersection threads
    for(int i=0; i<NUM_INTERSECTIONS; i++) {
        pthread_create(&intersections[i].thread, NULL, traffic_light_controller, &intersections[i]);
    }
}

// Main function
int main() {
    srand(time(NULL));

    // Create the intersections
    create_intersections();

    // Wait for user input to exit
    printf("Press enter to exit...\n");
    getchar();

    return 0;
}