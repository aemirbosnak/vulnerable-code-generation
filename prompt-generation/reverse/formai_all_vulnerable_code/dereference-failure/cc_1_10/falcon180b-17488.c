//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.01

struct point {
    double latitude;
    double longitude;
};

struct route {
    int num_points;
    struct point *points;
};

double distance(struct point p1, struct point p2) {
    double dlat = p2.latitude - p1.latitude;
    double dlon = p2.longitude - p1.longitude;
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(p1.latitude) * cos(p2.latitude) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

void add_point(struct route *route, double latitude, double longitude) {
    route->points = realloc(route->points, sizeof(struct point) * (route->num_points + 1));
    route->points[route->num_points].latitude = latitude;
    route->points[route->num_points].longitude = longitude;
    route->num_points++;
}

void print_route(struct route route) {
    printf("Route:\n");
    for (int i = 0; i < route.num_points; i++) {
        printf("(%f, %f)\n", route.points[i].latitude, route.points[i].longitude);
    }
}

void calculate_distance(struct route route) {
    double total_distance = 0;
    for (int i = 0; i < route.num_points - 1; i++) {
        total_distance += distance(route.points[i], route.points[i+1]);
    }
    printf("Total distance: %.2f km\n", total_distance);
}

int main() {
    srand(time(NULL));

    struct route route;
    route.num_points = 0;
    route.points = NULL;

    add_point(&route, 37.7749, -122.4194);
    add_point(&route, 40.7128, -74.0060);
    add_point(&route, 34.0522, -118.2437);
    add_point(&route, 21.2910, -157.8211);

    printf("Route:\n");
    print_route(route);

    calculate_distance(route);

    return 0;
}