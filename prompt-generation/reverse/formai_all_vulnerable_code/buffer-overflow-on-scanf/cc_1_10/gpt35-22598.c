//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define drone controller struct
typedef struct DroneController_t {
    int altitude;
    int distance;
    int batteryLife;
} DroneController;

// Define function to initialize drone controller
DroneController initController() {
    DroneController controller;
    controller.altitude = 0;
    controller.distance = 0;
    controller.batteryLife = 100;

    return controller;
}

int main() {
    srand(time(0));
    DroneController controller = initController();
    int input;

    printf("Welcome to the C Drone Remote Control Program! Let's get started.\n");

    while (controller.batteryLife > 0) {
        printf("Select an action:\n1 - Increase altitude\n2 - Decrease altitude\n3 - Move forward\n4 - Move backwards\n5 - Check battery life\n6 - Quit\n");

        scanf("%d", &input);

        switch(input) {
            case 1:
                controller.altitude++;
                printf("Altitude increased to %d.\n", controller.altitude);
                break;
            case 2:
                if (controller.altitude > 0) {
                    controller.altitude--;
                    printf("Altitude decreased to %d.\n", controller.altitude);
                } else {
                    printf("Drone is already at the lowest altitude.\n");
                }
                break;
            case 3:
                if (controller.altitude > 0) {
                    int distance = rand() % 11 + 10; // Generate a random distance between 10-20 meters
                    controller.distance += distance;
                    controller.batteryLife -= distance * 2; // Decrease battery life based on distance
                    printf("Moved forward %d meters.\n", distance);
                } else {
                    printf("Cannot move forward while altitude is 0.\n");
                }
                break;
            case 4:
                if (controller.altitude > 0) {
                    int distance = rand() % 11 + 10; // Generate a random distance between 10-20 meters
                    controller.distance -= distance;
                    controller.batteryLife -= distance * 2; // Decrease battery life based on distance
                    printf("Moved backwards %d meters.\n", distance);
                } else {
                    printf("Cannot move backwards while altitude is 0.\n");
                }
                break;
            case 5:
                printf("Battery life remaining: %d percent.\n", controller.batteryLife);
                break;
            case 6:
                printf("Exiting drone control program.\n");
                exit(0);
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }

        // Check battery life
        if (controller.batteryLife <= 0) {
            printf("Battery life is too low to continue. Drone has crashed.\n");
            exit(0);
        } else if (controller.batteryLife <= 20) {
            printf("WARNING: Battery life is low.\n");
        }
    }

    return 0;
}