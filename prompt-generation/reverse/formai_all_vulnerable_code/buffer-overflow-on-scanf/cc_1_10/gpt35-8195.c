//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: single-threaded
#include <stdio.h>
#include <math.h>
#define PI 3.14159

struct planet {
    char name[20];
    double mass;    //in kg
    double radius;  //in meters
    double period;  //in seconds
    double distance;//in meters
    double theta;   //in radians
    double x;       //in meters
    double y;       //in meters
    double vx;      //in meters per second
    double vy;      //in meters per second
} planets[] = {
    {"Sun", 1.989e30, 696340000, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
    {"Mercury", 3.301e23, 2439700, 87.9691*86400, 57910000000, 0.0, 0.0, 0.0, 0.0, 0.0},
    {"Venus", 4.867e24, 6051800, 224.701*86400, 108200000000, 0.0, 0.0, 0.0, 0.0, 0.0},
    {"Earth", 5.972e24, 6371000, 365.256*86400, 149600000000, 0.0, 0.0, 0.0, 0.0, 0.0},
    {"Mars", 6.417e23, 3389500, 686.971*86400, 227940000000, 0.0, 0.0, 0.0, 0.0, 0.0},
    {"Jupiter", 1.898e27, 69911000, 4332.59*86400, 778330000000, 0.0, 0.0, 0.0, 0.0, 0.0},
    {"Saturn", 5.683e26, 58232000, 10759.22*86400, 1429400000000, 0.0, 0.0, 0.0, 0.0, 0.0},
    {"Uranus", 8.681e25, 25362000, 30685.4*86400, 2870990000000, 0.0, 0.0, 0.0, 0.0, 0.0},
    {"Neptune", 1.024e26, 24622000, 60189*86400, 4498400000000, 0.0, 0.0, 0.0, 0.0, 0.0}
};

int main()
{
    const double G = 6.67430e-11;
    const int steps = 500000;
    const double time_step = 86400;

    for (int i = 0; i < sizeof(planets) / sizeof(struct planet); i++) {
        scanf("%s", planets[i].name);
    }

    for (int i = 0; i < sizeof(planets) / sizeof(struct planet); i++) {
        printf("Enter mass of %s (in kg): ", planets[i].name);
        scanf("%lf", &planets[i].mass);
        printf("Enter radius of %s (in meters): ", planets[i].name);
        scanf("%lf", &planets[i].radius);
        printf("Enter period of %s (in seconds): ", planets[i].name);
        scanf("%lf", &planets[i].period);
        printf("Enter distance of %s from Sun (in meters): ", planets[i].name);
        scanf("%lf", &planets[i].distance);
        printf("Enter angle of %s from x-axis (in degrees): ", planets[i].name);
        scanf("%lf", &planets[i].theta);
        planets[i].theta *= PI / 180.0;
        planets[i].x = planets[i].distance * cos(planets[i].theta);
        planets[i].y = planets[i].distance * sin(planets[i].theta);
        double v_circular = sqrt(G * planets[0].mass / planets[i].distance);
        planets[i].vx = -v_circular * sin(planets[i].theta);
        planets[i].vy = v_circular * cos(planets[i].theta);
    }

    for (int k = 0; k < steps; k++) {
        for (int i = 1; i < sizeof(planets) / sizeof(struct planet); i++) {
            double ax = 0.0, ay = 0.0;
            for (int j = 0; j < sizeof(planets) / sizeof(struct planet); j++) {
                if (i != j) {
                    double dx = planets[j].x - planets[i].x;
                    double dy = planets[j].y - planets[i].y;
                    double r = sqrt(dx * dx + dy * dy);
                    double f = G * planets[i].mass * planets[j].mass / (r * r);
                    ax += f / planets[i].mass * dx / r;
                    ay += f / planets[i].mass * dy / r;
                }
            }
            planets[i].vx += ax * time_step;
            planets[i].vy += ay * time_step;
        }
        for (int i = 1; i < sizeof(planets) / sizeof(struct planet); i++) {
            planets[i].x += planets[i].vx * time_step;
            planets[i].y += planets[i].vy * time_step;
        }
    }
    for (int i = 0; i < sizeof(planets) / sizeof(struct planet); i++) {
        printf("%s: (%.2f, %.2f)\n", planets[i].name, planets[i].x, planets[i].y);
    }
    return 0;
}