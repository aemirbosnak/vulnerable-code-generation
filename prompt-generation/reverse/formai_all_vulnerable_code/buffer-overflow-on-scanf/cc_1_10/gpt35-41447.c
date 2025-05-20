//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: safe
/* C Remote control Vehicle Simulation Example Program */

#include <stdio.h>
#include <stdlib.h>

/* Define constants for simulation */
#define MAX_SPEED 10
#define MAX_ANGLE 60

/* Define variables for simulation */
int current_speed = 0;
int current_angle = 0;

/* Function to increase vehicle speed */
void increase_speed() {
    if (current_speed < MAX_SPEED) {
        current_speed++;
    }
}

/* Function to decrease vehicle speed */
void decrease_speed() {
    if (current_speed > 0) {
        current_speed--;
    }
}

/* Function to turn the vehicle left */
void turn_left() {
    if (current_angle > -MAX_ANGLE) {
        current_angle--;
    }
}

/* Function to turn the vehicle right */
void turn_right() {
    if (current_angle < MAX_ANGLE) {
        current_angle++;
    }
}

int main() {
    char input;

    /* Loop until 'q' is entered */
    do {
        /* Display current speed and angle */
        printf("Current Speed: %d\n", current_speed);
        printf("Current Angle: %d\n", current_angle);

        /* Prompt for input */
        printf("Enter Command (s = speed up, d = slow down, l = turn left, r = turn right, q = quit): ");
        scanf(" %c", &input);

        /* Process input */
        switch (input) {
            case 's':
                increase_speed();
                break;
            case 'd':
                decrease_speed();
                break;
            case 'l':
                turn_left();
                break;
            case 'r':
                turn_right();
                break;
            case 'q':
                printf("Exiting Program...\n");
                break;
            default:
                printf("Invalid Command!\n");
        }

        printf("\n");
    } while (input != 'q');

    return 0;
}