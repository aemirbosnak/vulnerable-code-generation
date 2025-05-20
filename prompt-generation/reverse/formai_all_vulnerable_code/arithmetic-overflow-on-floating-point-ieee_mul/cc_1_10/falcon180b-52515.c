//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} point;

point* create_point(int x, int y) {
    point* p = (point*) malloc(sizeof(point));
    p->x = x;
    p->y = y;
    return p;
}

void print_point(point* p) {
    printf("(%d,%d)", p->x, p->y);
}

int distance(point* p1, point* p2) {
    return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
}

void midpoint(point* p1, point* p2, point* result) {
    result->x = (p1->x + p2->x) / 2;
    result->y = (p1->y + p2->y) / 2;
}

void slope(point* p1, point* p2, double* result) {
    if (p1->x == p2->x) {
        *result = 0;
    } else {
        *result = (double) (p2->y - p1->y) / (p2->x - p1->x);
    }
}

int main() {
    point* p1 = create_point(0, 0);
    point* p2 = create_point(3, 4);
    point* p3 = create_point(6, 8);

    printf("Distance between p1 and p2: %d\n", distance(p1, p2));

    point* mid = create_point(0, 0);
    midpoint(p1, p2, mid);
    printf("Midpoint of p1 and p2: (%d,%d)\n", mid->x, mid->y);

    double slope_value;
    slope(p1, p2, &slope_value);
    printf("Slope of line between p1 and p2: %lf\n", slope_value);

    free(p1);
    free(p2);
    free(p3);
    free(mid);

    return 0;
}