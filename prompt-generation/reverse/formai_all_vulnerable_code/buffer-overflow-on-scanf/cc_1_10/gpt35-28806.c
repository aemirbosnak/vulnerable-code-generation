//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define constants
#define MAX_SPEED 10
#define MAX_TURN_ANGLE 45

// Define structures
typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position position;
    int direction; // 0: North, 1: East, 2: South, 3: West
    int speed;
} Vehicle;

// Define functions
void move_forward(Vehicle *vehicle) {
    switch (vehicle->direction) {
        case 0: // North
            vehicle->position.y += vehicle->speed;
            break;
        case 1: // East
            vehicle->position.x += vehicle->speed;
            break;
        case 2: // South
            vehicle->position.y -= vehicle->speed;
            break;
        case 3: // West
            vehicle->position.x -= vehicle->speed;
            break;
    }
}

void turn_left(Vehicle *vehicle) {
    vehicle->direction = (vehicle->direction - 1) % 4; // Reduce the direction by 1, loop back to 3 if less than 0
}

void turn_right(Vehicle *vehicle) {
    vehicle->direction = (vehicle->direction + 1) % 4; // Increase the direction by 1, loop back to 0 if greater than 3
}

int main() {
    // Initialize the vehicle
    Vehicle vehicle;
    vehicle.position.x = 0;
    vehicle.position.y = 0;
    vehicle.direction = 0;
    vehicle.speed = 0;

    // Start the program loop
    while (true) {
        // Display menu
        printf("Remote control vehicle simulation\n");
        printf("Current position: (%d, %d)\n", vehicle.position.x, vehicle.position.y);
        printf("Current direction: ");
        switch (vehicle.direction) {
            case 0:
                printf("North\n");
                break;
            case 1:
                printf("East\n");
                break;
            case 2:
                printf("South\n");
                break;
            case 3:
                printf("West\n");
                break;
        }
        printf("Current speed: %d\n", vehicle.speed);
        printf("1. Accelerate\n");
        printf("2. Decelerate\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Quit\n");

        // Get user input
        int input;
        scanf("%d", &input);

        // Process the user input
        switch (input) {
            case 1:
                if (vehicle.speed < MAX_SPEED) {
                    vehicle.speed++;
                }
                break;
            case 2:
                if (vehicle.speed > 0) {
                    vehicle.speed--;
                }
                break;
            case 3:
                turn_left(&vehicle);
                break;
            case 4:
                turn_right(&vehicle);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid input\n");
                break;
        }

        // Move the vehicle
        move_forward(&vehicle);
    }

    return 0;
}