//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

struct point {
    double x;
    double y;
};

struct route {
    int num_points;
    struct point *points;
};

void init_route(struct route *route) {
    route->num_points = 0;
    route->points = NULL;
}

void add_point(struct route *route, double x, double y) {
    struct point *new_point = malloc(sizeof(struct point));
    new_point->x = x;
    new_point->y = y;
    route->points = realloc(route->points, sizeof(struct point) * (route->num_points + 1));
    route->points[route->num_points] = *new_point;
    route->num_points++;
}

double distance(struct point a, struct point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

void print_route(struct route *route) {
    printf("Route has %d points:\n", route->num_points);
    for (int i = 0; i < route->num_points; i++) {
        printf("(%f, %f)\n", route->points[i].x, route->points[i].y);
    }
}

int main() {
    struct route route;
    init_route(&route);

    add_point(&route, 0, 0);
    add_point(&route, 1, 1);
    add_point(&route, 2, 2);
    add_point(&route, 3, 3);

    print_route(&route);

    return 0;
}