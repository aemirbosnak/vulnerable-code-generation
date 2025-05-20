//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_VEHICLES 10
#define MAX_NAME_LENGTH 20

typedef enum {
    STOPPED,
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
} Movement;

typedef struct {
    char name[MAX_NAME_LENGTH];
    Movement movement;
    int speed;
    int battery; // in percentage
} RemoteControlVehicle;

void initializeVehicle(RemoteControlVehicle *vehicle, const char *name) {
    strncpy(vehicle->name, name, MAX_NAME_LENGTH);
    vehicle->movement = STOPPED;
    vehicle->speed = 0;
    vehicle->battery = 100; // Fully charged
}

void displayVehicleStatus(RemoteControlVehicle *vehicle) {
    printf("Vehicle: %s\n", vehicle->name);
    printf("Movement: ");
    switch (vehicle->movement) {
        case STOPPED: printf("Stopped\n"); break;
        case FORWARD: printf("Forward\n"); break;
        case BACKWARD: printf("Backward\n"); break;
        case LEFT: printf("Left\n"); break;
        case RIGHT: printf("Right\n"); break;
    }
    printf("Speed: %d\n", vehicle->speed);
    printf("Battery: %d%%\n", vehicle->battery);
}

void updateMovement(RemoteControlVehicle *vehicle, Movement newMovement, int newSpeed) {
    if (vehicle->battery <= 0) {
        printf("%s is out of battery!\n", vehicle->name);
        vehicle->movement = STOPPED;
        vehicle->speed = 0;
        return;
    }

    vehicle->movement = newMovement;
    vehicle->speed = newSpeed;
    vehicle->battery -= 5; // Using battery for each command
    if (vehicle->battery < 0) vehicle->battery = 0;
}

void simulateMovement(RemoteControlVehicle *vehicle) {
    if (vehicle->movement == STOPPED || vehicle->battery <= 0) {
        printf("%s is not moving.\n", vehicle->name);
        return;
    }
    
    printf("%s is moving ", vehicle->name);
    switch (vehicle->movement) {
        case FORWARD: printf("forward at speed %d.\n", vehicle->speed); break;
        case BACKWARD: printf("backward at speed %d.\n", vehicle->speed); break;
        case LEFT: printf("turning left at speed %d.\n", vehicle->speed); break;
        case RIGHT: printf("turning right at speed %d.\n", vehicle->speed); break;
        default: break;
    }
    sleep(1); //Simulate a delay for movement
}

void rechargeBattery(RemoteControlVehicle *vehicle) {
    if (vehicle->battery < 100) {
        vehicle->battery += 20;
        if (vehicle->battery > 100) vehicle->battery = 100;
        printf("Recharging %s's battery. Current charge: %d%%\n", vehicle->name, vehicle->battery);
    } else {
        printf("%s's battery is already full.\n", vehicle->name);
    }
}

void displayMenu() {
    printf("\n=== Remote Control Vehicle Simulation ===\n");
    printf("1. Initialize Vehicle\n");
    printf("2. Move Vehicle\n");
    printf("3. Show Vehicle Status\n");
    printf("4. Recharge Vehicle\n");
    printf("5. Exit\n");
    printf("=========================================\n");
}

int main() {
    RemoteControlVehicle vehicles[MAX_VEHICLES];
    int vehicleCount = 0;
    int choice;
    char name[MAX_NAME_LENGTH];

    while (1) {
        displayMenu();
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: // Initialize Vehicle
                if (vehicleCount < MAX_VEHICLES) {
                    printf("Enter vehicle name: ");
                    scanf("%s", name);
                    initializeVehicle(&vehicles[vehicleCount], name);
                    vehicleCount++;
                    printf("Vehicle %s initialized!\n", name);
                } else {
                    printf("Maximum vehicle limit reached.\n");
                }
                break;
                
            case 2: // Move Vehicle
                for (int i = 0; i < vehicleCount; i++) {
                    printf("Moving Vehicle %d: %s\n", i + 1, vehicles[i].name);
                    char direction[10];
                    int speed;
                    printf("Enter direction (forward/backward/left/right): ");
                    scanf("%s", direction);
                    printf("Enter speed (0-100): ");
                    scanf("%d", &speed);

                    if (strcmp(direction, "forward") == 0) updateMovement(&vehicles[i], FORWARD, speed);
                    else if (strcmp(direction, "backward") == 0) updateMovement(&vehicles[i], BACKWARD, speed);
                    else if (strcmp(direction, "left") == 0) updateMovement(&vehicles[i], LEFT, speed);
                    else if (strcmp(direction, "right") == 0) updateMovement(&vehicles[i], RIGHT, speed);
                    else printf("Invalid Direction! Vehicle remains stopped.\n");

                    simulateMovement(&vehicles[i]);
                }
                break;
                
            case 3: // Show Vehicle Status
                for (int i = 0; i < vehicleCount; i++) {
                    displayVehicleStatus(&vehicles[i]);
                }
                break;
                
            case 4: // Recharge Vehicle
                for (int i = 0; i < vehicleCount; i++) {
                    rechargeBattery(&vehicles[i]);
                }
                break;
                
            case 5: // Exit
                printf("Exiting the simulation. Goodbye!\n");
                exit(0);
                break;
                
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }
    
    return 0;
}