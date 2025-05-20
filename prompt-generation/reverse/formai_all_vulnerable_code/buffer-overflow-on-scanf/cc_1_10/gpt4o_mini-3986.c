//GPT-4o-mini DATASET v1.0 Category: Planet Gravity Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define G 6.67430e-11 // Gravitational constant
#define MAX_CELESTIAL_BODIES 10

typedef struct {
    char name[20];
    double mass; // in kg
    double radius; // in meters
    double distance; // distance from the sun or the planet's reference point
} CelestialBody;

void calculate_gravity(CelestialBody *body1, CelestialBody *body2) {
    double force = (G * body1->mass * body2->mass) / (body2->distance * body2->distance);
    printf("The gravitational force between %s and %s is %.2e N\n", body1->name, body2->name, force);
}

void display_info(CelestialBody *body) {
    printf("\nCelestial Body: %s\n", body->name);
    printf("Mass: %.2e kg\n", body->mass);
    printf("Radius: %.2f m\n", body->radius);
    printf("Distance from the reference point: %.2f m\n", body->distance);
}

int main() {
    printf("Welcome to the Happy Planet Gravity Simulation!\n");
    printf("Let's explore the wonders of celestial mechanics!\n\n");

    CelestialBody bodies[MAX_CELESTIAL_BODIES];
    int count = 0;
    char choice;

    do {
        if (count >= MAX_CELESTIAL_BODIES) {
            printf("We can only handle %d celestial bodies but you can explore them!\n", MAX_CELESTIAL_BODIES);
            break;
        }

        printf("Enter the name of the celestial body: ");
        scanf("%s", bodies[count].name);
        
        printf("Enter the mass of %s (in kg): ", bodies[count].name);
        scanf("%lf", &bodies[count].mass);
        
        printf("Enter the radius of %s (in meters): ", bodies[count].name);
        scanf("%lf", &bodies[count].radius);
        
        printf("Enter the distance from the reference point (in meters): ");
        scanf("%lf", &bodies[count].distance);
        
        display_info(&bodies[count]);
        
        count++;

        printf("\nDo you want to add another celestial body? (Y/N): ");
        getchar(); // clear newline left by scanf
        scanf("%c", &choice);
    } while (choice == 'Y' || choice == 'y');

    printf("\nAlright! Now let's calculate the gravitational forces!\n");
    
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            calculate_gravity(&bodies[i], &bodies[j]);
        }
    }

    printf("\nThank you for participating in the Happy Planet Gravity Simulation!\n");
    printf("May the forces be with you!\n");

    return 0;
}