//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PLANETS 10
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    float mass; // in kilograms
    float distance_from_sun; // in millions of km
    float gravity; // in m/s^2
} Planet;

typedef struct {
    Planet planets[MAX_PLANETS];
    int count;
} SolarSystem;

void initSolarSystem(SolarSystem *ss) {
    ss->count = 0;
}

bool addPlanet(SolarSystem *ss, char name[], float mass, float distance, float gravity) {
    if (ss->count >= MAX_PLANETS) {
        return false; // Max planets reached
    }
    strcpy(ss->planets[ss->count].name, name);
    ss->planets[ss->count].mass = mass;
    ss->planets[ss->count].distance_from_sun = distance;
    ss->planets[ss->count].gravity = gravity;
    ss->count++;
    return true;
}

void visualizeSolarSystem(SolarSystem *ss) {
    printf("\n---------------------- Space Visualization ----------------------\n\n");
    for (int i = 0; i < ss->count; i++) {
        printf("Planet Name: %s\n", ss->planets[i].name);
        printf("Mass (kg): %.2f\n", ss->planets[i].mass);
        printf("Distance from Sun (millions of km): %.2f\n", ss->planets[i].distance_from_sun);
        printf("Surface Gravity (m/s^2): %.2f\n", ss->planets[i].gravity);
        printf("------------------------------------------------------------\n");
    }
}

void displayCommands() {
    printf("\nChoose an option:\n");
    printf("1. Add a Planet\n");
    printf("2. Visualize Solar System\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    SolarSystem solarSystem;
    initSolarSystem(&solarSystem);
    int choice;

    while (true) {
        displayCommands();
        scanf("%d", &choice);
        getchar(); // consume newline after integer input

        if (choice == 1) {
            char name[NAME_LENGTH];
            float mass, distance, gravity;

            printf("Enter planet name: ");
            fgets(name, NAME_LENGTH, stdin);
            name[strcspn(name, "\n")] = '\0'; // Remove newline

            printf("Enter mass (kg): ");
            scanf("%f", &mass);
            printf("Enter distance from the Sun (millions of km): ");
            scanf("%f", &distance);
            printf("Enter surface gravity (m/s^2): ");
            scanf("%f", &gravity);

            if (addPlanet(&solarSystem, name, mass, distance, gravity)) {
                printf("Planet added successfully!\n");
            } else {
                printf("Failed to add planet. Max limit reached!\n");
            }

        } else if (choice == 2) {
            visualizeSolarSystem(&solarSystem);
        } else if (choice == 3) {
            printf("Exiting the simulation... Goodbye, space traveler!\n");
            break;
        } else {
            printf("Invalid choice! Please select again.\n");
        }
    }

    return 0;
}