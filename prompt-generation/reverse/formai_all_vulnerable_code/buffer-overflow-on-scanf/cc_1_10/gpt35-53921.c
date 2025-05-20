//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846
#define RADIUS 6371000 // Earth Radius in meters

typedef struct {
    double latitude;
    double longitude;
} Coordinates;

double calculateDistance(Coordinates c1, Coordinates c2);
Coordinates generateRandomCoordinates();

int main() {
    int i, numCoordinates;
    double totalDistance = 0;
    Coordinates current, destination;

    // Seed the random generator
    srand(time(NULL));

    printf("Enter the number of GPS coordinates to generate: ");
    scanf("%d", &numCoordinates);

    // Generate the first set of coordinates
    current = generateRandomCoordinates();

    // Generate the remaining coordinates and calculate their distance from the current coordinate
    for (i = 1; i < numCoordinates; i++) {
        destination = generateRandomCoordinates();
        totalDistance += calculateDistance(current, destination);
        current = destination;
    }

    printf("Total Distance Travelled: %.2lf meters\n", totalDistance);

    return 0;
}

double calculateDistance(Coordinates c1, Coordinates c2) {
    double lat1 = c1.latitude * PI / 180;
    double lat2 = c2.latitude * PI / 180;
    double lon1 = c1.longitude * PI / 180;
    double lon2 = c2.longitude * PI / 180;

    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;

    double a = sin(dLat / 2) * sin(dLat / 2) +
                cos(lat1) * cos(lat2) *
                sin(dLon / 2) * sin(dLon / 2);

    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return RADIUS * c;
}

Coordinates generateRandomCoordinates() {
    Coordinates coords;

    coords.latitude = ((double) rand() / (double) RAND_MAX) * 180 - 90;
    coords.longitude = ((double) rand() / (double) RAND_MAX) * 360 - 180;

    return coords;
}