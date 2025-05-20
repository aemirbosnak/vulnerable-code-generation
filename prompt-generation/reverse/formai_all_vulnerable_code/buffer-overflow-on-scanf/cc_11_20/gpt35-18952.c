//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isFlying = false;
int altitude = 0;
int batteryLife = 100;

int main() {
    printf("Welcome to the C Drone Remote Control Program!\n");
    printf("Press 1 to start the drone or 0 to quit: ");
    int start = 0;
    scanf("%d", &start);
    
    if (start != 1) {
        printf("You're no fun. Goodbye!\n");
        exit(0);
    }
    printf("Drone is now starting up...\n");
    printf("Press A to increase altitude, Z to decrease altitude, and X to land.\n");
    printf("Battery life is currently at %d%%\n", batteryLife);
    
    while (true) {
        char command;
        printf("Enter a command: ");
        scanf(" %c", &command);
        
        if (command == 'A') {
            if (!isFlying || altitude >= 100) {
                printf("Cannot increase altitude while landed or at max altitude.\n");
            } else {
                altitude += 10;
                printf("Altitude increased to %d\n", altitude);
            }
        } else if (command == 'Z') {
            if (!isFlying || altitude <= 0) {
                printf("Cannot decrease altitude while landed or at min altitude.\n");
            } else {
                altitude -= 10;
                printf("Altitude decreased to %d\n", altitude);
            }
        } else if (command == 'X') {
            if (!isFlying || altitude != 0) {
                printf("Cannot land while not in flight or not at min altitude.\n");
            } else {
                printf("Landing...\n");
                isFlying = false;
                batteryLife -= 10;
                printf("Battery life is now at %d%%\n", batteryLife);
                if (batteryLife <= 0) {
                    printf("Battery has reached critical levels. Returning drone to docking station.\n");
                    break;
                }
            }
        } else {
            printf("Invalid command. Please try again.\n");
        }
        
        if (!isFlying && altitude == 0) {
            printf("Drone is currently on the ground.\n");
            printf("Press F to take off or X to quit: ");
            char action;
            scanf(" %c", &action);
            if (action == 'F') {
                printf("Taking off...\n");
                altitude = 10;
                isFlying = true;
                batteryLife -= 5;
                printf("Battery life is now at %d%%\n", batteryLife);
                if (batteryLife <= 0) {
                    printf("Battery has reached critical levels. Returning drone to docking station.\n");
                    break;
                }
            } else if (action == 'X') {
                printf("Goodbye!\n");
                break;
            } else {
                printf("Invalid command. Returning drone to docking station.\n");
                altitude = 0;
                isFlying = false;
            }
        }
    }
    printf("Program complete. Returning drone to docking station.\n");
    altitude = 0;
    isFlying = false;
    printf("Drone successfully docked. Goodbye!\n");
    return 0;
}