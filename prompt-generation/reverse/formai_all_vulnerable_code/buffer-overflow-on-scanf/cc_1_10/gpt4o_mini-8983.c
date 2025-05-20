//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_VEHICLES 5
#define BUFFER_SIZE 100

typedef struct {
    char name[30];
    int speed;
    int direction; // 0: Forward, 1: Backward, 2: Left, 3: Right
} RemoteControlVehicle;

void printMenu() {
    printf("\n*** Remote Control Vehicle Simulation ***\n");
    printf("1. Create Vehicle\n");
    printf("2. Control Vehicle\n");
    printf("3. Show Vehicles\n");
    printf("4. Quit\n");
    printf("Please enter your choice: ");
}

void addVehicle(RemoteControlVehicle vehicles[], int *count) {
    if (*count >= MAX_VEHICLES) {
        printf("Oops! Maximum vehicles reached. Can't add more.\n");
        return;
    }
    RemoteControlVehicle newVehicle;
    printf("Enter vehicle name: ");
    fgets(newVehicle.name, sizeof(newVehicle.name), stdin);
    strtok(newVehicle.name, "\n"); // Remove newline character

    printf("Enter vehicle speed (1-10): ");
    scanf("%d", &newVehicle.speed);
    getchar(); // Clear newline from buffer

    newVehicle.direction = 0; // Start with forward direction
    vehicles[*count] = newVehicle;
    (*count)++;
    printf("Yay! Vehicle '%s' added successfully!\n", newVehicle.name);
}

void controlVehicle(RemoteControlVehicle vehicles[], int count) {
    if (count == 0) {
        printf("No vehicles to control! Please create one first.\n");
        return;
    }
    
    int vehicleIndex;
    printf("Select vehicle (0 to %d): ", count - 1);
    scanf("%d", &vehicleIndex);
    getchar(); // Clear newline from buffer

    if (vehicleIndex < 0 || vehicleIndex >= count) {
        printf("Oops! Invalid vehicle index.\n");
        return;
    }
    
    RemoteControlVehicle *vehicle = &vehicles[vehicleIndex];
    
    printf("Controlling vehicle: %s\n", vehicle->name);
    printf("Current speed: %d, Current direction: %d\n", vehicle->speed, vehicle->direction);
    
    char command[BUFFER_SIZE];
    printf("Enter command (forward/backward/left/right): ");
    fgets(command, sizeof(command), stdin);
    strtok(command, "\n"); // Remove newline character

    if (strcmp(command, "forward") == 0) {
        vehicle->direction = 0;
    } else if (strcmp(command, "backward") == 0) {
        vehicle->direction = 1;
    } else if (strcmp(command, "left") == 0) {
        vehicle->direction = 2;
    } else if (strcmp(command, "right") == 0) {
        vehicle->direction = 3;
    } else {
        printf("Oops! Invalid command. No action taken!\n");
        return;
    }
   
    printf("Vehicle %s is now moving %s!\n", vehicle->name, command);
}

void showVehicles(RemoteControlVehicle vehicles[], int count) {
    if (count == 0) {
        printf("No vehicles to show!\n");
        return;
    }
    
    printf("\n*** Currently Available Vehicles ***\n");
    for (int i = 0; i < count; i++) {
        printf("Index: %d, Name: %s, Speed: %d, Direction: %d\n",
               i, vehicles[i].name, vehicles[i].speed, vehicles[i].direction);
    }
}

int main() {
    RemoteControlVehicle vehicles[MAX_VEHICLES];
    int vehicleCount = 0;
    int choice;

    while (1) {
        printMenu();
        scanf("%d", &choice);
        getchar(); // Clear newline from buffer

        switch (choice) {
            case 1:
                addVehicle(vehicles, &vehicleCount);
                break;
            case 2:
                controlVehicle(vehicles, vehicleCount);
                break;
            case 3:
                showVehicles(vehicles, vehicleCount);
                break;
            case 4:
                printf("Thank you for playing! Bye-bye!\n");
                exit(0);
            default:
                printf("Oops! That's not a valid choice! Please try again.\n");
        }
        sleep(1); // Just a little pause for better user experience
    }

    return 0;
}