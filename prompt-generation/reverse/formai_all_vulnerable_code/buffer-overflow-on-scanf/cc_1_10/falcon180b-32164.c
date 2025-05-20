//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <pthread.h>

#define PI 3.14159265358979323846
#define DEG_TO_RAD (PI/180.0)
#define RAD_TO_DEG (180.0/PI)

typedef struct {
    double x, y;
} Point;

typedef struct {
    Point current;
    Point target;
    double speed;
} Robot;

void move_robot(Robot* robot) {
    double dx = robot->target.x - robot->current.x;
    double dy = robot->target.y - robot->current.y;
    double distance = sqrt(dx*dx + dy*dy);

    if (distance < robot->speed) {
        robot->current.x = robot->target.x;
        robot->current.y = robot->target.y;
    } else {
        double angle = atan2(dy, dx);
        robot->current.x += robot->speed * cos(angle);
        robot->current.y += robot->speed * sin(angle);
    }
}

void* run_robot(void* arg) {
    Robot* robot = (Robot*) arg;

    while (true) {
        move_robot(robot);
        usleep(100000); // Sleep for 100ms
    }

    return NULL;
}

int main() {
    pthread_t thread_id;
    Robot robot;

    printf("Enter starting position (x,y): ");
    scanf("%lf %lf", &robot.current.x, &robot.current.y);

    printf("Enter target position (x,y): ");
    scanf("%lf %lf", &robot.target.x, &robot.target.y);

    printf("Enter robot speed (m/s): ");
    scanf("%lf", &robot.speed);

    pthread_create(&thread_id, NULL, run_robot, &robot);

    while (true) {
        printf("Current position: (%lf,%lf)\n", robot.current.x, robot.current.y);
        usleep(1000000); // Sleep for 1s
    }

    return 0;
}