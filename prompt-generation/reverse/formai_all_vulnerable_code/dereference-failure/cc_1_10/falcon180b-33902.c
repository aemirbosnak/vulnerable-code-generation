//Falcon-180B DATASET v1.0 Category: Simulation of the Solar System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846

// Define the planets
#define NUM_PLANETS 8
#define PLANET_NAMES "Mercury Venus Earth Mars Jupiter Saturn Uranus Neptune "
#define PLANET_COLORS "red orange yellow green blue indigo violet "

typedef struct {
    char name[20];
    double distance;
    double velocity;
    double angle;
    int color;
} Planet;

// Function to initialize the planets
void initPlanets(Planet *planets) {
    int i;
    for (i = 0; i < NUM_PLANETS; i++) {
        sprintf(planets[i].name, "%s", strtok(PLANET_NAMES, " "));
        planets[i].distance = i * 50;
        planets[i].velocity = (double)rand() / RAND_MAX * 10;
        planets[i].angle = 0;
        planets[i].color = i % 7;
    }
}

// Function to update the planet positions
void updatePlanets(Planet *planets, double dt) {
    int i;
    for (i = 0; i < NUM_PLANETS; i++) {
        planets[i].angle += planets[i].velocity * dt;
        while (planets[i].angle >= 360) {
            planets[i].angle -= 360;
        }
    }
}

// Function to draw the planets
void drawPlanets(Planet *planets) {
    int i;
    for (i = 0; i < NUM_PLANETS; i++) {
        printf("%s ", planets[i].name);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    Planet planets[NUM_PLANETS];
    initPlanets(planets);

    while (1) {
        system("clear");
        drawPlanets(planets);
        printf("Press any key to continue...\n");
        getchar();
        updatePlanets(planets, 0.01);
        usleep(100000);
    }

    return 0;
}