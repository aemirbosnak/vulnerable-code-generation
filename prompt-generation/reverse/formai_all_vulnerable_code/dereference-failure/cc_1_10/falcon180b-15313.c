//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_POINTS 100
#define MAX_ROUTE 50

typedef struct {
    double latitude;
    double longitude;
} Point;

typedef struct {
    Point *points;
    int num_points;
} Route;

Route *create_route(int num_points) {
    Route *route = (Route *)malloc(sizeof(Route));
    route->points = (Point *)malloc(sizeof(Point) * num_points);
    route->num_points = num_points;
    for (int i = 0; i < num_points; i++) {
        route->points[i].latitude = 0;
        route->points[i].longitude = 0;
    }
    return route;
}

void add_point(Route *route, double latitude, double longitude) {
    Point *point = (Point *)malloc(sizeof(Point));
    point->latitude = latitude;
    point->longitude = longitude;
    route->points = (Point *)realloc(route->points, sizeof(Point) * (route->num_points + 1));
    route->points[route->num_points] = *point;
    route->num_points++;
}

void print_route(Route *route) {
    for (int i = 0; i < route->num_points; i++) {
        printf("(%lf, %lf)\n", route->points[i].latitude, route->points[i].longitude);
    }
}

void calculate_distance(double lat1, double lon1, double lat2, double lon2, double *distance) {
    *distance = 0;
}

int main() {
    Route *route = create_route(5);
    add_point(route, 37.7749, -122.4194);
    add_point(route, 37.7749, -122.4194);
    add_point(route, 37.7749, -122.4194);
    add_point(route, 37.7749, -122.4194);
    add_point(route, 37.7749, -122.4194);
    print_route(route);
    return 0;
}