//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WAYPOINTS 10
#define MAX_PATH 100
#define EARTH_RADIUS 6371

typedef struct {
    double latitude;
    double longitude;
} waypoint;

typedef struct {
    waypoint waypoints[MAX_WAYPOINTS];
    int count;
} path;

double to_radians(double degrees) {
    return degrees * M_PI / 180.0;
}

double haversine_distance(waypoint p1, waypoint p2) {
    double dlat = to_radians(p2.latitude - p1.latitude);
    double dlon = to_radians(p2.longitude - p1.longitude);
    double a = pow(sin(dlat / 2), 2) + cos(to_radians(p1.latitude)) * cos(to_radians(p2.latitude)) * pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

double total_distance(path p) {
    double distance = 0.0;
    for (int i = 0; i < p.count - 1; i++) {
        distance += haversine_distance(p.waypoints[i], p.waypoints[i+1]);
    }
    return distance;
}

void display_path(path p) {
    printf("Path with %d waypoints:\n", p.count);
    for (int i = 0; i < p.count; i++) {
        printf("\tWaypoint %d: (%lf, %lf)\n", i, p.waypoints[i].latitude, p.waypoints[i].longitude);
    }
}

int main() {
    path p;
    p.count = 0;
    char input[10];
    while (p.count < MAX_WAYPOINTS) {
        printf("Enter latitude and longitude for waypoint %d (or 'done' to stop):\n", p.count);
        if (fgets(input, sizeof(input), stdin) && sscanf(input, "%lf %lf", &p.waypoints[p.count].latitude, &p.waypoints[p.count].longitude) == 2) {
            p.count++;
        }
        else {
            break;
        }
    }
    display_path(p);
    printf("Total distance: %lf km\n", total_distance(p));
    return 0;
}