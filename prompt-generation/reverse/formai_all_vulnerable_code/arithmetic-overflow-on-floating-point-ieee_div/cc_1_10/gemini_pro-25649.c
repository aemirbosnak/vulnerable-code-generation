//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DEG_TO_RAD(deg) ((deg) * M_PI / 180.0)
#define RAD_TO_DEG(rad) ((rad) * 180.0 / M_PI)

typedef struct {
    double x;
    double y;
    double theta;
} Pose;

typedef struct {
    double v;
    double w;
} Twist;

Pose pose;
Twist twist;

void update_pose(double dt) {
    pose.x += twist.v * cos(pose.theta) * dt;
    pose.y += twist.v * sin(pose.theta) * dt;
    pose.theta += twist.w * dt;
}

void set_twist(double v, double w) {
    twist.v = v;
    twist.w = w;
}

void move_forward(double distance) {
    double dt = distance / twist.v;
    update_pose(dt);
}

void turn_left(double angle) {
    double dt = angle / twist.w;
    update_pose(dt);
}

void turn_right(double angle) {
    double dt = angle / twist.w;
    update_pose(dt);
}

void print_pose() {
    printf("Pose: x = %.2f, y = %.2f, theta = %.2f\n", pose.x, pose.y, RAD_TO_DEG(pose.theta));
}

int main() {
    pose.x = 0.0;
    pose.y = 0.0;
    pose.theta = DEG_TO_RAD(0.0);

    twist.v = 1.0;
    twist.w = 0.0;

    move_forward(5.0);
    turn_left(DEG_TO_RAD(90.0));
    move_forward(5.0);
    turn_right(DEG_TO_RAD(90.0));
    move_forward(5.0);
    turn_left(DEG_TO_RAD(90.0));
    move_forward(5.0);
    turn_right(DEG_TO_RAD(90.0));

    print_pose();

    return 0;
}