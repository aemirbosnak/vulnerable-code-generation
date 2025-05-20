//FormAI DATASET v1.0 Category: Physics simulation ; Style: light-weight
#include <stdio.h>
#include <math.h>

#define GRAVITY 9.8 // gravitational constant
#define DELTA_TIME 0.1 // time interval between each frame

int main() {
    double initialHeight, initialVelocity, angle; // user inputs
    double time = 0; // keep track of time
    double x, y; // position of the projectile
    double vx, vy; // velocity of the projectile
    double ax, ay; // acceleration of the projectile

    // get user inputs
    printf("Enter initial height (m): ");
    scanf("%lf", &initialHeight);
    printf("Enter initial velocity (m/s): ");
    scanf("%lf", &initialVelocity);
    printf("Enter angle of projection (degrees): ");
    scanf("%lf", &angle);

    // convert angle to radians
    angle = angle * M_PI / 180;

    // calculate initial velocity vector components
    vx = initialVelocity * cos(angle);
    vy = initialVelocity * sin(angle);

    // calculate initial position
    x = 0;
    y = initialHeight;

    // loop through each frame
    while (y >= 0) {
        // calculate acceleration components
        ax = 0;
        ay = -GRAVITY;

        // calculate new velocity components
        vx += ax * DELTA_TIME;
        vy += ay * DELTA_TIME;

        // calculate new position
        x += vx * DELTA_TIME;
        y += vy * DELTA_TIME;

        // increment time
        time += DELTA_TIME;

        // print current position and time
        printf("x = %.2f m\t y = %.2f m\t t = %.2f s\n", x, y, time);
    }

    printf("Projectile landed after %.2f seconds.\n", time);

    return 0;
}