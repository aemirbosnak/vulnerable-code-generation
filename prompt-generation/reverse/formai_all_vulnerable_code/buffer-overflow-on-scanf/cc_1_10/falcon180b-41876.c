//Falcon-180B DATASET v1.0 Category: Planet Gravity Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11
#define PI 3.14159265358979323846

struct planet {
    double mass;
    double x;
    double y;
    double vx;
    double vy;
};

void update(struct planet *p, int n) {
    int i;
    for (i = 0; i < n; i++) {
        double ax = 0;
        double ay = 0;
        int j;
        for (j = 0; j < n; j++) {
            if (i!= j) {
                double dx = p[j].x - p[i].x;
                double dy = p[j].y - p[i].y;
                double r = sqrt(dx*dx + dy*dy);
                ax += dx * p[j].mass / (r*r*r);
                ay += dy * p[j].mass / (r*r*r);
            }
        }
        p[i].vx += ax * G;
        p[i].vy += ay * G;
        p[i].x += p[i].vx;
        p[i].y += p[i].vy;
    }
}

void draw(struct planet *p, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%.2f, %.2f\n", p[i].x, p[i].y);
    }
}

int main() {
    int n;
    printf("Enter number of planets: ");
    scanf("%d", &n);
    struct planet *p = malloc(sizeof(struct planet) * n);
    printf("Enter mass and position of each planet:\n");
    int i;
    for (i = 0; i < n; i++) {
        scanf("%lf %lf", &p[i].mass, &p[i].x);
        p[i].y = 0;
        p[i].vx = 0;
        p[i].vy = 0;
    }
    while (1) {
        draw(p, n);
        update(p, n);
        system("clear");
    }
    return 0;
}