//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int main() {
    int altitude = 0; // current altitude
    int speed = 0; // current speed
    int direction = 0; // current direction (degrees)
    int battery = 100; // current battery percentage
    char command; // user command

    printf("Welcome to the C Drone Remote Control!\n");

    while(1) {
        printf("\nCurrent altitude: %d\n", altitude);
        printf("Current speed: %d\n", speed);
        printf("Current direction: %d degrees\n", direction);
        printf("Current battery: %d%%\n", battery);

        printf("\nEnter command (f = forward, b = backward, u = up, d = down, l = left, r = right, s = stop, c = charge): ");
        scanf(" %c", &command);

        switch(command) {
            case 'f':
                printf("Moving forward...\n");
                speed += 5;
                break;
            case 'b':
                printf("Moving backward...\n");
                speed -= 5;
                break;
            case 'u':
                printf("Moving up...\n");
                altitude += 10;
                break;
            case 'd':
                printf("Moving down...\n");
                altitude -= 10;
                break;
            case 'l':
                printf("Turning left...\n");
                direction -= 10;
                break;
            case 'r':
                printf("Turning right...\n");
                direction += 10;
                break;
            case 's':
                printf("Stopping...\n");
                speed = 0;
                break;
            case 'c':
                printf("Charging...\n");
                battery = 100;
                break;
            default:
                printf("Invalid command. Please try again.\n");
                break;
        }

        if(altitude < 0) {
            printf("Drone crashed! Game over.\n");
            break;
        }

        if(speed > 50) {
            printf("Warning: Drone is moving too fast!\n");
        }

        if(speed < -50) {
            printf("Warning: Drone is moving backwards too fast!\n");
        }

        if(battery <= 0) {
            printf("Battery drained! Game over.\n");
            break;
        }

        battery -= 1;
    }

    printf("Thanks for playing!\n");

    return 0;
}