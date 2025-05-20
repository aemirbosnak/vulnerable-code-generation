//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRID_SIZE 5

typedef struct {
    int x;
    int y;
} Robot;

void initializeRobot(Robot* robot) {
    robot->x = 0;
    robot->y = 0;
}

void printPosition(Robot* robot) {
    printf("Robot is at position (%d, %d)\n", robot->x, robot->y);
}

void moveUp(Robot* robot) {
    if (robot->y < GRID_SIZE - 1) {
        robot->y++;
        printf("Moved up!\n");
    } else {
        printf("Can't move up. Reached the top border!\n");
    }
}

void moveDown(Robot* robot) {
    if (robot->y > 0) {
        robot->y--;
        printf("Moved down!\n");
    } else {
        printf("Can't move down. Reached the bottom border!\n");
    }
}

void moveLeft(Robot* robot) {
    if (robot->x > 0) {
        robot->x--;
        printf("Moved left!\n");
    } else {
        printf("Can't move left. Reached the left border!\n");
    }
}

void moveRight(Robot* robot) {
    if (robot->x < GRID_SIZE - 1) {
        robot->x++;
        printf("Moved right!\n");
    } else {
        printf("Can't move right. Reached the right border!\n");
    }
}

void showMenu() {
    printf("Commands:\n");
    printf("1. Up\n");
    printf("2. Down\n");
    printf("3. Left\n");
    printf("4. Right\n");
    printf("5. Stop\n");
    printf("Enter your command (1-5): ");
}

int main() {
    Robot robot;
    int command;

    initializeRobot(&robot);
    printPosition(&robot);

    while (1) {
        showMenu();
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
                printf("Stopping robot. Final position: ");
                printPosition(&robot);
                return 0;
            default:
                printf("Invalid command. Please enter a number between 1 and 5.\n");
        }
        printPosition(&robot);
    }

    return 0;
}