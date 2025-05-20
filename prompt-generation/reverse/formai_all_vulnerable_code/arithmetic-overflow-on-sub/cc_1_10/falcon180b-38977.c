//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EARTH_RADIUS 6371 // in km
#define PI 3.14159265358979323846

typedef struct {
    double lat;
    double lon;
} Point;

double distance(Point p1, Point p2) {
    double dlat = p2.lat - p1.lat;
    double dlon = p2.lon - p1.lon;

    double a = sin(dlat/2) * sin(dlat/2) + cos(p1.lat) * cos(p2.lat) * sin(dlon/2) * sin(dlon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distance = EARTH_RADIUS * c;

    return distance;
}

int main() {
    int num_points;
    printf("Enter the number of points: ");
    scanf("%d", &num_points);

    Point points[num_points];
    printf("Enter the latitude and longitude of each point (in degrees):\n");
    for (int i = 0; i < num_points; i++) {
        scanf("%lf %lf", &points[i].lat, &points[i].lon);
    }

    int num_routes;
    printf("Enter the number of routes to calculate: ");
    scanf("%d", &num_routes);

    for (int i = 0; i < num_routes; i++) {
        int num_waypoints;
        printf("Enter the number of waypoints for route %d: ", i+1);
        scanf("%d", &num_waypoints);

        Point waypoints[num_waypoints];
        printf("Enter the latitude and longitude of each waypoint (in degrees):\n");
        for (int j = 0; j < num_waypoints; j++) {
            scanf("%lf %lf", &waypoints[j].lat, &waypoints[j].lon);
        }

        double total_distance = 0;
        for (int j = 0; j < num_waypoints-1; j++) {
            total_distance += distance(waypoints[j], waypoints[j+1]);
        }

        printf("The total distance for route %d is %.2lf km.\n", i+1, total_distance);
    }

    return 0;
}