//GEMINI-pro DATASET v1.0 Category: Simulation of the Solar System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67e-11
#define DT 3600

typedef struct {
    double m;
    double r[3];
    double v[3];
} Body;

Body bodies[] = {
    {1.989e30, {0, 0, 0}, {0, 0, 0}},
    {5.972e24, {0.387e12, 0, 0}, {0, 30e3, 0}},
    {7.348e22, {-0.723e12, 0, 0}, {0, 24e3, 0}},
    {1.899e27, {-1.433e12, 0, 0}, {0, 20e3, 0}},
    {5.685e26, {-2.28e12, 0, 0}, {0, 16e3, 0}},
    {8.683e25, {-3.01e12, 0, 0}, {0, 13e3, 0}},
    {1.024e26, {-3.95e12, 0, 0}, {0, 9e3, 0}},
    {1.274e22, {-4.5e12, 0, 0}, {0, 7e3, 0}}
};

int main() {
    int i, j;
    double f[3], r, d;

    for (i = 0; i < 10000; i++) {
        for (j = 0; j < 8; j++) {
            f[0] = f[1] = f[2] = 0;
            for (int k = 0; k < 8; k++) {
                if (j != k) {
                    r = sqrt(pow(bodies[j].r[0] - bodies[k].r[0], 2) + pow(bodies[j].r[1] - bodies[k].r[1], 2) + pow(bodies[j].r[2] - bodies[k].r[2], 2));
                    d = r * r * r;
                    f[0] += G * bodies[k].m * (bodies[k].r[0] - bodies[j].r[0]) / d;
                    f[1] += G * bodies[k].m * (bodies[k].r[1] - bodies[j].r[1]) / d;
                    f[2] += G * bodies[k].m * (bodies[k].r[2] - bodies[j].r[2]) / d;
                }
            }

            bodies[j].v[0] += f[0] * DT;
            bodies[j].v[1] += f[1] * DT;
            bodies[j].v[2] += f[2] * DT;

            bodies[j].r[0] += bodies[j].v[0] * DT;
            bodies[j].r[1] += bodies[j].v[1] * DT;
            bodies[j].r[2] += bodies[j].v[2] * DT;
        }
    }

    return 0;
}