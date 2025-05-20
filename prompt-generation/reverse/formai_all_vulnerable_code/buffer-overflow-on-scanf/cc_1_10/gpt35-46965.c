//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FORWARD 1
#define BACKWARD -1
#define LEFT 2
#define RIGHT -2
#define STOP 0

struct Vehicle {
    int direction;
    int speed;
    int battery;
};

void move(struct Vehicle *vehicle, int direction, int speed) {
    if (vehicle->battery > 0) {
        vehicle->direction = direction;
        vehicle->speed = speed;
        vehicle->battery--;
        printf("Moving %s at %d speed with battery level %d\n",
                direction == FORWARD ? "forward" : "backward",
                speed, vehicle->battery);
        usleep(1000000);
    } else {
        printf("Battery low, cannot move!\n");
    }
}

void stop(struct Vehicle *vehicle) {
    vehicle->direction = STOP;
    vehicle->speed = 0;
    printf("Vehicle stopped\n");
    usleep(500000);
}

int main() {
    struct Vehicle remoteVehicle = {STOP, 0, 10};
    
    printf("Remote Control Vehicle Simulation\n\n");
    printf("Commands:\n");
    printf("  - f <speed>: move forward at specified speed (0-10)\n");
    printf("  - b <speed>: move backward at specified speed (0-10)\n");
    printf("  - l: turn left\n");
    printf("  - r: turn right\n");
    printf("  - s: stop\n");
    printf("  - q: quit\n\n");

    char command;
    int speed;

    while (1) {
        printf("Enter command:");
        scanf(" %c", &command);

        switch (command) {
            case 'f':
                scanf("%d", &speed);
                move(&remoteVehicle, FORWARD, speed);
                break;
            case 'b':
                scanf("%d", &speed);
                move(&remoteVehicle, BACKWARD, speed);
                break;
            case 'l':
                move(&remoteVehicle, LEFT, 0);
                break;
            case 'r':
                move(&remoteVehicle, RIGHT, 0);
                break;
            case 's':
                stop(&remoteVehicle);
                break;
            case 'q':
                printf("Quitting...\n");
                exit(0);
            default:
                printf("Invalid command!\n");
                break;
        }
    }

    return 0;
}