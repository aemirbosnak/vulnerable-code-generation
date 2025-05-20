//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define GRID_SIZE 10
#define INITIAL_X 0
#define INITIAL_Y 0

typedef struct {
    int x;
    int y;
} Robot;

void initializeRobot(Robot *robot) {
    robot->x = INITIAL_X;
    robot->y = INITIAL_Y;
}

void printGrid(Robot *robot) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == robot->y && j == robot->x) {
                printf("[R] ");
            } else {
                printf("[ ] ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void moveUp(Robot *robot) {
    if (robot->y > 0) {
        robot->y--;
    }
}

void moveDown(Robot *robot) {
    if (robot->y < GRID_SIZE - 1) {
        robot->y++;
    }
}

void moveLeft(Robot *robot) {
    if (robot->x > 0) {
        robot->x--;
    }
}

void moveRight(Robot *robot) {
    if (robot->x < GRID_SIZE - 1) {
        robot->x++;
    }
}

void displayCommands() {
    printf("Commands:\n");
    printf("1: Move Up\n");
    printf("2: Move Down\n");
    printf("3: Move Left\n");
    printf("4: Move Right\n");
    printf("5: Show Position\n");
    printf("0: Exit\n");
}

int main() {
    Robot robot;
    initializeRobot(&robot);
    int command;

    printf("Welcome to the Robot Movement Control Program!\n");

    while (1) {
        printGrid(&robot);
        displayCommands();
        printf("Enter command: ");
        scanf("%d", &command);

        switch (command) {
            case 1:
                moveUp(&robot);
                break;
            case 2:
                moveDown(&robot);
                break;
            case 3:
                moveLeft(&robot);
                break;
            case 4:
                moveRight(&robot);
                break;
            case 5:
                printf("Robot Position: (X: %d, Y: %d)\n", robot.x, robot.y);
                break;
            case 0:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid command. Please try again.\n");
        }
        usleep(500000); // wait for half a second for better visibility of grid
    }

    return 0;
}