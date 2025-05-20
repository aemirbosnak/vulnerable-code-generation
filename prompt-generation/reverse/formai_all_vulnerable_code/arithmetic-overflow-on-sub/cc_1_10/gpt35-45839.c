//FormAI DATASET v1.0 Category: Robot movement control ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Define constants for the maximum and minimum positions
#define MAX_POS 100
#define MIN_POS 0

// Define a structure for the robot
struct Robot {
    int x_position;
    int y_position;
    int z_position;
};

// Function to move the robot forward in the x direction
void move_forward(struct Robot *robot, int distance) {
    if (robot->x_position + distance > MAX_POS) {
        printf("Error: Beyond maximum position\n");
    } else {
        robot->x_position += distance;
        printf("Robot moved forward %d units in the x direction. New position is (%d, %d, %d)\n", distance, robot->x_position, robot->y_position, robot->z_position);
    }
}

// Function to move the robot backward in the x direction
void move_backward(struct Robot *robot, int distance) {
    if (robot->x_position - distance < MIN_POS) {
        printf("Error: Below minimum position\n");
    } else {
        robot->x_position -= distance;
        printf("Robot moved backward %d units in the x direction. New position is (%d, %d, %d)\n", distance, robot->x_position, robot->y_position, robot->z_position);
    }
}

// Function to move the robot up in the z direction
void move_up(struct Robot *robot, int distance) {
    if (robot->z_position + distance > MAX_POS) {
        printf("Error: Beyond maximum position\n");
    } else {
        robot->z_position += distance;
        printf("Robot moved up %d units in the z direction. New position is (%d, %d, %d)\n", distance, robot->x_position, robot->y_position, robot->z_position);
    }
}

// Function to move the robot down in the z direction
void move_down(struct Robot *robot, int distance) {
    if (robot->z_position - distance < MIN_POS) {
        printf("Error: Below minimum position\n");
    } else {
        robot->z_position -= distance;
        printf("Robot moved down %d units in the z direction. New position is (%d, %d, %d)\n", distance, robot->x_position, robot->y_position, robot->z_position);
    }
}

// Function to move the robot left in the y direction
void move_left(struct Robot *robot, int distance) {
    if (robot->y_position - distance < MIN_POS) {
        printf("Error: Below minimum position\n");
    } else {
        robot->y_position -= distance;
        printf("Robot moved left %d units in the y direction. New position is (%d, %d, %d)\n", distance, robot->x_position, robot->y_position, robot->z_position);
    }
}

// Function to move the robot right in the y direction
void move_right(struct Robot *robot, int distance) {
    if (robot->y_position + distance > MAX_POS) {
        printf("Error: Beyond maximum position\n");
    } else {
        robot->y_position += distance;
        printf("Robot moved right %d units in the y direction. New position is (%d, %d, %d)\n", distance, robot->x_position, robot->y_position, robot->z_position);
    }
}

int main() {
    struct Robot robot = {0, 0, 0};
    char input;
    int distance;

    printf("Enter a command:\n");
    printf("f: Move forward\nb: Move backward\nu: Move up\nd: Move down\nl: Move left\nr: Move right\nq: Quit\n");

    while (1) {
        scanf(" %c", &input);
        if (input == 'q') {
            break;
        }
        printf("Enter distance: ");
        scanf("%d", &distance);

        switch(input) {
            case 'f':
                move_forward(&robot, distance);
                break;
            case 'b':
                move_backward(&robot, distance);
                break;
            case 'u':
                move_up(&robot, distance);
                break;
            case 'd':
                move_down(&robot, distance);
                break;
            case 'l':
                move_left(&robot, distance);
                break;
            case 'r':
                move_right(&robot, distance);
                break;
            default:
                printf("Invalid command. Please try again.\n");
                break;
        }
    }

    return 0;
}