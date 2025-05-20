//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the constants that will be used in this simulation.
#define MAX_SPEED 100.0
#define MIN_SPEED 0.0
#define TURN_RATE 5.0
#define MAX_BATTERY_LEVEL 100
#define MIN_BATTERY_LEVEL 0
#define BATTERY_DRAIN_RATE 0.5

int main() {
    // Initialise the variables used in the simulation
    bool is_on = false;
    float speed = 0.0;
    float direction = 0.0;
    int battery_level = MAX_BATTERY_LEVEL;
    
    // Run the simulation until the battery dies
    while (battery_level > MIN_BATTERY_LEVEL) {
        // Print the current state of the vehicle
        printf("Vehicle state: ON=%d, speed=%.2f, direction=%.2f, battery=%d\n", is_on, speed, direction, battery_level);
        
        // Get the user's input
        char input;
        printf("Enter command (s)peed up, (b)rake, (l)eft, (r)ight, (q)uit: ");
        scanf(" %c", &input);
        
        // Handle the input
        switch (input) {
            case 's':
                if (is_on && speed < MAX_SPEED && battery_level > 0) {
                    speed += 5.0;
                    battery_level -= BATTERY_DRAIN_RATE * speed;
                }
                break;
            case 'b':
                if (is_on && speed > 0.0 && battery_level > 0) {
                    speed -= 10.0;
                    if (speed < 0) {
                        speed = 0;
                    }
                    battery_level -= BATTERY_DRAIN_RATE * speed;
                }
                break;
            case 'l':
                if (is_on && battery_level > 0) {
                    direction += TURN_RATE;
                    if (direction >= 360.0) {
                        direction -= 360.0;
                    }
                    battery_level -= BATTERY_DRAIN_RATE * speed;
                }
                break;
            case 'r':
                if (is_on && battery_level > 0) {
                    direction -= TURN_RATE;
                    if (direction < 0.0) {
                        direction += 360.0;
                    }
                    battery_level -= BATTERY_DRAIN_RATE * speed;
                }
                break;
            case 'q':
                printf("Turning off the vehicle.\n");
                is_on = false;
                break;
            default:
                printf("Invalid command! Try again.\n");
        }
    }
    
    printf("Battery has died.\n");
    return 0;
}