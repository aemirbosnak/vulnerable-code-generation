//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WAYPOINTS 10

#define DEG_TO_RAD(x) ((x)*M_PI/180.0)

struct Waypoint {
    double latitude;
    double longitude;
};

struct NavigationInfo {
    double distance;
    double bearing;
};

double distance(struct Waypoint* wp1, struct Waypoint* wp2);
double bearing(struct Waypoint* wp1, struct Waypoint* wp2);
struct NavigationInfo navigate(struct Waypoint* wp1, struct Waypoint* wp2);

int main() {
    struct Waypoint waypoints[MAX_WAYPOINTS];
    int numWaypoints = 0;
    char input[80];

    printf("Enter up to %d waypoints.\n", MAX_WAYPOINTS);
    printf("Enter latitude, longitude for each waypoint,\n");
    printf("separated by a space. Enter an empty line to stop.\n");

    while (numWaypoints < MAX_WAYPOINTS) {
        printf("Waypoint %d: ", numWaypoints + 1);
        fgets(input, sizeof(input), stdin);
        if (input[0] == '\n') {
            break;
        }
        sscanf(input, "%lf %lf", &waypoints[numWaypoints].latitude, &waypoints[numWaypoints].longitude);
        numWaypoints++;
    }

    printf("%d waypoints entered.\n", numWaypoints);

    for (int i = 0; i < numWaypoints - 1; i++) {
        struct NavigationInfo nav = navigate(&waypoints[i], &waypoints[i+1]);
        printf("From waypoint %d to waypoint %d:\n", i+1, i+2);
        printf("\tDistance: %.2f km\n", nav.distance);
        printf("\tBearing: %.2f\n", nav.bearing);
    }

    return 0;
}

double distance(struct Waypoint* wp1, struct Waypoint* wp2) {
    double lat1 = DEG_TO_RAD(wp1->latitude);
    double lon1 = DEG_TO_RAD(wp1->longitude);
    double lat2 = DEG_TO_RAD(wp2->latitude);
    double lon2 = DEG_TO_RAD(wp2->longitude);

    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;

    double a = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return 6371 * c; // earth's radius in km
}

double bearing(struct Waypoint* wp1, struct Waypoint* wp2) {
    double lat1 = DEG_TO_RAD(wp1->latitude);
    double lon1 = DEG_TO_RAD(wp1->longitude);
    double lat2 = DEG_TO_RAD(wp2->latitude);
    double lon2 = DEG_TO_RAD(wp2->longitude);

    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;

    double a = sin(dlon) * cos(lat2);
    double b = cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(dlon);

    return atan2(a, b);
}

struct NavigationInfo navigate(struct Waypoint* wp1, struct Waypoint* wp2) {
    struct NavigationInfo nav;

    nav.distance = distance(wp1, wp2);
    nav.bearing = bearing(wp1, wp2);

    return nav;
}