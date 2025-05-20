//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PLANETS 10
#define MAX_MOONS 10
#define SPACE_GRADE 9.81
#define EXCELSIOR_MOD 100000

typedef struct {
    char name[20];
    float mass; // in kg
    float radius; // in meters
    int moons_count;
    char moons[MAX_MOONS][20];
} Planet;

typedef struct {
    Planet planets[MAX_PLANETS];
    int total_planets;
} Galaxy;

Galaxy galaxy;

void initialize_galaxy() {
    galaxy.total_planets = 0;
}

void add_planet(char *name, float mass, float radius) {
    if (galaxy.total_planets < MAX_PLANETS) {
        Planet new_planet;
        snprintf(new_planet.name, sizeof(new_planet.name), "%s", name);
        new_planet.mass = mass;
        new_planet.radius = radius;
        new_planet.moons_count = 0;

        galaxy.planets[galaxy.total_planets] = new_planet;
        galaxy.total_planets++;
    } else {
        printf("Galaxy has reached the maximum number of planets.\n");
    }
}

void add_moon_to_planet(char *planet_name, char *moon_name) {
    for (int i = 0; i < galaxy.total_planets; i++) {
        if (strcmp(galaxy.planets[i].name, planet_name) == 0) {
            if (galaxy.planets[i].moons_count < MAX_MOONS) {
                snprintf(galaxy.planets[i].moons[galaxy.planets[i].moons_count], sizeof(galaxy.planets[i].moons[0]), "%s", moon_name);
                galaxy.planets[i].moons_count++;
            } else {
                printf("Max moons reached for planet %s.\n", planet_name);
            }
            return;
        }
    }
    printf("Planet %s not found!\n", planet_name);
}

float calculate_gravitational_force(float mass1, float mass2, float distance) {
    const float G = 6.674e-11; // gravitational constant
    return (G * mass1 * mass2) / (distance * distance);
}

void display_galaxy_info() {
    printf("Galaxy contains %d planets:\n", galaxy.total_planets);
    for (int i = 0; i < galaxy.total_planets; i++) {
        Planet p = galaxy.planets[i];
        printf("Planet name: %s\n", p.name);
        printf("Mass: %.2f kg\n", p.mass);
        printf("Radius: %.2f m\n", p.radius);
        printf("Moons: ");
        for (int j = 0; j < p.moons_count; j++) {
            printf("%s ", p.moons[j]);
        }
        printf("\n\n");
    }
}

void execute_space_arithmetic_operations() {
    float mass1 = 5.972e24; // Earth mass in kg
    float mass2 = 7.348e22; // Moon mass in kg
    float distance = 3.844e8; // distance between Earth and Moon in meters

    float gravitational_force = calculate_gravitational_force(mass1, mass2, distance);
    printf("The gravitational force between Earth and Moon is: %.2e N\n", gravitational_force);

    float escape_velocity = sqrt((2 * SPACE_GRADE * mass1) / mass1);
    printf("The escape velocity for planet Earth is: %.2f m/s\n", escape_velocity);

    int retrograde_count = 0;
    float retrograde_momentum[MAX_PLANETS] = {0};

    for (int i = 0; i < galaxy.total_planets; i++) {
        retrograde_momentum[i] = sqrt(galaxy.planets[i].mass * escape_velocity);
        if (retrograde_momentum[i] > EXCELSIOR_MOD) {
            retrograde_count++;
        }
    }

    if (retrograde_count > 0) {
        printf("%d planets show retrograde motion due to high escape velocity.\n", retrograde_count);
    } else {
        printf("No planets show retrograde motion.\n");
    }
}

void user_interaction() {
    char planet_name[20];
    char moon_name[20];

    printf("Welcome to the Cosmic Arithmetic Program!\n");
    printf("Please enter a name for a new planet: ");
    scanf("%s", planet_name);
    printf("Enter mass for %s (kg): ", planet_name);
    float mass;
    scanf("%f", &mass);
    printf("Enter radius for %s (m): ", planet_name);
    float radius;
    scanf("%f", &radius);
    
    add_planet(planet_name, mass, radius);

    printf("Now, enter moons for planet %s. Type 'end' to finish:\n", planet_name);
    while (1) {
        scanf("%s", moon_name);
        if (strcmp(moon_name, "end") == 0) {
            break;
        }
        add_moon_to_planet(planet_name, moon_name);
    }

    display_galaxy_info();
    execute_space_arithmetic_operations();
}

int main() {
    initialize_galaxy();
    user_interaction();
    return 0;
}