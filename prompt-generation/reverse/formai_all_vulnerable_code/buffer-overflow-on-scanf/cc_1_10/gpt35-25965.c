//FormAI DATASET v1.0 Category: Robot movement control ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10 // N is the size of the grid used as the robot's workspace

// The direction type is used to express in which direction the robot is currently moving
typedef enum {
    NORTH,
    EAST,
    SOUTH,
    WEST
} direction_t;

// The position type is meant to store the current position of the robot in the grid
typedef struct {
    int x;
    int y;
} position_t;

// The robot type contains all the information needed to control the robot
typedef struct {
    position_t position;
    direction_t direction;
} robot_t;

// This function initializes a robot instance with the provided starting position and direction
robot_t initialize_robot(position_t starting_position, direction_t starting_direction) {
    robot_t robot;
    robot.position = starting_position;
    robot.direction = starting_direction;
    return robot;
}

// This function moves the robot forward one step in the direction it is currently facing
void move_forward(robot_t *robot) {
    switch (robot->direction) {
        case NORTH: {
            if (robot->position.y < N - 1) {
                robot->position.y++;
            } else {
                printf("Robot can't move forward anymore!\n");
            }
            break;
        }
        case EAST: {
            if (robot->position.x < N - 1) {
                robot->position.x++;
            } else {
                printf("Robot can't move forward anymore!\n");
            }
            break;
        }
        case SOUTH: {
            if (robot->position.y > 0) {
                robot->position.y--;
            } else {
                printf("Robot can't move forward anymore!\n");
            }
            break;
        }
        case WEST: {
            if (robot->position.x > 0) {
                robot->position.x--;
            } else {
                printf("Robot can't move forward anymore!\n");
            }
            break;
        }
    }
}

// This function turns the robot by 90 degrees to the left
void turn_left(robot_t *robot) {
    switch (robot->direction) {
        case NORTH: {
            robot->direction = WEST;
            break;
        }
        case EAST: {
            robot->direction = NORTH;
            break;
        }
        case SOUTH: {
            robot->direction = EAST;
            break;
        }
        case WEST: {
            robot->direction = SOUTH;
            break;
        }
    }
}

// This function turns the robot by 90 degrees to the right
void turn_right(robot_t *robot) {
    switch (robot->direction) {
        case NORTH: {
            robot->direction = EAST;
            break;
        }
        case EAST: {
            robot->direction = SOUTH;
            break;
        }
        case SOUTH: {
            robot->direction = WEST;
            break;
        }
        case WEST: {
            robot->direction = NORTH;
            break;
        }
    }
}

// This function prints out the current state of the robot
void print_robot_state(robot_t robot) {
    printf("The robot is at position (%d,%d) facing ", robot.position.x, robot.position.y);

    switch (robot.direction) {
        case NORTH: {
            printf("north\n");
            break;
        }
        case EAST: {
            printf("east\n");
            break;
        }
        case SOUTH: {
            printf("south\n");
            break;
        }
        case WEST: {
            printf("west\n");
            break;
        }
    }
}

// The main function controls the movement of the robot based on user input
int main() {
    position_t starting_position = {0, 0};
    direction_t starting_direction = NORTH;

    robot_t robot = initialize_robot(starting_position, starting_direction);

    bool running = true;

    while (running) {
        print_robot_state(robot);

        char input;
        printf("Enter a command (f/l/r/q): ");
        scanf(" %c", &input);

        switch (input) {
            case 'f': {
                move_forward(&robot);
                break;
            }
            case 'l': {
                turn_left(&robot);
                break;
            }
            case 'r': {
                turn_right(&robot);
                break;
            }
            case 'q': {
                running = false;
                break;
            }
            default: {
                printf("Invalid input, please try again!\n");
            }
        }
    }

    return 0;
}