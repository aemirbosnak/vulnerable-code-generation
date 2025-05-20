//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define GRID_SIZE 10

typedef enum {
    NORTH,
    EAST,
    SOUTH,
    WEST
} Direction;

typedef struct {
    int x;
    int y;
    Direction direction;
} Robot;

void printGrid(Robot *robot) {
    system("clear");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (robot->x == i && robot->y == j) {
                printf("R ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

void moveForward(Robot *robot) {
    switch (robot->direction) {
        case NORTH:
            if (robot->x > 0) robot->x--;
            break;
        case SOUTH:
            if (robot->x < GRID_SIZE - 1) robot->x++;
            break;
        case EAST:
            if (robot->y < GRID_SIZE - 1) robot->y++;
            break;
        case WEST:
            if (robot->y > 0) robot->y--;
            break;
    }
}

void turnLeft(Robot *robot) {
    robot->direction = (robot->direction + 3) % 4;  // Turn left
}

void turnRight(Robot *robot) {
    robot->direction = (robot->direction + 1) % 4;  // Turn right
}

void displayMenu() {
    printf("Robot Movement Control:\n");
    printf("1. Move Forward\n");
    printf("2. Turn Left\n");
    printf("3. Turn Right\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Robot robot = { .x = 0, .y = 0, .direction = EAST };  // Start at (0,0) facing east
    int choice = 0;

    while (choice != 4) {
        printGrid(&robot);
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                moveForward(&robot);
                break;
            case 2:
                turnLeft(&robot);
                break;
            case 3:
                turnRight(&robot);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
        usleep(500000);  // Sleep for half a second for better visualization
    }

    return 0;
}