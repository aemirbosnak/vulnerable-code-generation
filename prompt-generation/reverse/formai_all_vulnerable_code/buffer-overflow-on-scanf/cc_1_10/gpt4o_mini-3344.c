//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function prototypes
void initializeRobot();
void moveForward(int distance);
void moveBackward(int distance);
void turnLeft(int degrees);
void turnRight(int degrees);
void stopRobot();
void displayMenu();
int getUserInput();

int main() {
    initializeRobot();

    while (1) {
        displayMenu();
        int choice = getUserInput();

        switch (choice) {
            case 1:
                moveForward(10);
                break;
            case 2:
                moveBackward(10);
                break;
            case 3:
                turnLeft(90);
                break;
            case 4:
                turnRight(90);
                break;
            case 5:
                stopRobot();
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
        sleep(2); // Delay for 2 seconds between commands
    }
    return 0;
}

void initializeRobot() {
    printf("Robot initializing...\n");
    // Insert robot initialization routines here
    sleep(1);
    printf("Robot is ready for commands.\n");
}

void moveForward(int distance) {
    printf("Moving forward %d units.\n", distance);
    // Insert code to control motors to move forward
    sleep(1); // Simulate time taken to move
}

void moveBackward(int distance) {
    printf("Moving backward %d units.\n", distance);
    // Insert code to control motors to move backward
    sleep(1); // Simulate time taken to move
}

void turnLeft(int degrees) {
    printf("Turning left %d degrees.\n", degrees);
    // Insert code to control motors to turn left
    sleep(1); // Simulate time taken to turn
}

void turnRight(int degrees) {
    printf("Turning right %d degrees.\n", degrees);
    // Insert code to control motors to turn right
    sleep(1); // Simulate time taken to turn
}

void stopRobot() {
    printf("Stopping robot.\n");
    // Insert code to stop all motors
    sleep(1);
}

void displayMenu() {
    printf("\n--- Robot Control Menu ---\n");
    printf("1. Move Forward\n");
    printf("2. Move Backward\n");
    printf("3. Turn Left\n");
    printf("4. Turn Right\n");
    printf("5. Stop\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int getUserInput() {
    int choice;
    scanf("%d", &choice);
    return choice;
}