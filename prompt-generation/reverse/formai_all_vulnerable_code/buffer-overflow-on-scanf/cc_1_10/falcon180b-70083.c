//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 50
#define MAX_ALIENS 100

typedef struct {
    char name[20];
    int population;
    int resources;
} Planet;

typedef struct {
    char name[20];
    int age;
    int health;
    int attack;
} Alien;

Planet planets[MAX_PLANETS];
Alien aliens[MAX_ALIENS];

int numPlanets = 0;
int numAliens = 0;

void generatePlanets() {
    for (int i = 0; i < numPlanets; i++) {
        planets[i].population = rand() % 1000;
        planets[i].resources = rand() % 1000;
    }
}

void generateAliens() {
    for (int i = 0; i < numAliens; i++) {
        aliens[i].age = rand() % 100;
        aliens[i].health = rand() % 100;
        aliens[i].attack = rand() % 100;
    }
}

int main() {
    srand(time(0));

    int choice;
    do {
        printf("Welcome to the Space Adventure!\n");
        printf("Please choose an option:\n");
        printf("1. Explore a planet\n");
        printf("2. Encounter aliens\n");
        printf("3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (numPlanets == 0) {
                printf("No planets to explore.\n");
            } else {
                int planetIndex = rand() % numPlanets;
                printf("You land on planet %s.\n", planets[planetIndex].name);
                printf("Population: %d\n", planets[planetIndex].population);
                printf("Resources: %d\n", planets[planetIndex].resources);
            }
            break;

        case 2:
            if (numAliens == 0) {
                printf("No aliens to encounter.\n");
            } else {
                int alienIndex = rand() % numAliens;
                printf("You encounter an alien named %s.\n", aliens[alienIndex].name);
                printf("Age: %d\n", aliens[alienIndex].age);
                printf("Health: %d\n", aliens[alienIndex].health);
                printf("Attack: %d\n", aliens[alienIndex].attack);
            }
            break;

        case 3:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice.\n");
        }

    } while (choice!= 3);

    return 0;
}