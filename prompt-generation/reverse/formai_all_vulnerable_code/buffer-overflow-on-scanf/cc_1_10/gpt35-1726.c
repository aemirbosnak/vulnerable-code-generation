//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function to print welcome message
void printWelcome() {
    printf("Welcome to the C Drone Remote Control program! Let's fly high!\n");
}

// Function to print main menu
void printMainMenu() {
    printf("Main Menu\n");
    printf("1. Takeoff\n");
    printf("2. Land\n");
    printf("3. Move Forward\n");
    printf("4. Move Backward\n");
    printf("5. Move Left\n");
    printf("6. Move Right\n");
    printf("7. Stop\n");
    printf("8. Exit\n");
}

// Function to move forward
void moveForward() {
    printf("Moving forward...\n");
}

// Function to move backward
void moveBackward() {
    printf("Moving backward...\n");
}

// Function to move left
void moveLeft() {
    printf("Moving left...\n");
}

// Function to move right
void moveRight() {
    printf("Moving right...\n");
}

// Function to stop
void stop() {
    printf("Stopping...\n");
}

// Function to control the drone
void controlDrone() {
    int choice = 0;

    do {
        printMainMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Taking off...\n");
                break;
            case 2:
                printf("Landing...\n");
                break;
            case 3:
                moveForward();
                break;
            case 4:
                moveBackward();
                break;
            case 5:
                moveLeft();
                break;
            case 6:
                moveRight();
                break;
            case 7:
                stop();
                break;
            case 8:
                printf("Goodbye! Have a nice flight!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);
}

// Main function
int main() {
    printWelcome();
    controlDrone();

    return 0;
}