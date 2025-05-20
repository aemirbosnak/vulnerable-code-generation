//Falcon2-11B DATASET v1.0 Category: Planet Gravity Simulation ; Style: expert-level
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

// Structure to represent a planet
struct Planet {
    double mass;
    double radius;
    double position[3];
};

// Function to compute the gravitational force between two planets
double computeGravitationalForce(struct Planet* p1, struct Planet* p2) {
    double r1[3], r2[3], r12[3], force[3];
    double r1_mag, r2_mag, r12_mag, mag_force;

    // Compute distances between planets
    for (int i = 0; i < 3; i++) {
        r1[i] = p1->position[i] - p2->position[i];
        r2[i] = p2->position[i] - p1->position[i];
    }

    // Compute magnitudes of vectors r1 and r2
    r1_mag = sqrt(r1[0] * r1[0] + r1[1] * r1[1] + r1[2] * r1[2]);
    r2_mag = sqrt(r2[0] * r2[0] + r2[1] * r2[1] + r2[2] * r2[2]);

    // Compute magnitude of vector r12
    r12_mag = sqrt(r1[0] * r1[0] + r1[1] * r1[1] + r1[2] * r1[2]) + sqrt(r2[0] * r2[0] + r2[1] * r2[1] + r2[2] * r2[2]);

    // Compute gravitational force
    mag_force = (p1->mass * p2->mass) / pow(r12_mag, 2);

    // Normalize force vector
    for (int i = 0; i < 3; i++) {
        force[i] = mag_force * r12[i] / r12_mag;
    }

    return mag_force;
}

int main() {
    struct Planet planet1, planet2;

    printf("Enter mass of planet 1: ");
    scanf("%lf", &planet1.mass);
    printf("Enter radius of planet 1: ");
    scanf("%lf", &planet1.radius);

    printf("Enter mass of planet 2: ");
    scanf("%lf", &planet2.mass);
    printf("Enter radius of planet 2: ");
    scanf("%lf", &planet2.radius);

    printf("Enter position of planet 1 (x,y,z): ");
    scanf("%lf %lf %lf", &planet1.position[0], &planet1.position[1], &planet1.position[2]);

    printf("Enter position of planet 2 (x,y,z): ");
    scanf("%lf %lf %lf", &planet2.position[0], &planet2.position[1], &planet2.position[2]);

    // Compute gravitational force
    double force = computeGravitationalForce(&planet1, &planet2);

    // Print force
    printf("Gravitational force between planets 1 and 2: %lf\n", force);

    return 0;
}