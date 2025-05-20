//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Donald Knuth
#include <stdio.h>

// Constants for calculations
#define G 6.6743E-11   // gravitational constant
#define M_sun 1.989E30 // mass of the sun in kg

// Struct for holding planet data
typedef struct {
    char name[20];     // planet name
    double mass;       // planet mass in kg
    double radius;     // planet radius in m
    double distance;   // distance from sun in m
    double x, y, z;    // current position in 3D space
    double vx, vy, vz; // current velocity in 3D space
} planet_t;

// Function to initialize planet data
void initialize_planet(planet_t *planet, char *name, double mass, double radius, double distance);

// Function to calculate gravitational force between two planets
void calculate_force(planet_t *planet1, planet_t *planet2, double *fx, double *fy, double *fz);

// Main function
int main(void) {
    // Define planets
    planet_t sun, mercury, venus, earth, mars, jupiter, saturn, uranus, neptune;
    
    // Initialize planets
    initialize_planet(&sun, "Sun", M_sun, 696340E3, 0);
    initialize_planet(&mercury, "Mercury", 3.285E23, 2439.7E3, 57.9E9);
    initialize_planet(&venus, "Venus", 4.867E24, 6051.8E3, 108.2E9);
    initialize_planet(&earth, "Earth", 5.972E24, 6371.0E3, 149.6E9);
    initialize_planet(&mars, "Mars", 6.39E23, 3389.5E3, 227.9E9);
    initialize_planet(&jupiter, "Jupiter", 1.898E27, 69911E3, 778.3E9);
    initialize_planet(&saturn, "Saturn", 5.683E26, 58232E3, 1427.0E9);
    initialize_planet(&uranus, "Uranus", 8.681E25, 25362E3, 2871.0E9);
    initialize_planet(&neptune, "Neptune", 1.024E26, 24622E3, 4497.1E9);

    // Define simulation parameters
    double dt = 3600 * 24 * 365; // time step in seconds (one year)
    double t = 0;                // current time in seconds
    
    // Simulation loop
    while (1) {
        // Calculate forces on each planet
        double fx, fy, fz;
        calculate_force(&mercury, &sun, &fx, &fy, &fz);
        mercury.vx += fx / mercury.mass * dt;
        mercury.vy += fy / mercury.mass * dt;
        mercury.vz += fz / mercury.mass * dt;

        calculate_force(&venus, &sun, &fx, &fy, &fz);
        venus.vx += fx / venus.mass * dt;
        venus.vy += fy / venus.mass * dt;
        venus.vz += fz / venus.mass * dt;

        calculate_force(&earth, &sun, &fx, &fy, &fz);
        earth.vx += fx / earth.mass * dt;
        earth.vy += fy / earth.mass * dt;
        earth.vz += fz / earth.mass * dt;

        calculate_force(&mars, &sun, &fx, &fy, &fz);
        mars.vx += fx / mars.mass * dt;
        mars.vy += fy / mars.mass * dt;
        mars.vz += fz / mars.mass * dt;

        calculate_force(&jupiter, &sun, &fx, &fy, &fz);
        jupiter.vx += fx / jupiter.mass * dt;
        jupiter.vy += fy / jupiter.mass * dt;
        jupiter.vz += fz / jupiter.mass * dt;

        calculate_force(&saturn, &sun, &fx, &fy, &fz);
        saturn.vx += fx / saturn.mass * dt;
        saturn.vy += fy / saturn.mass * dt;
        saturn.vz += fz / saturn.mass * dt;

        calculate_force(&uranus, &sun, &fx, &fy, &fz);
        uranus.vx += fx / uranus.mass * dt;
        uranus.vy += fy / uranus.mass * dt;
        uranus.vz += fz / uranus.mass * dt;

        calculate_force(&neptune, &sun, &fx, &fy, &fz);
        neptune.vx += fx / neptune.mass * dt;
        neptune.vy += fy / neptune.mass * dt;
        neptune.vz += fz / neptune.mass * dt;

        // Update positions of each planet
        mercury.x += mercury.vx * dt;
        mercury.y += mercury.vy * dt;
        mercury.z += mercury.vz * dt;

        venus.x += venus.vx * dt;
        venus.y += venus.vy * dt;
        venus.z += venus.vz * dt;

        earth.x += earth.vx * dt;
        earth.y += earth.vy * dt;
        earth.z += earth.vz * dt;

        mars.x += mars.vx * dt;
        mars.y += mars.vy * dt;
        mars.z += mars.vz * dt;

        jupiter.x += jupiter.vx * dt;
        jupiter.y += jupiter.vy * dt;
        jupiter.z += jupiter.vz * dt;

        saturn.x += saturn.vx * dt;
        saturn.y += saturn.vy * dt;
        saturn.z += saturn.vz * dt;

        uranus.x += uranus.vx * dt;
        uranus.y += uranus.vy * dt;
        uranus.z += uranus.vz * dt;

        neptune.x += neptune.vx * dt;
        neptune.y += neptune.vy * dt;
        neptune.z += neptune.vz * dt;

        // Print position of Earth every year
        if ((int)t % (3600 * 24 * 365) == 0) {
            printf("Year: %d\n", (int)t / (3600 * 24 * 365));
            printf("Earth position: (%f, %f, %f)\n", earth.x, earth.y, earth.z);
            printf("\n");
        }
        
        t += dt; // increment time
    }
}

void initialize_planet(planet_t *planet, char *name, double mass, double radius, double distance) {
    planet->mass = mass;
    planet->radius = radius;
    planet->distance = distance;
    planet->x = distance;
    planet->y = 0;
    planet->z = 0;
    planet->vx = 0;
    planet->vy = sqrt(G * M_sun / distance);
    planet->vz = 0;
}

void calculate_force(planet_t *planet1, planet_t *planet2, double *fx, double *fy, double *fz) {
    double dx = planet2->x - planet1->x;
    double dy = planet2->y - planet1->y;
    double dz = planet2->z - planet1->z;
    double d = sqrt(dx * dx + dy * dy + dz * dz);
    double f = G * planet1->mass * planet2->mass / (d * d);

    *fx = f * dx / d;
    *fy = f * dy / d;
    *fz = f * dz / d;
}