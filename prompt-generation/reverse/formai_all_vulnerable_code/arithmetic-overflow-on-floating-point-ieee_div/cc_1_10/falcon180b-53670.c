//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846

// Robot structure
typedef struct {
    double x, y, theta;
    int status;
} Robot;

// Function prototypes
void move(Robot *robot, double v, double w);
void turn(Robot *robot, double v, double w);
void draw(Robot *robot);
void init(Robot *robot);
void forward(Robot *robot, double distance);
void backward(Robot *robot, double distance);
void left(Robot *robot, double angle);
void right(Robot *robot, double angle);
void stop(Robot *robot);

int main() {
    srand(time(NULL));
    Robot robot;
    init(&robot);
    draw(&robot);

    forward(&robot, 10);
    draw(&robot);

    left(&robot, 90);
    draw(&robot);

    backward(&robot, 5);
    draw(&robot);

    right(&robot, 45);
    draw(&robot);

    stop(&robot);
    draw(&robot);

    return 0;
}

// Initialize the robot
void init(Robot *robot) {
    robot->x = 0;
    robot->y = 0;
    robot->theta = 0;
    robot->status = 0;
}

// Draw the robot
void draw(Robot *robot) {
    printf("Robot: ");
    printf("x = %.2f, y = %.2f, theta = %.2f\n", robot->x, robot->y, robot->theta);
}

// Move the robot with given velocity and angular velocity
void move(Robot *robot, double v, double w) {
    robot->x += v * cos(robot->theta);
    robot->y += v * sin(robot->theta);
    robot->theta += w;
}

// Turn the robot with given angular velocity
void turn(Robot *robot, double v, double w) {
    robot->theta += w;
}

// Move the robot forward by given distance
void forward(Robot *robot, double distance) {
    double v = distance / (2 * PI * robot->x);
    double w = v / robot->x;
    move(robot, v, w);
}

// Move the robot backward by given distance
void backward(Robot *robot, double distance) {
    double v = distance / (2 * PI * robot->x);
    double w = -v / robot->x;
    move(robot, v, w);
}

// Turn the robot left by given angle
void left(Robot *robot, double angle) {
    double v = 0;
    double w = angle / (2 * PI * robot->x);
    turn(robot, v, w);
}

// Turn the robot right by given angle
void right(Robot *robot, double angle) {
    double v = 0;
    double w = -angle / (2 * PI * robot->x);
    turn(robot, v, w);
}

// Stop the robot
void stop(Robot *robot) {
    robot->theta = 0;
}