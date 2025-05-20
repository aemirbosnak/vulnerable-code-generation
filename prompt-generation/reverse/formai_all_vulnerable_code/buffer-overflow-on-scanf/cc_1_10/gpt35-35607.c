//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLANETS 10
#define MAX_NAME_LENGTH 20

struct Planet {
    char name[MAX_NAME_LENGTH];
    int distance;
    int inhabitants;
};

void print_planet(struct Planet planet) {
    printf("\nName: %s\n", planet.name);
    printf("Distance: %d\n", planet.distance);
    printf("Inhabitants: %d\n", planet.inhabitants);
}

void visit_planet(struct Planet *planet) {
    planet->inhabitants--;
    printf("\nYou have visited %s!\n", planet->name);
}

int main() {
    struct Planet planets[MAX_PLANETS] = {
        {"Asteroid", 10, 0},
        {"Mercury", 36, 0},
        {"Venus", 67, 0},
        {"Earth", 93, 1},
        {"Mars", 141, 0},
        {"Jupiter", 483, 0},
        {"Saturn", 886, 0},
        {"Uranus", 1782, 0},
        {"Neptune", 2793, 0},
        {"Pluto", 3670, 0}
    };
    int planets_visited = 0;
    int total_distance = 0;
    int romantic_distance = 0; // The distance that the couple will travel

    printf("Welcome to our space adventure!\n\n");
    printf("We have prepared 10 planets for you to visit!\n");

    while (planets_visited < 10) {
        int choice;

        printf("\nWhere would you like to go next?\n");
        printf("1. Asteroid\n");
        printf("2. Mercury\n");
        printf("3. Venus\n");
        printf("4. Earth\n");
        printf("5. Mars\n");
        printf("6. Jupiter\n");
        printf("7. Saturn\n");
        printf("8. Uranus\n");
        printf("9. Neptune\n");
        printf("10. Pluto\n");

        scanf("%d", &choice);

        if (choice < 1 || choice > 10) {
            printf("Invalid choice! Try again.\n");
            continue;
        }

        struct Planet *planet = &planets[choice - 1];

        if (planet->inhabitants == 0) {
            printf("\nYou landed on %s, but there were no inhabitants!\n", planet->name);
        } else {
            visit_planet(planet);
            planets_visited++;

            // If it's Earth, the couple will be there
            if (strcmp(planet->name, "Earth") == 0) {
                romantic_distance = total_distance;
                printf("\nCongratulations, you found us on Earth! We've been waiting for you.\n");
                printf("We are going to travel to other planets together.\n");
                printf("We have calculated the distance and we will travel a total of %d light years!\n", romantic_distance);
            }
        }

        total_distance += planet->distance;
    }

    printf("\nYou have visited all the planets! Congratulations!\n");

    // If the couple didn't meet on Earth, the program ends
    if (romantic_distance == 0) {
        return 0;
    }

    // But if they did, they will travel to other planets together
    printf("\nWe're starting our journey!\n");

    for (int i = 0; i < MAX_PLANETS; i++) {
        if (planets[i].inhabitants == 0) {
            continue;
        }

        printf("\nWe are on %s now!\n", planets[i].name);
        visit_planet(&planets[i]);

        romantic_distance += planets[i].distance;

        // If they travelled 150 light years in total, the program ends
        if (romantic_distance >= 150) {
            printf("\nWe've travelled 150 light years together. Our journey has come to an end!\n");
            return 0;
        }
    }

    return 0;
}