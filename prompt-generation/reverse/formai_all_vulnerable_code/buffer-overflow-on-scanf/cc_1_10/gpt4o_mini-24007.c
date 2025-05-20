//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int altitude;       // Altitude of the drone
    float speed;        // Speed of the drone
    char mode[20];      // Flying mode (e.g., 'manual', 'automatic')
    int isFlying;       // Status of the drone (flying or grounded)
} Drone;

void initializeDrone(Drone *drone) {
    drone->altitude = 0;
    drone->speed = 0.0;
    strcpy(drone->mode, "manual");
    drone->isFlying = 0;
    printf("Drone initialized. Ready for flight in peaceful skies.\n");
}

void showStatus(Drone *drone) {
    printf("\n--- Drone Status ---\n");
    printf("Altitude: %d meters\n", drone->altitude);
    printf("Speed: %.2f m/s\n", drone->speed);
    printf("Mode: %s\n", drone->mode);
    printf("Status: %s\n\n", drone->isFlying ? "Flying" : "Grounded");
}

void takeoff(Drone *drone) {
    if (!drone->isFlying) {
        drone->isFlying = 1;
        drone->altitude = 10; // Takeoff to 10 meters
        drone->speed = 0.0;
        printf("The drone has taken off gracefully, reaching a serene altitude of 10 meters.\n");
    } else {
        printf("The drone is already in the air, enjoying the view.\n");
    }
}

void land(Drone *drone) {
    if (drone->isFlying) {
        drone->isFlying = 0;
        drone->altitude = 0; // Grounded
        drone->speed = 0.0;
        printf("The drone has landed safely, back on solid ground.\n");
    } else {
        printf("The drone is already grounded, nestled peacefully.\n");
    }
}

void changeSpeed(Drone *drone, float newSpeed) {
    if (drone->isFlying) {
        drone->speed = newSpeed;
        printf("The drone's speed has been changed to %.2f m/s.\n", drone->speed);
    } else {
        printf("The drone must be flying to change speed.\n");
    }
}

void switchMode(Drone *drone, const char *newMode) {
    if (strcmp(newMode, "manual") == 0 || strcmp(newMode, "automatic") == 0) {
        strcpy(drone->mode, newMode);
        printf("The drone is now set to '%s' mode.\n", drone->mode);
    } else {
        printf("Invalid mode. Please choose 'manual' or 'automatic'.\n");
    }
}

void displayMenu() {
    printf("\n--- Drone Remote Control Menu ---\n");
    printf("1. Status\n");
    printf("2. Take Off\n");
    printf("3. Land\n");
    printf("4. Change Speed\n");
    printf("5. Switch Mode\n");
    printf("6. Exit\n");
}

int main() {
    Drone myDrone;
    initializeDrone(&myDrone);
    
    int choice;
    float newSpeed;
    char newMode[20];

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                showStatus(&myDrone);
                break;
            case 2:
                takeoff(&myDrone);
                break;
            case 3:
                land(&myDrone);
                break;
            case 4:
                printf("Enter new speed (m/s): ");
                scanf("%f", &newSpeed);
                changeSpeed(&myDrone, newSpeed);
                break;
            case 5:
                printf("Enter new flying mode (manual/automatic): ");
                scanf("%s", newMode);
                switchMode(&myDrone, newMode);
                break;
            case 6:
                printf("Exiting Drone Remote Control. Fly safe and enjoy the skies!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}