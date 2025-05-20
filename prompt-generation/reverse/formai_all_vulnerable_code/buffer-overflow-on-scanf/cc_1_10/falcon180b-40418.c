//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the structure of a remote control vehicle
typedef struct {
    int speed;
    int direction;
    int battery_level;
} Vehicle;

// Function to initialize a new vehicle with default values
Vehicle* create_vehicle() {
    Vehicle* v = (Vehicle*) malloc(sizeof(Vehicle));
    v->speed = 0;
    v->direction = 0;
    v->battery_level = 100;
    return v;
}

// Function to move the vehicle forward at the given speed
void move_forward(Vehicle* v, int speed) {
    printf("The vehicle moves forward at %d mph.\n", speed);
    v->speed = speed;
    v->direction = 1;
}

// Function to turn the vehicle left or right
void turn(Vehicle* v, int direction) {
    if (direction == 1) {
        printf("The vehicle turns left.\n");
    } else {
        printf("The vehicle turns right.\n");
    }
    v->direction = direction;
}

// Function to display the current status of the vehicle
void display_status(Vehicle* v) {
    printf("Current status:\n");
    printf("Speed: %d mph\n", v->speed);
    printf("Direction: %s\n", v->direction == 1? "Forward" : "Backward");
    printf("Battery level: %d%%\n", v->battery_level);
}

// Main function to simulate the remote control of a vehicle
int main() {
    srand(time(NULL));

    Vehicle* vehicle = create_vehicle();
    int choice;

    while (1) {
        printf("What would you like to do?\n");
        printf("1. Move forward\n");
        printf("2. Turn left/right\n");
        printf("3. Display status\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the speed (0-100): ");
                int speed = rand() % 101;
                move_forward(vehicle, speed);
                break;
            case 2:
                printf("Enter the direction (1 or 2): ");
                int direction = rand() % 2 + 1;
                turn(vehicle, direction);
                break;
            case 3:
                display_status(vehicle);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}