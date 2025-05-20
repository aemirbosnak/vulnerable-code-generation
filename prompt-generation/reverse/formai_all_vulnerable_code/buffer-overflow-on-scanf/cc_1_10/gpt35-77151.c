//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLANETS 10

struct planet {
    char name[20];
    float distance_from_earth;
    int no_of_moons;
};

void print_planet_details(struct planet *p) {
    printf("\n%s is located %.2f billion kilometers from Earth", p->name, p->distance_from_earth);
    printf("\nIt has %d moons orbiting around it.\n", p->no_of_moons);
}

int main() {
    struct planet planets[MAX_PLANETS];
    int no_of_planets;

    printf("Welcome to the Procedural Space Adventure!\n");
    printf("-------------------------------------------\n");

    printf("How many planets would you like to explore? (Max: %d)\n", MAX_PLANETS);
    scanf("%d", &no_of_planets);

    if(no_of_planets > MAX_PLANETS) {
        printf("Sorry, we cannot explore more than %d planets!\n", MAX_PLANETS);
        return -1;
    }

    printf("Great! Please answer the following questions about each planet:\n");

    for(int i=0; i<no_of_planets; i++) {
        printf("\nPlanet %d:\n", i+1);

        printf("What is the name of the planet?\n");
        scanf("%s", planets[i].name);

        printf("What is the distance of %s from Earth (in billions of kilometers)?\n", planets[i].name);
        scanf("%f", &planets[i].distance_from_earth);

        printf("How many moons orbit around %s?\n", planets[i].name);
        scanf("%d", &planets[i].no_of_moons);
    }

    printf("\n-------------------------------------------\n");
    printf("Let's explore the planets one by one!\n");

    for(int i=0; i<no_of_planets; i++) {
        printf("\n-------------------------------------------------------\n");
        printf("Exploring Planet %d: %s\n", i+1, planets[i].name);
        print_planet_details(&planets[i]);
    }

    printf("\n-------------------------------------------\n");
    printf("Thanks for exploring the universe with us. Come back soon!\n");
    printf("-------------------------------------------\n");

    return 0;
}