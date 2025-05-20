//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define GRID_SIZE 5

typedef struct {
    int x;
    int y;
} Position;

typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    STOP
} Direction;

// Function prototypes
void initializeRobot(Position* pos);
void displayPosition(const Position* pos);
void moveRobot(Position* pos, Direction dir);
void displayGrid(const Position* pos);

int main() {
    Position robotPos;
    initializeRobot(&robotPos);
    
    char input;
    bool running = true;

    printf("Robot Movement Control - Use arrow commands (w,a,s,d) to move and 'q' to quit.\n");

    while (running) {
        displayGrid(&robotPos);
        printf("Control Robot (w: up, s: down, a: left, d: right, q: quit): ");
        scanf(" %c", &input);

        switch (input) {
            case 'w':
                moveRobot(&robotPos, UP);
                break;
            case 's':
                moveRobot(&robotPos, DOWN);
                break;
            case 'a':
                moveRobot(&robotPos, LEFT);
                break;
            case 'd':
                moveRobot(&robotPos, RIGHT);
                break;
            case 'q':
                running = false;
                break;
            default:
                printf("Invalid command. Please use w, s, a, d or q.\n");
                break;
        }
    }

    printf("Robot has stopped.\n");
    return 0;
}

void initializeRobot(Position* pos) {
    pos->x = 0;
    pos->y = 0;
    printf("Robot initialized at position (0, 0).\n");
}

void displayPosition(const Position* pos) {
    printf("Current position: (%d, %d)\n", pos->x, pos->y);
}

void moveRobot(Position* pos, Direction dir) {
    switch (dir) {
        case UP:
            if (pos->y < GRID_SIZE - 1) {
                pos->y++;
            } else {
                printf("Cannot move up, limit reached.\n");
            }
            break;
        case DOWN:
            if (pos->y > 0) {
                pos->y--;
            } else {
                printf("Cannot move down, limit reached.\n");
            }
            break;
        case LEFT:
            if (pos->x > 0) {
                pos->x--;
            } else {
                printf("Cannot move left, limit reached.\n");
            }
            break;
        case RIGHT:
            if (pos->x < GRID_SIZE - 1) {
                pos->x++;
            } else {
                printf("Cannot move right, limit reached.\n");
            }
            break;
        case STOP:
            printf("Robot stopped.\n");
            break;
    }
    displayPosition(pos);
}

void displayGrid(const Position* pos) {
    printf("\nGrid Layout (%dx%d):\n", GRID_SIZE, GRID_SIZE);
    for (int i = GRID_SIZE - 1; i >= 0; i--) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (pos->x == j && pos->y == i) {
                printf("[R] "); // Robot's position
            } else {
                printf("[ ] ");
            }
        }
        printf("\n");
    }
    printf("\n");
}