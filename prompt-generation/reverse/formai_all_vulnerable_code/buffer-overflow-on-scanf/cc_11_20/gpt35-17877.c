//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: thoughtful
#include <stdio.h>

int main() {
    int speed = 0;
    int altitude = 0;
    int direction = 0;
    int battery = 100;
    int safety = 1;
    char input;

    printf("---Welcome to Drone Remote Control---\n");
    printf("Press w to increase speed, s to decrease speed\n");
    printf("Press a to turn left, d to turn right\n");
    printf("Press space to toggle safety mode\n");
    printf("Press q to exit the program\n\n");

    while (1) { // infinite loop until exit command is given
        printf("Current status: Speed: %d, Altitude: %d, Direction: %d, Battery: %d, Safety: %s\n", speed, altitude, direction, battery, safety == 1 ? "On" : "Off");
        printf("Enter command: ");
        scanf(" %c", &input);

        if (input == 'w') { // increase speed
            if (speed < 100) {
                speed += 10;
            }
        } else if (input == 's') { // decrease speed
            if (speed > 0) {
                speed -= 10;
            }
        } else if (input == 'a') { // turn left
            direction -= 15;
            if (direction < 0) {
                direction += 360;
            }
        } else if (input == 'd') { // turn right
            direction += 15;
            if (direction >= 360) {
                direction -= 360;
            }
        } else if (input == ' ') { // toggle safety
            if (safety == 1) {
                safety = 0;
                printf("Safety mode OFF.\n");
            } else {
                safety = 1;
                printf("Safety mode ON.\n");
            }
        } else if (input == 'q') { // exit program
            printf("Exiting program...\n");
            break;
        } else {
            printf("Invalid command.\n");
        }

        if (safety == 1) { // check safety before executing command
            if (speed > 0) {
                altitude += 5;
            }
            battery -= 1;
            if (battery <= 0) {
                printf("Battery low! Landing drone...\n");
                altitude = 0;
                speed = 0;
                battery = 0;
                break;
            }
        } else {
            printf("Safety mode is ON, command not executed.\n");
        }
    }

    return 0;
}