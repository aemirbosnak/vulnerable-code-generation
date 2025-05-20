//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOCATION 100
#define MAX_ROUTE 100

typedef struct {
    char name[20];
    int lat;
    int lon;
} location_t;

typedef struct {
    int from;
    int to;
    int distance;
} route_t;

int num_locations = 0;
location_t locations[MAX_LOCATION];
int num_routes = 0;
route_t routes[MAX_ROUTE];

void add_location(char *name, int lat, int lon) {
    if (num_locations >= MAX_LOCATION) {
        printf("Error: Maximum number of locations reached.\n");
        return;
    }

    strcpy(locations[num_locations].name, name);
    locations[num_locations].lat = lat;
    locations[num_locations].lon = lon;
    num_locations++;
}

void add_route(int from, int to, int distance) {
    if (num_routes >= MAX_ROUTE) {
        printf("Error: Maximum number of routes reached.\n");
        return;
    }

    routes[num_routes].from = from;
    routes[num_routes].to = to;
    routes[num_routes].distance = distance;
    num_routes++;
}

void gps_navigation() {
    int start, end, i;

    printf("Enter starting location: ");
    scanf("%d", &start);

    printf("Enter ending location: ");
    scanf("%d", &end);

    for (i = 0; i < num_routes; i++) {
        if (routes[i].from == start && routes[i].to == end) {
            printf("Route found:\n");
            printf("Distance: %d\n", routes[i].distance);
            return;
        }
    }

    printf("No route found.\n");
}

int main() {
    int i;

    // Add locations
    add_location("New York", 40.7128, -74.0060);
    add_location("Los Angeles", 34.0522, -118.2437);
    add_location("Chicago", 41.8781, -87.6298);

    // Add routes
    add_route(0, 1, 2451);
    add_route(0, 2, 1748);
    add_route(1, 2, 1959);

    gps_navigation();

    return 0;
}