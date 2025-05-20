//Falcon2-11B DATASET v1.0 Category: Planet Gravity Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int i, j, k, n;
    double m, r, x, y, z, g, vx, vy, vz, t, m2, r2, r3, vx2, vy2, vz2, vx3, vy3, vz3;

    printf("Welcome to the Romeo and Juliet C Planet Gravity Simulation!\n");
    printf("Please enter the number of planets: ");
    scanf("%d", &n);

    m = 0.0;
    r = 0.0;
    vx = 0.0;
    vy = 0.0;
    vz = 0.0;
    g = 9.81;

    for (i = 0; i < n; i++) {
        printf("Enter the mass of planet %d: ", i + 1);
        scanf("%lf", &m);
        printf("Enter the radius of planet %d: ", i + 1);
        scanf("%lf", &r);
        printf("Enter the x-velocity of planet %d: ", i + 1);
        scanf("%lf", &vx);
        printf("Enter the y-velocity of planet %d: ", i + 1);
        scanf("%lf", &vy);
        printf("Enter the z-velocity of planet %d: ", i + 1);
        scanf("%lf", &vz);

        m2 = 0.0;
        r2 = 0.0;
        r3 = 0.0;
        vx2 = 0.0;
        vy2 = 0.0;
        vz2 = 0.0;
        vx3 = 0.0;
        vy3 = 0.0;
        vz3 = 0.0;

        for (j = 0; j < n; j++) {
            if (j!= i) {
                m2 = m + m;
                r2 = r + r;
                r3 = sqrt(r2);
                vx2 = vx * m / r2;
                vy2 = vy * m / r2;
                vz2 = vz * m / r2;
                vx3 = vx * m2 / r3;
                vy3 = vy * m2 / r3;
                vz3 = vz * m2 / r3;

                printf("Planet %d has a gravitational force of %.2lf m/s^2 towards planet %d\n", i + 1, vx2 / r2, j + 1);
                printf("Planet %d has a gravitational force of %.2lf m/s^2 towards planet %d\n", j + 1, vx3 / r3, i + 1);
            }
        }
    }

    return 0;
}