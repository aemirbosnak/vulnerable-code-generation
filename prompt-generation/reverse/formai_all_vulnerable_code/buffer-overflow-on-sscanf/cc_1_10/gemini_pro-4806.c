//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_OF_ROBOTS 10
#define MAX_BUFFER_SIZE 256

// Robot movement directions
typedef enum {
    LEFT,
    RIGHT,
    UP,
    DOWN
} MovementDirection;

// Robot struct
typedef struct {
    int id;
    int x;
    int y;
    MovementDirection direction;
} Robot;

// Function to create a new robot
Robot *create_robot(int id, int x, int y, MovementDirection direction) {
    Robot *robot = (Robot *)malloc(sizeof(Robot));
    robot->id = id;
    robot->x = x;
    robot->y = y;
    robot->direction = direction;
    return robot;
}

// Function to free a robot
void free_robot(Robot *robot) {
    free(robot);
}

// Function to move a robot in the specified direction
void move_robot(Robot *robot, MovementDirection direction) {
    switch (direction) {
    case LEFT:
        robot->x--;
        break;
    case RIGHT:
        robot->x++;
        break;
    case UP:
        robot->y++;
        break;
    case DOWN:
        robot->y--;
        break;
    }
}

// Function to parse a command and move the corresponding robot
void parse_command(char *command, Robot *robots[], int num_of_robots) {
    int robot_id, direction;
    char buffer[MAX_BUFFER_SIZE];

    // Parse the command
    sscanf(command, "robot %d move %s", &robot_id, buffer);

    // Convert the direction to an enum value
    if (strcmp(buffer, "left") == 0) {
        direction = LEFT;
    } else if (strcmp(buffer, "right") == 0) {
        direction = RIGHT;
    } else if (strcmp(buffer, "up") == 0) {
        direction = UP;
    } else if (strcmp(buffer, "down") == 0) {
        direction = DOWN;
    } else {
        printf("Invalid direction: %s\n", buffer);
        return;
    }

    // Move the robot
    for (int i = 0; i < num_of_robots; i++) {
        if (robots[i]->id == robot_id) {
            move_robot(robots[i], direction);
            break;
        }
    }
}

// Function to print the positions of all robots
void print_robots(Robot *robots[], int num_of_robots) {
    for (int i = 0; i < num_of_robots; i++) {
        printf("Robot %d: (%d, %d)\n", robots[i]->id, robots[i]->x, robots[i]->y);
    }
}

int main() {
    // Create an array of robots
    Robot *robots[MAX_NUM_OF_ROBOTS];

    // Create some robots
    robots[0] = create_robot(1, 0, 0, LEFT);
    robots[1] = create_robot(2, 5, 5, UP);
    robots[2] = create_robot(3, 10, 10, RIGHT);

    // Get the number of robots
    int num_of_robots = sizeof(robots) / sizeof(robots[0]);

    // Get the commands from the user
    char command[MAX_BUFFER_SIZE];
    while (1) {
        printf("> ");
        fgets(command, MAX_BUFFER_SIZE, stdin);
        if (strcmp(command, "exit\n") == 0) {
            break;
        } else {
            parse_command(command, robots, num_of_robots);
        }
    }

    // Print the positions of all robots
    print_robots(robots, num_of_robots);

    // Free the robots
    for (int i = 0; i < num_of_robots; i++) {
        free_robot(robots[i]);
    }

    return 0;
}