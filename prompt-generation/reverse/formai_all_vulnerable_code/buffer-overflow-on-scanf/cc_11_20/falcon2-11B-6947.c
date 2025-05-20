//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 100
#define MIN_SPEED -100

// Joystick states
#define JOYSTICK_DOWN 1
#define JOYSTICK_UP 2
#define JOYSTICK_LEFT 4
#define JOYSTICK_RIGHT 8

int main() {
    // Initialize joystick state
    int joystick_state = 0;

    // Initialize vehicle speed and direction
    int speed = 0;
    int direction = 0;

    // Main loop
    while (1) {
        // Read joystick state
        scanf("%d", &joystick_state);

        // Update vehicle speed and direction
        switch (joystick_state) {
            case JOYSTICK_DOWN:
                speed += 10;
                break;
            case JOYSTICK_UP:
                speed -= 10;
                break;
            case JOYSTICK_LEFT:
                direction -= 10;
                break;
            case JOYSTICK_RIGHT:
                direction += 10;
                break;
        }

        // Limit speed and direction
        speed = (speed > MAX_SPEED)? MAX_SPEED : speed;
        speed = (speed < MIN_SPEED)? MIN_SPEED : speed;

        direction = (direction > 180)? 180 : direction;
        direction = (direction < -180)? -180 : direction;

        // Update vehicle position
        if (direction < 0) {
            printf("Vehicle is turning left.\n");
        } else if (direction > 0) {
            printf("Vehicle is turning right.\n");
        } else {
            printf("Vehicle is going straight.\n");
        }

        printf("Vehicle speed: %d\n", speed);

        // Sleep for 0.1 seconds
        sleep(0.1);
    }
}