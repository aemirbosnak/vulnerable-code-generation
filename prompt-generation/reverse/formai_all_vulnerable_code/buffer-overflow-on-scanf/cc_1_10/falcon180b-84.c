//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.01

typedef struct {
    double latitude;
    double longitude;
} Coordinates;

typedef struct {
    Coordinates current;
    Coordinates destination;
} GPS;

void initializeGPS(GPS* gps) {
    gps->current.latitude = 0.0;
    gps->current.longitude = 0.0;
    gps->destination.latitude = 0.0;
    gps->destination.longitude = 0.0;
}

void getCurrentLocation(GPS* gps) {
    printf("Enter your current location (in decimal degrees):\n");
    printf("Latitude: ");
    scanf("%lf", &gps->current.latitude);
    printf("Longitude: ");
    scanf("%lf", &gps->current.longitude);
}

void setDestination(GPS* gps) {
    printf("Enter your destination (in decimal degrees):\n");
    printf("Latitude: ");
    scanf("%lf", &gps->destination.latitude);
    printf("Longitude: ");
    scanf("%lf", &gps->destination.longitude);
}

double calculateDistance(Coordinates coord1, Coordinates coord2) {
    double deltaLat = coord2.latitude - coord1.latitude;
    double deltaLon = coord2.longitude - coord1.longitude;

    double a = sin(deltaLat / 2) * sin(deltaLat / 2) + cos(coord1.latitude) * cos(coord2.latitude) * sin(deltaLon / 2) * sin(deltaLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return EARTH_RADIUS * c;
}

void displayRoute(GPS* gps) {
    printf("The distance between your current location and destination is %.2lf kilometers.\n", calculateDistance(gps->current, gps->destination));
    printf("To reach your destination, follow these directions:\n");
    if (gps->destination.latitude > gps->current.latitude) {
        printf("Go north.\n");
    } else if (gps->destination.latitude < gps->current.latitude) {
        printf("Go south.\n");
    }
    if (gps->destination.longitude > gps->current.longitude) {
        printf("Go east.\n");
    } else if (gps->destination.longitude < gps->current.longitude) {
        printf("Go west.\n");
    }
}

int main() {
    GPS gps;
    initializeGPS(&gps);
    getCurrentLocation(&gps);
    setDestination(&gps);
    displayRoute(&gps);

    return 0;
}