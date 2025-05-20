//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the Earth's radius in kilometers
#define EARTH_RADIUS 6371.0

// Define the maximum number of waypoints
#define MAX_WAYPOINTS 100

// Define the structure for a waypoint
typedef struct {
    double latitude;
    double longitude;
} Waypoint;

// Define the structure for a route
typedef struct {
    int num_waypoints;
    Waypoint waypoints[MAX_WAYPOINTS];
} Route;

// Function prototypes
void read_waypoints(Route *route);
double distance(double lat1, double lon1, double lat2, double lon2);
void print_route(Route *route);

int main() {
    Route route;

    // Read the waypoints from the user
    read_waypoints(&route);

    // Print the route
    print_route(&route);

    return 0;
}

// Function to read the waypoints from the user
void read_waypoints(Route *route) {
    int i;
    Waypoint waypoint;

    printf("Enter the number of waypoints (max %d): ", MAX_WAYPOINTS);
    scanf("%d", &route->num_waypoints);

    for (i = 0; i < route->num_waypoints; i++) {
        printf("Enter the latitude and longitude for waypoint %d (in degrees): ", i+1);
        scanf("%lf %lf", &waypoint.latitude, &waypoint.longitude);
        route->waypoints[i] = waypoint;
    }
}

// Function to calculate the distance between two points on the Earth's surface
double distance(double lat1, double lon1, double lat2, double lon2) {
    double dlat, dlon, a, c, d;
    double R = EARTH_RADIUS;

    dlat = lat2 - lat1;
    dlon = lon2 - lon1;

    a = sin(dlat/2) * sin(dlat/2) + cos(lat1) * cos(lat2) * sin(dlon/2) * sin(dlon/2);
    c = 2 * atan2(sqrt(a), sqrt(1-a));

    d = R * c; // Distance in kilometers

    return d;
}

// Function to print the route
void print_route(Route *route) {
    int i;
    Waypoint waypoint;

    printf("Route:\n");

    for (i = 0; i < route->num_waypoints; i++) {
        waypoint = route->waypoints[i];
        printf("Waypoint %d: %.2f°N %.2f°E\n", i+1, waypoint.latitude, waypoint.longitude);
    }
}