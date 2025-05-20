//FormAI DATASET v1.0 Category: Physics simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants
#define PI 3.14159265359
#define G 9.81

// Define structure for particle
typedef struct {
    double mass;    // Mass of particle in kg
    double x;       // X-coordinate of particle in m
    double y;       // Y-coordinate of particle in m
    double vx;      // X-velocity of particle in m/s
    double vy;      // Y-velocity of particle in m/s
} particle;

int main() {
    // Declare variables
    particle ball;
    double time = 0.0, dt = 0.01, angle;

    // Get input from user
    printf("Enter the mass of the ball in kg: ");
    scanf("%lf", &ball.mass);

    printf("Enter the initial velocity of the ball in m/s: ");
    scanf("%lf", &ball.vx);

    printf("Enter the angle at which the ball is being thrown in degrees: ");
    scanf("%lf", &angle);

    // Convert angle to radians
    angle = angle * PI / 180.0;

    // Calculate initial values
    ball.x = 0.0;
    ball.y = 0.0;
    ball.vy = ball.vx * sin(angle);
    ball.vx = ball.vx * cos(angle);

    // Run simulation
    while (ball.y >= 0.0) {
        // Print values for current time
        printf("t = %.2lf s: x = %.2lf m, y = %.2lf m, vx = %.2lf m/s, vy = %.2lf m/s\n", time, ball.x, ball.y, ball.vx, ball.vy);

        // Update position and velocity
        ball.x = ball.x + ball.vx * dt;
        ball.y = ball.y + ball.vy * dt - 0.5 * G * pow(dt, 2);
        ball.vy = ball.vy - G * dt;
        
        // Increase time
        time = time + dt;
    }

    // Print final values
    printf("t = %.2lf s: x = %.2lf m, y = %.2lf m, vx = %.2lf m/s, vy = %.2lf m/s\n", time, ball.x, ball.y, ball.vx, ball.vy);
    printf("The ball landed after %.2lf seconds.\n", time);

    return 0;
}