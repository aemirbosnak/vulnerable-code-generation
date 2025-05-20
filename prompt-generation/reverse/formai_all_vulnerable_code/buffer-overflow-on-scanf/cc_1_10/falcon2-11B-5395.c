//Falcon2-11B DATASET v1.0 Category: Planet Gravity Simulation ; Style: enthusiastic
#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j, k;
    double x[100], y[100], z[100], r[100], g[100], a[100], t, d, dt, r0, g0, a0;
    double pi = 3.14159265358979323846;

    printf("Enter the number of particles: ");
    scanf("%d", &n);

    printf("Enter the x, y, z coordinates of the particles: ");
    for (i = 0; i < n; i++) {
        scanf("%lf%lf%lf", &x[i], &y[i], &z[i]);
    }

    printf("Enter the initial velocity components: ");
    for (i = 0; i < n; i++) {
        scanf("%lf%lf%lf", &r[i], &g[i], &a[i]);
    }

    printf("Enter the initial distance between particles: ");
    scanf("%lf", &r0);

    printf("Enter the initial acceleration due to gravity: ");
    scanf("%lf", &g0);

    printf("Enter the initial acceleration due to friction: ");
    scanf("%lf", &a0);

    dt = 0.001;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            t = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]) + (z[i] - z[j])*(z[i] - z[j]));
            d = t - r0;

            if (d > 0) {
                d = r0 + d;
            }

            r[i] += (g0 * d - a0 * d * t) / (1.0 + a0 * t);
            g[i] += (r0 * g0 - a0 * d * t) / (1.0 + a0 * t);
            a[i] += (r0 * a0 - g0 * d * t) / (1.0 + a0 * t);

            r[j] += (g0 * d - a0 * d * t) / (1.0 + a0 * t);
            g[j] += (r0 * g0 - a0 * d * t) / (1.0 + a0 * t);
            a[j] += (r0 * a0 - g0 * d * t) / (1.0 + a0 * t);

            r0 += d;
        }
    }

    printf("Position of particle %d (x, y, z): %lf, %lf, %lf\n", i, x[i], y[i], z[i]);
    printf("Velocity of particle %d (r, g, a): %lf, %lf, %lf\n", i, r[i], g[i], a[i]);

    return 0;
}