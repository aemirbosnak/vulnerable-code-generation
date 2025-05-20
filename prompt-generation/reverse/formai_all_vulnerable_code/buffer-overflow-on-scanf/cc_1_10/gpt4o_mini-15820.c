//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x;
    int y;
    char direction; // 'N', 'E', 'S', 'W'
} RCVehicle;

void initializeVehicle(RCVehicle *vehicle) {
    vehicle->x = 0;
    vehicle->y = 0;
    vehicle->direction = 'N'; // Default to facing North
}

void displayStatus(RCVehicle *vehicle) {
    printf("Vehicle is at (%d, %d) facing %c\n", vehicle->x, vehicle->y, vehicle->direction);
}

void moveForward(RCVehicle *vehicle) {
    switch (vehicle->direction) {
        case 'N':
            vehicle->y += 1;
            break;
        case 'E':
            vehicle->x += 1;
            break;
        case 'S':
            vehicle->y -= 1;
            break;
        case 'W':
            vehicle->x -= 1;
            break;
    }
    printf("Moving forward...\n");
}

void moveBackward(RCVehicle *vehicle) {
    switch (vehicle->direction) {
        case 'N':
            vehicle->y -= 1;
            break;
        case 'E':
            vehicle->x -= 1;
            break;
        case 'S':
            vehicle->y += 1;
            break;
        case 'W':
            vehicle->x += 1;
            break;
    }
    printf("Moving backward...\n");
}

void turnLeft(RCVehicle *vehicle) {
    switch (vehicle->direction) {
        case 'N':
            vehicle->direction = 'W';
            break;
        case 'E':
            vehicle->direction = 'N';
            break;
        case 'S':
            vehicle->direction = 'E';
            break;
        case 'W':
            vehicle->direction = 'S';
            break;
    }
    printf("Turning left...\n");
}

void turnRight(RCVehicle *vehicle) {
    switch (vehicle->direction) {
        case 'N':
            vehicle->direction = 'E';
            break;
        case 'E':
            vehicle->direction = 'S';
            break;
        case 'S':
            vehicle->direction = 'W';
            break;
        case 'W':
            vehicle->direction = 'N';
            break;
    }
    printf("Turning right...\n");
}

int main() {
    RCVehicle myVehicle;
    initializeVehicle(&myVehicle);
    char command[20];

    printf("Welcome to the RC Vehicle Simulation!\n");
    printf("Use 'F' to move forward, 'B' to move backward, 'L' to turn left,\n");
    printf("'R' to turn right, 'S' to stop, 'Q' to quit.\n\n");

    while (1) {
        displayStatus(&myVehicle);
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "F") == 0) {
            moveForward(&myVehicle);
        } else if (strcmp(command, "B") == 0) {
            moveBackward(&myVehicle);
        } else if (strcmp(command, "L") == 0) {
            turnLeft(&myVehicle);
        } else if (strcmp(command, "R") == 0) {
            turnRight(&myVehicle);
        } else if (strcmp(command, "S") == 0) {
            printf("Vehicle stopped.\n");
        } else if (strcmp(command, "Q") == 0) {
            printf("Exiting simulation. Goodbye!\n");
            break;
        } else {
            printf("Unknown command! Please try again.\n");
        }
    }

    return 0;
}