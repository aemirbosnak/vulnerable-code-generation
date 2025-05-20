//Falcon-180B DATASET v1.0 Category: Planet Gravity Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11
#define PI 3.14159265358979323846

struct Planet {
    double x, y, z, vx, vy, vz, mass, radius;
};

void update(struct Planet *p, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i!= j) {
                double dx = p[j].x - p[i].x;
                double dy = p[j].y - p[i].y;
                double dz = p[j].z - p[i].z;
                double r = sqrt(dx * dx + dy * dy + dz * dz);
                double f = G * p[i].mass * p[j].mass / (r * r);
                p[i].vx += dx * f;
                p[i].vy += dy * f;
                p[i].vz += dz * f;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        p[i].x += p[i].vx;
        p[i].y += p[i].vy;
        p[i].z += p[i].vz;
    }
}

void draw(struct Planet *p, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f %.2f %.2f\n", p[i].x / 100, p[i].y / 100, p[i].z / 100);
    }
}

int main() {
    int n;
    printf("Enter the number of planets: ");
    scanf("%d", &n);
    struct Planet *p = malloc(n * sizeof(struct Planet));
    for (int i = 0; i < n; i++) {
        printf("Enter the mass of planet %d: ", i + 1);
        scanf("%lf", &p[i].mass);
        printf("Enter the radius of planet %d: ", i + 1);
        scanf("%lf", &p[i].radius);
        p[i].x = rand() % 1000 - 500;
        p[i].y = rand() % 1000 - 500;
        p[i].z = rand() % 1000 - 500;
        p[i].vx = (rand() % 100 - 50) / 50.0;
        p[i].vy = (rand() % 100 - 50) / 50.0;
        p[i].vz = (rand() % 100 - 50) / 50.0;
    }
    int t = 0;
    while (1) {
        draw(p, n);
        update(p, n);
        t++;
        if (t % 100 == 0) {
            printf("\n");
        }
    }
    return 0;
}