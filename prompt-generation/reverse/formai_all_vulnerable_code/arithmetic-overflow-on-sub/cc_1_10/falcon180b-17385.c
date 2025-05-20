//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT 0
#define YELLOW_LIGHT 1
#define GREEN_LIGHT 2
#define LIGHT_CHANGE_DELAY 5 // seconds

// Function prototypes
void initialize_lights(void);
void change_lights(void);

int main(void) {
    initialize_lights();

    while (1) {
        change_lights();
    }

    return 0;
}

// Initialize the lights to red for all directions
void initialize_lights(void) {
    printf("Initializing lights...\n");
    printf("All lights set to red.\n");
}

// Change the lights according to the current state
void change_lights(void) {
    static int current_state = RED_LIGHT;
    static time_t last_change_time = 0;

    // Check if it's time to change the lights
    time_t current_time = time(NULL);
    if (current_time - last_change_time >= LIGHT_CHANGE_DELAY) {
        last_change_time = current_time;

        // Change to the next state
        switch (current_state) {
            case RED_LIGHT:
                printf("Changing from red to green for north-south traffic.\n");
                current_state = GREEN_LIGHT;
                break;
            case YELLOW_LIGHT:
                printf("Changing from yellow to red for north-south traffic.\n");
                current_state = RED_LIGHT;
                break;
            case GREEN_LIGHT:
                printf("Changing from green to yellow for north-south traffic.\n");
                current_state = YELLOW_LIGHT;
                break;
        }
    }
}