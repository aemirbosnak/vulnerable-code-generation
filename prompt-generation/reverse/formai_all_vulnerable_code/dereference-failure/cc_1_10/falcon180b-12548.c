//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_POINTS 100
#define MAX_ROUTE_LENGTH 20

typedef struct {
    double x, y;
} Point;

typedef struct {
    int length;
    Point* route;
} Route;

void rand_point(Point* p) {
    p->x = rand() % 100;
    p->y = rand() % 100;
}

void rand_route(Route* r) {
    r->length = rand() % MAX_ROUTE_LENGTH + 2;
    r->route = malloc(sizeof(Point) * r->length);
    for (int i = 0; i < r->length; i++) {
        rand_point(&r->route[i]);
    }
}

void print_point(Point p) {
    printf("(%d, %d)\n", p.x, p.y);
}

void print_route(Route r) {
    printf("Route length: %d\n", r.length);
    for (int i = 0; i < r.length; i++) {
        print_point(r.route[i]);
    }
}

int main() {
    srand(time(NULL));

    Point start, end;
    rand_point(&start);
    rand_point(&end);

    Route route;
    rand_route(&route);

    printf("GPS Navigation Simulation\n");
    printf("Starting point: ");
    print_point(start);
    printf("Ending point: ");
    print_point(end);
    printf("Route: ");
    print_route(route);

    return 0;
}