//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define GRID_SIZE 10

typedef struct {
    int x;
    int y;
} Position;

typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    STAY
} Direction;

void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '.';
        }
    }
}

void displayGrid(char grid[GRID_SIZE][GRID_SIZE], Position robot) {
    system("clear");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == robot.y && j == robot.x) {
                printf("R ");
            } else {
                printf("%c ", grid[i][j]);
            }
        }
        printf("\n");
    }
}

bool moveRobot(Position *robot, Direction dir) {
    switch (dir) {
        case UP:
            if (robot->y > 0) {
                robot->y--;
                return true;
            }
            break;
        case DOWN:
            if (robot->y < GRID_SIZE - 1) {
                robot->y++;
                return true;
            }
            break;
        case LEFT:
            if (robot->x > 0) {
                robot->x--;
                return true;
            }
            break;
        case RIGHT:
            if (robot->x < GRID_SIZE - 1) {
                robot->x++;
                return true;
            }
            break;
        case STAY:
            return false;
    }
    return false;
}

Direction getInput() {
    char input;
    printf("Enter move (W: Up, S: Down, A: Left, D: Right, Q: Quit): ");
    scanf(" %c", &input);
    switch (input) {
        case 'W': case 'w':
            return UP;
        case 'S': case 's':
            return DOWN;
        case 'A': case 'a':
            return LEFT;
        case 'D': case 'd':
            return RIGHT;
        case 'Q': case 'q':
            return STAY;
        default:
            printf("Invalid input, robot will stay still.\n");
            return STAY;
    }
}

void executeMovements(Position *robot) {
    Direction dir;
    while (true) {
        displayGrid((char[GRID_SIZE][GRID_SIZE]){{'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                                 {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                                 {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                                 {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                                 {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                                 {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                                 {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                                 {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                                 {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                                 {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}}, *robot);
        dir = getInput();
        if (dir == STAY) {
            printf("Exiting the program...\n");
            break;
        }
        moveRobot(robot, dir);
        usleep(500000); // Pause for 0.5 seconds
    }
}

int main() {
    Position robot = {GRID_SIZE / 2, GRID_SIZE / 2}; // Starting position in the center
    printf("Robot Movement Control Program\n");
    printf("Control the robot in a %dx%d grid. Use W, S, A, D to move.\n", GRID_SIZE, GRID_SIZE);
    executeMovements(&robot);
    return 0;
}