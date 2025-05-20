//FormAI DATASET v1.0 Category: Physics simulation ; Style: future-proof
#include <stdio.h>
#include <math.h>

// Declare universal constants
#define K 9e9
#define PI 3.14159265358979323846

// Define structure for charge object
typedef struct {
    double x, y;  // Position
    double q;     // Charge
} Charge;

// Calculate electric force between two charges
double electric_force(Charge charge1, Charge charge2) {
    double dx = charge2.x - charge1.x;
    double dy = charge2.y - charge1.y;
    double r = hypot(dx, dy);
    double f = K * charge1.q * charge2.q / (r * r);
    return f;
}

// Calculate net electric force on a charge from a list of charges
double net_electric_force(Charge target, Charge* charges, int n) {
    double fx = 0, fy = 0;
    for (int i = 0; i < n; i++) {
        if (charges[i].x == target.x && charges[i].y == target.y) {
            continue;  // Skip self
        }
        double f = electric_force(target, charges[i]);
        double dx = charges[i].x - target.x;
        double dy = charges[i].y - target.y;
        double theta = atan2(dy, dx);
        fx += f * cos(theta);
        fy += f * sin(theta);
    }
    return hypot(fx, fy);
}

int main() {
    // Declare array of charge objects
    Charge charges[] = {
        {2, 2, 1},
        {-2, -2, -1},
        {-2, 2, 1},
        {2, -2, -1},
        {0, 0, 2},
        {0, 3, -1},
        {3, 0, -1},
        {0, -3, 1},
        {-3, 0, 1}
    };
    int n = sizeof(charges) / sizeof(charges[0]);

    // Simulate charged particle moving through electric field
    Charge particle = {0, 0, 1};
    double vx = 5, vy = -5;
    double dt = 0.01;
    double t = 0;
    printf("t\tp.x\tp.y\n");
    while (t < 10) {
        // Calculate net force on particle
        double f = net_electric_force(particle, charges, n);
        double theta = atan2(vy, vx);
        double fx = f * cos(theta);
        double fy = f * sin(theta);

        // Update particle position and velocity
        double ax = fx / particle.q;
        double ay = fy / particle.q;
        particle.x += vx * dt + 0.5 * ax * dt * dt;
        particle.y += vy * dt + 0.5 * ay * dt * dt;
        vx += ax * dt;
        vy += ay * dt;

        // Print particle position
        printf("%.2f\t%.2f\t%.2f\n", t, particle.x, particle.y);
        t += dt;
    }
    return 0;
}