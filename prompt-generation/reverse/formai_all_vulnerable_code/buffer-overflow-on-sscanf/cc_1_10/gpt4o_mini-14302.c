//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: Sherlock Holmes
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define DRONE_NAME "Sherlock's Drone"

typedef struct {
    int altitude; // The current altitude level of the drone
    int x_position; // The x-axis position of the drone
    int y_position; // The y-axis position of the drone
} Drone;

// Function declarations
void initialize_drone(Drone *drone);
void display_status(const Drone *drone);
void move_drone(Drone *drone, const char *direction, int distance);
void ascend_drone(Drone *drone, int height);
void descend_drone(Drone *drone, int height);

// Main function
int main(void) {
    Drone my_drone;
    char command[MAX_COMMAND_LENGTH];
    char direction[20];
    int distance;

    initialize_drone(&my_drone);
    printf("Welcome to %s, my dear Watson! Let us control the drone.\n", DRONE_NAME);
    display_status(&my_drone);
    
    while (1) {
        printf("Enter your command (or type 'exit' to quit): ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        
        if (strncmp(command, "exit", 4) == 0) {
            printf("Exiting the drone control program. Until next time!\n");
            break;
        }

        if (sscanf(command, "move %s %d", direction, &distance) == 2) {
            move_drone(&my_drone, direction, distance);
        } else if (sscanf(command, "ascend %d", &distance) == 1) {
            ascend_drone(&my_drone, distance);
        } else if (sscanf(command, "descend %d", &distance) == 1) {
            descend_drone(&my_drone, distance);
        } else {
            printf("Alas! I did not understand the command. Please try again.\n");
        }
        
        display_status(&my_drone);
    }
    
    return 0;
}

// Function definitions
void initialize_drone(Drone *drone) {
    drone->altitude = 0;
    drone->x_position = 0;
    drone->y_position = 0;
    printf("The drone has been initialized, Watson.\n");
}

void display_status(const Drone *drone) {
    printf("Current Status: Altitude: %d m, Position: (%d, %d)\n", 
           drone->altitude, drone->x_position, drone->y_position);
}

void move_drone(Drone *drone, const char *direction, int distance) {
    if (strcmp(direction, "north") == 0) {
        drone->y_position += distance;
        printf("The drone moves north by %d meters.\n", distance);
    } else if (strcmp(direction, "south") == 0) {
        drone->y_position -= distance;
        printf("The drone moves south by %d meters.\n", distance);
    } else if (strcmp(direction, "east") == 0) {
        drone->x_position += distance;
        printf("The drone moves east by %d meters.\n", distance);
    } else if (strcmp(direction, "west") == 0) {
        drone->x_position -= distance;
        printf("The drone moves west by %d meters.\n", distance);
    } else {
        printf("The direction '%s' is quite unfamiliar, my dear Watson.\n", direction);
    }
}

void ascend_drone(Drone *drone, int height) {
    if (height < 0) {
        printf("A negative ascent is beyond my comprehension, Watson.\n");
    } else {
        drone->altitude += height;
        printf("The drone ascends by %d meters.\n", height);
    }
}

void descend_drone(Drone *drone, int height) {
    if (height < 0) {
        printf("Descending a negative height? A perplexing thought indeed!\n");
    } else if (drone->altitude < height) {
        printf("The drone cannot descend that much. It is already at an altitude of %d m.\n", drone->altitude);
    } else {
        drone->altitude -= height;
        printf("The drone descends by %d meters.\n", height);
    }
}