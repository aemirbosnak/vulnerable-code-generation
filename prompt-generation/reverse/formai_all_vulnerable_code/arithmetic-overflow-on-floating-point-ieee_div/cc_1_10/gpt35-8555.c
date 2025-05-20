//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11  // gravitational constant

struct planet {
    char name[20];
    double mass;
    double x, y, z;
    double vx, vy, vz;
};

double distance(struct planet p1, struct planet p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
}

double acceleration(struct planet p1, struct planet p2) {
    double r = distance(p1, p2);
    return G * p2.mass / pow(r, 2);
}

void update_velocity(struct planet *p1, struct planet *p2, double dt) {
    double a = acceleration(*p1, *p2);
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;
    double r = distance(*p1, *p2);
    p1->vx += a * dx / r * dt;
    p1->vy += a * dy / r * dt;
    p1->vz += a * dz / r * dt;
}

void update_position(struct planet *p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

int main() {
    struct planet planets[3] = {
        {"Earth", 5.97e24, 0, 0, 0, 0, 0, 0},
        {"Moon", 7.34e22, 0, 384400000, 0, 1022, 0, 0},
        {"Sun", 1.989e30, 0, 0, 0, 0, 0, 0}
    };
    // initialize positions and velocities
    planets[0].x = 149600000000;
    planets[0].vy = 29783;
    planets[1].x = 149600000000;
    planets[1].y += planets[0].y - 384400000;
    planets[1].vy += planets[0].vy;
    
    double dt = 3600;  // time step in seconds
    double t = 0;  // current time in seconds
    double duration = 365 * 24 * 3600;  // one year

    while (t < duration) {
        // update velocities and positions
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i != j) {
                    update_velocity(&planets[i], &planets[j], dt);
                }
            }
            update_position(&planets[i], dt);
        }
        t += dt;
    }

    // print final positions
    for (int i = 0; i < 3; i++) {
        printf("%s: (%.2f, %.2f, %.2f)\n", planets[i].name, planets[i].x, planets[i].y, planets[i].z);
    }

    return 0;
}