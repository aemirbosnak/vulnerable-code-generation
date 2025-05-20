//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Define the robot's possible movements
#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4

// Define the robot's current position and heading
int x = 0;
int y = 0;
int heading = FORWARD;

// Define the maze
int maze[10][10] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// Function to move the robot forward
void moveForward() {
    switch (heading) {
        case FORWARD:
            y++;
            break;
        case BACKWARD:
            y--;
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
    }
}

// Function to turn the robot left
void turnLeft() {
    heading = (heading + 1) % 4;
}

// Function to turn the robot right
void turnRight() {
    heading = (heading + 3) % 4;
}

// Function to print the maze
void printMaze() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Print the initial maze
    printMaze();

    // Move the robot through the maze
    while (x != 9 || y != 9) {
        // Check if the robot can move forward
        if (maze[y][x + 1] == 0 && heading == RIGHT) {
            moveForward();
        } else if (maze[y - 1][x] == 0 && heading == FORWARD) {
            moveForward();
        } else if (maze[y][x - 1] == 0 && heading == LEFT) {
            moveForward();
        } else if (maze[y + 1][x] == 0 && heading == BACKWARD) {
            moveForward();
        } else {
            // If the robot cannot move forward, turn left
            turnLeft();
        }

        // Print the updated maze
        printMaze();
    }

    // The robot has reached the end of the maze
    printf("The robot has reached the end of the maze!\n");

    return 0;
}