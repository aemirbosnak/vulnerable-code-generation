//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Define structure for Vehicle
typedef struct {
    char type[10];
    float speed;
    float altitude;
    float distanceTravelled;
} Vehicle;

// Function to initialize vehicle as a car
void initializeCar(Vehicle *v) {
    strcpy(v->type, "Car");
    v->speed = 0.0;
    v->altitude = 0.0;
    v->distanceTravelled = 0.0;
}

// Function to initialize vehicle as a drone
void initializeDrone(Vehicle *v) {
    strcpy(v->type, "Drone");
    v->speed = 0.0;
    v->altitude = 0.0;
    v->distanceTravelled = 0.0;
}

// Function to accelerate the vehicle
void accelerate(Vehicle *v, float acceleration) {
    v->speed += acceleration;
    if (v->speed < 0) v->speed = 0; // Speed cannot be negative
}

// Function to move the vehicle forward
void move(Vehicle *v) {
    if (strcmp(v->type, "Drone") == 0 && v->altitude <= 0) {
        printf("Drone cannot fly. Please ascend first.\n");
        return;
    }
    v->distanceTravelled += v->speed;
}

// Function to change the vehicle type
void changeVehicleType(Vehicle *v) {
    if (strcmp(v->type, "Car") == 0) {
        printf("Changing to Drone...\n");
        initializeDrone(v);
    } else {
        printf("Changing to Car...\n");
        initializeCar(v);
    }
}

// Function to set altitude for drone
void setAltitude(Vehicle *v, float altitude) {
    if (strcmp(v->type, "Drone") == 0) {
        v->altitude = altitude;
    } else {
        printf("Altitude is only applicable to Drones.\n");
    }
}

// Function to display vehicle status
void displayStatus(Vehicle *v) {
    printf("Current Vehicle: %s\n", v->type);
    printf("Speed: %.2f m/s\n", v->speed);
    if (strcmp(v->type, "Drone") == 0) {
        printf("Altitude: %.2f m\n", v->altitude);
    }
    printf("Distance Travelled: %.2f m\n", v->distanceTravelled);
    printf("=====================\n");
}

int main() {
    Vehicle myVehicle;
    char command[20];
    float value;

    // Start the program with the vehicle as a car
    initializeCar(&myVehicle);
    
    printf("Welcome to the Shape-Shifting Vehicle Simulator!\n");
    printf("You can control a Car or a Drone.\n");

    while (1) {
        displayStatus(&myVehicle);
        printf("Enter command (accelerate, move, change, altitude, exit): ");
        scanf("%s", command);

        if (strcmp(command, "accelerate") == 0) {
            printf("Enter acceleration value (m/s^2): ");
            scanf("%f", &value);
            accelerate(&myVehicle, value);
        } else if (strcmp(command, "move") == 0) {
            move(&myVehicle);
        } else if (strcmp(command, "change") == 0) {
            changeVehicleType(&myVehicle);
        } else if (strcmp(command, "altitude") == 0) {
            printf("Enter altitude value (m): ");
            scanf("%f", &value);
            setAltitude(&myVehicle, value);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the simulator. Goodbye!\n");
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }

        // Simulate a small delay for better visibility of the program flow
        sleep(1);
    }

    return 0;
}