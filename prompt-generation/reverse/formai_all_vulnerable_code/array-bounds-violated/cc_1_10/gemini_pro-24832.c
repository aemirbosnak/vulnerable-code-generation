//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// The robot's current position
int x, y;

// The robot's current shape
int shape;

// The robot's current direction
int direction;

// The robot's goal position
int goal_x, goal_y;

// The map of the environment
int map[SIZE][SIZE];

// Function to initialize the robot
void init_robot() {
    // Set the robot's initial position
    x = 0;
    y = 0;

    // Set the robot's initial shape
    shape = 0;

    // Set the robot's initial direction
    direction = 0;

    // Set the robot's goal position
    goal_x = SIZE - 1;
    goal_y = SIZE - 1;

    // Initialize the map
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            map[i][j] = 0;
        }
    }
}

// Function to move the robot
void move_robot() {
    // Get the robot's current position
    int current_x = x;
    int current_y = y;

    // Get the robot's current direction
    int current_direction = direction;

    // Move the robot forward
    switch (current_direction) {
        case 0:
            y++;
            break;
        case 1:
            x++;
            break;
        case 2:
            y--;
            break;
        case 3:
            x--;
            break;
    }

    // Check if the robot has reached its goal
    if (x == goal_x && y == goal_y) {
        printf("The robot has reached its goal!\n");
        exit(0);
    }

    // Check if the robot has hit a wall
    if (map[x][y] == 1) {
        // Turn the robot around
        direction = (direction + 2) % 4;

        // Move the robot back to its original position
        x = current_x;
        y = current_y;
    }
}

// Function to change the robot's shape
void change_shape() {
    // Get the robot's current shape
    int current_shape = shape;

    // Change the robot's shape
    shape = (current_shape + 1) % 3;
}

// Function to print the map
void print_map() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Initialize the robot
    init_robot();

    // Print the initial map
    print_map();

    // While the robot has not reached its goal
    while (1) {
        // Move the robot
        move_robot();

        // Change the robot's shape
        change_shape();

        // Print the updated map
        print_map();
    }

    return 0;
}