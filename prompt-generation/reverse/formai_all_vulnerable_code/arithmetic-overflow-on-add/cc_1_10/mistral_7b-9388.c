//MISTRAL-7B DATASET v1.0 Category: Planet Gravity Simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_PLANETS 5
#define WIDTH 80
#define HEIGHT 25
#define MIN_X -40
#define MAX_X 40
#define MIN_Y -20
#define MAX_Y 20

typedef struct {
    double x, y, vx, vy, mass;
} planet;

void init_planets(planet planets[]) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        planets[i].x = rand() * (MAX_X - MIN_X) + MIN_X;
        planets[i].y = rand() * (MAX_Y - MIN_Y) + MIN_Y;
        planets[i].vx = 0;
        planets[i].vy = 0;
        planets[i].mass = rand() % 10 + 5.0;
    }
}

void print_planets(planet planets[]) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("Planet %d: (%lf, %lf) m=%.1f\n", i + 1, planets[i].x, planets[i].y, planets[i].mass);
    }
}

void update_velocities(planet planets[]) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        double ax = 0, ay = 0;
        for (int j = 0; j < NUM_PLANETS; j++) {
            if (i != j) {
                double dx = planets[j].x - planets[i].x;
                double dy = planets[j].y - planets[i].y;
                double distance = sqrt(dx * dx + dy * dy);
                ax += (dx / distance) * planets[j].mass;
                ay += (dy / distance) * planets[j].mass;
            }
        }
        planets[i].vx += ax;
        planets[i].vy += ay;
    }
}

void update_positions(planet planets[]) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        planets[i].x += planets[i].vx;
        planets[i].y += planets[i].vy;
        if (planets[i].x < MIN_X) planets[i].x = MIN_X;
        if (planets[i].x > MAX_X) planets[i].x = MAX_X;
        if (planets[i].y < MIN_Y) planets[i].y = MIN_Y;
        if (planets[i].y > MAX_Y) planets[i].y = MAX_Y;
    }
}

void clear_screen() {
    printf("\033[2J");
}

int main() {
    srand(time(NULL));
    planet planets[NUM_PLANETS];

    init_planets(planets);
    print_planets(planets);

    while (1) {
        clear_screen();
        update_velocities(planets);
        update_positions(planets);
        print_planets(planets);
        fflush(stdout);
        usleep(50000);
    }

    return 0;
}