//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_VEHICLES 5
#define MAX_SPEED 10
#define MIN_SPEED 1

typedef struct {
    char name[20];
    int position;
    int speed;
} Vehicle;

void initializeVehicles(Vehicle *vehicles, int count) {
    for (int i = 0; i < count; i++) {
        snprintf(vehicles[i].name, sizeof(vehicles[i].name), "Vehicle_%d", i + 1);
        vehicles[i].position = 0;
        vehicles[i].speed = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
    }
}

void displayPosition(Vehicle *vehicles, int count) {
    printf("Current positions:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: Position %d, Speed %d\n", vehicles[i].name, vehicles[i].position, vehicles[i].speed);
    }
    printf("\n");
}

void updatePositions(Vehicle *vehicles, int count) {
    for (int i = 0; i < count; i++) {
        vehicles[i].position += vehicles[i].speed;
    }
}

void changeSpeed(Vehicle *vehicles, int index, int newSpeed) {
    if (newSpeed >= MIN_SPEED && newSpeed <= MAX_SPEED) {
        vehicles[index].speed = newSpeed;
        printf("%s speed changed to %d\n", vehicles[index].name, newSpeed);
    } else {
        printf("Invalid speed for %s. Speed must be between %d and %d.\n", vehicles[index].name, MIN_SPEED, MAX_SPEED);
    }
}

int main() {
    srand(time(NULL));
    
    Vehicle vehicles[MAX_VEHICLES];
    int running = 1;
    int choice, vehicleIndex, newSpeed;

    initializeVehicles(vehicles, MAX_VEHICLES);

    while (running) {
        displayPosition(vehicles, MAX_VEHICLES);
        
        printf("1. Change speed of a vehicle\n");
        printf("2. Update positions\n");
        printf("3. Exit simulation\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Choose vehicle index (0 to %d): ", MAX_VEHICLES - 1);
                scanf("%d", &vehicleIndex);
                if (vehicleIndex < 0 || vehicleIndex >= MAX_VEHICLES) {
                    printf("Invalid vehicle index!\n");
                    break;
                }
                printf("Enter new speed (1 to 10): ");
                scanf("%d", &newSpeed);
                changeSpeed(vehicles, vehicleIndex, newSpeed);
                break;
                
            case 2:
                updatePositions(vehicles, MAX_VEHICLES);
                printf("Positions updated!\n");
                break;

            case 3:
                running = 0;
                printf("Exiting simulation. Thank you!\n");
                break;

            default:
                printf("Invalid option, please try again.\n");
                break;
        }

        usleep(500000); // Sleep for half a second
    }

    return 0;
}