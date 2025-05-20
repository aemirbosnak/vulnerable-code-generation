//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x, y, theta; // position and orientation
} Pose;

typedef struct {
    double v, w; // linear and angular velocity
} Twist;

void move(Pose* pose, Twist* twist, double dt) {
    double v = twist->v;
    double w = twist->w;
    double x = pose->x;
    double y = pose->y;
    double theta = pose->theta;

    double dx = v * cos(theta) * dt;
    double dy = v * sin(theta) * dt;
    double dtheta = w * dt;

    pose->x += dx;
    pose->y += dy;
    pose->theta += dtheta;
}

void turn(Pose* pose, Twist* twist, double dt) {
    double v = twist->v;
    double w = twist->w;
    double x = pose->x;
    double y = pose->y;
    double theta = pose->theta;

    double dtheta = w * dt;

    pose->theta += dtheta;
}

int main() {
    Pose robot = {0, 0, 0};
    Twist cmd_vel = {0, 0};

    while (1) {
        printf("Enter the linear velocity (m/s): ");
        scanf("%lf", &cmd_vel.v);

        printf("Enter the angular velocity (rad/s): ");
        scanf("%lf", &cmd_vel.w);

        move(&robot, &cmd_vel, 0.1);
        printf("Current pose: x=%lf, y=%lf, theta=%lf\n", robot.x, robot.y, robot.theta);

        turn(&robot, &cmd_vel, 0.1);
        printf("Current pose: x=%lf, y=%lf, theta=%lf\n", robot.x, robot.y, robot.theta);
    }

    return 0;
}