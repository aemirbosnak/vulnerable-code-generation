//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX_DEPTH 100
#define MAX_WIDTH 800
#define MAX_HEIGHT 800
#define PI 3.14159265359

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point p;
    Point v;
    int depth;
} Particle;

void init_particle(Particle *p, int x, int y, int depth) {
    p->p.x = x;
    p->p.y = y;
    p->v.x = 0;
    p->v.y = 0;
    p->depth = depth;
}

void update_particle(Particle *p, int width, int height) {
    int new_x = p->p.x + p->v.x;
    int new_y = p->p.y + p->v.y;

    if (new_x < 0 || new_x >= width || new_y < 0 || new_y >= height) {
        p->v.x = -p->v.x;
        p->v.y = -p->v.y;
    }

    p->p.x = new_x;
    p->p.y = new_y;
}

void draw_particle(Particle *p) {
    printf("*");
}

void fractal(int width, int height, int depth) {
    Particle *particles = malloc(sizeof(Particle) * (width * height));

    for (int i = 0; i < width * height; i++) {
        int x = rand() % width;
        int y = rand() % height;
        init_particle(&particles[i], x, y, depth);
    }

    for (int i = 0; i < MAX_DEPTH; i++) {
        for (int j = 0; j < width * height; j++) {
            Particle *p = &particles[j];
            update_particle(p, width, height);
            draw_particle(p);
        }
        printf("\n");
    }

    free(particles);
}

int main() {
    int width, height;

    printf("Enter the width of the fractal: ");
    scanf("%d", &width);

    printf("Enter the height of the fractal: ");
    scanf("%d", &height);

    fractal(width, height, 0);

    return 0;
}