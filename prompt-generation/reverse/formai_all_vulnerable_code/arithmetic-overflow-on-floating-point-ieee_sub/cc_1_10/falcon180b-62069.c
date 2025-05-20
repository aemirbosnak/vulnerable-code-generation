//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.0

// GPS coordinates
struct Coordinate {
    double latitude;
    double longitude;
};

void calculateDistance(struct Coordinate* coord1, struct Coordinate* coord2, double* distance) {
    double lat1 = coord1->latitude * PI / 180.0;
    double lat2 = coord2->latitude * PI / 180.0;
    double dLat = lat2 - lat1;
    double dLon = (coord2->longitude - coord1->longitude) * PI / 180.0;

    double a = sin(dLat / 2) * sin(dLat / 2) + cos(lat1) * cos(lat2) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distanceInMeters = EARTH_RADIUS * c;

    *distance = distanceInMeters;
}

void getInput(struct Coordinate* coord) {
    printf("Enter the latitude of the starting point: ");
    scanf("%lf", &coord->latitude);
    printf("Enter the longitude of the starting point: ");
    scanf("%lf", &coord->longitude);
}

int main() {
    struct Coordinate start, end;
    double distance;

    // Get the starting coordinates
    getInput(&start);

    // Get the ending coordinates
    printf("Enter the latitude of the destination: ");
    scanf("%lf", &end.latitude);
    printf("Enter the longitude of the destination: ");
    scanf("%lf", &end.longitude);

    // Calculate the distance between the two points
    calculateDistance(&start, &end, &distance);

    // Print the distance between the two points
    printf("The distance between the starting point and the destination is %.2lf meters.\n", distance);

    return 0;
}