//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: minimalist
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define G 6.67430e-11 // gravitational constant
#define DT 3600 // time step
#define YEARS 100 // duration of simulation in years
#define PIXELS_PER_METER 1e-10 // scaling factor for display
#define WINDOW_SIZE 1000 // size of display window in pixels

struct Vector {
    double x;
    double y;
};

struct Body {
    struct Vector position;
    struct Vector velocity;
    double mass;
    double radius;
    int color[3];
};

void initialize_bodies(struct Body *bodies, int num_bodies, double radius_max, double mass_min, double mass_max) {
    srand(time(NULL));
    for (int i = 0; i < num_bodies; i++) {
        bodies[i].position.x = rand() % WINDOW_SIZE;
        bodies[i].position.y = rand() % WINDOW_SIZE;
        bodies[i].velocity.x = (double) (rand() % 100 - 50) / 1000;
        bodies[i].velocity.y = (double) (rand() % 100 - 50) / 1000;
        bodies[i].mass = (double) (rand() % (int) (mass_max * 100) - (int) (mass_min * 100)) / 100;
        bodies[i].radius = bodies[i].mass * radius_max / mass_max;
        bodies[i].color[0] = rand() % 256;
        bodies[i].color[1] = rand() % 256;
        bodies[i].color[2] = rand() % 256;
    }
}

void apply_gravity(struct Body *bodies, int num_bodies) {
    struct Vector acceleration;
    for (int i = 0; i < num_bodies; i++) {
        acceleration.x = 0;
        acceleration.y = 0;
        for (int j = 0; j < num_bodies; j++) {
            if (i == j) continue;
            double dx = bodies[j].position.x - bodies[i].position.x;
            double dy = bodies[j].position.y - bodies[i].position.y;
            double distance = sqrt(dx * dx + dy * dy);
            double force = G * bodies[i].mass * bodies[j].mass / (distance * distance);
            acceleration.x += force * dx / distance / bodies[i].mass;
            acceleration.y += force * dy / distance / bodies[i].mass;
        }
        bodies[i].velocity.x += acceleration.x * DT;
        bodies[i].velocity.y += acceleration.y * DT;
    }
}

void update_positions(struct Body *bodies, int num_bodies) {
    for (int i = 0; i < num_bodies; i++) {
        bodies[i].position.x += bodies[i].velocity.x * DT;
        bodies[i].position.y += bodies[i].velocity.y * DT;
    }
}

void display_bodies(struct Body *bodies, int num_bodies) {
    char pixels[WINDOW_SIZE][WINDOW_SIZE][3];
    for (int i = 0; i < WINDOW_SIZE; i++) {
        for (int j = 0; j < WINDOW_SIZE; j++) {
            pixels[i][j][0] = 0;
            pixels[i][j][1] = 0;
            pixels[i][j][2] = 0;
        }
    }
    for (int i = 0; i < num_bodies; i++) {
        int x = (int) bodies[i].position.x * PIXELS_PER_METER;
        int y = (int) bodies[i].position.y * PIXELS_PER_METER;
        int radius = (int) bodies[i].radius * PIXELS_PER_METER;
        for (int j = x - radius; j <= x + radius; j++) {
            for (int k = y - radius; k <= y + radius; k++) {
                if (j >= 0 && j < WINDOW_SIZE && k >= 0 && k < WINDOW_SIZE) {
                    pixels[k][j][0] = bodies[i].color[0];
                    pixels[k][j][1] = bodies[i].color[1];
                    pixels[k][j][2] = bodies[i].color[2];
                }
            }
        }
    }
    FILE *fp = fopen("solar_system.bmp", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", WINDOW_SIZE, WINDOW_SIZE);
    for (int i = 0; i < WINDOW_SIZE; i++) {
        for (int j = 0; j < WINDOW_SIZE; j++) {
            fwrite(pixels[i][j], 1, 3, fp);
        }
    }
    fclose(fp);
}

int main() {
    int num_bodies = 5;
    double radius_max = 7e8;
    double mass_min = 5.97e24;
    double mass_max = 1.99e30;
    struct Body bodies[num_bodies];
    initialize_bodies(bodies, num_bodies, radius_max, mass_min, mass_max);
    for (int t = 0; t < YEARS * 365 * 24 * 60 * 60 / DT; t++) {
        apply_gravity(bodies, num_bodies);
        update_positions(bodies, num_bodies);
    }
    display_bodies(bodies, num_bodies);
    return 0;
}