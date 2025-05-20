//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.0

typedef struct {
    double latitude;
    double longitude;
} Coordinate;

Coordinate get_coordinate(char *input) {
    Coordinate coord;
    sscanf(input, "%lf,%lf", &coord.latitude, &coord.longitude);
    return coord;
}

double haversine(double lat1, double lon1, double lat2, double lon2) {
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(lat1) * cos(lat2) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

void main() {
    int num_locations;
    printf("Enter the number of locations: ");
    scanf("%d", &num_locations);

    Coordinate locations[num_locations];
    for (int i = 0; i < num_locations; i++) {
        printf("Enter the coordinates for location %d (latitude, longitude): ", i + 1);
        char input[100];
        scanf("%s", input);
        locations[i] = get_coordinate(input);
    }

    int num_routes;
    printf("Enter the number of routes: ");
    scanf("%d", &num_routes);

    for (int i = 0; i < num_routes; i++) {
        int num_stops;
        printf("Enter the number of stops for route %d: ", i + 1);
        scanf("%d", &num_stops);

        Coordinate stops[num_stops];
        for (int j = 0; j < num_stops; j++) {
            printf("Enter the coordinates for stop %d (latitude, longitude): ", j + 1);
            char input[100];
            scanf("%s", input);
            stops[j] = get_coordinate(input);
        }

        double total_distance = 0;
        for (int j = 0; j < num_stops - 1; j++) {
            total_distance += haversine(stops[j].latitude, stops[j].longitude, stops[j + 1].latitude, stops[j + 1].longitude);
        }

        printf("The total distance for route %d is %.2lf km.\n", i + 1, total_distance);
    }
}