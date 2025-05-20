//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: single-threaded
// C GPS Navigation Simulation

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define PI 3.14159265 // Pi constant

// Define a structure to hold the GPS coordinates
typedef struct {
    double latitude;
    double longitude;
} Coordinates;

// Function to calculate distance between two GPS coordinates using Haversine formula
double distance(Coordinates start, Coordinates end) {
    double dLat = (end.latitude - start.latitude) * PI / 180.0;
    double dLon = (end.longitude - start.longitude) * PI / 180.0;

    double a = sin(dLat/2) * sin(dLat/2) + cos(start.latitude * PI / 180.0) * cos(end.latitude * PI / 180.0) * sin(dLon/2) * sin(dLon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double d = 6371.0 * c; // Earth's radius in km

    return d;
}

int main() {
    Coordinates currentLocation = {48.8584, 2.2945}; // Initialize current location
    double totalDistance = 0.0;
    char locationName[256];
    printf("Starting at coordinates: %lf, %lf\n", currentLocation.latitude, currentLocation.longitude);

    // Open a file containing a list of GPS coordinates and corresponding location names
    FILE *fp;
    fp = fopen("gps_data.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read GPS coordinates and location names from file line by line
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        // Get GPS coordinates and location name from line
        char *latitudeStr = strtok(line, ",");
        char *longitudeStr = strtok(NULL, ",");
        strcpy(locationName, strtok(NULL, "\n"));

        // Convert latitude and longitude strings to double
        double latitude = atof(latitudeStr);
        double longitude = atof(longitudeStr);

        // Calculate distance to new location and update current location
        Coordinates newLocation = {latitude, longitude};
        double distanceToNewLocation = distance(currentLocation, newLocation);
        totalDistance += distanceToNewLocation;
        currentLocation = newLocation;

        printf("Traveled from %s to %s - Distance: %.2lf km - Total Distance: %.2lf km\n", locationName, strtok(NULL, "\n"), distanceToNewLocation, totalDistance);
    }

    fclose(fp);

    printf("Arrived at final destination.\n");
    printf("Total Distance Traveled: %.2lf km\n", totalDistance);

    return 0;
}