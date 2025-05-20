//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VEHICLES 10

typedef enum {
    CAR,
    TRUCK,
    BIKE
} VehicleType;

typedef struct {
    VehicleType type;
    int speed; // Speed in km/h
    int direction; // Direction in degrees (0-360)
} RCVehicle;

void initializeVehicle(RCVehicle* vehicle, VehicleType type) {
    vehicle->type = type;
    vehicle->speed = 0;
    vehicle->direction = 0;
}

void setSpeed(RCVehicle* vehicle, int speed) {
    if (speed < 0) {
        printf("Speed cannot be negative. Keeping current speed: %d km/h.\n", vehicle->speed);
    } else {
        vehicle->speed = speed;
        printf("Speed for vehicle set to: %d km/h.\n", vehicle->speed);
    }
}

void setDirection(RCVehicle* vehicle, int direction) {
    if (direction < 0 || direction >= 360) {
        printf("Invalid direction. Keeping current direction: %d degrees.\n", vehicle->direction);
    } else {
        vehicle->direction = direction;
        printf("Direction for vehicle set to: %d degrees.\n", vehicle->direction);
    }
}

void displayVehicleInfo(RCVehicle* vehicle) {
    char* typeNames[] = { "Car", "Truck", "Bike" };
    printf("\nVehicle Type: %s\n", typeNames[vehicle->type]);
    printf("Speed: %d km/h\n", vehicle->speed);
    printf("Direction: %d degrees\n", vehicle->direction);
}

void simulateMovement(RCVehicle* vehicle) {
    printf("\nSimulating movement for vehicle...\n");
    if (vehicle->speed > 0) {
        printf("The %s is moving at %d km/h towards %d degrees.\n",
            (vehicle->type == CAR) ? "Car" :
            (vehicle->type == TRUCK) ? "Truck" : "Bike",
            vehicle->speed, vehicle->direction);
    } else {
        printf("The %s is stationary.\n",
            (vehicle->type == CAR) ? "Car" :
            (vehicle->type == TRUCK) ? "Truck" : "Bike");
    }
}

void configureVehicle(RCVehicle* vehicle) {
    int speed, direction;
    printf("Enter speed (km/h) for the vehicle: ");
    scanf("%d", &speed);
    setSpeed(vehicle, speed);
    printf("Enter direction (0-360 degrees) for the vehicle: ");
    scanf("%d", &direction);
    setDirection(vehicle, direction);
}

int main() {
    RCVehicle vehicles[MAX_VEHICLES];
    int vehicleCount = 0;
    int choice;
    
    while (1) {
        printf("\nRC Vehicle Simulation Menu:\n");
        printf("1. Add Vehicle\n");
        printf("2. Configure Vehicle\n");
        printf("3. Display Vehicle Information\n");
        printf("4. Simulate Vehicle Movement\n");
        printf("0. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (vehicleCount < MAX_VEHICLES) {
                    int type;
                    printf("Select Vehicle Type (0: Car, 1: Truck, 2: Bike): ");
                    scanf("%d", &type);
                    if (type < 0 || type > 2) {
                        printf("Invalid vehicle type selected.\n");
                        break;
                    }
                    initializeVehicle(&vehicles[vehicleCount], (VehicleType)type);
                    vehicleCount++;
                    printf("Vehicle added successfully!\n");
                } else {
                    printf("Maximum vehicle limit reached.\n");
                }
                break;

            case 2:
                if (vehicleCount == 0) {
                    printf("No vehicles to configure.\n");
                } else {
                    int vIndex;
                    printf("Select vehicle index to configure (0-%d): ", vehicleCount - 1);
                    scanf("%d", &vIndex);
                    if (vIndex < 0 || vIndex >= vehicleCount) {
                        printf("Invalid vehicle index.\n");
                    } else {
                        configureVehicle(&vehicles[vIndex]);
                    }
                }
                break;

            case 3:
                if (vehicleCount == 0) {
                    printf("No vehicles added.\n");
                } else {
                    for (int i = 0; i < vehicleCount; i++) {
                        printf("\nVehicle %d Info:\n", i);
                        displayVehicleInfo(&vehicles[i]);
                    }
                }
                break;

            case 4:
                if (vehicleCount == 0) {
                    printf("No vehicles to simulate.\n");
                } else {
                    for (int i = 0; i < vehicleCount; i++) {
                        simulateMovement(&vehicles[i]);
                    }
                }
                break;

            case 0:
                printf("Exiting program.\n");
                exit(0);
                break;

            default:
                printf("Invalid selection. Please try again.\n");
                break;
        }
    }

    return 0;
}