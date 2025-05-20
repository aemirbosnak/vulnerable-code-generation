//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 5

// Define the robot states
typedef enum { NORTH, EAST, SOUTH, WEST } Direction;

// Structure to hold robot information
typedef struct {
    int x;
    int y;
    Direction dir;
} Robot;

// Function declarations
void init_robot(Robot *robot);
void display_grid(Robot robot);
void move_forward(Robot *robot);
void turn_left(Robot *robot);
void turn_right(Robot *robot);
void execute_command(Robot *robot, char command);

int main() {
    Robot robot;
    char command;

    init_robot(&robot);

    while (1) {
        display_grid(robot);
        printf("Enter command (w: forward, a: turn left, d: turn right, q: quit): ");
        scanf(" %c", &command);

        if (command == 'q') {
            printf("Goodbye!\n");
            break;
        }

        execute_command(&robot, command);
    }

    return 0;
}

void init_robot(Robot *robot) {
    robot->x = GRID_SIZE / 2; // Start in the middle of the grid
    robot->y = GRID_SIZE / 2;
    robot->dir = NORTH;  // Initially facing north
}

void display_grid(Robot robot) {
    system("clear"); // Clear the terminal
    printf("Grid size: %dx%d\n", GRID_SIZE, GRID_SIZE);
    for (int y = GRID_SIZE - 1; y >= 0; y--) {
        for (int x = 0; x < GRID_SIZE; x++) {
            if (robot.x == x && robot.y == y) {
                switch (robot.dir) {
                    case NORTH: printf(" ^ "); break;
                    case EAST:  printf(" > "); break;
                    case SOUTH: printf(" v "); break;
                    case WEST:  printf(" < "); break;
                }
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

void move_forward(Robot *robot) {
    switch (robot->dir) {
        case NORTH:
            if (robot->y < GRID_SIZE - 1) robot->y++;
            break;
        case EAST:
            if (robot->x < GRID_SIZE - 1) robot->x++;
            break;
        case SOUTH:
            if (robot->y > 0) robot->y--;
            break;
        case WEST:
            if (robot->x > 0) robot->x--;
            break;
    }
}

void turn_left(Robot *robot) {
    robot->dir = (robot->dir + 3) % 4; // Turn left (90 degrees counter-clockwise)
}

void turn_right(Robot *robot) {
    robot->dir = (robot->dir + 1) % 4; // Turn right (90 degrees clockwise)
}

void execute_command(Robot *robot, char command) {
    switch (command) {
        case 'w':
            move_forward(robot);
            break;
        case 'a':
            turn_left(robot);
            break;
        case 'd':
            turn_right(robot);
            break;
        default:
            printf("Unknown command!\n");
    }
}