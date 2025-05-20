//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define EARTH_RADIUS 6371.01
#define PI 3.14159265358979323846

typedef struct {
    double latitude;
    double longitude;
} Coordinate;

Coordinate parseCoordinate(const char *str) {
    Coordinate coord;
    char *latStr = strtok(str, ",");
    if (!latStr) {
        return coord;
    }
    coord.latitude = atof(latStr);
    char *lonStr = strtok(NULL, ",");
    if (!lonStr) {
        return coord;
    }
    coord.longitude = atof(lonStr);
    return coord;
}

double distanceBetween(Coordinate coord1, Coordinate coord2) {
    double lat1 = coord1.latitude * PI / 180.0;
    double lon1 = coord1.longitude * PI / 180.0;
    double lat2 = coord2.latitude * PI / 180.0;
    double lon2 = coord2.longitude * PI / 180.0;
    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(lat1) * cos(lat2) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

int main() {
    char input[1024];
    printf("Enter starting coordinate (latitude,longitude): ");
    fgets(input, sizeof(input), stdin);
    Coordinate start = parseCoordinate(input);
    printf("Enter destination coordinate (latitude,longitude): ");
    fgets(input, sizeof(input), stdin);
    Coordinate destination = parseCoordinate(input);
    double distance = distanceBetween(start, destination);
    printf("Distance between starting and destination coordinates: %.2f km\n", distance);
    return 0;
}