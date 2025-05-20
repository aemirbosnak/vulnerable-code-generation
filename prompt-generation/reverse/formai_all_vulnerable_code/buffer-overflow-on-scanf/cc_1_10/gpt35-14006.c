//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Set random seed based on current time

    printf("Welcome to the Remote Control Vehicle Simulator!\n");
    printf("Choose your vehicle:\n");
    printf("1. Car\n");
    printf("2. Truck\n");
    printf("3. Helicopter\n");

    int choice = 0;
    scanf("%d", &choice);

    int speed = 0;
    if (choice == 1) {
        printf("You have selected a car.\n");
        printf("Enter the speed of the car (in km/h): ");
        scanf("%d", &speed);
    } else if (choice == 2) {
        printf("You have selected a truck.\n");
        printf("Enter the speed of the truck (in km/h): ");
        scanf("%d", &speed);
    } else if (choice == 3) {
        printf("You have selected a helicopter.\n");
        printf("Enter the height of the helicopter (in meters): ");
        scanf("%d", &speed);
    } else {
        printf("Invalid selection. Exiting program.\n");
        return 0;
    }

    printf("Starting vehicle simulation...\n");

    int time = 0;
    int distance = 0;
    int altitude = 0;

    while (time < 10) {
        int randomValue = rand() % 10 - 5; // Generate random value between -5 and 5

        if (choice == 1 || choice == 2) {
            distance += speed + randomValue; // Update distance traveled
            printf("Time: %d seconds | Distance: %d km\n", time, distance);
        } else {
            altitude += speed + randomValue; // Update altitude
            printf("Time: %d seconds | Altitude: %d meters\n", time, altitude);
        }

        time++; // increment time
    }

    printf("Simulation has ended. Thank you for using the Remote Control Vehicle Simulator!\n");

    return 0;
}