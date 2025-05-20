//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define GRID_SIZE 5
#define MAX_STEPS 100

// Robot struct representing the robot's position
typedef struct {
    int x;
    int y;
} Robot;

// Function prototypes
void initialize_robot(Robot *robot);
void display_grid(Robot robot);
void move_robot(Robot *robot, const char *direction);
void move_randomly(Robot *robot);

int main() {
    Robot myRobot;
    char command[10];
    int steps = 0;

    initialize_robot(&myRobot);
    
    printf("Welcome to the Robot Movement Control Program!\n");
    printf("You can control the robot using the commands:\n");
    printf(" - 'up' to move up\n");
    printf(" - 'down' to move down\n");
    printf(" - 'left' to move left\n");
    printf(" - 'right' to move right\n");
    printf(" - 'random' to let the robot move randomly\n");
    printf(" - 'exit' to end the program\n");
    
    while (steps < MAX_STEPS) {
        display_grid(myRobot);
        printf("Enter command (step %d of %d): ", steps + 1, MAX_STEPS);
        scanf("%s", command);

        if (strcmp(command, "exit") == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        } else if (strcmp(command, "random") == 0) {
            move_randomly(&myRobot);
            steps++;
        } else {
            move_robot(&myRobot, command);
            steps++;
        }
        
        // Give feedback to the user
        printf("Moved robot to position (%d, %d)\n", myRobot.x, myRobot.y);
    }
    
    if (steps == MAX_STEPS) {
        printf("Maximum steps reached. Stopping...\n");
    }
    return 0;
}

void initialize_robot(Robot *robot) {
    robot->x = GRID_SIZE / 2;
    robot->y = GRID_SIZE / 2;
    printf("Robot initialized at position (%d, %d)\n", robot->x, robot->y);
}

void display_grid(Robot robot) {
    printf("\nCurrent Grid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == robot.y && j == robot.x) {
                printf("[R] ");
            } else {
                printf("[ ] ");
            }
        }
        printf("\n");
    }
}

void move_robot(Robot *robot, const char *direction) {
    if (strcmp(direction, "up") == 0 && robot->y > 0) {
        robot->y--;
    } else if (strcmp(direction, "down") == 0 && robot->y < GRID_SIZE - 1) {
        robot->y++;
    } else if (strcmp(direction, "left") == 0 && robot->x > 0) {
        robot->x--;
    } else if (strcmp(direction, "right") == 0 && robot->x < GRID_SIZE - 1) {
        robot->x++;
    } else {
        printf("Invalid move! Robot can't move in that direction.\n");
    }
}

void move_randomly(Robot *robot) {
    int rand_direction = rand() % 4;

    switch(rand_direction) {
        case 0:
            move_robot(robot, "up");
            break;
        case 1:
            move_robot(robot, "down");
            break;
        case 2:
            move_robot(robot, "left");
            break;
        case 3:
            move_robot(robot, "right");
            break;
    }
}