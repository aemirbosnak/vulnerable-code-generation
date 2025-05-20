//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: automated
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

#define G 9.81 // gravitational constant
#define TIME_INTERVAL 0.1 // time interval for simulation
#define MAX_TIME 10 // maximum time to run the simulation
#define MAX_LENGTH 50 // max length of the visual display of the projectile

void print_trajectory(double t, double x, double y) {
    int position = (int)(x / MAX_LENGTH * 10);
    if (position < 0) position = 0;
    if (position >= MAX_LENGTH) position = MAX_LENGTH - 1;

    printf("\r");
    for (int i = 0; i < position; i++) {
        printf(" ");
    }
    printf("o");

    printf(" Time: %.2f s | X: %.2f m | Y: %.2f m ", t, x, y);
    fflush(stdout);
}

void simulate_projectile(double velocity, double angle) {
    double radian_angle = angle * (M_PI / 180.0);
    double vx = velocity * cos(radian_angle);
    double vy = velocity * sin(radian_angle);
    double time = 0.0;

    double x, y;
    printf("Simulating projectile motion...\n");
    
    while (time <= MAX_TIME) {
        x = vx * time;
        y = vy * time - 0.5 * G * time * time;

        if (y < 0) break; // stop if the projectile hits the ground

        print_trajectory(time, x, y);
        usleep(100000); // sleep for 100 ms
        time += TIME_INTERVAL;
    }
    printf("\nSimulation complete.\n");
}

int main() {
    double velocity, angle;

    printf("Enter initial velocity (m/s): ");
    scanf("%lf", &velocity);
    printf("Enter launch angle (degrees): ");
    scanf("%lf", &angle);

    if (velocity < 0 || angle < 0) {
        printf("Invalid input. Both velocity and angle must be non-negative.\n");
        return 1;
    }

    simulate_projectile(velocity, angle);

    return 0;
}