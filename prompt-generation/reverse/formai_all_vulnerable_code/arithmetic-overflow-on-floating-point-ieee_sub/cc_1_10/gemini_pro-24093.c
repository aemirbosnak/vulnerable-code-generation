//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
    double theta;
} pose_t;

typedef struct {
    double left_speed;
    double right_speed;
} velocity_t;

pose_t pose;
velocity_t velocity;

void update_pose(double delta_left, double delta_right) {
    double delta_theta = (delta_right - delta_left) / 2.0;
    double delta_x = (delta_right + delta_left) * cos(pose.theta) / 2.0;
    double delta_y = (delta_right + delta_left) * sin(pose.theta) / 2.0;
    pose.x += delta_x;
    pose.y += delta_y;
    pose.theta += delta_theta;
}

velocity_t compute_velocity(double vx, double vy, double omega) {
    double r = 0.1;  // wheel radius
    double l = 0.2;  // wheelbase length
    velocity_t v;
    v.left_speed = (vx - omega * l / 2.0) / r;
    v.right_speed = (vx + omega * l / 2.0) / r;
    return v;
}

int main() {
    // initialize the robot's pose and velocity
    pose.x = 0.0;
    pose.y = 0.0;
    pose.theta = 0.0;
    velocity.left_speed = 0.0;
    velocity.right_speed = 0.0;

    // create a loop to control the robot's movement
    while (1) {
        // get the desired linear and angular velocities from the user
        double vx, vy, omega;
        printf("Enter desired linear velocity (x, y): ");
        scanf("%lf %lf", &vx, &vy);
        printf("Enter desired angular velocity: ");
        scanf("%lf", &omega);

        // compute the corresponding left and right wheel speeds
        velocity = compute_velocity(vx, vy, omega);

        // update the robot's pose
        update_pose(velocity.left_speed, velocity.right_speed);

        // print the robot's current pose
        printf("Robot's current pose: (x, y, theta) = (%lf, %lf, %lf)\n", pose.x, pose.y, pose.theta);
    }

    return 0;
}