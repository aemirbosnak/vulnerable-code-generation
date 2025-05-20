//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPEED 100
#define MAX_TURN 30

typedef struct {
    int x;
    int y;
} position;

typedef struct {
    int speed;
    int direction;
} movement;

position currentPosition;
movement currentMovement;

void initializeVehicle() {
    // Set starting position to (0, 0)
    currentPosition.x = 0;
    currentPosition.y = 0;

    // Set initial speed to 0 and direction to north
    currentMovement.speed = 0;
    currentMovement.direction = 0;
}

void accelerate(int speed) {
    if (currentMovement.speed + speed > MAX_SPEED) {
        currentMovement.speed = MAX_SPEED;
    } else {
        currentMovement.speed += speed;
    }
}

void turn(int degrees) {
    if (currentMovement.direction + degrees > 360) {
        currentMovement.direction = currentMovement.direction + degrees - 360;
    } else if (currentMovement.direction + degrees < 0) {
        currentMovement.direction = currentMovement.direction + degrees + 360;
    } else {
        currentMovement.direction += degrees;
    }
}

void move() {
    float radians = currentMovement.direction * (3.14159 / 180);

    int dx = currentMovement.speed * cos(radians);
    int dy = currentMovement.speed * sin(radians);

    currentPosition.x += dx;
    currentPosition.y += dy;
}

void printPosition() {
    printf("Current position: (%d, %d)\n", currentPosition.x, currentPosition.y);
}

int main() {
    printf("Welcome to the Remote Control Vehicle Simulation.\n");
    printf("You can accelerate the vehicle by giving a speed value between 0 and 100.\n");
    printf("You can turn the vehicle by giving a degrees value between -30 and 30.\n");
    printf("Enjoy the ride!\n");

    initializeVehicle();

    // Keep asking for commands until user inputs 'exit'
    char input[100];
    while (1) {
        printf("Enter a command (accelerate X, turn X, exit): ");
        scanf("%[^\n]", input);

        char command[100];
        int value;

        sscanf(input, "%s %d", command, &value);

        if (strcmp(command, "exit") == 0) {
            printf("Exiting...\n");
            break;
        } else if (strcmp(command, "accelerate") == 0) {
            if (value >= 0 && value <= 100) {
                accelerate(value);
                printf("Accelerating to speed %d...\n", currentMovement.speed);
            } else {
                printf("Invalid speed value. Please enter a value between 0 and 100.\n");
            }
        } else if (strcmp(command, "turn") == 0) {
            if (value >= -30 && value <= 30) {
                turn(value);
                printf("Turning to %d degrees...\n", currentMovement.direction);
            } else {
                printf("Invalid degrees value. Please enter a value between -30 and 30.\n");
            }
        } else {
            printf("Invalid command. Please enter a valid command.\n");
        }

        // Clear input buffer
        getchar();
    }

    return 0;
}