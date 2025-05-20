//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define GRID_SIZE 5
#define EMPTY '.'
#define OBSTACLE '#'
#define ROBOT 'R'

typedef struct {
    int x;
    int y;
} Position;

char grid[GRID_SIZE][GRID_SIZE];
Position robot;

void initialize_grid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = EMPTY;
        }
    }

    // Place obstacles
    grid[1][1] = OBSTACLE;
    grid[2][2] = OBSTACLE;
    grid[3][3] = OBSTACLE;

    // Place robot at starting position
    robot.x = 0;
    robot.y = 0;
    grid[robot.x][robot.y] = ROBOT;
}

void print_grid() {
    printf("\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(int new_x, int new_y) {
    if (new_x < 0 || new_y < 0 || new_x >= GRID_SIZE || new_y >= GRID_SIZE) {
        return 0; // Out of bounds
    }
    if (grid[new_x][new_y] == OBSTACLE) {
        return 0; // Hit an obstacle
    }
    return 1; // Valid move
}

void move_robot(int dx, int dy) {
    int new_x = robot.x + dx;
    int new_y = robot.y + dy;

    if (is_valid_move(new_x, new_y)) {
        grid[robot.x][robot.y] = EMPTY; // Clear previous position
        robot.x = new_x;
        robot.y = new_y;
        grid[robot.x][robot.y] = ROBOT; // Update new position
    } else {
        printf("Invalid move to (%d, %d)\n", new_x, new_y);
    }
}

int main() {
    initialize_grid();
    print_grid();

    char command;
    while (1) {
        printf("Enter command (w = up, s = down, a = left, d = right, q = quit): ");
        scanf(" %c", &command);

        switch (command) {
            case 'w':
                move_robot(-1, 0);
                break;
            case 's':
                move_robot(1, 0);
                break;
            case 'a':
                move_robot(0, -1);
                break;
            case 'd':
                move_robot(0, 1);
                break;
            case 'q':
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Unknown command. Please try again.\n");
        }

        print_grid();
    }
    
    return 0;
}