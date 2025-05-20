//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x, y, theta;
} Pose;

typedef struct {
    double v, w;
} Twist;

void move(Pose *pose, Twist *twist, double dt) {
    pose->x += twist->v * cos(pose->theta) * dt;
    pose->y += twist->v * sin(pose->theta) * dt;
    pose->theta += twist->w * dt;
}

void turn_to_angle(Pose *pose, double target_angle, double max_w, double dt) {
    double error = target_angle - pose->theta;
    if (error > PI) error -= 2 * PI;
    else if (error < -PI) error += 2 * PI;

    double w = max_w * error / PI;
    if (fabs(w) > max_w) w = max_w * (w > 0 ? 1 : -1);

    move(pose, &(Twist){0, w}, dt);
}

int main() {
    Pose pose = {0, 0, 0};
    Twist twist = {0, 0};

    double dt = 0.1;
    double max_v = 1;
    double max_w = PI / 2;

    while (1) {
        // Get user input
        printf("Enter velocity (v) and angular velocity (w): ");
        scanf("%lf %lf", &twist.v, &twist.w);

        // Clamp velocities to maximums
        if (fabs(twist.v) > max_v) twist.v = max_v * (twist.v > 0 ? 1 : -1);
        if (fabs(twist.w) > max_w) twist.w = max_w * (twist.w > 0 ? 1 : -1);

        // Move the robot
        move(&pose, &twist, dt);

        // Print the robot's pose
        printf("Robot's pose: (%.2f, %.2f, %.2f)\n", pose.x, pose.y, pose.theta);
    }

    return 0;
}