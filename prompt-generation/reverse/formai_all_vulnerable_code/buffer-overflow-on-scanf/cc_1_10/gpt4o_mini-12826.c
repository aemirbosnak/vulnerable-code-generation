//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_VEHICLES 5
#define VEHICLE_NAME_LENGTH 20

// Define the structure for our remote control vehicles
typedef struct {
    char name[VEHICLE_NAME_LENGTH];
    int speed;            // Speed of the vehicle
    int direction;        // Direction (0: stopped, 1: forward, 2: backward, 3: left, 4: right)
    int battery;          // Battery percentage
} RemoteControlVehicle;

// Function prototypes
void InitializeVehicle(RemoteControlVehicle *vehicle, const char *name);
void DisplayVehicleStatus(RemoteControlVehicle *vehicle);
void MoveVehicle(RemoteControlVehicle *vehicle);
void RechargeVehicle(RemoteControlVehicle *vehicle);
void DisplayMenu();
int GetUserChoice();

int main() {
    RemoteControlVehicle vehicles[MAX_VEHICLES];
    int vehicleCount = 0;
    int choice;

    // Initialize some vehicles
    InitializeVehicle(&vehicles[vehicleCount++], "Zoomer");
    InitializeVehicle(&vehicles[vehicleCount++], "Speedy");
    InitializeVehicle(&vehicles[vehicleCount++], "Stinger");

    printf("Welcome to the Happy Remote Control Vehicle Simulator!\n");
    
    while (1) {
        DisplayMenu();
        choice = GetUserChoice();
        
        switch (choice) {
            case 1:
                for (int i = 0; i < vehicleCount; i++) {
                    DisplayVehicleStatus(&vehicles[i]);
                }
                break;
            case 2:
                for (int i = 0; i < vehicleCount; i++) {
                    MoveVehicle(&vehicles[i]);
                }
                break;
            case 3:
                for (int i = 0; i < vehicleCount; i++) {
                    RechargeVehicle(&vehicles[i]);
                }
                break;
            case 4:
                printf("Exiting the simulator... Bye! Have a great day!!!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }
        
        sleep(1);  // Add some delay for better user experience
    }
    
    return 0;
}

void InitializeVehicle(RemoteControlVehicle *vehicle, const char *name) {
    strncpy(vehicle->name, name, VEHICLE_NAME_LENGTH - 1);
    vehicle->speed = rand() % 50;  // Random speed between 0-50
    vehicle->direction = 0;         // Starting stopped
    vehicle->battery = 100;         // Fully charged
}

void DisplayVehicleStatus(RemoteControlVehicle *vehicle) {
    printf("%s Status:\n", vehicle->name);
    printf("  Speed: %d\n", vehicle->speed);
    printf("  Direction: %d\n", vehicle->direction);
    printf("  Battery: %d%%\n\n", vehicle->battery);
}

void MoveVehicle(RemoteControlVehicle *vehicle) {
    if (vehicle->battery > 0) {
        vehicle->direction = rand() % 5;  // Choose a random direction
        vehicle->battery -= 10;  // Consume battery
        printf("%s is moving in direction %d with speed %d! 🎉\n", vehicle->name, vehicle->direction, vehicle->speed);
    } else {
        printf("%s cannot move, battery is empty! ⚡️ Let's recharge.\n", vehicle->name);
    }
}

void RechargeVehicle(RemoteControlVehicle *vehicle) {
    vehicle->battery = 100;  // Recharge the vehicle
    printf("%s is recharged to 100%! 🚀\n", vehicle->name);
}

void DisplayMenu() {
    printf("\n--- Vehicle Control Menu ---\n");
    printf("1. Display Vehicle Status\n");
    printf("2. Move Vehicles\n");
    printf("3. Recharge Vehicles\n");
    printf("4. Exit\n");
    printf("Please select an option: ");
}

int GetUserChoice() {
    int choice;
    scanf("%d", &choice);
    return choice;
}