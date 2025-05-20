//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Create a struct to hold the current state of the vehicle
struct VehicleState {
    bool isMovingForward;
    bool isMovingBackward;
    int speed;
    int direction;
};

// Function to handle moving the vehicle forward
void moveForward(struct VehicleState *state) {
    state->isMovingForward = true;
    state->isMovingBackward = false;
    printf("Vehicle moving forward at %d speed\n", state->speed);
}

// Function to handle moving the vehicle backward
void moveBackward(struct VehicleState *state) {
    state->isMovingBackward = true;
    state->isMovingForward = false;
    printf("Vehicle moving backward at %d speed\n", state->speed);
}

// Function to handle stopping the vehicle
void stop(struct VehicleState *state) {
    state->isMovingForward = false;
    state->isMovingBackward = false;
    state->speed = 0;
    printf("Vehicle has stopped\n");
}

// Function to change the speed of the vehicle
void setSpeed(struct VehicleState *state, int speed) {
    state->speed = speed;
    printf("Vehicle speed set to %d\n", speed);
}

// Function to change the direction of the vehicle
void setDirection(struct VehicleState *state, int direction) {
    state->direction = direction;
    printf("Vehicle direction set to %d degrees\n", direction);
}

int main() {
    struct VehicleState state = {false, false, 0, 0};

    printf("Welcome to the RC vehicle simulator!\n");

    while (true) {
        int userInput;

        printf("\nWhat would you like to do?\n");
        printf("1: Move forward\n");
        printf("2: Move backward\n");
        printf("3: Stop\n");
        printf("4: Set speed\n");
        printf("5: Set direction\n");
        printf("6: Exit\n");

        scanf("%d", &userInput);

        if (userInput == 1) {
            moveForward(&state);
        } else if (userInput == 2) {
            moveBackward(&state);
        } else if (userInput == 3) {
            stop(&state);
        } else if (userInput == 4) {
            int speedInput;
            printf("Enter speed (0-100): ");
            scanf("%d", &speedInput);
            if (speedInput < 0 || speedInput > 100) {
                printf("Invalid speed entered\n");
            } else {
                setSpeed(&state, speedInput);
            }
        } else if (userInput == 5) {
            int directionInput;
            printf("Enter direction (0-360): ");
            scanf("%d", &directionInput);
            if (directionInput < 0 || directionInput > 360) {
                printf("Invalid direction entered\n");
            } else {
                setDirection(&state, directionInput);
            }
        } else if (userInput == 6) {
            printf("Exiting program\n");
            break;
        } else {
            printf("Invalid input\n");
        }
    }

    return 0;
}