//FormAI DATASET v1.0 Category: Physics simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <math.h>

#define g 9.81 // gravitational acceleration
#define rho 1.2 // air density
#define CD 0.45 // drag coefficient
#define A 0.01 // cross-sectional area of projectile

int main(void) {
    
    // input variables
    double v0, theta, m;
    printf("Enter initial velocity (m/s): ");
    scanf("%lf", &v0);
    printf("Enter launch angle (degrees): ");
    scanf("%lf", &theta);
    printf("Enter mass of projectile (kg): ");
    scanf("%lf", &m);
    
    // convert angle to radians
    theta = theta * M_PI / 180;
    
    // initial x- and y-coordinates
    double x = 0;
    double y = 0;
    
    // initial x- and y-velocities
    double vx = v0 * cos(theta);
    double vy = v0 * sin(theta);
    
    // time step
    double dt = 0.01;
    
    // simulation loop
    while (y >= 0) {
        
        // calculate air resistance
        double Fdrag = 0.5 * CD * rho * A * pow(vx*vx + vy*vy, 0.5) * (vx*vx + vy*vy);
        
        // calculate x- and y-accelerations
        double ax = -Fdrag/m * vx / pow(vx*vx + vy*vy, 0.5);
        double ay = -g - Fdrag/m * vy / pow(vx*vx + vy*vy, 0.5);
        
        // update velocities and positions
        vx += ax * dt;
        vy += ay * dt;
        x += vx * dt;
        y += vy * dt;
        
        // print position
        printf("t=%.2f x=%.2f y=%.2f\n", y/vy, x, y);
    }
    
    return 0;
}