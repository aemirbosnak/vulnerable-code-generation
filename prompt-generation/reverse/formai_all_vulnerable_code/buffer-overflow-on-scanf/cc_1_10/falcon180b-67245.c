//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 100
#define TURN_RATE 10
#define ACCELERATION_RATE 5

// Define the structure of the remote control vehicle
typedef struct {
    int speed;
    int direction;
    int acceleration;
} Vehicle;

// Initialize the remote control vehicle with default values
void initializeVehicle(Vehicle* vehicle) {
    vehicle->speed = 0;
    vehicle->direction = 0;
    vehicle->acceleration = 0;
}

// Move the remote control vehicle forward
void moveForward(Vehicle* vehicle) {
    vehicle->speed += ACCELERATION_RATE;
    if (vehicle->speed > MAX_SPEED) {
        vehicle->speed = MAX_SPEED;
    }
}

// Turn the remote control vehicle left or right
void turn(Vehicle* vehicle, int direction) {
    vehicle->direction += direction * TURN_RATE;
    if (vehicle->direction > 360) {
        vehicle->direction -= 360;
    } else if (vehicle->direction < 0) {
        vehicle->direction += 360;
    }
}

// Stop the remote control vehicle
void stop(Vehicle* vehicle) {
    vehicle->speed = 0;
    vehicle->acceleration = 0;
}

// Main function to simulate the remote control vehicle
int main() {
    Vehicle vehicle;
    initializeVehicle(&vehicle);

    int choice;
    while (1) {
        printf("Enter your choice:\n");
        printf("1. Move Forward\n");
        printf("2. Turn Left\n");
        printf("3. Turn Right\n");
        printf("4. Stop\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                moveForward(&vehicle);
                break;
            case 2:
                turn(&vehicle, -1);
                break;
            case 3:
                turn(&vehicle, 1);
                break;
            case 4:
                stop(&vehicle);
                break;
            default:
                printf("Invalid choice!\n");
        }

        printf("Current speed: %d\n", vehicle.speed);
        printf("Current direction: %d\n", vehicle.direction);
        printf("\n");
    }

    return 0;
}