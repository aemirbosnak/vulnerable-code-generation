//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_ITER 1000
#define MAX_POINTS 10000
#define MAX_LEVELS 10

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point *points;
    int num_points;
    int max_level;
} Fractal;

void init_fractal(Fractal *f, int max_level) {
    f->points = (Point *)malloc(MAX_POINTS * sizeof(Point));
    f->num_points = 0;
    f->max_level = max_level;
}

void free_fractal(Fractal *f) {
    free(f->points);
}

int is_point_in_fractal(Point p, Fractal *f) {
    int i;
    for (i = 0; i < f->num_points; i++) {
        if (p.x == f->points[i].x && p.y == f->points[i].y) {
            return 1;
        }
    }
    return 0;
}

void add_point_to_fractal(Point p, Fractal *f) {
    if (f->num_points >= MAX_POINTS) {
        return;
    }
    if (is_point_in_fractal(p, f)) {
        return;
    }
    f->points[f->num_points++] = p;
}

void generate_fractal(Fractal *f, int level) {
    int i;
    for (i = 0; i < f->num_points; i++) {
        Point p = f->points[i];
        int x = p.x;
        int y = p.y;
        int x1 = x + (int)(level * (rand() % 2 - 1));
        int y1 = y + (int)(level * (rand() % 2 - 1));
        add_point_to_fractal((Point){x1, y1}, f);
    }
}

void print_fractal(Fractal *f) {
    int i;
    for (i = 0; i < f->num_points; i++) {
        Point p = f->points[i];
        printf("(%d, %d)\n", p.x, p.y);
    }
}

int main() {
    srand(time(NULL));
    Fractal f;
    init_fractal(&f, MAX_LEVELS);
    add_point_to_fractal((Point){0, 0}, &f);
    generate_fractal(&f, 1);
    print_fractal(&f);
    return 0;
}