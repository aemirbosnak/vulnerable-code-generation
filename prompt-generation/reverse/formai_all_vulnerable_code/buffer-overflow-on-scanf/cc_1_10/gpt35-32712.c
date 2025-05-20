//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_COMMAND_LENGTH 20

// Define global variables
int batteryLevel = 100;
int altitude = 0;
int distanceFromOrigin = 0;
int xPosition = 0;
int yPosition = 0;

// Function prototypes
void printDroneStatus();
void moveForward(int distance);
void moveBackward(int distance);
void moveLeft(int distance);
void moveRight(int distance);
void increaseAltitude(int amount);
void decreaseAltitude(int amount);
void recharge();

int main() {
    char command[MAX_COMMAND_LENGTH];
    printf("Welcome to the C Drone Remote Control Program!\n");

    while(1) {
        printf("Enter a command: ");
        scanf("%s", command);

        if(strcmp(command, "status") == 0) {
            printDroneStatus();
        } else if(strcmp(command, "forward") == 0) {
            int distance;
            printf("Enter distance in meters: ");
            scanf("%d", &distance);
            moveForward(distance);
        } else if(strcmp(command, "backward") == 0) {
            int distance;
            printf("Enter distance in meters: ");
            scanf("%d", &distance);
            moveBackward(distance);
        } else if(strcmp(command, "left") == 0) {
            int distance;
            printf("Enter distance in meters: ");
            scanf("%d", &distance);
            moveLeft(distance);
        } else if(strcmp(command, "right") == 0) {
            int distance;
            printf("Enter distance in meters: ");
            scanf("%d", &distance);
            moveRight(distance);
        } else if(strcmp(command, "up") == 0) {
            int amount;
            printf("Enter altitude in meters: ");
            scanf("%d", &amount);
            increaseAltitude(amount);
        } else if(strcmp(command, "down") == 0) {
            int amount;
            printf("Enter altitude in meters: ");
            scanf("%d", &amount);
            decreaseAltitude(amount);
        } else if(strcmp(command, "recharge") == 0) {
            recharge();
        } else {
            printf("Invalid command!\n");
        }
    }

    return 0;
}

void printDroneStatus() {
    printf("Battery Level: %d%%\n", batteryLevel);
    printf("Altitude: %d meters\n", altitude);
    printf("Distance from Origin: %d meters\n", distanceFromOrigin);
    printf("Current Position: (%d, %d)\n", xPosition, yPosition);
}

void moveForward(int distance) {
    if(batteryLevel < 20) {
        printf("Not enough battery to move forward!\n");
        return;
    }

    double angle = atan2(yPosition, xPosition);
    xPosition += distance * cos(angle);
    yPosition += distance * sin(angle);
    distanceFromOrigin = sqrt(xPosition * xPosition + yPosition * yPosition);
    batteryLevel -= (distance/10);
    printf("Moved forward %d meters!\n", distance);
}

void moveBackward(int distance) {
    if(batteryLevel < 20) {
        printf("Not enough battery to move backward!\n");
        return;
    }

    double angle = atan2(yPosition, xPosition);
    xPosition -= distance * cos(angle);
    yPosition -= distance * sin(angle);
    distanceFromOrigin = sqrt(xPosition * xPosition + yPosition * yPosition);
    batteryLevel -= (distance/10);
    printf("Moved backward %d meters!\n", distance);
}

void moveLeft(int distance) {
    if(batteryLevel < 20) {
        printf("Not enough battery to move left!\n");
        return;
    }

    double angle = atan2(yPosition, xPosition) + (M_PI / 2);
    xPosition -= distance * cos(angle);
    yPosition -= distance * sin(angle);
    distanceFromOrigin = sqrt(xPosition * xPosition + yPosition * yPosition);
    batteryLevel -= (distance/10);
    printf("Moved left %d meters!\n", distance);
}

void moveRight(int distance) {
    if(batteryLevel < 20) {
        printf("Not enough battery to move right!\n");
        return;
    }

    double angle = atan2(yPosition, xPosition) - (M_PI / 2);
    xPosition += distance * cos(angle);
    yPosition += distance * sin(angle);
    distanceFromOrigin = sqrt(xPosition * xPosition + yPosition * yPosition);
    batteryLevel -= (distance/10);
    printf("Moved right %d meters!\n", distance);
}

void increaseAltitude(int amount) {
    if(batteryLevel < 10) {
        printf("Not enough battery to increase altitude!\n");
        return;
    }

    altitude += amount;
    batteryLevel -= (amount/5);
    printf("Increased altitude by %d meters!\n", amount);
}

void decreaseAltitude(int amount) {
    if(batteryLevel < 10) {
        printf("Not enough battery to decrease altitude!\n");
        return;
    }

    altitude -= amount;
    if(altitude < 0) {
        altitude = 0;
    }
    batteryLevel -= (amount/5);
    printf("Decreased altitude by %d meters!\n", amount);
}

void recharge() {
    batteryLevel = 100;
    printf("Recharged battery!\n");
}