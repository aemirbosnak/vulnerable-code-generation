//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: interoperable
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#define TURN_RIGHT 'R'
#define TURN_LEFT 'L'
#define MOVE_FORWARD 'F'
#define MOVE_BACK 'B'

typedef struct {
    float x;
    float y;
    float z;
} Coords;

typedef struct {
    int pitch;
    int roll;
    int yaw;
} Angles;

typedef struct {
    Coords position;
    Angles orientation;
    bool isFlying;
} Drone;

Drone initDrone() {
    Drone drone = {
        .position = {0, 0, 0},
        .orientation = {0, 0, 0},
        .isFlying = false
    };
    return drone;
}

void printCoords(Coords coords) {
    printf("(%.2f, %.2f, %.2f)\n", coords.x, coords.y, coords.z);
}

void printAngles(Angles angles) {
    printf("(%d, %d, %d)\n", angles.pitch, angles.roll, angles.yaw);
}

void printDroneInfo(Drone drone) {
    printf("Drone Info:\n  Position: ");
    printCoords(drone.position);
    printf("  Orientation: ");
    printAngles(drone.orientation);
    printf("  Is Flying: %s\n", drone.isFlying ? "Yes" : "No");
}

void turnDroneRight(Drone *drone) {
    drone->orientation.yaw += 10;
}

void turnDroneLeft(Drone *drone) {
    drone->orientation.yaw -= 10;
}

void moveDroneForward(Drone *drone) {
    drone->position.z += 2;
}

void moveDroneBack(Drone *drone) {
    drone->position.z -= 2;
}

void handleInput(char input, Drone *drone) {
    switch (input) {
        case TURN_RIGHT:
            turnDroneRight(drone);
            break;
        case TURN_LEFT:
            turnDroneLeft(drone);
            break;
        case MOVE_FORWARD:
            moveDroneForward(drone);
            break;
        case MOVE_BACK:
            moveDroneBack(drone);
            break;
        default:
            printf("Invalid input '%c'\n", input);
    }
}

void runDroneRemoteControl() {
    Drone drone = initDrone();
    char input;
    
    printf("Starting drone...\n");
    
    do {
        printDroneInfo(drone);
        printf("Enter command: ");
        scanf(" %c", &input);
        handleInput(input, &drone);
        system("clear");
    } while (input != 'q');
    
    printf("Stopping drone...\n");
}

int main() {
    runDroneRemoteControl();
    return 0;
}