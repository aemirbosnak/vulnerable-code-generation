//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SPEED_MAX 100
#define TURN_LEFT 'l'
#define TURN_RIGHT 'r'
#define INCREASE_SPEED '+'
#define DECREASE_SPEED '-'
#define QUIT 'q'

void display_menu() {
    printf("\n\tREMOTE CONTROL VEHICLE SIMULATION\n");
    printf("\t=================================\n");
    printf("\tSpeed Range: 0 - 100\n");
    printf("\tCommands:\n");
    printf("\t\tl - Turn Left\n");
    printf("\t\tr - Turn Right\n");
    printf("\t\t+ - Increase Speed\n");
    printf("\t\t- - Decrease Speed\n");
    printf("\t\tq - Quit\n");
    printf("\t=================================\n");
}

void simulate_vehicle() {
    srand(time(NULL));
    int speed = 0;
    int direction = rand() % 360;
    bool running = true;
    printf("Vehicle spinning up... Ready to run.\n");
    while (running) {
        printf("\nCurrent Speed: %d\n", speed);
        printf("Current Direction: %d\n", direction);
        char input;
        printf("Enter a command: ");
        scanf(" %c", &input);
        switch (input) {
            case TURN_LEFT:
                direction = direction - 90;
                if (direction < 0) {
                    direction += 360;
                }
                printf("Turning left!\n");
                break;
            case TURN_RIGHT:
                direction = direction + 90;
                if (direction >= 360) {
                    direction -= 360;
                }
                printf("Turning right!\n");
                break;
            case INCREASE_SPEED:
                if (speed < SPEED_MAX) {
                    speed += 10;
                    printf("Increasing speed!\n");
                } else {
                    printf("Vehicle already at maximum speed!\n");
                }
                break;
            case DECREASE_SPEED:
                if (speed > 0) {
                    speed -= 10;
                    printf("Decreasing speed!\n");
                } else {
                    printf("Vehicle already at minimum speed!\n");
                }
                break;
            case QUIT:
                running = false;
                break;
            default:
                printf("Invalid command. Please try again.\n");
        }
    }
    printf("Vehicle shutting down... Thank you for using our simulation!\n");
}

int main() {
    display_menu();
    simulate_vehicle();
    return 0;
}