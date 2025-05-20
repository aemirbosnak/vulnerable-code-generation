//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    CAR,
    BOAT,
    DRONE
} VehicleType;

typedef struct {
    VehicleType type;
    float speed;
    float distance;
} Vehicle;

// Function to initiate Vehicle
void initVehicle(Vehicle *v) {
    v->type = CAR;
    v->speed = 0.0;
    v->distance = 0.0;
}

// Function to transform vehicle
void transformVehicle(Vehicle *v) {
    if (v->type == CAR) {
        v->type = BOAT;
        printf("Transformed to BOAT.\n");
    } else if (v->type == BOAT) {
        v->type = DRONE;
        printf("Transformed to DRONE.\n");
    } else {
        v->type = CAR;
        printf("Transformed to CAR.\n");
    }
}

// Function to set speed
void setSpeed(Vehicle *v, float speed) {
    v->speed = speed;
    printf("Speed set to %.2f\n", speed);
}

// Function to move vehicle
void moveVehicle(Vehicle *v, float time) {
    if (v->speed <= 0) {
        printf("Can't move. Please set a positive speed first.\n");
        return;
    }

    v->distance += v->speed * time;
    printf("Moved %.2f units. Total distance: %.2f\n", v->speed * time, v->distance);
}

// Function to display current vehicle state
void displayVehicleState(Vehicle *v) {
    char *typeStr = v->type == CAR ? "Car" : (v->type == BOAT ? "Boat" : "Drone");
    printf("Current Vehicle: %s | Speed: %.2f | Distance: %.2f\n", typeStr, v->speed, v->distance);
}

// Function for menu
void displayMenu() {
    printf("\n--- Vehicle Simulation Menu ---\n");
    printf("1. Transform Vehicle\n");
    printf("2. Set Speed\n");
    printf("3. Move Vehicle\n");
    printf("4. Display Vehicle State\n");
    printf("5. Exit\n");
    printf("-------------------------------\n");
}

int main() {
    Vehicle vehicle;
    initVehicle(&vehicle);
    
    int choice;
    float input;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                transformVehicle(&vehicle);
                break;
            case 2:
                printf("Enter speed: ");
                scanf("%f", &input);
                setSpeed(&vehicle, input);
                break;
            case 3:
                printf("Enter time to move: ");
                scanf("%f", &input);
                moveVehicle(&vehicle, input);
                break;
            case 4:
                displayVehicleState(&vehicle);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}