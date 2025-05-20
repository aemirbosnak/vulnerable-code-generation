//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants
#define G 6.67430E-11 // gravitational constant in m3 kg-1 s-2
#define AU 1.496E+11 // astronomical unit in meters
#define YEAR 31536000 // length of year in seconds

// Define planet struct
typedef struct Planet {
    char name[20];
    double mass;
    double radius;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} Planet;

// Define function to calculate distance between two planets
double distance(Planet one, Planet two) {
    double dx = one.x - two.x;
    double dy = one.y - two.y;
    double dz = one.z - two.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

// Define function to calculate gravitational force between two planets
double force(Planet one, Planet two) {
    double dist = distance(one, two);
    return (G * one.mass * two.mass) / (dist * dist);
}

// Define function to update velocities of all planets due to gravitational force
void updateVelocities(Planet *planets, int numPlanets) {
    for (int i = 0; i < numPlanets; i++) {
        double ax = 0;
        double ay = 0;
        double az = 0;
        for (int j = 0; j < numPlanets; j++) {
            if (i != j) {
                double f = force(planets[i], planets[j]);
                double dist = distance(planets[i], planets[j]);
                double fx = f * (planets[j].x - planets[i].x) / dist;
                double fy = f * (planets[j].y - planets[i].y) / dist;
                double fz = f * (planets[j].z - planets[i].z) / dist;
                ax += fx / planets[i].mass;
                ay += fy / planets[i].mass;
                az += fz / planets[i].mass;
            }
        }
        planets[i].vx += ax * YEAR;
        planets[i].vy += ay * YEAR;
        planets[i].vz += az * YEAR;
    }
}

// Define function to update positions of all planets
void updatePositions(Planet *planets, int numPlanets) {
    for (int i = 0; i < numPlanets; i++) {
        planets[i].x += planets[i].vx * YEAR;
        planets[i].y += planets[i].vy * YEAR;
        planets[i].z += planets[i].vz * YEAR;
    }
}

// Define function to simulate solar system motion for a given number of years
void simulateSolarSystem(Planet *planets, int numPlanets, double years) {
    double totalTime = 0;
    while (totalTime < years * YEAR) {
        updateVelocities(planets, numPlanets);
        updatePositions(planets, numPlanets);
        totalTime += YEAR;
    }
}

int main() {
    // Define planets in the solar system
    Planet sun = {"Sun", 1.989E+30, 696340000, 0, 0, 0, 0, 0, 0};
    Planet mercury = {"Mercury", 3.285E+23, 2440000, 0, 57909000, 0, 47890, 0, 0};
    Planet venus = {"Venus", 4.867E+24, 6051800, 0, 108160000, 0, 35000, 0, 0};
    Planet earth = {"Earth", 5.972E+24, 6371000, 0, 149600000, 0, 29783, 0, 0};
    Planet mars = {"Mars", 6.390E+23, 3397000, 0, 227940000, 0, 24077, 0, 0};
    Planet jupiter = {"Jupiter", 1.898E+27, 69911000, 0, 778330000, 0, 13070, 0, 0};
    Planet saturn = {"Saturn", 5.683E+26, 58232000, 0, 1429400000, 0, 9690, 0, 0};
    Planet uranus = {"Uranus", 8.681E+25, 25362000, 0, 2870990000, 0, 6800, 0, 0};
    Planet neptune = {"Neptune", 1.024E+26, 24622000, 0, 4498400000, 0, 5477, 0, 0};

    Planet planets[] = {sun, mercury, venus, earth, mars, jupiter, saturn, uranus, neptune};
    int numPlanets = sizeof(planets) / sizeof(planets[0]);

    // Simulate solar system motion for 1 year
    simulateSolarSystem(planets, numPlanets, 1);

    // Print final positions of all planets
    for (int i = 0; i < numPlanets; i++) {
        printf("%s - x:%f y:%f z:%f\n", planets[i].name, planets[i].x/AU, planets[i].y/AU, planets[i].z/AU);
    }

    return 0;
}