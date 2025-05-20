//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_MOVES 100
#define GRID_SIZE 10

typedef struct {
    int x;
    int y;
    int forward_count;
    int backward_count;
    int left_count;
    int right_count;
} Robot;

void initialize_robot(Robot *robot) {
    robot->x = GRID_SIZE / 2;
    robot->y = GRID_SIZE / 2;
    robot->forward_count = 0;
    robot->backward_count = 0;
    robot->left_count = 0;
    robot->right_count = 0;
}

void move_forward(Robot *robot) {
    robot->y++;
    robot->forward_count++;
}

void move_backward(Robot *robot) {
    robot->y--;
    robot->backward_count++;
}

void move_left(Robot *robot) {
    robot->x--;
    robot->left_count++;
}

void move_right(Robot *robot) {
    robot->x++;
    robot->right_count++;
}

void print_statistics(Robot *robot) {
    printf("--- Movement Statistics ---\n");
    printf("Forward Moves: %d\n", robot->forward_count);
    printf("Backward Moves: %d\n", robot->backward_count);
    printf("Left Moves: %d\n", robot->left_count);
    printf("Right Moves: %d\n", robot->right_count);
    printf("Current Position: (%d, %d)\n", robot->x, robot->y);
}

void print_grid(Robot *robot) {
    printf("Grid Position of Robot:\n");
    for (int i = GRID_SIZE - 1; i >= 0; i--) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (robot->x == j && robot->y == i) {
                printf("[R] ");
            } else {
                printf("[ ] ");
            }
        }
        printf("\n");
    }
}

int main() {
    Robot robot;
    char command[10];
    
    initialize_robot(&robot);
    
    printf("Welcome to the Robot Movement Control System\n");
    printf("Commands: forward | backward | left | right | stats | exit\n");

    while (1) {
        printf("\nEnter command: ");
        scanf("%s", command);

        if (strcmp(command, "forward") == 0) {
            if (robot.y < GRID_SIZE - 1) {
                move_forward(&robot);
            } else {
                printf("Cannot move forward, boundary reached!\n");
            }
        } else if (strcmp(command, "backward") == 0) {
            if (robot.y > 0) {
                move_backward(&robot);
            } else {
                printf("Cannot move backward, boundary reached!\n");
            }
        } else if (strcmp(command, "left") == 0) {
            if (robot.x > 0) {
                move_left(&robot);
            } else {
                printf("Cannot move left, boundary reached!\n");
            }
        } else if (strcmp(command, "right") == 0) {
            if (robot.x < GRID_SIZE - 1) {
                move_right(&robot);
            } else {
                printf("Cannot move right, boundary reached!\n");
            }
        } else if (strcmp(command, "stats") == 0) {
            print_statistics(&robot);
            print_grid(&robot);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the program.\n");
            break;
        } else {
            printf("Invalid command!\n");
        }
        
        usleep(500000); // Adding a delay for better user experience
    }
    
    return 0;
}