//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.0

// Function to calculate distance between two coordinates
double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(lat1) * cos(lat2) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c; // Distance in kilometers
}

// Function to convert degrees to radians
double deg2rad(double deg) {
    return deg * PI / 180.0;
}

// Function to read coordinates from file
void readCoordinates(char *filename, double *lat, double *lon) {
    FILE *fp;
    char line[100];

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    fscanf(fp, "%lf %lf", lat, lon);
    fclose(fp);
}

// Function to calculate distance between current location and destination
double calculateDistanceToDestination(double currentLat, double currentLon, double destinationLat, double destinationLon) {
    return calculateDistance(currentLat, currentLon, destinationLat, destinationLon);
}

// Function to print the coordinates
void printCoordinates(double lat, double lon) {
    printf("Latitude: %.6f\n", lat);
    printf("Longitude: %.6f\n", lon);
}

int main() {
    double currentLat, currentLon, destinationLat, destinationLon;
    char filename[100];

    // Read current location coordinates from file
    printf("Enter the name of the file containing current location coordinates: ");
    scanf("%s", filename);
    readCoordinates(filename, &currentLat, &currentLon);

    // Read destination coordinates from file
    printf("Enter the name of the file containing destination coordinates: ");
    scanf("%s", filename);
    readCoordinates(filename, &destinationLat, &destinationLon);

    // Calculate distance between current location and destination
    double distance = calculateDistanceToDestination(currentLat, currentLon, destinationLat, destinationLon);

    // Print the coordinates and distance
    printf("Current location:\n");
    printCoordinates(currentLat, currentLon);
    printf("Destination:\n");
    printCoordinates(destinationLat, destinationLon);
    printf("Distance: %.2f kilometers\n", distance);

    return 0;
}