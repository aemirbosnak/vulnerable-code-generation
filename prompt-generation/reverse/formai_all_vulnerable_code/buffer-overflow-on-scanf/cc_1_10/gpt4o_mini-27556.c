//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SPEED 10
#define MIN_SPEED 0
#define DISTANCE 100

typedef struct {
    int position;
    int speed;
} RemoteControlVehicle;

void initializeVehicle(RemoteControlVehicle *vehicle) {
    vehicle->position = 0;
    vehicle->speed = 0;
    printf("Rev up your engines! The vehicle is ready to race!\n");
}

void accelerate(RemoteControlVehicle *vehicle) {
    if (vehicle->speed < MAX_SPEED) {
        vehicle->speed++;
        printf("Accelerating! Current speed: %d\n", vehicle->speed);
    } else {
        printf("Max speed reached! Hold tight!\n");
    }
}

void decelerate(RemoteControlVehicle *vehicle) {
    if (vehicle->speed > MIN_SPEED) {
        vehicle->speed--;
        printf("Decelerating! Current speed: %d\n", vehicle->speed);
    } else {
        printf("The vehicle is already at a standstill!\n");
    }
}

void move(RemoteControlVehicle *vehicle) {
    vehicle->position += vehicle->speed;
    printf("Vroom vroom! The vehicle is now at position: %d\n", vehicle->position);
}

void displayStatus(RemoteControlVehicle *vehicle) {
    printf("Current position: %d | Current speed: %d\n", vehicle->position, vehicle->speed);
}

void showMenu() {
    printf("=== Remote Control Vehicle Simulator ===\n");
    printf("1. Accelerate\n");
    printf("2. Decelerate\n");
    printf("3. Move\n");
    printf("4. Display Status\n");
    printf("5. Exit\n");
    printf("=========================================\n");
    printf("Choose your action: ");
}

int main() {
    int choice;
    RemoteControlVehicle vehicle;

    initializeVehicle(&vehicle);

    while (1) {
        showMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                accelerate(&vehicle);
                break;
            case 2:
                decelerate(&vehicle);
                break;
            case 3:
                move(&vehicle);
                break;
            case 4:
                displayStatus(&vehicle);
                break;
            case 5:
                printf("Thank you for driving! See you next time!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select again. \n");
                break;
        }

        printf("\n");
        sleep(1); // Short delay for better user experience
    }

    return 0;
}