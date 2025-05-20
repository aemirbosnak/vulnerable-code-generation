//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define GRID_SIZE 10
#define INIT_POS_X 0
#define INIT_POS_Y 0

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position pos;
    int id;
} Robot;

void initialize_robot(Robot *robot, int id) {
    robot->id = id;
    robot->pos.x = INIT_POS_X;
    robot->pos.y = INIT_POS_Y;
}

void print_position(Robot *robot) {
    printf("Robot %d is at position (%d, %d)\n", robot->id, robot->pos.x, robot->pos.y);
}

int move_robot(Robot *robot, int direction) {
    switch (direction) {
        case 0: // Up
            if (robot->pos.y < GRID_SIZE - 1) {
                robot->pos.y++;
                return 1;
            }
            break;
        case 1: // Down
            if (robot->pos.y > 0) {
                robot->pos.y--;
                return 1;
            }
            break;
        case 2: // Left
            if (robot->pos.x > 0) {
                robot->pos.x--;
                return 1;
            }
            break;
        case 3: // Right
            if (robot->pos.x < GRID_SIZE - 1) {
                robot->pos.x++;
                return 1;
            }
            break;
    }
    return 0; // Move not possible
}

void random_movement(Robot *robot) {
    srand(time(NULL) + robot->id); // Seed random number generator
    for (int i = 0; i < 10; i++) {
        int direction = rand() % 4; // Random direction 0-3
        int success = move_robot(robot, direction);
        if (success) {
            print_position(robot);
        } else {
            printf("Robot %d cannot move in that direction!\n", robot->id);
        }
        usleep(500000); // Sleep for 0.5 seconds
    }
}

void move_multiple_robots(Robot *robots, int count) {
    for (int i = 0; i < count; i++) {
        printf("Moving Robot %d...\n", robots[i].id);
        random_movement(&robots[i]);
    }
}

int main() {
    int robot_count = 5;
    Robot robots[robot_count];

    // Initialize robots
    for (int i = 0; i < robot_count; i++) {
        initialize_robot(&robots[i], i + 1);
    }

    // Move all robots
    move_multiple_robots(robots, robot_count);

    return 0;
}