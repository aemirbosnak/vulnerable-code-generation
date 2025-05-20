//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.01

struct Point {
    double latitude;
    double longitude;
};

struct Route {
    int num_points;
    struct Point *points;
};

double distance(struct Point p1, struct Point p2) {
    double dlat = p2.latitude - p1.latitude;
    double dlon = p2.longitude - p1.longitude;
    double a = 
        (sin(dlat / 2) * sin(dlat / 2) + 
         cos(p1.latitude) * cos(p2.latitude) * 
         sin(dlon / 2) * sin(dlon / 2)) + 
        cos(p1.latitude) * cos(p2.latitude) * 
        cos(dlon / 2) * cos(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

void add_point(struct Route *route, double lat, double lon) {
    route->points = realloc(route->points, sizeof(struct Point) * (route->num_points + 1));
    route->points[route->num_points].latitude = lat;
    route->points[route->num_points].longitude = lon;
    route->num_points++;
}

int main() {
    struct Route route;
    route.num_points = 0;
    route.points = NULL;

    add_point(&route, 40.7128, -74.0060);
    add_point(&route, 34.0522, -118.2437);

    double total_distance = 0;
    for (int i = 0; i < route.num_points - 1; i++) {
        total_distance += distance(route.points[i], route.points[i+1]);
    }

    printf("Total distance: %.2f km\n", total_distance);

    return 0;
}