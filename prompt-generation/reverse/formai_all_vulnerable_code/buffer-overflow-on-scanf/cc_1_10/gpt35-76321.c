//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: sophisticated
#include <stdio.h>

// Constants to define drone movements
#define MOVE_NORTH 1
#define MOVE_SOUTH 2
#define MOVE_EAST  3
#define MOVE_WEST  4

// Constants to define drone functions
#define FUNCTION_PUT 1
#define FUNCTION_GET 2
#define FUNCTION_PHOTO 3

// Function to move the drone
void moveDrone(int direction, int distance) {
    printf("Drone moved ");
    switch (direction) {
        case MOVE_NORTH:
            printf("north");
            break;
        case MOVE_SOUTH:
            printf("south");
            break;
        case MOVE_EAST:
            printf("east");
            break;
        case MOVE_WEST:
            printf("west");
            break;
        default:
            printf("in an unknown direction");
            break;
    }
    printf(" by %d meters.\n", distance);
}

// Function to perform drone function
void droneFunction(int function) {
    switch (function) {
        case FUNCTION_PUT:
            printf("Drone put down the package.\n");
            break;
        case FUNCTION_GET:
            printf("Drone picked up the package.\n");
            break;
        case FUNCTION_PHOTO:
            printf("Drone took a photo.\n");
            break;
        default:
            printf("Drone performed an unknown function.\n");
            break;
    }
}

int main() {
    // Take input from user for drone movements and functions
    int moves;
    printf("How many movements to make?: ");
    scanf("%d", &moves);
    int moveDirection[moves];
    int moveDistance[moves];
    int functions;
    printf("How many functions to perform?: ");
    scanf("%d", &functions);
    int functionType[functions];

    // Take input from user for drone movements
    for (int i = 0; i < moves; i++) {
        printf("Enter move %d (1=north, 2=south, 3=east, 4=west): ", i+1);
        scanf("%d", &moveDirection[i]);
        printf("Enter move distance (in meters): ");
        scanf("%d", &moveDistance[i]);
    }

    // Take input from user for drone functions
    for (int i = 0; i < functions; i++) {
        printf("Enter function %d (1=put package, 2=get package, 3=take photo): ", i+1);
        scanf("%d", &functionType[i]);
    }

    // Execute drone movements
    for (int i = 0; i < moves; i++) {
        moveDrone(moveDirection[i], moveDistance[i]);
    }

    // Execute drone functions
    for (int i = 0; i < functions; i++) {
        droneFunction(functionType[i]);
    }

    printf("Drone landed safely.\n");

    return 0;
}