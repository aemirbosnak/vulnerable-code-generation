//FormAI DATASET v1.0 Category: Physics simulation ; Style: expert-level
#include <stdio.h>
#include <math.h>

double distance(double x1, double y1, double x2, double y2) {
    double x_diff = x2 - x1;
    double y_diff = y2 - y1;
    return sqrt(pow(x_diff, 2) + pow(y_diff, 2));
}

int main() {
    double mass = 1.0; // kg
    double radius = 0.01; // m
    double position_x = 0.0; // m
    double position_y = 0.0; // m
    double velocity_x = 0.0; // m/s
    double velocity_y = 0.0; // m/s
    double acceleration_x = 0.0; // m/s^2
    double acceleration_y = 0.0; // m/s^2
    double time_step = 0.001; // s
    double force_x = 0.0;
    double force_y = 0.0;

    double earth_mass = 5.97e24;
    double earth_radius = 6.371e6;
    double gravitational_constant = 6.67e-11;

    double earth_x = 0.0;
    double earth_y = 0.0;

    double distance_to_earth;
    double force_gravity;

    int steps = 10000;
    int i;
    for (i = 0; i < steps; i++) {
        distance_to_earth = distance(position_x, position_y, earth_x, earth_y);
        force_gravity = (gravitational_constant * mass * earth_mass) / pow(distance_to_earth, 2);
        force_x = force_gravity * ((earth_x - position_x) / distance_to_earth);
        force_y = force_gravity * ((earth_y - position_y) / distance_to_earth);
        acceleration_x = force_x / mass;
        acceleration_y = force_y / mass;
        velocity_x += acceleration_x * time_step;
        velocity_y += acceleration_y * time_step;
        position_x += velocity_x * time_step + 0.5 * acceleration_x * pow(time_step, 2);
        position_y += velocity_y * time_step + 0.5 * acceleration_y * pow(time_step, 2);

        // Check if the particle hits the surface of the Earth
        if (distance(position_x, position_y, earth_x, earth_y) < earth_radius) {
            printf("The particle hit the surface of the Earth after %d steps\n", i);
            break;
        }
    }

    if(i == steps) {
        printf("The particle did not hit the surface of the Earth\n");
    }

    return 0;
}