//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: puzzling
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define GRAVITY 9.81 // Acceleration due to gravity
#define PI 3.14159265

void display_welcome_message() {
    printf("Welcome to the Puzzling Projectile Simulation!\n");
    printf("Can you solve the riddle to launch your projectile?\n\n");
}

double get_initial_velocity() {
    double v;
    printf("Puzzle 1: What is the initial velocity of the projectile in m/s?\n");
    printf("Hint: It's a two-digit number, the sum of its digits is 10.\n");
    while (1) {
        scanf("%lf", &v);
        if (v >= 10 && v < 100 && (int)v % 10 + (int)v / 10 == 10) {
            return v;
        }
        printf("Incorrect! Try again:\n");
    }
}

double get_launch_angle() {
    double angle;
    printf("Puzzle 2: What is the launch angle of the projectile in degrees?\n");
    printf("Hint: It's an acute angle that is a prime number.\n");
    while (1) {
        scanf("%lf", &angle);
        if (angle > 0 && angle < 90 && (angle == 2 || angle == 3 || angle == 5 || angle == 7 || angle == 11 || angle == 13 || angle == 17 || angle == 19 || angle == 23 || angle == 29 || angle == 31 || angle == 37 || angle == 41 || angle == 43 || angle == 47 || angle == 53 || angle == 59 || angle == 61 || angle == 67 || angle == 71 || angle == 73 || angle == 79 || angle == 83 || angle == 89)) {
            return angle;
        }
        printf("Incorrect! Try again:\n");
    }
}

void compute_trajectory(double v, double angle) {
    double angle_rad = angle * PI / 180.0;
    double time_of_flight = (2 * v * sin(angle_rad)) / GRAVITY;
    
    printf("\nCalculating trajectory...\n");
    printf("Time of flight: %.2f seconds\n", time_of_flight);
    
    // Maximum height
    double max_height = (v * v * sin(angle_rad) * sin(angle_rad)) / (2 * GRAVITY);
    printf("Maximum height: %.2f meters\n", max_height);
    
    // Horizontal range
    double range = (v * v * sin(2 * angle_rad)) / GRAVITY;
    printf("Horizontal range: %.2f meters\n", range);
}

void plot_trajectory(double v, double angle) {
    double angle_rad = angle * PI / 180.0;
    double t_flight = (2 * v * sin(angle_rad)) / GRAVITY; // total time of flight
    double dt = t_flight / 30; // time intervals for plotting

    printf("\nProjectile trajectory:\n");
    for (double t = 0; t <= t_flight; t += dt) {
        double x = v * cos(angle_rad) * t;
        double y = v * sin(angle_rad) * t - 0.5 * GRAVITY * t * t;
        printf("Time: %5.2fs | X: %5.2fm | Y: %5.2fm\n", t, x, y);
    }
}

int main() {
    display_welcome_message();

    double initial_velocity = get_initial_velocity();
    double launch_angle = get_launch_angle();

    compute_trajectory(initial_velocity, launch_angle);
    plot_trajectory(initial_velocity, launch_angle);

    printf("\nCongratulations, you've solved the puzzles and completed the simulation!\n");
    return 0;
}