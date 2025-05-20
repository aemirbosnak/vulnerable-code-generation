//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRID_SIZE 5

typedef struct {
    int x;
    int y;
} Robot;

void initialize_robot(Robot *robot) {
    robot->x = 0;
    robot->y = 0;
}

void display_position(Robot *robot) {
    printf("Robot is at position (%d, %d)\n", robot->x, robot->y);
}

void move_up(Robot *robot) {
    if (robot->y < GRID_SIZE - 1) {
        robot->y++;
    } else {
        printf("Move up failed: Out of bounds!\n");
    }
}

void move_down(Robot *robot) {
    if (robot->y > 0) {
        robot->y--;
    } else {
        printf("Move down failed: Out of bounds!\n");
    }
}

void move_left(Robot *robot) {
    if (robot->x > 0) {
        robot->x--;
    } else {
        printf("Move left failed: Out of bounds!\n");
    }
}

void move_right(Robot *robot) {
    if (robot->x < GRID_SIZE - 1) {
        robot->x++;
    } else {
        printf("Move right failed: Out of bounds!\n");
    }
}

void display_grid(Robot *robot) {
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
    initialize_robot(&robot);

    char command[10];
    printf("Robot Movement Control\n");
    printf("Commands: up, down, left, right, exit\n");

    while (1) {
        display_position(&robot);
        display_grid(&robot);

        printf("Enter command: ");
        scanf("%s", command);
        
        if (strcmp(command, "up") == 0) {
            move_up(&robot);
        } else if (strcmp(command, "down") == 0) {
            move_down(&robot);
        } else if (strcmp(command, "left") == 0) {
            move_left(&robot);
        } else if (strcmp(command, "right") == 0) {
            move_right(&robot);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the robot control system.\n");
            break;
        } else {
            printf("Unknown command: %s\n", command);
        }

        printf("\n");
    }

    return 0;
}