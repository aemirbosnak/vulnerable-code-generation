//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Dennis Ritchie
#include<stdio.h>
#include<math.h>

#define GRAV_CONST 6.67408e-11 // Gravitational constant
#define METERS_PER_UNIT 149.6e9 // Meters per astronomical unit
#define SECONDS_PER_DAY 86400 // Seconds in a day
#define DAYS_PER_YEAR 365.25 // Days in a year

struct planet {
    char name[20];
    double mass; // kg
    double radius; // meters
    double position[3]; // 3D position in meters
    double velocity[3]; // 3D velocity in meters/second
};

int main() {
    struct planet solar_system[9] = {
        {"Sun", 1.9885e30, 696340000, {0, 0, 0}, {0, 0, 0}}, // Sun
        {"Mercury", 0.33011e24, 2439700, {-0.387098*METERS_PER_UNIT, 0, 0}, {0, -47362, 0}}, // Mercury
        {"Venus", 4.8675e24, 6051800, {-0.723332*METERS_PER_UNIT, 0, 0}, {0, -35020, 0}}, // Venus
        {"Earth", 5.97237e24, 6371000, {-1*METERS_PER_UNIT, 0, 0}, {0, 0, 29800}}, // Earth
        {"Mars", 0.64171e24, 3389500, {1.524*METERS_PER_UNIT, 0, 0}, {0, 24077, 0}}, // Mars
        {"Jupiter", 1898.13e24, 69911000, {-5.203363*METERS_PER_UNIT, 0, 0}, {0, -13070, 0}}, // Jupiter
        {"Saturn", 5.68319e26, 58232000, {-9.537070*METERS_PER_UNIT, 0, 0}, {0, -9690, 0}}, // Saturn
        {"Uranus", 86.8103e24, 25362000, {-19.191263*METERS_PER_UNIT, 0, 0}, {0, -6810, 0}}, // Uranus
        {"Neptune", 102.41e24, 24622000, {-30.068963*METERS_PER_UNIT, 0, 0}, {0, -5430, 0}} // Neptune
    };

    double time_step = 3600; // Seconds
    double time = 0; // Seconds

    int i, j;
    double distance, force_magnitude;
    double force[3];

    while(1) {
        // Calculate forces
        for(i = 0; i < 9; i++) {
            for(j = 0; j < 9; j++) {
                if(i == j) {
                    continue;
                }

                distance = sqrt(pow(solar_system[j].position[0] - solar_system[i].position[0], 2) +
                                pow(solar_system[j].position[1] - solar_system[i].position[1], 2) +
                                pow(solar_system[j].position[2] - solar_system[i].position[2], 2));

                force_magnitude = GRAV_CONST * solar_system[i].mass * solar_system[j].mass / pow(distance, 2);

                force[0] = force_magnitude * (solar_system[j].position[0] - solar_system[i].position[0]) / distance;
                force[1] = force_magnitude * (solar_system[j].position[1] - solar_system[i].position[1]) / distance;
                force[2] = force_magnitude * (solar_system[j].position[2] - solar_system[i].position[2]) / distance;

                solar_system[i].velocity[0] += force[0] / solar_system[i].mass * time_step;
                solar_system[i].velocity[1] += force[1] / solar_system[i].mass * time_step;
                solar_system[i].velocity[2] += force[2] / solar_system[i].mass * time_step;
            }
        }

        // Update positions
        for(i = 0; i < 9; i++) {
            solar_system[i].position[0] += solar_system[i].velocity[0] * time_step;
            solar_system[i].position[1] += solar_system[i].velocity[1] * time_step;
            solar_system[i].position[2] += solar_system[i].velocity[2] * time_step;
        }

        // Print positions
        printf("Time: %lf seconds\n", time);
        for(i = 0; i < 9; i++) {
            printf("%s: (%lf, %lf, %lf)\n", solar_system[i].name,
                   solar_system[i].position[0] / METERS_PER_UNIT,
                   solar_system[i].position[1] / METERS_PER_UNIT,
                   solar_system[i].position[2] / METERS_PER_UNIT);
        }

        // Update time
        time += time_step;
    }

    return 0;
}