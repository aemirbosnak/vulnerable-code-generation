//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: synchronous
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CMD_LENGTH 20
#define MAX_DRONE_SPEED 100
#define MAX_DRONE_HEIGHT 500
#define MIN_DRONE_HEIGHT 10
#define MAX_BATTERY 100

int droneSpeed;
int droneHeight;
int batteryLife;
bool isFlying = false;

void takeOff() {
    if (!isFlying) {
        if (batteryLife > 0) {
            srand(time(NULL));
            droneSpeed = rand() % MAX_DRONE_SPEED + 1;
            droneHeight = rand() % (MAX_DRONE_HEIGHT - MIN_DRONE_HEIGHT) + MIN_DRONE_HEIGHT;
            printf("Drone has taken off!\n");
            printf("Speed: %d\nHeight: %d\n", droneSpeed, droneHeight);
            isFlying = true;
            batteryLife -= rand() % 10 + 1; // decrement battery randomly between 1-10%
        }
        else {
            printf("Battery life is too low to take off.\n");
        }
    }
    else {
        printf("Drone is already flying!\n");
    }
}

void land() {
    if (isFlying) {
        srand(time(NULL));
        int landingSpeed = rand() % MAX_DRONE_SPEED + 1;
        printf("Landing the drone at a speed of %d mph.\n", landingSpeed);
        isFlying = false;
        batteryLife -= rand() % 10 + 1; // decrement battery randomly between 1-10%
    }
    else {
        printf("Drone is not flying!\n");
    }
}

void flyUp(int height) {
    if (isFlying) {
        if (droneHeight + height <= MAX_DRONE_HEIGHT) {
            droneHeight += height;
            printf("Drone height is now: %d\n", droneHeight);
        }
        else {
            printf("Cannot fly higher than maximum height.\n");
        }
        batteryLife -= rand() % 5 + 1; // decrement battery randomly between 1-5%
    }
    else {
        printf("Drone is not flying!\n");
    }
}

void flyDown(int height) {
    if (isFlying) {
        if (droneHeight - height >= MIN_DRONE_HEIGHT) {
            droneHeight -= height;
            printf("Drone height is now: %d\n", droneHeight);
        }
        else {
            printf("Cannot fly lower than minimum height.\n");
        }
        batteryLife -= rand() % 5 + 1; // decrement battery randomly between 1-5%
    }
    else {
        printf("Drone is not flying!\n");
    }
}

void moveForward(int distance) {
    if (isFlying) {
        printf("Drone has moved forward by %d meters.\n", distance);
        batteryLife -= rand() % 5 + 1; // decrement battery randomly between 1-5%
    }
    else {
        printf("Drone is not flying!\n");
    }
}

void moveBackward(int distance) {
    if (isFlying) {
        printf("Drone has moved backward by %d meters.\n", distance);
        batteryLife -= rand() % 5 + 1; // decrement battery randomly between 1-5%
    }
    else {
        printf("Drone is not flying!\n");
    }
}

void printInstructions() {
    printf("Welcome to C Drone Remote Control\n\n");
    printf("Commands:\n");
    printf("'takeoff': take off the drone\n");
    printf("'land': land the drone\n");
    printf("'up <height>': fly the drone up by specified height in meters\n");
    printf("'down <height>': fly the drone down by specified height in meters\n");
    printf("'forward <distance>': move the drone forward by specified distance in meters\n");
    printf("'backward <distance>': move the drone backward by specified distance in meters\n");
    printf("'battery': check battery life\n");
    printf("'exit': exit the program\n\n");
}

int main() {
    bool isRunning = true;
    char input[MAX_CMD_LENGTH];
    printInstructions();
    batteryLife = MAX_BATTERY;
    while (isRunning) {
        printf("Enter command: ");
        fgets(input, MAX_CMD_LENGTH, stdin);
        sscanf(input, "%s", input);
        if (strcmp(input, "takeoff") == 0) {
            takeOff();
        }
        else if (strcmp(input, "land") == 0) {
            land();
        }
        else if (strcmp(input, "up") == 0) {
            int height;
            sscanf(input, "%*s %d", &height);
            flyUp(height);
        }
        else if (strcmp(input, "down") == 0) {
            int height;
            sscanf(input, "%*s %d", &height);
            flyDown(height);
        }
        else if (strcmp(input, "forward") == 0) {
            int distance;
            sscanf(input, "%*s %d", &distance);
            moveForward(distance);
        }
        else if (strcmp(input, "backward") == 0) {
            int distance;
            sscanf(input, "%*s %d", &distance);
            moveBackward(distance);
        }
        else if (strcmp(input, "battery") == 0) {
            printf("Battery life: %d%%\n", batteryLife);
        }
        else if (strcmp(input, "exit") == 0) {
            printf("Exiting program...\n");
            isRunning = false;
        }
        else {
            printf("Invalid command. Please try again.\n");
        }
        if (batteryLife <= 0) {
            printf("Drone out of battery. Landing automatically...\n");
            land();
            isRunning = false;
        }
    }
    return 0;
}