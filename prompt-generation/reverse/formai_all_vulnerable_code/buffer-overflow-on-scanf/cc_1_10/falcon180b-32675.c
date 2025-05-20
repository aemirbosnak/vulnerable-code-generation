//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define remote control vehicle structure
typedef struct {
    char *name;
    int speed;
    int direction;
} Vehicle;

// Function to initialize vehicle
void initVehicle(Vehicle *vehicle) {
    vehicle->name = "Remote Control Car";
    vehicle->speed = 0;
    vehicle->direction = 0;
}

// Function to accelerate vehicle
void accelerateVehicle(Vehicle *vehicle) {
    vehicle->speed += 10;
    printf("%s is accelerating to %d mph!\n", vehicle->name, vehicle->speed);
}

// Function to brake vehicle
void brakeVehicle(Vehicle *vehicle) {
    vehicle->speed -= 10;
    printf("%s is braking to %d mph!\n", vehicle->name, vehicle->speed);
}

// Function to turn left vehicle
void turnLeftVehicle(Vehicle *vehicle) {
    vehicle->direction -= 90;
    printf("%s is turning left to %d degrees!\n", vehicle->name, vehicle->direction);
}

// Function to turn right vehicle
void turnRightVehicle(Vehicle *vehicle) {
    vehicle->direction += 90;
    printf("%s is turning right to %d degrees!\n", vehicle->name, vehicle->direction);
}

// Function to display vehicle information
void displayVehicleInfo(Vehicle *vehicle) {
    printf("Name: %s\n", vehicle->name);
    printf("Speed: %d mph\n", vehicle->speed);
    printf("Direction: %d degrees\n", vehicle->direction);
}

// Main function
int main() {
    srand(time(0));

    // Initialize remote control car
    Vehicle car;
    initVehicle(&car);

    // Simulate driving
    int choice;
    while (1) {
        printf("Enter your choice:\n");
        printf("1. Accelerate\n");
        printf("2. Brake\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Display vehicle info\n");
        printf("6. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            accelerateVehicle(&car);
            break;
        case 2:
            brakeVehicle(&car);
            break;
        case 3:
            turnLeftVehicle(&car);
            break;
        case 4:
            turnRightVehicle(&car);
            break;
        case 5:
            displayVehicleInfo(&car);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}