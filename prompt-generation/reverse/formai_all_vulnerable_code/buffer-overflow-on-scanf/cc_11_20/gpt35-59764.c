//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_DISTANCE 100 // Maximum distance the drone can travel
#define MIN_DISTANCE 10 // Minimum distance the drone can travel
#define MAX_SPEED 10 // Maximum speed the drone can travel
#define MIN_SPEED 1 // Minimum speed the drone can travel

int main()
{
    srand(time(NULL)); // Initializes random number generator

    int distance = (rand() % (MAX_DISTANCE - MIN_DISTANCE + 1)) + MIN_DISTANCE; // Generates random distance between MAX_DISTANCE and MIN_DISTANCE
    int speed = (rand() % (MAX_SPEED - MIN_SPEED + 1)) + MIN_SPEED; // Generates random speed between MAX_SPEED and MIN_SPEED

    int currentPosition = 0; // Current position of the drone
    bool isFlying = false; // Flag to check if the drone is flying or not

    printf("*** Retro C Drone Remote Control ***\n\n");

    while (true) {
        printf("Enter command (f - fly, l - land, s - status, q - quit): ");
        char command;
        scanf(" %c", &command);

        switch (command) {
            case 'f': // Fly command
                if (isFlying) { // If drone is already flying, output error message
                    printf("Drone is already flying\n");
                } else { // If drone is not flying, take off and update status
                    printf("Taking off...\n");
                    isFlying = true;
                }
                break;
            case 'l': // Land command
                if (!isFlying) { // If drone is not flying, output error message
                    printf("Drone is not flying\n");
                } else { // If drone is flying, land and update status
                    printf("Landing...\n");
                    isFlying = false;
                }
                break;
            case 's': // Status command
                printf("Drone is %s at position %d\n", isFlying ? "flying" : "on the ground", currentPosition);
                break;
            case 'q': // Quit command
                printf("Quitting...\n");
                return 0;
            default: // Invalid command
                printf("Invalid command\n");
        }

        if (isFlying) { // If drone is flying, update position based on speed and distance
            currentPosition += speed;
            if (currentPosition >= distance) { // If drone reaches the destination, land and update status
                printf("Reached destination\n");
                printf("Landing...\n");
                isFlying = false;
                currentPosition = 0;
                distance = (rand() % (MAX_DISTANCE - MIN_DISTANCE + 1)) + MIN_DISTANCE;
                speed = (rand() % (MAX_SPEED - MIN_SPEED + 1)) + MIN_SPEED;
            }
        }
    }

    return 0;
}