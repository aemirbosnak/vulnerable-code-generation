//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define PI 3.14159265358979323846

typedef struct {
    double lat;
    double lon;
} position;

typedef struct {
    position start;
    position end;
} route;

void init_position(position *pos) {
    pos->lat = 0;
    pos->lon = 0;
}

void set_position(position *pos, double lat, double lon) {
    pos->lat = lat;
    pos->lon = lon;
}

void print_position(position pos) {
    printf("%.6f, %.6f\n", pos.lat, pos.lon);
}

double distance(position a, position b) {
    double dlat = b.lat - a.lat;
    double dlon = b.lon - a.lon;
    return sqrt(pow(dlat, 2) + pow(dlon, 2));
}

void init_route(route *rte) {
    init_position(&rte->start);
    init_position(&rte->end);
}

void set_route(route *rte, double start_lat, double start_lon, double end_lat, double end_lon) {
    set_position(&rte->start, start_lat, start_lon);
    set_position(&rte->end, end_lat, end_lon);
}

void print_route(route rte) {
    printf("Start: ");
    print_position(rte.start);
    printf("End: ");
    print_position(rte.end);
}

int main() {
    position start, end;
    route route;

    init_position(&start);
    init_position(&end);

    set_position(&start, 40.7128, -74.0060); // New York City
    set_position(&end, 34.0522, -118.2437); // Los Angeles

    set_route(&route, start.lat, start.lon, end.lat, end.lon);

    printf("Distance: %.2f km\n", distance(start, end) / 1000);
    printf("Route:\n");
    print_route(route);

    return 0;
}