//FormAI DATASET v1.0 Category: Robot movement control ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This program controls the movement of a C Robot. The robot has a mind-bending ability to move in 
 * four directions - North, South, East and West. The program communicates with the Robot using four 
 * commands - "N", "S", "E", and "W", which stands for North, South, East, and West respectively.
 *
 * The Robot is represented by a two-dimensional grid system, with (0, 0) being the bottom left 
 * corner of the grid, and (N, N) being the upper right corner, where N is the size of the grid. 
 * Initially, the Robot is at (0, 0).
 *
 * The program takes in a series of commands and moves the Robot accordingly. If the Robot reaches 
 * the edge of the grid, it bounces off and moves in the opposite direction. For example, if the Robot 
 * is at (0, 0) and receives the "S" command, it will move to (0, -1) and then bounce off to (0, 1).
 *
 * The program finishes when the "Q" command is received.
 */

// Define Robot structure
typedef struct {
    int x; // current x coordinate 
    int y; // current y coordinate
    int size; // size of the grid
    char direction; // current direction of the Robot
} Robot;

// Function to display the current status of the Robot.
void displayStatus(Robot* robot) {
    printf("Current position: (%d, %d). Direction: %c\n", robot->x, robot->y, robot->direction);
}

// Function to move the Robot North.
void moveNorth(Robot* robot) {
    robot->y++;
    if (robot->y > robot->size) {
        robot->y = robot->size - 1;
        robot->direction = 'S';
        printf("Bounced off North wall! Switched direction to South.\n");
    } else {
        printf("Moved North.\n");
    }
}

// Function to move the Robot South.
void moveSouth(Robot* robot) {
    robot->y--;
    if (robot->y < 0) {
        robot->y = 0;
        robot->direction = 'N';
        printf("Bounced off South wall! Switched direction to North.\n");
    } else {
        printf("Moved South.\n");
    }
}

// Function to move the Robot East.
void moveEast(Robot* robot) {
    robot->x++;
    if (robot->x > robot->size) {
        robot->x = robot->size - 1;
        robot->direction = 'W';
        printf("Bounced off East wall! Switched direction to West.\n");
    } else {
        printf("Moved East.\n");
    }
}

// Function to move the Robot West.
void moveWest(Robot* robot) {
    robot->x--;
    if (robot->x < 0) {
        robot->x = 0;
        robot->direction = 'E';
        printf("Bounced off West wall! Switched direction to East.\n");
    } else {
        printf("Moved West.\n");
    }
}

int main() {
    Robot robot;
    char command[2];

    printf("=================\n");
    printf("= C ROBOT MOVES =\n");
    printf("=================\n\n");

    do {
        displayStatus(&robot);
        printf("Enter command (N/S/E/W or Q to quit): ");
        scanf("%s", command);

        if (strcmp(command, "N") == 0) {
            moveNorth(&robot);
        } else if (strcmp(command, "S") == 0) {
            moveSouth(&robot);
        } else if (strcmp(command, "E") == 0) {
            moveEast(&robot);
        } else if (strcmp(command, "W") == 0) {
            moveWest(&robot);
        } else if (strcmp(command, "Q") == 0) {
            printf("Goodbye!");
            break;
        } else {
            printf("Unknown command. Please enter N/S/E/W or Q.\n");
        }
        printf("\n");
    } while (1);

    return 0;
}