//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct remoteControlVehicle {
    int speed;
    int direction;
} Rcv;

void moveForward(Rcv *vehicle) {
    vehicle->speed = 50;
    vehicle->direction = 0;
    printf("Vehicle is moving forward.\n");
}

void moveBackward(Rcv *vehicle) {
    vehicle->speed = 30;
    vehicle->direction = 180;
    printf("Vehicle is moving backward.\n");
}

void turnLeft(Rcv *vehicle) {
    vehicle->direction -= 30;
    printf("Vehicle is turning left.\n");
}

void turnRight(Rcv *vehicle) {
    vehicle->direction += 30;
    printf("Vehicle is turning right.\n");
}

int main() {
    int choice;
    Rcv vehicle;
    vehicle.speed = 0;
    vehicle.direction = 0;
    printf("Welcome to Remote Control Vehicle Simulation!\n");
    printf("Press 1 to move forward.\nPress 2 to move backward.\nPress 3 to turn left.\nPress 4 to turn right.\nPress 5 to exit.\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                moveForward(&vehicle);
                break;
            case 2:
                moveBackward(&vehicle);
                break;
            case 3:
                turnLeft(&vehicle);
                break;
            case 4:
                turnRight(&vehicle);
                break;
            case 5:
                printf("Exiting program...");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("Speed: %d | Direction: %d\n", vehicle.speed, vehicle.direction);
    }
    return 0;
}