//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMenu();
void takeoff();
void land();
void emergencyStop();
void moveForward();
void moveBackward();
void moveLeft();
void moveRight();
void moveUp();
void moveDown();

int main() {
    printf("Welcome to the Mind-Bending C Drone Remote Control!\n\n");

    char input[50];
    int landed = 1; // 1 means the drone is landed, 0 means it is in the air

    do {
        printMenu(); // print menu options

        printf("Enter your command: ");
        scanf("%s", input);

        // determine what command was entered and call the appropriate function
        if (strcmp(input, "takeoff") == 0) {
            if (landed) {
                takeoff();
                landed = 0;
            } else {
                printf("Error: drone is already in the air.\n");
            }
        } else if (strcmp(input, "land") == 0) {
            if (landed) {
                printf("Error: drone is already landed.\n");
            } else {
                land();
                landed = 1;
            }
        } else if (strcmp(input, "stop") == 0) {
            emergencyStop();
            landed = 1;
        } else if (strcmp(input, "forward") == 0) {
            moveForward();
        } else if (strcmp(input, "backward") == 0) {
            moveBackward();
        } else if (strcmp(input, "left") == 0) {
            moveLeft();
        } else if (strcmp(input, "right") == 0) {
            moveRight();
        } else if (strcmp(input, "up") == 0) {
            moveUp();
        } else if (strcmp(input, "down") == 0) {
            moveDown();
        } else {
            printf("Unknown command.\n");
        }

    } while (strcmp(input, "stop") != 0);

    printf("Exiting drone program.\n");

    return 0;
}

// print menu options
void printMenu() {
    printf("Available Commands:\n");
    printf("takeoff\t\t- lift off from the ground\n");
    printf("land\t\t- return to the ground\n");
    printf("stop\t\t- stop all movement and return to the ground\n");
    printf("forward\t\t- move drone forward\n");
    printf("backward\t- move drone backward\n");
    printf("left\t\t- move drone to the left\n");
    printf("right\t\t- move drone to the right\n");
    printf("up\t\t- move drone up\n");
    printf("down\t\t- move drone down\n");
}

void takeoff() {
    printf("Drone is taking off.\n");
}

void land() {
    printf("Drone is landing.\n");
}

void emergencyStop() {
    printf("Drone emergency stopped.\n");
}

void moveForward() {
    printf("Drone is moving forward.\n");
}

void moveBackward() {
    printf("Drone is moving backward.\n");
}

void moveLeft() {
    printf("Drone is moving left.\n");
}

void moveRight() {
    printf("Drone is moving right.\n");
}

void moveUp() {
    printf("Drone is moving up.\n");
}

void moveDown() {
    printf("Drone is moving down.\n");
}