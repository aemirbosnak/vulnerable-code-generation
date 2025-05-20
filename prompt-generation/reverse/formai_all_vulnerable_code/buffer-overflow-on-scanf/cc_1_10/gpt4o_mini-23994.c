//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 10

typedef enum { NORTH, SOUTH, EAST, WEST } Direction;

typedef struct {
    int x;
    int y;
    Direction direction;
} Robot;

void initializeRobot(Robot *r) {
    r->x = GRID_SIZE / 2;
    r->y = GRID_SIZE / 2;
    r->direction = NORTH;
}

void printPosition(Robot *r) {
    printf("Robot is currently at (%d, %d) facing ", r->x, r->y);
    switch (r->direction) {
        case NORTH: printf("NORTH\n"); break;
        case SOUTH: printf("SOUTH\n"); break;
        case EAST: printf("EAST\n"); break;
        case WEST: printf("WEST\n"); break;
    }
}

void moveForward(Robot *r, int steps) {
    printf("Moving forward %d steps!\n", steps);
    for (int i = 0; i < steps; i++) {
        switch (r->direction) {
            case NORTH: if (r->y < GRID_SIZE - 1) r->y++; break;
            case SOUTH: if (r->y > 0) r->y--; break;
            case EAST: if (r->x < GRID_SIZE - 1) r->x++; break;
            case WEST: if (r->x > 0) r->x--; break;
        }
        printPosition(r);
    }
}

void turnLeft(Robot *r) {
    printf("Turning left!\n");
    r->direction = (r->direction + 3) % 4; // Turn left (3 mod operations)
    printPosition(r);
}

void turnRight(Robot *r) {
    printf("Turning right!\n");
    r->direction = (r->direction + 1) % 4; // Turn right (1 mod operation)
    printPosition(r);
}

void showMenu() {
    printf("-------- Robot Control Menu --------\n");
    printf("1. Move Forward\n");
    printf("2. Turn Left\n");
    printf("3. Turn Right\n");
    printf("4. Exit\n");
    printf("------------------------------------\n");
}

int main() {
    Robot robot;
    int choice, steps;

    initializeRobot(&robot);
    printf("Welcome to the Robot Movement Simulator!\n");
    printPosition(&robot);

    while (1) {
        showMenu();
        printf("Choose an action: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("How many steps would you like to move forward? ");
                scanf("%d", &steps);
                moveForward(&robot, steps);
                break;
            case 2:
                turnLeft(&robot);
                break;
            case 3:
                turnRight(&robot);
                break;
            case 4:
                printf("Exiting the simulator! Have a great day!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }

    return 0;
}