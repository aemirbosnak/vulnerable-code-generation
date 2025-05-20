//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100

typedef struct Drone {
    int altitude;
    int speed;
    char direction[10];
} Drone;

void initializeDrone(Drone *drone) {
    drone->altitude = 0;
    drone->speed = 0;
    strcpy(drone->direction, "hover");
    printf("Drone initialized. Ready for commands!\n");
}

void takeOff(Drone *drone) {
    if (drone->altitude <= 0) {
        drone->altitude = 10; // take off to 10 meters
        printf("Drone took off. Altitude: %d meters\n", drone->altitude);
    } else {
        printf("Drone is already in the air at %d meters altitude.\n", drone->altitude);
    }
}

void land(Drone *drone) {
    if (drone->altitude > 0) {
        drone->altitude = 0; // land the drone
        printf("Drone has landed safely.\n");
    } else {
        printf("Drone is already on the ground.\n");
    }
}

void ascend(Drone *drone, int meters) {
    if (meters > 0) {
        drone->altitude += meters;
        printf("Drone ascended. Current altitude: %d meters\n", drone->altitude);
    } else {
        printf("Please provide a positive number to ascend.\n");
    }
}

void descend(Drone *drone, int meters) {
    if (meters > 0 && drone->altitude >= meters) {
        drone->altitude -= meters;
        printf("Drone descended. Current altitude: %d meters\n", drone->altitude);
    } else if (drone->altitude < meters) {
        printf("Cannot descend beyond ground level.\n");
    } else {
        printf("Please provide a positive number to descend.\n");
    }
}

void setSpeed(Drone *drone, int speed) {
    if (speed >= 0) {
        drone->speed = speed;
        printf("Drone speed set to %d m/s\n", drone->speed);
    } else {
        printf("Speed cannot be negative.\n");
    }
}

void changeDirection(Drone *drone, const char *newDirection) {
    if (strcmp(newDirection, "forward") == 0 || strcmp(newDirection, "backward") == 0 || 
        strcmp(newDirection, "left") == 0 || strcmp(newDirection, "right") == 0) {
        strcpy(drone->direction, newDirection);
        printf("Drone is now facing %s.\n", drone->direction);
    } else {
        printf("Invalid direction. Use forward, backward, left, or right.\n");
    }
}

void showStatus(Drone *drone) {
    printf("Drone Status:\n");
    printf("Altitude: %d meters\n", drone->altitude);
    printf("Speed: %d m/s\n", drone->speed);
    printf("Direction: %s\n", drone->direction);
}

void processCommand(Drone *drone, char *command) {
    char action[MAX_COMMAND_LENGTH];
    int value;
    
    if (sscanf(command, "%s %d", action, &value) >= 1) {
        if (strcmp(action, "takeoff") == 0) {
            takeOff(drone);
        } else if (strcmp(action, "land") == 0) {
            land(drone);
        } else if (strcmp(action, "ascend") == 0) {
            ascend(drone, value);
        } else if (strcmp(action, "descend") == 0) {
            descend(drone, value);
        } else if (strcmp(action, "speed") == 0) {
            setSpeed(drone, value);
        } else if (strcmp(action, "direction") == 0) {
            if (sscanf(command, "%*s %s", action) == 1) {
                changeDirection(drone, action);
            }
        } else if (strcmp(action, "status") == 0) {
            showStatus(drone);
        } else {
            printf("Unknown command: %s\n", command);
        }
    } else {
        printf("Invalid command format.\n");
    }
}

int main() {
    Drone drone;
    char command[MAX_COMMAND_LENGTH];

    initializeDrone(&drone);

    while (1) {
        printf("\nEnter Command: ");
        if (fgets(command, sizeof(command), stdin) != NULL) {
            command[strcspn(command, "\n")] = 0; // remove the newline character
            if (strcmp(command, "exit") == 0) {
                printf("Exiting drone control.\n");
                break;
            }
            processCommand(&drone, command);
        }
    }

    return 0;
}