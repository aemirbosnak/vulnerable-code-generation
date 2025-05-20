//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define R 6371.009 // Radius of the earth in km
#define D2R (PI/180.0) // Degrees to radians conversion factor
#define R2D (180.0/PI) // Radians to degrees conversion factor

struct Point {
    double lat;
    double lon;
};

struct Route {
    int numPoints;
    struct Point *points;
};

void initRoute(struct Route *route) {
    route->numPoints = 0;
    route->points = NULL;
}

void addPoint(struct Route *route, double lat, double lon) {
    struct Point *newPoint = malloc(sizeof(struct Point));
    newPoint->lat = lat;
    newPoint->lon = lon;
    route->points = realloc(route->points, sizeof(struct Point) * (route->numPoints + 1));
    route->points[route->numPoints] = *newPoint;
    route->numPoints++;
}

void printRoute(struct Route route) {
    for(int i=0; i<route.numPoints; i++) {
        printf("%.6f,%.6f\n", route.points[i].lat*R2D, route.points[i].lon*R2D);
    }
}

double distance(double lat1, double lon1, double lat2, double lon2) {
    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;
    double a = sin(dLat/2) * sin(dLat/2) + cos(lat1*D2R) * cos(lat2*D2R) * sin(dLon/2) * sin(dLon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    return R * c;
}

int main() {
    struct Route route;
    initRoute(&route);
    addPoint(&route, 37.774929, -122.419416); // San Francisco
    addPoint(&route, 40.712776, -74.005974); // New York
    printf("Total distance: %.2f km\n", distance(route.points[0].lat, route.points[0].lon, route.points[1].lat, route.points[1].lon));
    printRoute(route);
    return 0;
}