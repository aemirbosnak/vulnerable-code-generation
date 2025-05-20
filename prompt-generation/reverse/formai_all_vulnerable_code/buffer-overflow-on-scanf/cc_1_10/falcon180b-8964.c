//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOCATIONS 100
#define MAX_ROUTES 50

typedef struct location {
    char name[50];
    float latitude;
    float longitude;
} location;

location locations[MAX_LOCATIONS];
int num_locations;

typedef struct route {
    int start;
    int end;
    float distance;
} route;

route routes[MAX_ROUTES];
int num_routes;

void add_location(char* name, float lat, float lon) {
    if (num_locations >= MAX_LOCATIONS) {
        printf("Error: Maximum number of locations reached.\n");
        return;
    }
    strcpy(locations[num_locations].name, name);
    locations[num_locations].latitude = lat;
    locations[num_locations].longitude = lon;
    num_locations++;
}

void add_route(int start, int end, float dist) {
    if (num_routes >= MAX_ROUTES) {
        printf("Error: Maximum number of routes reached.\n");
        return;
    }
    routes[num_routes].start = start;
    routes[num_routes].end = end;
    routes[num_routes].distance = dist;
    num_routes++;
}

int main() {
    srand(time(NULL));
    num_locations = 0;
    num_routes = 0;
    add_location("New York", 40.7128, -74.0060);
    add_location("Los Angeles", 34.0522, -118.2437);
    add_route(0, 1, 2458.11);
    int start_index, end_index;
    printf("Enter starting location: ");
    scanf("%d", &start_index);
    printf("Enter ending location: ");
    scanf("%d", &end_index);
    if (start_index >= num_locations || end_index >= num_locations) {
        printf("Error: Invalid location.\n");
        return 1;
    }
    printf("Total distance: %.2f miles\n", routes[0].distance);
    return 0;
}