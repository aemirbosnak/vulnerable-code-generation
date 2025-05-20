//Falcon2-11B DATASET v1.0 Category: Simulation of the Solar System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Planet {
    char name[50];
    double mass;
    double distance;
};

struct Planet planets[8];

struct Planet earth;
struct Planet mercury;
struct Planet venus;
struct Planet mars;
struct Planet jupiter;
struct Planet saturn;
struct Planet uranus;
struct Planet neptune;

double distance(struct Planet p1, struct Planet p2) {
    double x1 = p1.distance;
    double x2 = p2.distance;
    double r = sqrt(pow(x1 - x2, 2) + pow(p1.distance - p2.distance, 2));
    return r;
}

void solarSystem() {
    printf("Current position of planets:\n");
    for (int i = 0; i < 8; i++) {
        printf("%s: %.2f\n", planets[i].name, planets[i].distance);
    }
    printf("\n");

    for (int i = 0; i < 8; i++) {
        if (distance(planets[i], planets[i+1]) < distance(planets[i], planets[i-1])) {
            planets[i].distance = distance(planets[i], planets[i+1]);
            planets[i+1].distance = distance(planets[i+1], planets[i+2]);
            solarSystem();
        }
    }
}

int main() {
    printf("Solar System Simulation\n");
    printf("1. Add a planet\n");
    printf("2. Update planet position\n");
    printf("3. Remove a planet\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);

    while (choice!= 4) {
        switch (choice) {
            case 1:
                printf("Enter planet name: ");
                scanf("%s", planets[8].name);
                printf("Enter planet mass: ");
                scanf("%lf", &planets[8].mass);
                printf("Enter planet distance: ");
                scanf("%lf", &planets[8].distance);
                printf("Planet added successfully.\n");
                break;
            case 2:
                printf("Enter planet name: ");
                scanf("%s", planets[8].name);
                printf("Enter new planet position: ");
                scanf("%lf", &planets[8].distance);
                printf("Planet position updated successfully.\n");
                break;
            case 3:
                printf("Enter planet name: ");
                scanf("%s", planets[8].name);
                printf("Planet removed successfully.\n");
                for (int i = 0; i < 8; i++) {
                    if (strcmp(planets[i].name, planets[8].name) == 0) {
                        for (int j = i; j < 8; j++) {
                            planets[j] = planets[j+1];
                        }
                        break;
                    }
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        printf("Enter your choice: ");
        scanf("%d", &choice);
    }
    solarSystem();
    return 0;
}