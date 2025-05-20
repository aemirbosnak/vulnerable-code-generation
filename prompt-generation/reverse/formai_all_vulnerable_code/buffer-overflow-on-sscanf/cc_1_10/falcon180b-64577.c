//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ROBOT_SPEED 1000
#define MAX_ROBOT_ROTATION_SPEED 1000
#define ROBOT_MAX_HEALTH 100

typedef struct {
    int x, y;
    int health;
    int speed;
    int rotation_speed;
} Robot;

void create_robot(Robot* robot) {
    robot->x = 0;
    robot->y = 0;
    robot->health = ROBOT_MAX_HEALTH;
    robot->speed = 0;
    robot->rotation_speed = 0;
}

void move_robot(Robot* robot, int dx, int dy) {
    robot->x += dx;
    robot->y += dy;
}

void rotate_robot(Robot* robot, int dr) {
    robot->rotation_speed = dr;
}

void update_robot(Robot* robot) {
    int nx = robot->x + robot->speed * cos(robot->rotation_speed);
    int ny = robot->y + robot->speed * sin(robot->rotation_speed);
    if (nx >= 0 && nx < 1000 && ny >= 0 && ny < 1000) {
        robot->x = nx;
        robot->y = ny;
    }
}

void check_collision(Robot* robot) {
    if (robot->x < 0 || robot->x >= 1000 || robot->y < 0 || robot->y >= 1000) {
        printf("Robot collided with an obstacle.\n");
        exit(1);
    }
}

int main() {
    Robot robot;
    create_robot(&robot);
    char command[MAX_COMMAND_LENGTH];
    while (fgets(command, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        int dx, dy, dr;
        sscanf(command, "move %d %d", &dx, &dy);
        move_robot(&robot, dx, dy);
        sscanf(command, "rotate %d", &dr);
        rotate_robot(&robot, dr);
        update_robot(&robot);
        check_collision(&robot);
    }
    return 0;
}