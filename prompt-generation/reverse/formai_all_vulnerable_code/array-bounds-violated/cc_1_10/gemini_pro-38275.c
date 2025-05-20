//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the remote control vehicle's state
enum state {
    IDLE,
    FORWARD,
    REVERSE,
    LEFT,
    RIGHT
};

// Define the remote control vehicle's speed
enum speed {
    SLOW,
    MEDIUM,
    FAST
};

// Define the remote control vehicle's direction
enum direction {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

// Define the remote control vehicle's position
struct position {
    int x;
    int y;
};

// Define the remote control vehicle's simulation environment
struct environment {
    int width;
    int height;
    int obstacles[100][2];
    int num_obstacles;
};

// Initialize the remote control vehicle's state
enum state state = IDLE;

// Initialize the remote control vehicle's speed
enum speed speed = SLOW;

// Initialize the remote control vehicle's direction
enum direction direction = NORTH;

// Initialize the remote control vehicle's position
struct position position = {0, 0};

// Initialize the remote control vehicle's simulation environment
struct environment environment = {100, 100, {{0, 0}, {10, 10}, {20, 20}, {30, 30}, {40, 40}}, 5};

// Update the remote control vehicle's state
void update_state(char command) {
    switch (command) {
        case 'w':
            state = FORWARD;
            break;
        case 's':
            state = REVERSE;
            break;
        case 'a':
            state = LEFT;
            break;
        case 'd':
            state = RIGHT;
            break;
        case 'q':
            state = IDLE;
            break;
    }
}

// Update the remote control vehicle's speed
void update_speed(char command) {
    switch (command) {
        case '1':
            speed = SLOW;
            break;
        case '2':
            speed = MEDIUM;
            break;
        case '3':
            speed = FAST;
            break;
    }
}

// Update the remote control vehicle's direction
void update_direction(char command) {
    switch (command) {
        case 'w':
            direction = NORTH;
            break;
        case 's':
            direction = SOUTH;
            break;
        case 'a':
            direction = WEST;
            break;
        case 'd':
            direction = EAST;
            break;
    }
}

// Update the remote control vehicle's position
void update_position() {
    switch (state) {
        case FORWARD:
            switch (direction) {
                case NORTH:
                    position.y++;
                    break;
                case SOUTH:
                    position.y--;
                    break;
                case WEST:
                    position.x--;
                    break;
                case EAST:
                    position.x++;
                    break;
            }
            break;
        case REVERSE:
            switch (direction) {
                case NORTH:
                    position.y--;
                    break;
                case SOUTH:
                    position.y++;
                    break;
                case WEST:
                    position.x++;
                    break;
                case EAST:
                    position.x--;
                    break;
            }
            break;
        case LEFT:
            switch (direction) {
                case NORTH:
                    direction = WEST;
                    break;
                case SOUTH:
                    direction = EAST;
                    break;
                case WEST:
                    direction = SOUTH;
                    break;
                case EAST:
                    direction = NORTH;
                    break;
            }
            break;
        case RIGHT:
            switch (direction) {
                case NORTH:
                    direction = EAST;
                    break;
                case SOUTH:
                    direction = WEST;
                    break;
                case WEST:
                    direction = NORTH;
                    break;
                case EAST:
                    direction = SOUTH;
                    break;
            }
            break;
    }

    // Check for collisions
    for (int i = 0; i < environment.num_obstacles; i++) {
        if (position.x == environment.obstacles[i][0] && position.y == environment.obstacles[i][1]) {
            state = IDLE;
            printf("Collision detected!\n");
            break;
        }
    }

    // Check for out of bounds
    if (position.x < 0 || position.x >= environment.width || position.y < 0 || position.y >= environment.height) {
        state = IDLE;
        printf("Out of bounds!\n");
    }
}

// Draw the remote control vehicle's simulation environment
void draw_environment() {
    for (int i = 0; i < environment.height; i++) {
        for (int j = 0; j < environment.width; j++) {
            if (position.x == j && position.y == i) {
                printf("X");
            } else if (environment.obstacles[i][j] == 1) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create a remote control vehicle simulation loop
    while (1) {
        // Get a random command from the user
        char command = getchar();

        // Update the remote control vehicle's state
        update_state(command);

        // Update the remote control vehicle's speed
        update_speed(command);

        // Update the remote control vehicle's direction
        update_direction(command);

        // Update the remote control vehicle's position
        update_position();

        // Draw the remote control vehicle's sim
        draw_environment();

        // Sleep for a bit
        usleep(100000);
    }

    return 0;
}