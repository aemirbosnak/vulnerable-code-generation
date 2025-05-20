//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: multivariable
#include <stdio.h>
#include <math.h>

#define G 6.67408E-11 // Gravitational constant
#define TIME_STEP 10 // Time step in seconds

// Structure to store vector components
typedef struct {
    double x;
    double y;
    double z;
} Vector;

// Structure to store planet properties
typedef struct {
    char name[20];
    double mass;
    Vector position;
    Vector velocity;
} Planet;

// Function to calculate distance between two planets
double distance(Planet p1, Planet p2) {
    double dx = p1.position.x - p2.position.x;
    double dy = p1.position.y - p2.position.y;
    double dz = p1.position.z - p2.position.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

// Function to calculate gravitational force between two planets
Vector gravity(Planet p1, Planet p2) {
    double r = distance(p1, p2);
    double f = (G * p1.mass * p2.mass) / (r*r);
    Vector dir = {p2.position.x - p1.position.x, p2.position.y - p1.position.y, p2.position.z - p1.position.z};
    double mag = sqrt(dir.x*dir.x + dir.y*dir.y + dir.z*dir.z);
    dir.x /= mag;
    dir.y /= mag;
    dir.z /= mag;
    Vector force = {dir.x * f, dir.y * f, dir.z * f};
    return force;
}

// Function to update planet position and velocity based on gravitational forces
void update(Planet *p, Planet *planets, int n) {
    Vector net_force = {0.0, 0.0, 0.0};
    for (int i = 0; i < n; i++) {
        if (p != &planets[i]) {
            net_force.x += gravity(*p, planets[i]).x;
            net_force.y += gravity(*p, planets[i]).y;
            net_force.z += gravity(*p, planets[i]).z;
        }
    }
    double ax = net_force.x / p->mass;
    double ay = net_force.y / p->mass;
    double az = net_force.z / p->mass;
    p->velocity.x += ax * TIME_STEP;
    p->velocity.y += ay * TIME_STEP;
    p->velocity.z += az * TIME_STEP;
    p->position.x += p->velocity.x * TIME_STEP;
    p->position.y += p->velocity.y * TIME_STEP;
    p->position.z += p->velocity.z * TIME_STEP;
}

int main() {
    // Define planets
    Planet sun = {"Sun", 1.989E+30, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};
    Planet earth = {"Earth", 5.97E+24, {1.4710E+11, 0.0, 0.0}, {0.0, 30290.0, 0.0}};
    Planet mars = {"Mars", 6.39E+23, {0.0, 2.279E+11, 0.0}, {-24007.0, 0.0, 0.0}};
    Planet venus = {"Venus", 4.87E+24, {-1.0758E+11, 0.0, 0.0}, {0.0, -35020.0, 0.0}};
    Planet planets[4] = {sun, earth, mars, venus};
    int n = 4;

    // Run simulation for 1 year
    int seconds_in_year = 365*24*60*60;
    int steps = seconds_in_year / TIME_STEP; 
    for (int i = 0; i < steps; i++) {
        for (int j = 0; j < n; j++) {
            update(&planets[j], planets, n);
        }
    }

    // Print final positions of planets
    for (int i = 0; i < n; i++) {
        printf("%s position: %.2f, %.2f, %.2f\n", planets[i].name, planets[i].position.x, planets[i].position.y, planets[i].position.z);
    }

    return 0;
}