//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 50

typedef struct {
    float altitude;
    float speed;
    float position[3]; // x, y, z
    int isFlying;
} Drone;

void takeOff(Drone *drone) {
    if (!drone->isFlying) {
        drone->altitude = 10.0; // Ascend 10 meters
        drone->isFlying = 1;
        printf("Drone has taken off!\n");
    } else {
        printf("Drone is already in the air.\n");
    }
}

void land(Drone *drone) {
    if (drone->isFlying) {
        drone->altitude = 0.0; // Descend to ground
        drone->isFlying = 0;
        printf("Drone has landed.\n");
    } else {
        printf("Drone is already on the ground.\n");
    }
}

void move(Drone *drone, float x, float y, float z) {
    if (drone->isFlying) {
        drone->position[0] += x;
        drone->position[1] += y;
        drone->position[2] += z;
        printf("Drone moved to position (%.2f, %.2f, %.2f).\n", 
               drone->position[0], drone->position[1], drone->position[2]);
    } else {
        printf("Drone must be in the air to move.\n");
    }
}

void changeSpeed(Drone *drone, float newSpeed) {
    if (newSpeed >= 0) {
        drone->speed = newSpeed;
        printf("Drone speed set to %.2f.\n", drone->speed);
    } else {
        printf("Speed cannot be negative.\n");
    }
}

void displayStatus(Drone *drone) {
    printf("\nDrone Status:\n");
    printf("   Altitude: %.2f meters\n", drone->altitude);
    printf("   Speed: %.2f m/s\n", drone->speed);
    printf("   Position: (%.2f, %.2f, %.2f)\n", 
           drone->position[0], drone->position[1], drone->position[2]);
    printf("   Status: %s\n\n", drone->isFlying ? "Flying" : "Landed");
}

int main() {
    Drone myDrone = {0.0, 0.0, {0.0, 0.0, 0.0}, 0};

    char command[MAX_COMMAND_LENGTH];
    printf("Drone Remote Control Interface\n");
    printf("Available commands: takeoff, land, move <x> <y> <z>, speed <value>, status, exit\n");

    while (1) {
        printf("> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline character

        if (strcmp(command, "takeoff") == 0) {
            takeOff(&myDrone);
        } else if (strcmp(command, "land") == 0) {
            land(&myDrone);
        } else if (sscanf(command, "move %f %f %f", 
                          &myDrone.position[0], &myDrone.position[1], &myDrone.position[2]) == 3) {
            move(&myDrone, myDrone.position[0], myDrone.position[1], myDrone.position[2]);
        } else if (sscanf(command, "speed %f", &myDrone.speed) == 1) {
            changeSpeed(&myDrone, myDrone.speed);
        } else if (strcmp(command, "status") == 0) {
            displayStatus(&myDrone);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting Drone Control Interface...\n");
            break;
        } else {
            printf("Invalid command. Please enter a valid command.\n");
        }
    }

    return 0;
}