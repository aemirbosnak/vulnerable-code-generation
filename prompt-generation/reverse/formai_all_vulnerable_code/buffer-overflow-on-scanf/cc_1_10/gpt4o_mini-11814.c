//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // For sleep
#include <stdbool.h>

#define MAX_COMMAND 256

typedef struct {
    bool isFlying;
    int altitude;
    int speed;
} Drone;

void displayStatus(Drone *drone) {
    printf("Drone Status:\n");
    printf("  - Flying: %s\n", drone->isFlying ? "Yes" : "No");
    printf("  - Altitude: %d meters\n", drone->altitude);
    printf("  - Speed: %d m/s\n", drone->speed);
}

void takeOff(Drone *drone) {
    if (!drone->isFlying) {
        printf("Taking off...\n");
        drone->isFlying = true;
        drone->altitude = 10; // Takeoff to 10 meters
        drone->speed = 0;
        printf("Drone has taken off.\n");
    } else {
        printf("Drone is already in the air!\n");
    }
}

void land(Drone *drone) {
    if (drone->isFlying) {
        printf("Landing...\n");
        drone->isFlying = false;
        drone->altitude = 0;
        drone->speed = 0;
        printf("Drone has landed safely.\n");
    } else {
        printf("Drone is already on the ground!\n");
    }
}

void increaseAltitude(Drone *drone, int meters) {
    if (drone->isFlying) {
        drone->altitude += meters;
        printf("Altitude increased to %d meters.\n", drone->altitude);
    } else {
        printf("Drone must be flying to increase altitude!\n");
    }
}

void decreaseAltitude(Drone *drone, int meters) {
    if (drone->isFlying && drone->altitude > meters) {
        drone->altitude -= meters;
        printf("Altitude decreased to %d meters.\n", drone->altitude);
    } else {
        printf("Drone is either not flying or can't decrease below ground level!\n");
    }
}

void setSpeed(Drone *drone, int speed) {
    if (drone->isFlying) {
        drone->speed = speed;
        printf("Speed set to %d m/s.\n", drone->speed);
    } else {
        printf("Drone must be flying to set speed!\n");
    }
}

void recoveryMode(Drone *drone) {
    printf("Entering recovery mode...\n");
    drone->isFlying = false;
    drone->altitude = 0;
    drone->speed = 0;
    printf("Drone has safely landed and is now in recovery mode.\n");
}

void displayMenu() {
    printf("\nDrone Remote Control Menu:\n");
    printf("1. Take Off\n");
    printf("2. Land\n");
    printf("3. Increase Altitude\n");
    printf("4. Decrease Altitude\n");
    printf("5. Set Speed\n");
    printf("6. View Status\n");
    printf("7. Enter Recovery Mode\n");
    printf("8. Exit\n");
}

int main() {
    Drone myDrone = {false, 0, 0}; // Initialize drone status
    int command, altitudeChange, speedChange;

    while (true) {
        displayMenu();
        printf("Enter your command: ");
        if (scanf("%d", &command) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while(getchar() != '\n'); // Clear invalid input
            continue;
        }

        switch (command) {
            case 1:
                takeOff(&myDrone);
                break;
            case 2:
                land(&myDrone);
                break;
            case 3:
                printf("Enter amount to increase altitude (in meters): ");
                if (scanf("%d", &altitudeChange) != 1) {
                    printf("Invalid input! Please enter a number.\n");
                    while(getchar() != '\n'); // Clear invalid input
                    continue;
                }
                increaseAltitude(&myDrone, altitudeChange);
                break;
            case 4:
                printf("Enter amount to decrease altitude (in meters): ");
                if (scanf("%d", &altitudeChange) != 1) {
                    printf("Invalid input! Please enter a number.\n");
                    while(getchar() != '\n'); // Clear invalid input
                    continue;
                }
                decreaseAltitude(&myDrone, altitudeChange);
                break;
            case 5:
                printf("Enter speed (in m/s): ");
                if (scanf("%d", &speedChange) != 1) {
                    printf("Invalid input! Please enter a number.\n");
                    while(getchar() != '\n'); // Clear invalid input
                    continue;
                }
                setSpeed(&myDrone, speedChange);
                break;
            case 6:
                displayStatus(&myDrone);
                break;
            case 7:
                recoveryMode(&myDrone);
                break;
            case 8:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid command! Please try again.\n");
                break;
        }
        sleep(1); // Small delay for better user experience
    }

    return 0;
}