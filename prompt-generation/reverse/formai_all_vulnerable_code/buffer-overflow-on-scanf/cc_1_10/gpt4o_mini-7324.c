//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_VEHICLES 5
#define NAME_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    int position;
    int speed;
    int is_moving;
} Vehicle;

void initializeVehicles(Vehicle vehicles[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter name for vehicle %d: ", i + 1);
        scanf("%s", vehicles[i].name);
        vehicles[i].position = 0;
        vehicles[i].speed = 0;
        vehicles[i].is_moving = 0;
    }
}

void displayVehicles(const Vehicle vehicles[], int count) {
    printf("\nCurrent status of vehicles:\n");
    for (int i = 0; i < count; i++) {
        printf("Vehicle %d: %s | Position: %d | Speed: %d | %s\n", 
                i + 1, vehicles[i].name, vehicles[i].position, 
                vehicles[i].speed, vehicles[i].is_moving ? "Moving" : "Stopped");
    }
    printf("\n");
}

void accelerateVehicle(Vehicle *vehicle, int increment) {
    vehicle->speed += increment;
    vehicle->is_moving = 1;
    printf("%s accelerated to speed %d!\n", vehicle->name, vehicle->speed);
}

void brakeVehicle(Vehicle *vehicle) {
    vehicle->speed = 0;
    vehicle->is_moving = 0;
    printf("%s has stopped.\n", vehicle->name);
}

void moveVehicle(Vehicle *vehicle) {
    if (vehicle->is_moving) {
        vehicle->position += vehicle->speed;
        printf("%s is moving to position %d!\n", vehicle->name, vehicle->position);
    } else {
        printf("%s is not moving!\n", vehicle->name);
    }
}

void menu() {
    printf("***********************************\n");
    printf("*    Remote Control Vehicle!      *\n");
    printf("***********************************\n");
    printf("1. Initialize Vehicles\n");
    printf("2. Display Vehicle Status\n");
    printf("3. Accelerate Vehicle\n");
    printf("4. Brake Vehicle\n");
    printf("5. Move Vehicle\n");
    printf("6. Quit\n");
    printf("***********************************\n");
}

int main() {
    Vehicle vehicles[MAX_VEHICLES];
    int vehicleCount = 0;
    int choice;

    printf("Welcome to the Cheerful Remote Control Vehicle Simulation!\n");
  
    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("How many vehicles do you want to initialize? (Max %d): ", MAX_VEHICLES);
                scanf("%d", &vehicleCount);
                if (vehicleCount > MAX_VEHICLES) {
                    printf("No more than %d vehicles can be initialized.\n", MAX_VEHICLES);
                } else {
                    initializeVehicles(vehicles, vehicleCount);
                }
                break;
            case 2:
                displayVehicles(vehicles, vehicleCount);
                break;
            case 3: {
                int index, increment;
                printf("Select vehicle (1 to %d): ", vehicleCount);
                scanf("%d", &index);
                if (index < 1 || index > vehicleCount) {
                    printf("Invalid vehicle number!\n");
                } else {
                    printf("Enter speed increment: ");
                    scanf("%d", &increment);
                    accelerateVehicle(&vehicles[index - 1], increment);
                }
                break;
            }
            case 4: {
                int index;
                printf("Select vehicle (1 to %d): ", vehicleCount);
                scanf("%d", &index);
                if (index < 1 || index > vehicleCount) {
                    printf("Invalid vehicle number!\n");
                } else {
                    brakeVehicle(&vehicles[index - 1]);
                }
                break;
            }
            case 5: {
                int index;
                printf("Select vehicle (1 to %d): ", vehicleCount);
                scanf("%d", &index);
                if (index < 1 || index > vehicleCount) {
                    printf("Invalid vehicle number!\n");
                } else {
                    moveVehicle(&vehicles[index - 1]);
                }
                break;
            }
            case 6:
                printf("Thank you for enjoying the remote control vehicle simulation! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
  
    return 0;
}