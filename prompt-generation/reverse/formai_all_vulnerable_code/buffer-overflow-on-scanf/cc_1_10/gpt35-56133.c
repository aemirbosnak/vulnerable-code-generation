//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the C Remote Control Vehicle Simulation!\n");

    int speed = 0;
    int velocity = 0;
    int direction = 0;
    char command;

    srand(time(0));

    printf("The vehicle is currently stationary.\n");

    while (1) {
        printf("Enter a command (f: accelerate, b: brake, l: turn left, r: turn right, q: quit): ");
        scanf(" %c", &command);

        if (command == 'q') {
            printf("Program terminated by user.\n");
            break;
        }

        int randint = (rand() % 10) - 4; // Random integer between -4 to 5, to simulate slight change in speed/velocity/direction
        switch (command) {
            case 'f':
                speed += 10;
                velocity += speed + randint;
                printf("Accelerating! Current speed: %d, Current velocity: %d\n", speed, velocity);
                break;

            case 'b':
                speed -= 10;
                if (speed < 0) { // Ensure speed doesn't go negative
                    speed = 0;
                    velocity = 0;
                }
                else {
                    velocity += speed + randint;
                }
                printf("Braking! Current speed: %d, Current velocity: %d\n", speed, velocity);
                break;

            case 'l':
                direction -= 10;
                printf("Turning left! Current direction: %d\n", direction);
                break;

            case 'r':
                direction += 10;
                printf("Turning right! Current direction: %d\n", direction);
                break;

            default:
                printf("Invalid command entered. Please try again.\n");
                break;
        }
    }

    return 0;
}