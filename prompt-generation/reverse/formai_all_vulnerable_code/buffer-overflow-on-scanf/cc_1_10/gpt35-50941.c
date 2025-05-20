//FormAI DATASET v1.0 Category: Robot movement control ; Style: accurate
#include <stdio.h>

// Function to move the robot forward
void moveForward(int distance) {
    printf("Moving robot forward for %d units", distance);
}

// Function to move the robot backward
void moveBackward(int distance) {
    printf("Moving robot backward for %d units", distance);
}

// Function to turn the robot left
void moveLeft(int angle) {
    printf("Turning robot left for %d degrees", angle);
}

// Function to turn the robot right
void moveRight(int angle) {
    printf("Turning robot right for %d degrees", angle);
}

int main() {
    int option, distance, angle;

    printf("Welcome to the robot movement control program!\n");

    while (1) {
        printf("\nPlease select the option you want to execute:\n");
        printf("1. Move the robot forward\n");
        printf("2. Move the robot backward\n");
        printf("3. Turn the robot left\n");
        printf("4. Turn the robot right\n");
        printf("5. Exit\n");

        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nEnter the distance you want to move the robot forward: ");
                scanf("%d", &distance);
                moveForward(distance);
                break;
            case 2:
                printf("\nEnter the distance you want to move the robot backward: ");
                scanf("%d", &distance);
                moveBackward(distance);
                break;
            case 3:
                printf("\nEnter the angle you want to turn the robot left: ");
                scanf("%d", &angle);
                moveLeft(angle);
                break;
            case 4:
                printf("\nEnter the angle you want to turn the robot right: ");
                scanf("%d", &angle);
                moveRight(angle);
                break;
            case 5:
                printf("\nExiting program...");
                return 0;
            default:
                printf("\nInvalid option selected!");
        }
    }
}