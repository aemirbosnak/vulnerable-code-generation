//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 10000
#define M 1000
#define DT 0.001
#define G 6.67408e-11

typedef struct {
    double x, y, z;
    double vx, vy, vz;
    double m;
} particle;

particle particles[N];

void initialize() {
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        particles[i].x = (2 * rand() / (double)RAND_MAX - 1) * M;
        particles[i].y = (2 * rand() / (double)RAND_MAX - 1) * M;
        particles[i].z = (2 * rand() / (double)RAND_MAX - 1) * M;
        particles[i].vx = 0;//(2 * rand() / (double)RAND_MAX - 1) * 100;
        particles[i].vy = 0;//(2 * rand() / (double)RAND_MAX - 1) * 100;
        particles[i].vz = 0;//(2 * rand() / (double)RAND_MAX - 1) * 100;
        particles[i].m = 1000;
    }
}

void update() {
    for (int i = 0; i < N; i++) {
        double ax = 0, ay = 0, az = 0;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            double dx = particles[i].x - particles[j].x;
            double dy = particles[i].y - particles[j].y;
            double dz = particles[i].z - particles[j].z;
            double r = sqrt(dx * dx + dy * dy + dz * dz);
            double f = G * particles[i].m * particles[j].m / (r * r * r);
            ax += f * dx / r;
            ay += f * dy / r;
            az += f * dz / r;
        }
        particles[i].vx += ax * DT;
        particles[i].vy += ay * DT;
        particles[i].vz += az * DT;
        particles[i].x += particles[i].vx * DT;
        particles[i].y += particles[i].vy * DT;
        particles[i].z += particles[i].vz * DT;
    }
}

void draw() {
    for (int i = 0; i < N; i++) {
        printf("%f %f %f\n", particles[i].x, particles[i].y, particles[i].z);
    }
}

int main() {
    initialize();
    for (int i = 0; i < 100000; i++) {
        update();
        draw();
    }
    return 0;
}