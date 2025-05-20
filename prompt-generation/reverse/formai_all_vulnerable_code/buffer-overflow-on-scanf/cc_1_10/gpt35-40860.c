//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: expert-level
#include <stdio.h>
#include <math.h>

#define G 6.674e-11  // Gravitational constant in SI units
#define DT 7200  // Time step in seconds
#define STEPS_PER_DAY 12  // Simulate 1 day with 12 time steps
#define SEC_PER_DAY 86400  // Number of seconds in a day

typedef struct vector {
    double x, y, z;
} vector;

typedef struct planet {
    char name[20];
    double mass;  // In kg
    vector position;  // In m
    vector velocity;  // In m/s
} planet;

int main() {
    int n;  // Number of planets
    printf("Enter the number of planets: ");
    scanf("%d", &n);
    planet planets[n];

    // Populate planet data
    for (int i = 0; i < n; i++) {
        printf("\nEnter the name of planet %d: ", i+1);
        scanf("%s", planets[i].name);
        printf("Enter the mass of planet %d (in kg): ", i+1);
        scanf("%lf", &planets[i].mass);
        printf("Enter the initial position of planet %d (in m):\n", i+1);
        printf("x: ");
        scanf("%lf", &planets[i].position.x);
        printf("y: ");
        scanf("%lf", &planets[i].position.y);
        printf("z: ");
        scanf("%lf", &planets[i].position.z);
        printf("Enter the initial velocity of planet %d (in m/s):\n", i+1);
        printf("x: ");
        scanf("%lf", &planets[i].velocity.x);
        printf("y: ");
        scanf("%lf", &planets[i].velocity.y);
        printf("z: ");
        scanf("%lf", &planets[i].velocity.z);
    }

    // Simulate gravity
    int steps = STEPS_PER_DAY;
    double dt = DT;
    for (int day = 0; day < 365; day++) {
        for (int i = 0; i < n; i++) {
            vector acceleration = {0, 0, 0};
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                double distance = sqrt(pow(planets[j].position.x - planets[i].position.x, 2) +
                                       pow(planets[j].position.y - planets[i].position.y, 2) +
                                       pow(planets[j].position.z - planets[i].position.z, 2));
                vector direction = {(planets[j].position.x - planets[i].position.x) / distance,
                                    (planets[j].position.y - planets[i].position.y) / distance,
                                    (planets[j].position.z - planets[i].position.z) / distance};
                double force_magnitude = G * planets[i].mass * planets[j].mass / pow(distance, 2);
                vector force = {direction.x * force_magnitude,
                                 direction.y * force_magnitude,
                                 direction.z * force_magnitude};
                acceleration.x += force.x / planets[i].mass;
                acceleration.y += force.y / planets[i].mass;
                acceleration.z += force.z / planets[i].mass;
            }
            planets[i].position.x += planets[i].velocity.x * dt + 0.5 * acceleration.x * pow(dt, 2);
            planets[i].position.y += planets[i].velocity.y * dt + 0.5 * acceleration.y * pow(dt, 2);
            planets[i].position.z += planets[i].velocity.z * dt + 0.5 * acceleration.z * pow(dt, 2);
            planets[i].velocity.x += acceleration.x * dt;
            planets[i].velocity.y += acceleration.y * dt;
            planets[i].velocity.z += acceleration.z * dt;
        }
        printf("\nDAY %d\n", day+1);
        for (int i = 0; i < n; i++) {
            printf("%s position: (%.2f, %.2f, %.2f) m\n", planets[i].name,
                   planets[i].position.x, planets[i].position.y, planets[i].position.z);
            printf("%s velocity: (%.2f, %.2f, %.2f) m/s\n", planets[i].name,
                   planets[i].velocity.x, planets[i].velocity.y, planets[i].velocity.z);
        }
    }

    return 0;
}