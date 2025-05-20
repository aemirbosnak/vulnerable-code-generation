//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Define the commands for the drone
#define TAKEOFF 1
#define LAND 2
#define FORWARD 3
#define BACKWARD 4
#define LEFT 5
#define RIGHT 6
#define HOVER 7
#define STATUS 8
#define EXIT 9

void displayMenu() {
    printf("Welcome to the Drone Remote Control Interface!\n");
    printf("Please choose an option below:\n");
    printf("1. Take Off\n");
    printf("2. Land\n");
    printf("3. Move Forward\n");
    printf("4. Move Backward\n");
    printf("5. Move Left\n");
    printf("6. Move Right\n");
    printf("7. Hover\n");
    printf("8. Status Report\n");
    printf("9. Exit\n");
}

void takeOff() {
    printf("Drone is taking off... 🚀\n");
    // Simulate some delay
    sleep(2);
    printf("Drone has successfully taken off!\n");
}

void land() {
    printf("Drone is landing... 🛬\n");
    // Simulate some delay
    sleep(2);
    printf("Drone has safely landed!\n");
}

void moveForward() {
    printf("Drone is moving forward... 🛩️\n");
    // Simulate some movement
    sleep(1);
    printf("Drone has moved forward!\n");
}

void moveBackward() {
    printf("Drone is moving backward... 🛩️\n");
    // Simulate some movement
    sleep(1);
    printf("Drone has moved backward!\n");
}

void moveLeft() {
    printf("Drone is moving left... ⬅️\n");
    // Simulate some movement
    sleep(1);
    printf("Drone has moved left!\n");
}

void moveRight() {
    printf("Drone is moving right... ➡️\n");
    // Simulate some movement
    sleep(1);
    printf("Drone has moved right!\n");
}

void hover() {
    printf("Drone is now hovering... 🥳\n");
    // Simulate some hovering
    sleep(3);
    printf("Drone is still hovering!\n");
}

void statusReport() {
    printf("Drone Status Report:\n");
    printf(" - Altitude: 150 meters\n");
    printf(" - Speed: 20 km/h\n");
    printf(" - Battery: 85%%\n");
    printf("All systems are functional! 😊\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case TAKEOFF:
                takeOff();
                break;
            case LAND:
                land();
                break;
            case FORWARD:
                moveForward();
                break;
            case BACKWARD:
                moveBackward();
                break;
            case LEFT:
                moveLeft();
                break;
            case RIGHT:
                moveRight();
                break;
            case HOVER:
                hover();
                break;
            case STATUS:
                statusReport();
                break;
            case EXIT:
                printf("Exiting the Drone Control Program. Thank you! 👋\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }

    return 0;
}