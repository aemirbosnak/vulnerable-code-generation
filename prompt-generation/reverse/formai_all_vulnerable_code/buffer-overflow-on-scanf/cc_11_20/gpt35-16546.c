//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SPEED 100
#define MIN_SPEED 0

typedef struct {
    int speed;
    int direction;
    bool isOn;
} Vehicle;

enum Command {
    SPEED_UP,
    SLOW_DOWN,
    TURN_LEFT,
    TURN_RIGHT,
    START_ENGINE,
    STOP_ENGINE,
    EXIT
};

void handleCommand(enum Command command, Vehicle* vehicle) {
    switch (command) {
        case SPEED_UP:
            if (vehicle->isOn) {
                vehicle->speed += 10;
                if (vehicle->speed > MAX_SPEED) {
                    vehicle->speed = MAX_SPEED;
                }
            } else {
                printf("Vehicle is not turned on.\n");
            }
            break;
        case SLOW_DOWN:
            if (vehicle->isOn) {
                vehicle->speed -= 10;
                if (vehicle->speed < MIN_SPEED) {
                    vehicle->speed = MIN_SPEED;
                }
            } else {
                printf("Vehicle is not turned on.\n");
            }
            break;
        case TURN_LEFT:
            if (vehicle->isOn) {
                vehicle->direction -= 10;
                if (vehicle->direction < 0) {
                    vehicle->direction += 360;
                }
            } else {
                printf("Vehicle is not turned on.\n");
            }
            break;
        case TURN_RIGHT:
            if (vehicle->isOn) {
                vehicle->direction += 10;
                if (vehicle->direction >= 360) {
                    vehicle->direction -= 360;
                }
            } else {
                printf("Vehicle is not turned on.\n");
            }
            break;
        case START_ENGINE:
            if (vehicle->isOn) {
                printf("Vehicle is already turned on.\n");
            } else {
                vehicle->isOn = true;
                printf("Vehicle turned on.\n");
            }
            break;
        case STOP_ENGINE:
            if (!vehicle->isOn) {
                printf("Vehicle is already turned off.\n");
            } else if (vehicle->speed > 0) {
                printf("Cannot turn off vehicle while it is still moving.\n");
            } else {
                vehicle->isOn = false;
                printf("Vehicle turned off.\n");
            }
            break;
        case EXIT:
            printf("Exiting program.\n");
            exit(0);
    }
}

int main() {
    Vehicle vehicle = {
        .speed = 0,
        .direction = 0,
        .isOn = false
    };

    while (true) {
        printf("\nCurrent Vehicle Status:\n");
        printf("Speed: %d\n", vehicle.speed);
        printf("Direction: %d\n", vehicle.direction);
        printf("Ignition: %s\n", vehicle.isOn ? "ON" : "OFF");

        printf("\nEnter a command:\n");
        printf("1 - Speed up\n");
        printf("2 - Slow down\n");
        printf("3 - Turn left\n");
        printf("4 - Turn right\n");
        printf("5 - Start engine\n");
        printf("6 - Stop engine\n");
        printf("7 - Exit\n");

        int commandNum;
        if (scanf("%d", &commandNum) <= 0) {
            printf("Invalid command. Please enter a number between 1 and 7.\n");
            continue;
        }

        if (commandNum < 1 || commandNum > 7) {
            printf("Invalid command. Please enter a number between 1 and 7.\n");
            continue;
        }

        enum Command command = (enum Command) commandNum;
        handleCommand(command, &vehicle);
    }

    return 0;
}