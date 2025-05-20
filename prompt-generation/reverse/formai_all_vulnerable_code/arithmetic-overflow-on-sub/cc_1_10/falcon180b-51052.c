//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the time for each light
#define RED_LIGHT_TIME 10
#define YELLOW_LIGHT_TIME 3
#define GREEN_LIGHT_TIME 20

// Define the number of intersections
#define NUM_INTERSECTIONS 4

// Define the intersection names
char *intersection_names[NUM_INTERSECTIONS] = {"Intersection 1", "Intersection 2", "Intersection 3", "Intersection 4"};

// Define the intersection struct
typedef struct {
    int id;
    int light_state;
    time_t last_change_time;
} Intersection;

// Define the intersection array
Intersection intersections[NUM_INTERSECTIONS];

// Define the light states
#define RED_LIGHT 0
#define YELLOW_LIGHT 1
#define GREEN_LIGHT 2

// Define the light colors
char *light_colors[3] = {"Red", "Yellow", "Green"};

// Define the light state function
void set_light_state(Intersection *intersection, int new_state) {
    intersection->light_state = new_state;
    intersection->last_change_time = time(NULL);
}

// Define the main function
int main() {
    // Initialize the intersections
    for (int i = 0; i < NUM_INTERSECTIONS; i++) {
        intersections[i].id = i + 1;
        intersections[i].light_state = RED_LIGHT;
    }

    // Simulate the traffic lights
    while (1) {
        // Sleep for 1 second
        sleep(1);

        // Loop through each intersection
        for (int i = 0; i < NUM_INTERSECTIONS; i++) {
            // Get the current time
            time_t current_time = time(NULL);

            // Check if the light needs to change
            if (current_time - intersections[i].last_change_time >= (RED_LIGHT_TIME + YELLOW_LIGHT_TIME + GREEN_LIGHT_TIME)) {
                // Change the light state
                int new_state = (intersections[i].light_state + 1) % 3;
                set_light_state(&intersections[i], new_state);

                // Print the new light state
                printf("Intersection %d: %s light\n", intersections[i].id, light_colors[new_state]);
            }
        }
    }

    return 0;
}