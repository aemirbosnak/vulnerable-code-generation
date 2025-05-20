//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ALTITUDE 100
#define MIN_ALTITUDE 0

typedef struct {
    int isFlying;
    int altitude;
} Drone;

void printMenu() {
    printf("=== Drone Remote Control ===\n");
    printf("1. Take Off\n");
    printf("2. Land\n");
    printf("3. Increase Altitude\n");
    printf("4. Decrease Altitude\n");
    printf("5. Check Status\n");
    printf("6. Exit\n");
    printf("===========================\n");
}

void takeOff(Drone *drone) {
    if (drone->isFlying) {
        printf("The drone is already flying!\n");
    } else {
        drone->isFlying = 1;
        drone->altitude = MIN_ALTITUDE + 1; // set to a minimum flight altitude
        printf("The drone has taken off! Altitude: %d meters\n", drone->altitude);
    }
}

void land(Drone *drone) {
    if (!drone->isFlying) {
        printf("The drone is already on the ground!\n");
    } else {
        drone->isFlying = 0;
        drone->altitude = MIN_ALTITUDE;
        printf("The drone has landed safely!\n");
    }
}

void increaseAltitude(Drone *drone) {
    if (!drone->isFlying) {
        printf("The drone needs to be flying to increase altitude!\n");
    } else {
        if (drone->altitude < MAX_ALTITUDE) {
            drone->altitude++;
            printf("Altitude increased! Current Altitude: %d meters\n", drone->altitude);
        } else {
            printf("Maximum altitude reached: %d meters\n", MAX_ALTITUDE);
        }
    }
}

void decreaseAltitude(Drone *drone) {
    if (!drone->isFlying) {
        printf("The drone needs to be flying to decrease altitude!\n");
    } else {
        if (drone->altitude > MIN_ALTITUDE) {
            drone->altitude--;
            printf("Altitude decreased! Current Altitude: %d meters\n", drone->altitude);
        } else {
            printf("The drone is already at the minimum altitude: %d meters\n", MIN_ALTITUDE);
        }
    }
}

void checkStatus(Drone *drone) {
    if (drone->isFlying) {
        printf("The drone is in the air at an altitude of %d meters.\n", drone->altitude);
    } else {
        printf("The drone is on the ground.\n");
    }
}

int main() {
    Drone myDrone = {0, 0}; // Initialize drone to not flying and at ground level
    int choice;

    while (1) {
        printMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 6.\n");
            while(getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                takeOff(&myDrone);
                break;
            case 2:
                land(&myDrone);
                break;
            case 3:
                increaseAltitude(&myDrone);
                break;
            case 4:
                decreaseAltitude(&myDrone);
                break;
            case 5:
                checkStatus(&myDrone);
                break;
            case 6:
                printf("Exiting the drone control system.\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option from the menu.\n");
        }

        sleep(1); // Wait for a second before displaying the menu again
    }

    return 0;
}