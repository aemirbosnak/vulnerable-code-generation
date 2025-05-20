//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 50

typedef struct {
    char *status;
    float altitude;
    float position[3]; // x, y, z coordinates
} Drone;

void initialize_drone(Drone *drone) {
    drone->status = "landed";
    drone->altitude = 0.0;
    drone->position[0] = 0.0;
    drone->position[1] = 0.0;
    drone->position[2] = 0.0;
}

void takeoff(Drone *drone) {
    if (strcmp(drone->status, "landed") == 0) {
        drone->status = "flying";
        drone->altitude = 10.0; // set altitude to 10 meters
        printf("Drone has taken off to an altitude of %.2f meters.\n", drone->altitude);
    } else {
        printf("Drone is already flying.\n");
    }
}

void landing(Drone *drone) {
    if (strcmp(drone->status, "flying") == 0) {
        drone->status = "landed";
        drone->altitude = 0.0; // set altitude to 0 meters
        printf("Drone has landed safely.\n");
    } else {
        printf("Drone is already on the ground.\n");
    }
}

void move_drone(Drone *drone, float x, float y, float z) {
    if (strcmp(drone->status, "flying") == 0) {
        drone->position[0] += x;
        drone->position[1] += y;
        drone->position[2] += z;
        printf("Drone moved to position: (%.2f, %.2f, %.2f)\n", drone->position[0], drone->position[1], drone->position[2]);
    } else {
        printf("Drone must be flying to move.\n");
    }
}

void display_status(Drone *drone) {
    printf("Drone status: %s\n", drone->status);
    printf("Current altitude: %.2f meters\n", drone->altitude);
    printf("Current position: (%.2f, %.2f, %.2f)\n", drone->position[0], drone->position[1], drone->position[2]);
}

void display_help() {
    printf("Available commands:\n");
    printf("  takeoff       - Makes the drone take off.\n");
    printf("  landing       - Makes the drone land.\n");
    printf("  move x y z    - Move the drone by x, y, and z positions.\n");
    printf("  status        - Display the current status of the drone.\n");
    printf("  help          - Show this help message.\n");
    printf("  exit          - Exit the program.\n");
}

int main() {
    Drone drone;
    initialize_drone(&drone);
    
    char command[MAX_COMMAND_LENGTH];
    
    printf("Welcome to the Drone Remote Control!\n");
    display_help();
    
    while (1) {
        printf("\n> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline character
        
        if (strcmp(command, "takeoff") == 0) {
            takeoff(&drone);
        } else if (strcmp(command, "landing") == 0) {
            landing(&drone);
        } else if (strncmp(command, "move", 4) == 0) {
            float x, y, z;
            if (sscanf(command + 5, "%f %f %f", &x, &y, &z) == 3) {
                move_drone(&drone, x, y, z);
            } else {
                printf("Invalid move command. Please specify x, y, z values.\n");
            }
        } else if (strcmp(command, "status") == 0) {
            display_status(&drone);
        } else if (strcmp(command, "help") == 0) {
            display_help();
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the Drone Remote Control. Goodbye!\n");
            break;
        } else {
            printf("Unknown command: %s. Type 'help' for a list of commands.\n", command);
        }
    }

    return 0;
}