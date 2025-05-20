//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
    int x;
    int y;
} Robot;

void displayPosition(Robot *robot) {
    printf("Robot is at position (%d, %d)\n", robot->x, robot->y);
}

void moveForward(Robot *robot) {
    robot->y += 1;
    printf("Robot moves forward!\n");
}

void moveBackward(Robot *robot) {
    robot->y -= 1;
    printf("Robot moves backward!\n");
}

void moveLeft(Robot *robot) {
    robot->x -= 1;
    printf("Robot moves left!\n");
}

void moveRight(Robot *robot) {
    robot->x += 1;
    printf("Robot moves right!\n");
}

void showInstructions() {
    printf("Welcome to the Robot Movement Control Program!\n");
    printf("Use the following commands to control your robot:\n");
    printf("  w : Move Forward\n");
    printf("  s : Move Backward\n");
    printf("  a : Move Left\n");
    printf("  d : Move Right\n");
    printf("  q : Quit the simulation\n");
}

char getInput() {
    char input;
    printf("Enter your command: ");
    scanf(" %c", &input);
    return input;
}

int main() {
    Robot robot = {0, 0}; // Starting position
    char command;

    showInstructions();
    
    while (1) {
        displayPosition(&robot);
        command = getInput();

        if (command == 'w') {
            moveForward(&robot);
        } else if (command == 's') {
            moveBackward(&robot);
        } else if (command == 'a') {
            moveLeft(&robot);
        } else if (command == 'd') {
            moveRight(&robot);
        } else if (command == 'q') {
            printf("Quitting the simulation. Goodbye!\n");
            break;
        } else {
            printf("Invalid command, please try again!\n");
        }

        usleep(500000); // Sleep for half a second
    }

    return 0;
}