//GPT-4o-mini DATASET v1.0 Category: Simulation of the Solar System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_PLANETS 8
#define NAME_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    double orbit_radius; // in millions of kilometers
    double orbit_speed;  // in kilometers per hour
    double mass;         // in kg
} Planet;

void display_planet_info(Planet *p) {
    printf("Name: %s\n", p->name);
    printf("Orbit Radius: %.2f million km\n", p->orbit_radius);
    printf("Orbit Speed: %.2f km/h\n", p->orbit_speed);
    printf("Mass: %.2e kg\n", p->mass);
}

void initialize_planets(Planet planets[]) {
    strcpy(planets[0].name, "Mercury");
    planets[0].orbit_radius = 57.91;
    planets[0].orbit_speed = 47.87;
    planets[0].mass = 3.285e23;

    strcpy(planets[1].name, "Venus");
    planets[1].orbit_radius = 108.21;
    planets[1].orbit_speed = 35.02;
    planets[1].mass = 4.867e24;

    strcpy(planets[2].name, "Earth");
    planets[2].orbit_radius = 149.60;
    planets[2].orbit_speed = 29.78;
    planets[2].mass = 5.972e24;

    strcpy(planets[3].name, "Mars");
    planets[3].orbit_radius = 227.92;
    planets[3].orbit_speed = 24.07;
    planets[3].mass = 6.417e23;

    strcpy(planets[4].name, "Jupiter");
    planets[4].orbit_radius = 778.57;
    planets[4].orbit_speed = 13.07;
    planets[4].mass = 1.898e27;

    strcpy(planets[5].name, "Saturn");
    planets[5].orbit_radius = 1433.5;
    planets[5].orbit_speed = 9.69;
    planets[5].mass = 5.683e26;

    strcpy(planets[6].name, "Uranus");
    planets[6].orbit_radius = 2872.5;
    planets[6].orbit_speed = 6.81;
    planets[6].mass = 8.681e25;

    strcpy(planets[7].name, "Neptune");
    planets[7].orbit_radius = 4495.1;
    planets[7].orbit_speed = 5.43;
    planets[7].mass = 1.024e26;
}

void menu(Planet planets[]) {
    int choice;
    while (1) {
        printf("\nSolar System Simulation\n");
        printf("Choose a planet (1-8) to display its information or 0 to exit:\n");
        for (int i = 0; i < MAX_PLANETS; i++) {
            printf("%d. %s\n", i + 1, planets[i].name);
        }
        printf("0. Exit\n");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }
        if (choice < 1 || choice > MAX_PLANETS) {
            printf("Invalid choice, please try again.\n");
        } else {
            display_planet_info(&planets[choice - 1]);
        }
    }
}

int main() {
    Planet planets[MAX_PLANETS];
    initialize_planets(planets);
    menu(planets);
    return 0;
}