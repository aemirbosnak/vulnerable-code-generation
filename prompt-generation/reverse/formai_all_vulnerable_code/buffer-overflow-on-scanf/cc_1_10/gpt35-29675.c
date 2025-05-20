//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_DIST 10000

typedef struct {
    char name[20];
    int x;
    int y;
    int fuel;
} spaceship;

typedef struct {
    char name[20];
    int x;
    int y;
} planet;

void planetInfo(planet p);
void travel(spaceship *s, planet p);
void refuel(spaceship *s, int cost);
void gameOver();

int main() {
    srand(time(NULL));
    spaceship ship = {"Enterprise", 0, 0, 100};
    planet planets[5] = {{"Alderaan", rand() % MAX_DIST, rand() % MAX_DIST},
                         {"Tatooine", rand() % MAX_DIST, rand() % MAX_DIST},
                         {"Hoth", rand() % MAX_DIST, rand() % MAX_DIST},
                         {"Naboo", rand() % MAX_DIST, rand() % MAX_DIST},
                         {"Coruscant", rand() % MAX_DIST, rand() % MAX_DIST}};

    printf("Welcome to the Space Adventure!\n");
    printf("You are in command of the spaceship %s.\n", ship.name);
    printf("You will be travelling through space to explore 5 planets.\n");
    printf("You have enough fuel to explore all of the planets,\nbut don't forget to refuel when necessary.\n");
    printf("Good luck, Captain!\n");

    for (int i = 0; i < 5; i++) {
        planetInfo(planets[i]);
        travel(&ship, planets[i]);
    }

    printf("Congratulations, Captain! You have explored all the planets and completed your mission.\n");
    printf("It's time to celebrate!\n");
    return 0;
}

void planetInfo(planet p) {
    printf("Welcome to planet %s!\n", p.name);
    printf("Coordinates: (%d,%d)\n", p.x, p.y);
}

void travel(spaceship *s, planet p) {
    int distance = abs(s->x - p.x) + abs(s->y - p.y);
    printf("Travelling to planet %s...\n", p.name);
    printf("Distance to %s: %d km\n", p.name, distance);
    s->fuel -= distance;

    if (s->fuel <= 0) {
        gameOver();
    }

    s->x = p.x;
    s->y = p.y;
    printf("Arriving at planet %s.\n", p.name);
    printf("Current fuel: %d\n", s->fuel);

    int refuelCost = rand() % 25 + 1;
    printf("Refuel cost: %d\n", refuelCost);
    refuel(s, refuelCost);
}

void refuel(spaceship *s, int cost) {
    char response[5];
    printf("Would you like to refuel (y/n)? ");
    scanf("%s", response);

    if (strcmp(response, "y") == 0) {
        if (cost > s->fuel) {
            printf("You do not have enough fuel to refuel.\n");
        } else {
            s->fuel -= cost;
            printf("Refueled successfully. Current fuel: %d\n", s->fuel);
        }
    }
}

void gameOver() {
    printf("You have run out of fuel! Game over.\n");
    exit(0);
}