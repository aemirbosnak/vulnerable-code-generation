//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Structure used to hold the coordinates
typedef struct {
    double latitude;
    double longitude;
} coordinate_t;

// Calculates the distance between two coordinates
double distance(coordinate_t coord1, coordinate_t coord2) {
    const double R = 6371e3;    // Earth's radius
    double lat1 = coord1.latitude * M_PI / 180.0;
    double lat2 = coord2.latitude * M_PI / 180.0;
    double lon1 = coord1.longitude * M_PI / 180.0;
    double lon2 = coord2.longitude * M_PI / 180.0;
    double deltaLat = (lat2 - lat1);
    double deltaLon = (lon2 - lon1);

    double a = sin(deltaLat / 2) * sin(deltaLat / 2)
             + cos(lat1) * cos(lat2)
             * sin(deltaLon / 2) * sin(deltaLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double d = R * c;

    return d;
}

// Main function
int main() {
    const int MAX_LINES = 1000;
    char line[MAX_LINES];
    coordinate_t currentCoords, previousCoords;
    double totalDistance = 0;

    // Ask for starting coordinates
    printf("Enter the starting latitude and longitude in decimal format:\n");
    fgets(line, MAX_LINES, stdin);
    sscanf(line, "%lf %lf", &currentCoords.latitude, &currentCoords.longitude);

    // Loop through waypoints
    while (fgets(line, MAX_LINES, stdin)) {
        sscanf(line, "%lf %lf", &previousCoords.latitude, &previousCoords.longitude);

        double d = distance(currentCoords, previousCoords);
        printf("Distance from (%lf, %lf) to (%lf, %lf) is %lf meters\n",
               currentCoords.latitude, currentCoords.longitude,
               previousCoords.latitude, previousCoords.longitude,
               d);
        totalDistance += d;

        currentCoords = previousCoords;
    }

    // Print total distance
    printf("Total distance is %lf meters\n", totalDistance);

    return 0;
}