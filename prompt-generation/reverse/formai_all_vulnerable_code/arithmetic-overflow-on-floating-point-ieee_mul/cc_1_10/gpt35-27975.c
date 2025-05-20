//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define GRAV_CONST 6.674e-11

struct Star {
    double mass;
    double x_position;
    double y_position;
    double x_velocity;
    double y_velocity;
};

void update_star_position(struct Star *star, double time_step) {
    star->x_position += star->x_velocity * time_step;
    star->y_position += star->y_velocity * time_step;
}

void update_star_velocity(struct Star *star, double x_accel, double y_accel, double time_step) {
    star->x_velocity += x_accel * time_step;
    star->y_velocity += y_accel * time_step;
}

int main() {
    printf("Starting Solar System Simulation\n");

    const int num_stars = 5;
    const double time_step = 0.001;
    const double sim_duration = 10 * 365.25 * 24 * 60 * 60; // 10 years in seconds
    struct Star stars[num_stars];

    // Set up initial conditions
    srand(time(NULL));
    for (int i = 0; i < num_stars; i++) {
        stars[i].mass = pow(10, 30) * (double)(rand() % 100);
        stars[i].x_position = 1e11 * (double)(rand() % 100) - 5e11;
        stars[i].y_position = 1e11 * (double)(rand() % 100) - 5e11;
        stars[i].x_velocity = (double)(rand() % 100) - 50;
        stars[i].y_velocity = (double)(rand() % 100) - 50;
    }

    // Simulate motion of the stars
    double current_time = 0;
    while (current_time < sim_duration) {
        for (int i = 0; i < num_stars; i++) {
            double net_x_accel = 0;
            double net_y_accel = 0;

            // Calculate acceleration due to gravity from all other stars
            for (int j = 0; j < num_stars; j++) {
                if (j != i) {
                    double x_diff = stars[j].x_position - stars[i].x_position;
                    double y_diff = stars[j].y_position - stars[i].y_position;
                    double distance = sqrt(x_diff * x_diff + y_diff * y_diff);
                    double force = GRAV_CONST * stars[j].mass * stars[i].mass / (distance * distance);
                    net_x_accel += force * x_diff / distance / stars[i].mass;
                    net_y_accel += force * y_diff / distance / stars[i].mass;
                }
            }

            // Update star velocity and position
            update_star_velocity(&stars[i], net_x_accel, net_y_accel, time_step);
            update_star_position(&stars[i], time_step);
        }
        current_time += time_step;
    }

    printf("Simulation complete.\n");
    return 0;
}