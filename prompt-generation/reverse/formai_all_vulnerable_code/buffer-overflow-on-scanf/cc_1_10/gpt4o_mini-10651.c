//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <fcntl.h>

// Define drone control commands
#define TAKE_OFF "takeoff"
#define LAND "land"
#define FORWARD "forward"
#define BACKWARD "backward"
#define LEFT "left"
#define RIGHT "right"
#define UP "up"
#define DOWN "down"
#define QUIT "quit"

// Structure to hold the drone's state
typedef struct {
    int altitude; // Altitude of the drone
    int positionX; // Position in X-axis
    int positionY; // Position in Y-axis
} Drone;

void init_drone(Drone *drone) {
    drone->altitude = 0; // Start on the ground
    drone->positionX = 0; // Start at origin
    drone->positionY = 0; // Start at origin
}

void take_off(Drone *drone) {
    if (drone->altitude == 0) {
        drone->altitude = 1; // Ascend to the first altitude
        printf("Drone is taking off!\n");
    } else {
        printf("Drone is already in the air!\n");
    }
}

void land(Drone *drone) {
    if (drone->altitude > 0) {
        drone->altitude = 0; // Land the drone
        printf("Drone is landing!\n");
    } else {
        printf("Drone is already on the ground!\n");
    }
}

void move_forward(Drone *drone) {
    if (drone->altitude > 0) {
        drone->positionY += 1; // Move forward
        printf("Drone moved forward to position (%d, %d)\n", drone->positionX, drone->positionY);
    } else {
        printf("Drone must be in the air to move forward!\n");
    }
}

void move_backward(Drone *drone) {
    if (drone->altitude > 0) {
        drone->positionY -= 1; // Move backward
        printf("Drone moved backward to position (%d, %d)\n", drone->positionX, drone->positionY);
    } else {
        printf("Drone must be in the air to move backward!\n");
    }
}

void move_left(Drone *drone) {
    if (drone->altitude > 0) {
        drone->positionX -= 1; // Move left
        printf("Drone moved left to position (%d, %d)\n", drone->positionX, drone->positionY);
    } else {
        printf("Drone must be in the air to move left!\n");
    }
}

void move_right(Drone *drone) {
    if (drone->altitude > 0) {
        drone->positionX += 1; // Move right
        printf("Drone moved right to position (%d, %d)\n", drone->positionX, drone->positionY);
    } else {
        printf("Drone must be in the air to move right!\n");
    }
}

void ascend(Drone *drone) {
    if (drone->altitude > 0) {
        drone->altitude += 1; // Increase altitude
        printf("Drone ascended to altitude %d\n", drone->altitude);
    } else {
        printf("Drone must be in the air to ascend!\n");
    }
}

void descend(Drone *drone) {
    if (drone->altitude > 0 && drone->altitude > 1) {
        drone->altitude -= 1; // Decrease altitude
        printf("Drone descended to altitude %d\n", drone->altitude);
    } else if (drone->altitude == 1) {
        printf("Drone cannot descend further without landing!\n");
    } else {
        printf("Drone must be in the air to descend!\n");
    }
}

// Function to get user input
void get_command(char *cmd) {
    printf("\nEnter command: ");
    scanf("%s", cmd);
}

int main() {
    Drone drone;
    init_drone(&drone);
    char command[50];

    printf("Welcome to the Drone Remote Control Program!\n");
    printf("Available commands: takeoff, land, forward, backward, left, right, up, down, quit\n");

    while (1) {
        get_command(command);

        if (strcmp(command, TAKE_OFF) == 0) {
            take_off(&drone);
        } else if (strcmp(command, LAND) == 0) {
            land(&drone);
        } else if (strcmp(command, FORWARD) == 0) {
            move_forward(&drone);
        } else if (strcmp(command, BACKWARD) == 0) {
            move_backward(&drone);
        } else if (strcmp(command, LEFT) == 0) {
            move_left(&drone);
        } else if (strcmp(command, RIGHT) == 0) {
            move_right(&drone);
        } else if (strcmp(command, UP) == 0) {
            ascend(&drone);
        } else if (strcmp(command, DOWN) == 0) {
            descend(&drone);
        } else if (strcmp(command, QUIT) == 0) {
            printf("Exiting the Drone Remote Control Program. Goodbye!\n");
            break;
        } else {
            printf("Unknown command! Try again.\n");
        }
    }

    return 0;
}