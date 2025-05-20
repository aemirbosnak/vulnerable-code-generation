//FormAI DATASET v1.0 Category: Robot movement control ; Style: protected
#include <stdio.h>

#define MAX_COMMAND_LENGTH 50
#define SAFE_DISTANCE 10

typedef struct {
    int x;
    int y;
} Position;

typedef enum {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
} Command;

int isSafeDistance(Position position1, Position position2) {
    int xDiff = position1.x - position2.x;
    int yDiff = position1.y - position2.y;
    return (xDiff * xDiff + yDiff * yDiff) >= SAFE_DISTANCE * SAFE_DISTANCE;
}

void moveRobot(Position *currentPositionPtr, Command command) {
    Position tempPosition = *currentPositionPtr;
    switch (command) {
        case FORWARD:
            tempPosition.y++;
            break;
        case BACKWARD:
            tempPosition.y--;
            break;
        case LEFT:
            tempPosition.x--;
            break;
        case RIGHT:
            tempPosition.x++;
            break;
    }
    if (isSafeDistance(*currentPositionPtr, tempPosition)) {
        *currentPositionPtr = tempPosition;
    } else {
        printf("Movement not allowed\n");
    }
}

int main() {
    Position myPosition = {0, 0};
    char commandString[MAX_COMMAND_LENGTH];
    while (1) {
        printf("Enter command: ");
        scanf("%s", commandString);
        if (strcmp(commandString, "FORWARD") == 0) {
            moveRobot(&myPosition, FORWARD);
        } else if (strcmp(commandString, "BACKWARD") == 0) {
            moveRobot(&myPosition, BACKWARD);
        } else if (strcmp(commandString, "LEFT") == 0) {
            moveRobot(&myPosition, LEFT);
        } else if (strcmp(commandString, "RIGHT") == 0) {
            moveRobot(&myPosition, RIGHT);
        } else if (strcmp(commandString, "EXIT") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
        printf("Current position: (%d, %d)\n", myPosition.x, myPosition.y);
    }
    printf("Goodbye!\n");
    return 0;
}