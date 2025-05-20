//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare the car's state
typedef enum {
    PARKED,
    DRIVING,
    CRASHED
} car_state;

// Declare the car's controls
typedef enum {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    STOP
} car_control;

// Initialize the car's state and controls
car_state state = PARKED;
car_control control = STOP;

// Main simulation loop
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Run the simulation until the car crashes
    while (state != CRASHED) {
        // Get the user's input
        printf("Enter a command (forward, backward, left, right, stop): ");
        char input[20];
        scanf("%s", input);

        // Parse the user's input
        if (strcmp(input, "forward") == 0) {
            control = FORWARD;
        } else if (strcmp(input, "backward") == 0) {
            control = BACKWARD;
        } else if (strcmp(input, "left") == 0) {
            control = LEFT;
        } else if (strcmp(input, "right") == 0) {
            control = RIGHT;
        } else if (strcmp(input, "stop") == 0) {
            control = STOP;
        } else {
            printf("Invalid command!\n");
            continue;
        }

        // Update the car's state based on the user's input
        switch (control) {
            case FORWARD:
                if (state == PARKED) {
                    state = DRIVING;
                } else if (state == DRIVING) {
                    // The car is already moving forward, so do nothing
                } else if (state == CRASHED) {
                    // The car is crashed, so do nothing
                }
                break;
            case BACKWARD:
                if (state == PARKED) {
                    // The car is parked, so do nothing
                } else if (state == DRIVING) {
                    state = BACKWARD;
                } else if (state == CRASHED) {
                    // The car is crashed, so do nothing
                }
                break;
            case LEFT:
                if (state == PARKED) {
                    // The car is parked, so do nothing
                } else if (state == DRIVING) {
                    state = LEFT;
                } else if (state == CRASHED) {
                    // The car is crashed, so do nothing
                }
                break;
            case RIGHT:
                if (state == PARKED) {
                    // The car is parked, so do nothing
                } else if (state == DRIVING) {
                    state = RIGHT;
                } else if (state == CRASHED) {
                    // The car is crashed, so do nothing
                }
                break;
            case STOP:
                if (state == PARKED) {
                    // The car is already parked, so do nothing
                } else if (state == DRIVING) {
                    state = PARKED;
                } else if (state == CRASHED) {
                    // The car is crashed, so do nothing
                }
                break;
        }

        // Simulate the car's movement
        if (state == DRIVING) {
            // The car is moving forward, so increment its position
            printf("The car is moving forward.\n");
        } else if (state == BACKWARD) {
            // The car is moving backward, so decrement its position
            printf("The car is moving backward.\n");
        } else if (state == LEFT) {
            // The car is turning left, so decrement its orientation
            printf("The car is turning left.\n");
        } else if (state == RIGHT) {
            // The car is turning right, so increment its orientation
            printf("The car is turning right.\n");
        } else if (state == PARKED) {
            // The car is parked, so do nothing
            printf("The car is parked.\n");
        }

        // Check if the car has crashed
        if (rand() % 100 < 10) {
            state = CRASHED;
            printf("The car has crashed!\n");
        }
    }

    return 0;
}