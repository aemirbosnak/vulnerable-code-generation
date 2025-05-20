//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: minimalist
#include <stdio.h>

#define MAX_SPEED 100 // Max speed of the remote control vehicle
#define MIN_SPEED 0 // Min speed of the remote control vehicle

typedef struct {
    int speed;
    int distance;
    int battery_life;
} Vehicle;

void forward(Vehicle *vehicle) {
    if (vehicle->speed < MAX_SPEED) {
        vehicle->speed++;
        vehicle->distance += vehicle->speed;
        vehicle->battery_life--;
        printf("Vehicle moved forward at a speed of %d. Distance travelled: %d. Battery life left: %d\n", vehicle->speed, vehicle->distance, vehicle->battery_life);
    } else {
        printf("Vehicle is already at max speed of %d\n", MAX_SPEED);
    }
}

void backward(Vehicle *vehicle) {
    if (vehicle->speed > MIN_SPEED) {
        vehicle->speed--;
        vehicle->distance -= vehicle->speed;
        vehicle->battery_life--;
        printf("Vehicle moved backward at a speed of %d. Distance travelled: %d. Battery life left: %d\n", vehicle->speed, vehicle->distance, vehicle->battery_life);
    } else {
        printf("Vehicle is already at min speed of %d\n", MIN_SPEED);
    }
}

void stop(Vehicle *vehicle) {
    vehicle->speed = 0;
    printf("Vehicle stopped. Distance travelled: %d. Battery life left: %d\n", vehicle->distance, vehicle->battery_life);
}

int main() {
    Vehicle vehicle;
    vehicle.speed = 0;
    vehicle.distance = 0;
    vehicle.battery_life = 100;

    printf("Remote Control Vehicle Simulation\n");
    printf("Commands:\n");
    printf("f - Move forward\n");
    printf("b - Move backward\n");
    printf("s - Stop\n");
    printf("q - Quit\n");

    char command;
    while (1) {
        printf("Enter command: ");
        scanf(" %c", &command);

        switch (command) {
            case 'f':
                forward(&vehicle);
                break;
            case 'b':
                backward(&vehicle);
                break;
            case 's':
                stop(&vehicle);
                break;
            case 'q':
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid command\n");
        }
    }

    return 0;
}