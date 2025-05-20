//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DRONES 5
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int isFlying;
    int altitude;
    int positionX;
    int positionY;
} Drone;

void displayMenu() {
    printf("\n----- Drone Remote Control -----\n");
    printf("1. Take Off\n");
    printf("2. Land\n");
    printf("3. Move Left\n");
    printf("4. Move Right\n");
    printf("5. Ascend\n");
    printf("6. Descend\n");
    printf("7. Status\n");
    printf("8. Exit\n");
    printf("--------------------------------\n");
    printf("Select an option: ");
}

void takeOff(Drone *drone) {
    if (drone->isFlying) {
        printf("Drone %s is already flying!\n", drone->name);
    } else {
        drone->isFlying = 1;
        drone->altitude = 10; // Start at an altitude of 10
        printf("Drone %s has taken off!\n", drone->name);
    }
}

void land(Drone *drone) {
    if (!drone->isFlying) {
        printf("Drone %s is already on the ground!\n", drone->name);
    } else {
        drone->isFlying = 0;
        drone->altitude = 0;
        printf("Drone %s has landed!\n", drone->name);
    }
}

void moveLeft(Drone *drone) {
    if (drone->isFlying) {
        drone->positionX--;
        printf("Drone %s moved left to position (%d, %d).\n", drone->name, drone->positionX, drone->positionY);
    } else {
        printf("Drone %s needs to be in the air to move!\n", drone->name);
    }
}

void moveRight(Drone *drone) {
    if (drone->isFlying) {
        drone->positionX++;
        printf("Drone %s moved right to position (%d, %d).\n", drone->name, drone->positionX, drone->positionY);
    } else {
        printf("Drone %s needs to be in the air to move!\n", drone->name);
    }
}

void ascend(Drone *drone) {
    if (drone->isFlying) {
        drone->altitude++;
        printf("Drone %s ascended to altitude %d.\n", drone->name, drone->altitude);
    } else {
        printf("Drone %s needs to be in the air to ascend!\n", drone->name);
    }
}

void descend(Drone *drone) {
    if (drone->isFlying) {
        if (drone->altitude > 0) {
            drone->altitude--;
            printf("Drone %s descended to altitude %d.\n", drone->name, drone->altitude);
        } else {
            printf("Drone %s is already at ground level.\n", drone->name);
        }
    } else {
        printf("Drone %s needs to be in the air to descend!\n", drone->name);
    }
}

void displayStatus(Drone *drone) {
    printf("\n----- Status of Drone %s -----\n", drone->name);
    printf("Flying: %s\n", drone->isFlying ? "Yes" : "No");
    printf("Altitude: %d\n", drone->altitude);
    printf("Position: (%d, %d)\n", drone->positionX, drone->positionY);
    printf("--------------------------------\n");
}

int main() {
    Drone drones[MAX_DRONES] = {
        {"Drone1", 0, 0, 0, 0},
        {"Drone2", 0, 0, 0, 0},
        {"Drone3", 0, 0, 0, 0},
        {"Drone4", 0, 0, 0, 0},
        {"Drone5", 0, 0, 0, 0}
    };
    
    int choice, droneIndex;
    
    // Select a Drone
    printf("Select a drone (1 to 5): ");
    scanf("%d", &droneIndex);
    if (droneIndex < 1 || droneIndex > MAX_DRONES) {
        printf("Invalid drone selection!\n");
        return 1;
    }
    Drone *selectedDrone = &drones[droneIndex - 1];

    // Main Loop
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: takeOff(selectedDrone); break;
            case 2: land(selectedDrone); break;
            case 3: moveLeft(selectedDrone); break;
            case 4: moveRight(selectedDrone); break;
            case 5: ascend(selectedDrone); break;
            case 6: descend(selectedDrone); break;
            case 7: displayStatus(selectedDrone); break;
            case 8: 
                printf("Exiting the drone control interface...\n");
                exit(0);
            default: 
                printf("Invalid option! Please try again.\n"); break;
        }
    }

    return 0;
}