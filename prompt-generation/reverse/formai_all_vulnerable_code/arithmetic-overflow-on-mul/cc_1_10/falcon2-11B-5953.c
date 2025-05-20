//Falcon2-11B DATASET v1.0 Category: Planet Gravity Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

struct Planet {
    int mass;
    int radius;
    int x;
    int y;
};

struct Planet createPlanet(int mass, int radius, int x, int y) {
    struct Planet planet;
    planet.mass = mass;
    planet.radius = radius;
    planet.x = x;
    planet.y = y;
    return planet;
}

void movePlanet(struct Planet* planet, int dx, int dy) {
    planet->x += dx;
    planet->y += dy;
}

int main() {
    struct Planet earth;
    earth.mass = 5.972e24;
    earth.radius = 6371;
    earth.x = 0;
    earth.y = 0;

    struct Planet moon;
    moon.mass = 7.347e22;
    moon.radius = 1738;
    moon.x = 384400;
    moon.y = 575200;

    int dx = 0;
    int dy = 0;

    while (1) {
        movePlanet(&earth, dx, dy);
        movePlanet(&moon, dx, dy);

        printf("Earth's position: (%d, %d)\n", earth.x, earth.y);
        printf("Moon's position: (%d, %d)\n", moon.x, moon.y);
        printf("Earth's distance from Moon: %d km\n", distance(earth.x, earth.y, moon.x, moon.y));

        printf("Enter x-direction: ");
        scanf("%d", &dx);
        printf("Enter y-direction: ");
        scanf("%d", &dy);
    }

    return 0;
}

int distance(int x1, int y1, int x2, int y2) {
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}