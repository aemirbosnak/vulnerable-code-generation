//Code Llama-13B DATASET v1.0 Category: GPS Navigation Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_POINTS 10
#define MAX_WAYPOINTS 5

typedef struct {
    double latitude;
    double longitude;
} Point;

typedef struct {
    Point points[MAX_WAYPOINTS];
    int num_points;
} Route;

void init_route(Route *route) {
    route->num_points = 0;
}

void add_point(Route *route, Point point) {
    if (route->num_points < MAX_WAYPOINTS) {
        route->points[route->num_points] = point;
        route->num_points++;
    }
}

void navigate(Route route) {
    Point current_point;
    int i;

    current_point.latitude = 0;
    current_point.longitude = 0;

    for (i = 0; i < route.num_points; i++) {
        Point next_point = route.points[i];
        double distance = sqrt(pow(next_point.latitude - current_point.latitude, 2) + pow(next_point.longitude - current_point.longitude, 2));
        current_point = next_point;
        printf("Moving %lf meters to (%lf, %lf)\n", distance, current_point.latitude, current_point.longitude);
    }
}

int main() {
    Route route;
    init_route(&route);
    add_point(&route, (Point){10, 10});
    add_point(&route, (Point){20, 20});
    add_point(&route, (Point){30, 30});
    add_point(&route, (Point){40, 40});
    add_point(&route, (Point){50, 50});
    navigate(route);
    return 0;
}