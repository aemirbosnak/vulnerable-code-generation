//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Constants for remote control commands
#define UP 'u'
#define DOWN 'd'
#define LEFT 'l'
#define RIGHT 'r'
#define TAKEOFF 't'
#define LAND 'a'
#define EMERGENCY 'e'

// Constants for drone movement
#define HEIGHT_INCREMENT 10
#define ANGLE_INCREMENT 5
#define MAX_HEIGHT 100
#define MAX_ANGLE 360

// Function prototypes
void moveUp(int *currentHeight);
void moveDown(int *currentHeight);
void turnLeft(int *currentAngle);
void turnRight(int *currentAngle);

int main()
{
    int currentHeight = 0;
    int currentAngle = 0;
    char command;

    printf("DRONE REMOTE CONTROL\n");
    printf("---------------------\n");
    printf("Use the following commands to control the drone:\n");
    printf("\t- 'u' to move up\n");
    printf("\t- 'd' to move down\n");
    printf("\t- 'l' to turn left\n");
    printf("\t- 'r' to turn right\n");
    printf("\t- 't' to take off\n");
    printf("\t- 'a' to land\n");
    printf("\t- 'e' for emergency stop\n");

    while(1) {
        printf("Enter command: ");
        scanf(" %c", &command);

        switch(command) {
            case UP:
                moveUp(&currentHeight);
                break;
            case DOWN:
                moveDown(&currentHeight);
                break;
            case LEFT:
                turnLeft(&currentAngle);
                break;
            case RIGHT:
                turnRight(&currentAngle);
                break;
            case TAKEOFF:
                printf("Taking off...\n");
                currentHeight = HEIGHT_INCREMENT;
                break;
            case LAND:
                printf("Landing...\n");
                currentHeight = 0;
                break;
            case EMERGENCY:
                printf("Emergency stop!\n");
                exit(0);
            default:
                printf("Invalid command. Try again.\n");
                break;
        }

        printf("Current height: %d\n", currentHeight);
        printf("Current angle: %d\n", currentAngle);
    }

    return 0;
}

void moveUp(int *currentHeight) {
    if((*currentHeight) + HEIGHT_INCREMENT <= MAX_HEIGHT) {
        (*currentHeight) += HEIGHT_INCREMENT;
        printf("Moving up...\n");
    } else {
        printf("Cannot move up, maximum height reached.\n");
    }
}

void moveDown(int *currentHeight) {
    if((*currentHeight) - HEIGHT_INCREMENT >= 0) {
        (*currentHeight) -= HEIGHT_INCREMENT;
        printf("Moving down...\n");
    } else {
        printf("Cannot move down, already at ground level.\n");
    }
}

void turnLeft(int *currentAngle) {
    (*currentAngle) -= ANGLE_INCREMENT;
    if((*currentAngle) < 0) {
        (*currentAngle) += MAX_ANGLE;
    }
    printf("Turning left...\n");
}

void turnRight(int *currentAngle) {
    (*currentAngle) += ANGLE_INCREMENT;
    if((*currentAngle) >= MAX_ANGLE) {
        (*currentAngle) -= MAX_ANGLE;
    }
    printf("Turning right...\n");
}