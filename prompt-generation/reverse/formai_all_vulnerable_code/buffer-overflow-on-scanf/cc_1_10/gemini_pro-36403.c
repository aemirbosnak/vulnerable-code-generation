//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
    double theta;
} Pose;

typedef struct {
    double v;
    double w;
} Velocity;

Pose pose = {0, 0, 0};
Velocity velocity = {0, 0};

void set_velocity(double v, double w) {
    velocity.v = v;
    velocity.w = w;
}

void update_pose() {
    pose.x += velocity.v * cos(pose.theta) * 0.01;
    pose.y += velocity.v * sin(pose.theta) * 0.01;
    pose.theta += velocity.w * 0.01;
    if (pose.theta > PI) {
        pose.theta -= 2 * PI;
    } else if (pose.theta < -PI) {
        pose.theta += 2 * PI;
    }
}

void print_pose() {
    printf("Pose: (%.2f, %.2f, %.2f)\n", pose.x, pose.y, pose.theta);
}

int main() {
    // Set the initial pose of the robot
    pose.x = 0;
    pose.y = 0;
    pose.theta = 0;

    // Set the initial velocity of the robot
    velocity.v = 0;
    velocity.w = 0;

    // Create a loop to control the robot
    while (1) {
        // Get the input from the user
        char input[100];
        printf("Enter a command (v, w, p, q): ");
        scanf("%s", input);

        // Parse the input
        if (strcmp(input, "v") == 0) {
            // Set the velocity of the robot
            double v, w;
            printf("Enter the velocity (v, w): ");
            scanf("%lf %lf", &v, &w);
            set_velocity(v, w);
        } else if (strcmp(input, "w") == 0) {
            // Set the angular velocity of the robot
            double w;
            printf("Enter the angular velocity (w): ");
            scanf("%lf", &w);
            set_velocity(0, w);
        } else if (strcmp(input, "p") == 0) {
            // Print the pose of the robot
            print_pose();
        } else if (strcmp(input, "q") == 0) {
            // Quit the program
            break;
        }

        // Update the pose of the robot
        update_pose();
    }

    return 0;
}