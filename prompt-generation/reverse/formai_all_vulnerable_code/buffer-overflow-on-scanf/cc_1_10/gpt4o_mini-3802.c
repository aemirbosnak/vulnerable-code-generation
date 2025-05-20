//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Define the structure for the remote control vehicle
typedef struct {
    int x;               // Current x position
    int y;               // Current y position
    char direction;      // Current direction 'N', 'E', 'S', 'W'
    int speed;          // Current speed of the vehicle
} RC_Vehicle;

// Function to initialize the vehicle
void initializeVehicle(RC_Vehicle *vehicle) {
    vehicle->x = 0;
    vehicle->y = 0;
    vehicle->direction = 'N';
    vehicle->speed = 0;
}

// Function to display the vehicle's current position and status
void displayStatus(RC_Vehicle *vehicle) {
    printf("Vehicle Position: (%d, %d)\n", vehicle->x, vehicle->y);
    printf("Direction: %c\n", vehicle->direction);
    printf("Speed: %d units\n", vehicle->speed);
}

// Function to change the speed of the vehicle
void setSpeed(RC_Vehicle *vehicle, int newSpeed) {
    vehicle->speed = newSpeed;
    printf("Speed changed to %d units.\n", vehicle->speed);
}

// Function to turn the vehicle
void turn(RC_Vehicle *vehicle, char newDirection) {
    if (newDirection == 'N' || newDirection == 'E' || newDirection == 'S' || newDirection == 'W') {
        vehicle->direction = newDirection;
        printf("Turned to direction: %c\n", vehicle->direction);
    } else {
        printf("Invalid direction. Please use 'N', 'E', 'S', or 'W'.\n");
    }
}

// Function to move the vehicle based on its direction and speed
void move(RC_Vehicle *vehicle) {
    switch (vehicle->direction) {
        case 'N':
            vehicle->y += vehicle->speed;
            break;
        case 'E':
            vehicle->x += vehicle->speed;
            break;
        case 'S':
            vehicle->y -= vehicle->speed;
            break;
        case 'W':
            vehicle->x -= vehicle->speed;
            break;
    }
    printf("Moved to: (%d, %d)\n", vehicle->x, vehicle->y);
}

// Main function to run the simulation
int main() {
    RC_Vehicle vehicle;
    initializeVehicle(&vehicle);
    displayStatus(&vehicle);

    char command;
    int value;

    while (1) {
        printf("\n--- Remote Control Commands ---\n");
        printf("1. Set Speed (1-10)\n");
        printf("2. Turn Direction (N,E,S,W)\n");
        printf("3. Move Vehicle\n");
        printf("4. Display Status\n");
        printf("5. Exit\n");
        printf("Enter command: ");
        scanf(" %c", &command);

        switch (command) {
            case '1':
                printf("Enter speed (1-10): ");
                scanf("%d", &value);
                if (value >= 1 && value <= 10) {
                    setSpeed(&vehicle, value);
                } else {
                    printf("Invalid speed. Please enter a value between 1 and 10.\n");
                }
                break;
            case '2':
                printf("Enter direction (N,E,S,W): ");
                scanf(" %c", &command);
                turn(&vehicle, command);
                break;
            case '3':
                move(&vehicle);
                break;
            case '4':
                displayStatus(&vehicle);
                break;
            case '5':
                printf("Exiting simulation...\n");
                exit(0);
            default:
                printf("Invalid command. Please try again.\n");
                break;
        }

        sleep(1); // Adding a delay for simulation realism
    }

    return 0;
}