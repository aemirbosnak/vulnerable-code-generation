//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define WHEEL_RADIUS 0.05
#define WHEEL_BASE 0.3
#define MAX_SPEED 0.5
#define MAX_TORQUE 0.5
#define DISTANCE_THRESHOLD 0.1

typedef struct {
    double x, y, theta;
} Pose;

typedef struct {
    double v, w;
} Twist;

void move(Pose pose, Twist twist, double dt) {
    double v = twist.v;
    double w = twist.w;
    double dx = v * cos(pose.theta) * dt;
    double dy = v * sin(pose.theta) * dt;
    double dtheta = w * dt;

    pose.x += dx;
    pose.y += dy;
    pose.theta += dtheta;
}

void turn(Pose pose, Twist twist, double dt) {
    double v = twist.v;
    double w = twist.w;
    double dtheta = w * dt;

    pose.theta += dtheta;
}

void drive(Pose pose, Twist twist, double dt) {
    move(pose, twist, dt);
    turn(pose, twist, dt);
}

double distance(Pose p1, Pose p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

double angle(Pose p1, Pose p2) {
    double dtheta = p2.theta - p1.theta;
    if (dtheta > PI) {
        dtheta -= 2 * PI;
    } else if (dtheta < -PI) {
        dtheta += 2 * PI;
    }
    return dtheta;
}

int main() {
    Pose pose = {0, 0, 0};
    Twist twist = {0, 0};
    double dt = 0.1;

    while (1) {
        printf("Enter command (f for forward, b for backward, l for left, r for right, s for stop): ");
        char command;
        scanf("%c", &command);

        switch (command) {
        case 'f':
            twist.v = MAX_SPEED;
            twist.w = 0;
            break;
        case 'b':
            twist.v = -MAX_SPEED;
            twist.w = 0;
            break;
        case 'l':
            twist.v = 0;
            twist.w = MAX_TORQUE;
            break;
        case 'r':
            twist.v = 0;
            twist.w = -MAX_TORQUE;
            break;
        case's':
            twist.v = 0;
            twist.w = 0;
            break;
        default:
            printf("Invalid command\n");
            continue;
        }

        drive(pose, twist, dt);

        printf("Current pose: (%lf, %lf, %lf)\n", pose.x, pose.y, pose.theta);
        printf("Current speed: %lf\n", twist.v);
        printf("Current angular speed: %lf\n", twist.w);
    }

    return 0;
}