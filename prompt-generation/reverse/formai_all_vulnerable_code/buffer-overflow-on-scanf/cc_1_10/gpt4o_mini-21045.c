//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void takeOff() {
    printf("Taking off... 🚀\n");
    sleep(2);
    printf("Drone has ascended! Thank you for trusting me with this flight!\n\n");
}

void land() {
    printf("Landing... 🛬\n");
    sleep(2);
    printf("Drone has landed safely. Grateful for a smooth journey!\n\n");
}

void moveForward() {
    printf("Moving forward... 🏃‍♂️\n");
    sleep(1);
    printf("Drone has moved forward! Thanks for the push in the right direction!\n\n");
}

void moveBackward() {
    printf("Moving backward... 👣\n");
    sleep(1);
    printf("Drone has moved backward! Your guidance is truly appreciated!\n\n");
}

void turnLeft() {
    printf("Turning left... ⬅️\n");
    sleep(1);
    printf("Drone has turned left! Grateful for your precise instructions!\n\n");
}

void turnRight() {
    printf("Turning right... ➡️\n");
    sleep(1);
    printf("Drone has turned right! Thank you for navigating me!\n\n");
}

void showInstructions() {
    printf("Welcome to the Drone Control Program! Here are your commands:\n");
    printf("1: Take Off\n");
    printf("2: Land\n");
    printf("3: Move Forward\n");
    printf("4: Move Backward\n");
    printf("5: Turn Left\n");
    printf("6: Turn Right\n");
    printf("7: Exit Program\n");
    printf("Your drone is ready to fly. Thank you for joining the adventure!\n\n");
}

int main() {
    int command = 0;

    showInstructions();

    while (1) {
        printf("Enter command number: ");
        scanf("%d", &command);

        switch (command) {
            case 1:
                takeOff();
                break;
            case 2:
                land();
                break;
            case 3:
                moveForward();
                break;
            case 4:
                moveBackward();
                break;
            case 5:
                turnLeft();
                break;
            case 6:
                turnRight();
                break;
            case 7:
                printf("Exiting program. Thank you for flying with us today! 🌟\n");
                return 0;
            default:
                printf("Invalid command. Your patience is greatly appreciated!\n\n");
                break;
        }
    }
    return 0;
}