//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PATH 50
#define MAX_COMMAND 20
#define MAX_SPEED 100
#define MAX_FUEL 50

typedef struct {
    char direction[10];
    int speed;
    int fuel;
    int health;
} Vehicle;

int main() {
    // Initialize the vehicle
    Vehicle myVehicle = {"north", 0, MAX_FUEL, 100};

    // Introduction
    printf("Welcome to the Post-Apocalyptic Remote Control Vehicle Simulation!\n");
    printf("Commands: left, right, forward, backward, speed up, slow down, exit.\n");
    printf("Type 'help' for the list of commands.\n");

    while (1) {
        // Prompt for user input
        char command[MAX_COMMAND];
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "left") == 0) {
            printf("Turning left.\n");
            strcpy(myVehicle.direction, "west");
        }
        else if (strcmp(command, "right") == 0) {
            printf("Turning right.\n");
            strcpy(myVehicle.direction, "east");
        }
        else if (strcmp(command, "forward") == 0) {
            printf("Moving forward.\n");
            if (myVehicle.speed <= 0) {
                printf("You can't move forward without speed.\n");
                continue;
            }
            if (myVehicle.fuel <= 0) {
                printf("Out of fuel! Game over.\n");
                break;
            }
            myVehicle.fuel--;
            if (rand() % 10 == 0) {
                printf("The vehicle hit a rough patch. Health decreased by 10.\n");
                myVehicle.health -= 10;
            }
        }
        else if (strcmp(command, "backward") == 0) {
            printf("Moving backward.\n");
            if (myVehicle.speed <= 0) {
                printf("You can't move backward without speed.\n");
                continue;
            }
            if (myVehicle.fuel <= 0) {
                printf("Out of fuel! Game over.\n");
                break;
            }
            myVehicle.fuel--;
            if (rand() % 10 == 0) {
                printf("The vehicle hit a rough patch. Health decreased by 10.\n");
                myVehicle.health -= 10;
            }
        }
        else if (strcmp(command, "speed up") == 0) {
            printf("Speeding up.\n");
            if (myVehicle.speed >= MAX_SPEED) {
                printf("You can't speed up any more.\n");
                continue;
            }
            if (myVehicle.fuel <= 0) {
                printf("Out of fuel! Game over.\n");
                break;
            }
            myVehicle.fuel--;
            myVehicle.speed++;
        }
        else if (strcmp(command, "slow down") == 0) {
            printf("Slowing down.\n");
            if (myVehicle.speed <= 0) {
                printf("You can't slow down any more.\n");
                continue;
            }
            myVehicle.speed--;
        }
        else if (strcmp(command, "help") == 0) {
            printf("Commands: left, right, forward, backward, speed up, slow down, exit.\n");
        }
        else if (strcmp(command, "exit") == 0) {
            printf("Exiting program.\n");
            break;
        }
        else {
            printf("Invalid command. Type 'help' for the list of commands.\n");
        }

        // Print the status of the vehicle
        printf("Direction: %s\n", myVehicle.direction);
        printf("Speed: %d\n", myVehicle.speed);
        printf("Fuel: %d\n", myVehicle.fuel);
        printf("Health: %d\n", myVehicle.health);

        // Check if the vehicle is still alive
        if (myVehicle.health <= 0) {
            printf("Vehicle has been destroyed! Game over.\n");
            break;
        }
    }

    return 0;
}