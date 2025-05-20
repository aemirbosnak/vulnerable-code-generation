//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: systematic
#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

struct Body {
    char* name;
    double mass;
    double radius;
    double x;
    double y;
    double vx;
    double vy;
};

double getDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

double getForce(double m1, double m2, double distance) {
    double G = 6.674e-11;
    return G * ((m1 * m2) / pow(distance, 2));
}

void updateVelocity(struct Body* body1, struct Body* body2, double forceX, double forceY, double time) {
    double x1 = body1->x;
    double y1 = body1->y;
    double x2 = body2->x;
    double y2 = body2->y;
    double distance = getDistance(x1, y1, x2, y2);
    double force = getForce(body1->mass, body2->mass, distance);
    forceX += force * ((x2 - x1) / distance);
    forceY += force * ((y2 - y1) / distance);
    body1->vx += forceX * time / body1->mass;
    body1->vy += forceY * time / body1->mass;
}

void simulate(struct Body* bodies, int numBodies, double time, int numSteps) {
    for (int step = 0; step < numSteps; step++) {
        for (int i = 0; i < numBodies; i++) {
            double forceX = 0;
            double forceY = 0;
            for (int j = 0; j < numBodies; j++) {
                if (i == j) continue;
                updateVelocity(&bodies[i], &bodies[j], forceX, forceY, time);
            }
        }
        for (int i = 0; i < numBodies; i++) {
            bodies[i].x += bodies[i].vx * time;
            bodies[i].y += bodies[i].vy * time;
            printf("%s: \t x = %.3f \t y = %.3f \n", bodies[i].name, bodies[i].x, bodies[i].y);
        }
        printf("\n");
    }
}

int main() {
    struct Body bodies[] = {
        {"Sun", 1.989e+30, 696340, 0, 0, 0, 0},
        {"Earth", 5.972e+24, 6371, 1.496e+11, 0, 0, 29790},
        {"Moon", 7.342e+22, 1737, 1.496e+11 + 384400000, 0, 0, 3070}
    };
    int numBodies = sizeof(bodies) / sizeof(bodies[0]);
    double time = 60 * 60 * 24;
    int numSteps = 365;
    simulate(bodies, numBodies, time, numSteps);
    return 0;
}