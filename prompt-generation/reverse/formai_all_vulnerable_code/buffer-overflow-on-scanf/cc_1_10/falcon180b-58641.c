//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846

// GPS coordinates
struct coord {
    double lat;
    double lon;
};

// Function to calculate distance between two GPS coordinates
double distance(struct coord c1, struct coord c2) {
    double dLat = c2.lat - c1.lat;
    double dLon = c2.lon - c1.lon;
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(c1.lat * PI / 180) * cos(c2.lat * PI / 180) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = 6371 * c; // radius of earth in km
    return distance;
}

int main() {
    int numPoints;
    double distanceTraveled = 0;
    struct coord currentLocation;
    struct coord previousLocation;

    // Initialize random seed
    srand(time(NULL));

    // Get number of GPS coordinates to simulate
    printf("Enter number of GPS coordinates to simulate: ");
    scanf("%d", &numPoints);

    // Simulate GPS coordinates
    for (int i = 0; i < numPoints; i++) {
        currentLocation.lat = rand() % 90 + 1; // simulate latitude between 1 and 90 degrees
        currentLocation.lon = rand() % 180 + 1; // simulate longitude between 1 and 180 degrees

        // Calculate distance from previous location
        if (i > 0) {
            distanceTraveled += distance(currentLocation, previousLocation);
        }

        // Update previous location
        previousLocation = currentLocation;

        // Print current location
        printf("Current location: %.2f, %.2f\n", currentLocation.lat, currentLocation.lon);
    }

    // Print total distance traveled
    printf("Total distance traveled: %.2f km\n", distanceTraveled);

    return 0;
}