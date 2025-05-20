//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define SPEED_INCREMENT 5
#define SPEED_LIMIT 60

#define STEERING_INCREMENT 10
#define STEERING_MAX_ANGLE 45

int main() {
    int speed = 0;
    int target_speed = 0;
    int steering = 0;
    int target_steering = 0;

    char input = ' ';

    while (input != 'q') {
        // Read user input
        scanf("%c", &input);

        // Update speed and steering based on input
        if (input == 'w') {
            target_speed += SPEED_INCREMENT;
        } else if (input == 's') {
            target_speed -= SPEED_INCREMENT;
        } else if (input == 'a') {
            target_steering -= STEERING_INCREMENT;
        } else if (input == 'd') {
            target_steering += STEERING_INCREMENT;
        }

        // Limit speed and steering within range
        if (target_speed > SPEED_LIMIT) {
            target_speed = SPEED_LIMIT;
        } else if (target_speed < 0) {
            target_speed = 0;
        }
        if (target_steering > STEERING_MAX_ANGLE) {
            target_steering = STEERING_MAX_ANGLE;
        } else if (target_steering < -STEERING_MAX_ANGLE) {
            target_steering = -STEERING_MAX_ANGLE;
        }

        // Update speed and steering gradually
        if (target_speed > speed) {
            speed++;
        } else if (target_speed < speed) {
            speed--;
        }
        if (target_steering > steering) {
            steering++;
        } else if (target_steering < steering) {
            steering--;
        }

        // Print status
        printf("Speed: %d\n", speed);
        printf("Steering: %d\n", steering);
    }

    return 0;
}