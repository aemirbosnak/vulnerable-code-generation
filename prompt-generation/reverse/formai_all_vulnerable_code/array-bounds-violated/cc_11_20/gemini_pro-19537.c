//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Robot movement control
#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4
#define STOP 0

// Maze dimensions
#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

// Robot position
int robot_x = 0;
int robot_y = 0;

// Maze
int maze[MAZE_WIDTH][MAZE_HEIGHT] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Main loop
    while (1) {
        // Get the current robot position
        int current_x = robot_x;
        int current_y = robot_y;

        // Get the possible moves
        int possible_moves[4] = {FORWARD, BACKWARD, LEFT, RIGHT};

        // Remove impossible moves
        if (current_x == 0) {
            possible_moves[LEFT] = STOP;
        }
        if (current_x == MAZE_WIDTH - 1) {
            possible_moves[RIGHT] = STOP;
        }
        if (current_y == 0) {
            possible_moves[BACKWARD] = STOP;
        }
        if (current_y == MAZE_HEIGHT - 1) {
            possible_moves[FORWARD] = STOP;
        }

        // Choose a random move
        int move = possible_moves[rand() % 4];

        // Make the move
        switch (move) {
            case FORWARD:
                robot_y++;
                break;
            case BACKWARD:
                robot_y--;
                break;
            case LEFT:
                robot_x--;
                break;
            case RIGHT:
                robot_x++;
                break;
            case STOP:
                break;
        }

        // Check if the robot hit a wall
        if (maze[robot_x][robot_y] == 1) {
            // Move the robot back to its previous position
            robot_x = current_x;
            robot_y = current_y;
        }

        // Check if the robot reached the exit
        if (robot_x == MAZE_WIDTH - 1 && robot_y == MAZE_HEIGHT - 1) {
            // Exit the loop
            break;
        }
    }

    // Print the final robot position
    printf("The robot reached the exit at (%d, %d).\n", robot_x, robot_y);

    return 0;
}