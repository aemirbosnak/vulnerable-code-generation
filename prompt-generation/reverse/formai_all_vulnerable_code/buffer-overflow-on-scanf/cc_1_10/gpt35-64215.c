//FormAI DATASET v1.0 Category: Physics simulation ; Style: inquisitive
#include <stdio.h>
#include <math.h>

int main() {
    // In this physics simulation program, we will simulate the motion of a ball thrown in the air with air resistance.

    // First, we will define some constants.
    const double g = 9.81; // gravitational acceleration
    const double rho = 1.23; // density of air
    const double C = 0.47; // drag coefficient
    const double A = 0.003; // cross-sectional area of the ball
    const double m = 0.2; // mass of the ball

    // Next, we will prompt the user to enter the initial velocity of the ball.
    printf("Enter the initial velocity of the ball in m/s: ");
    double v_0;
    scanf("%lf", &v_0);

    // We will also prompt the user to enter the angle at which the ball is thrown.
    printf("Enter the angle at which the ball is thrown in degrees: ");
    double theta;
    scanf("%lf", &theta);

    // We will convert the angle from degrees to radians.
    theta = theta * M_PI / 180;

    // Now, we will initialize some variables for our simulation.
    double t = 0; // time
    double x = 0; // horizontal distance
    double y = 0; // height
    double vy = v_0 * sin(theta); // vertical velocity
    double vx = v_0 * cos(theta); // horizontal velocity
    double F_d, a, v, v_prev, delta_t = 0.01; // drag force, acceleration, velocity, previous velocity, time step

    // We will loop until the ball hits the ground.
    while (y >= 0) {
        // Calculate the drag force.
        F_d = 0.5 * rho * pow(vx, 2) * C * A;

        // Calculate the net force.
        double F_net = -F_d - m * g;

        // Calculate the acceleration.
        a = F_net / m;

        // Calculate the new velocity.
        v = vy + a * delta_t;

        // Calculate the average velocity.
        double v_avg = (v + vy) / 2;

        // Calculate the new position.
        y = y + v_avg * delta_t;
        x = x + vx * delta_t;

        // Print the position of the ball.
        printf("t=%.2fs\tx=%.2fm\ty=%.2fm\n", t, x, y);

        // Update the velocity.
        vy = v;
        vx = vx;

        // Update the time.
        t = t + delta_t;
    }

    // Print the total time of the simulation.
    printf("The ball hit the ground after %.2f seconds.\n", t);

    return 0;
}