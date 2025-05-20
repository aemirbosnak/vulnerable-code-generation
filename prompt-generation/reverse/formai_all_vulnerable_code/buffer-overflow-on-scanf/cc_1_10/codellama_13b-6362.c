//Code Llama-13B DATASET v1.0 Category: Procedural Space Adventure ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the constants
#define MAX_SPACESHIPS 10
#define MAX_PLANETS 50

// Define the structs
typedef struct {
    int x;
    int y;
    int z;
} Coordinate;

typedef struct {
    char name[32];
    int distance;
    Coordinate location;
} Planet;

typedef struct {
    char name[32];
    int fuel;
    int damage;
    Coordinate location;
} Spaceship;

// Define the functions
void print_planet_info(Planet planet) {
    printf("Planet name: %s\n", planet.name);
    printf("Distance: %d\n", planet.distance);
    printf("Location: (%d, %d, %d)\n", planet.location.x, planet.location.y, planet.location.z);
}

void print_spaceship_info(Spaceship spaceship) {
    printf("Spaceship name: %s\n", spaceship.name);
    printf("Fuel: %d\n", spaceship.fuel);
    printf("Damage: %d\n", spaceship.damage);
    printf("Location: (%d, %d, %d)\n", spaceship.location.x, spaceship.location.y, spaceship.location.z);
}

void move_spaceship(Spaceship* spaceship, Coordinate direction) {
    spaceship->location.x += direction.x;
    spaceship->location.y += direction.y;
    spaceship->location.z += direction.z;
}

void attack_planet(Planet* planet, Spaceship* spaceship) {
    spaceship->fuel -= planet->distance;
    spaceship->damage += planet->distance;
}

void defend_planet(Planet* planet, Spaceship* spaceship) {
    spaceship->fuel += planet->distance;
    spaceship->damage -= planet->distance;
}

// Define the main function
int main() {
    // Declare variables
    int num_planets = 0;
    int num_spaceships = 0;
    Planet planets[MAX_PLANETS];
    Spaceship spaceships[MAX_SPACESHIPS];
    Coordinate direction;

    // Get the number of planets and spaceships
    scanf("%d %d", &num_planets, &num_spaceships);

    // Initialize the planets
    for (int i = 0; i < num_planets; i++) {
        scanf("%s %d %d %d", planets[i].name, &planets[i].distance, &planets[i].location.x, &planets[i].location.y, &planets[i].location.z);
    }

    // Initialize the spaceships
    for (int i = 0; i < num_spaceships; i++) {
        scanf("%s %d %d %d %d", spaceships[i].name, &spaceships[i].fuel, &spaceships[i].damage, &spaceships[i].location.x, &spaceships[i].location.y, &spaceships[i].location.z);
    }

    // Get the direction
    scanf("%d %d %d", &direction.x, &direction.y, &direction.z);

    // Move the spaceships
    for (int i = 0; i < num_spaceships; i++) {
        move_spaceship(&spaceships[i], direction);
    }

    // Attack the planets
    for (int i = 0; i < num_planets; i++) {
        attack_planet(&planets[i], &spaceships[i]);
    }

    // Defend the planets
    for (int i = 0; i < num_planets; i++) {
        defend_planet(&planets[i], &spaceships[i]);
    }

    // Print the planets
    for (int i = 0; i < num_planets; i++) {
        print_planet_info(planets[i]);
    }

    // Print the spaceships
    for (int i = 0; i < num_spaceships; i++) {
        print_spaceship_info(spaceships[i]);
    }

    return 0;
}