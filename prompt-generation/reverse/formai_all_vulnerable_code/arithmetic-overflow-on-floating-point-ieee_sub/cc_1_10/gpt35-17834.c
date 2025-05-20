//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

// Function to calculate the distance between two GPS coordinates
// latitude1 and longitude1 are the coordinates of Point 1
// latitude2 and longitude2 are the coordinates of Point 2
double calculate_distance(double latitude1, double longitude1, double latitude2, double longitude2) {
    double earth_radius = 6371.0; // Earth's radius in km
    double diff_latitude = (latitude2 - latitude1) * (PI / 180.0); // Difference in latitude
    double diff_longitude = (longitude2 - longitude1) * (PI / 180.0); // Difference in longitude
    double a = pow(sin(diff_latitude / 2), 2) + cos(latitude1 * (PI / 180.0)) * cos(latitude2 * (PI / 180.0)) * pow(sin(diff_longitude / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a)); // Central angle
    double distance = earth_radius * c; // Distance between the two points
    return distance;
}

// Structure to hold GPS coordinates of a location
struct location {
    double latitude;
    double longitude;
    char name[50];
};

int main() {
    struct location start; // Starting location
    struct location destination; // Destination location
    double distance; // Distance between start and destination

    // Get starting location's details from user
    printf("Enter starting location details:\n");
    printf("Latitude: ");
    scanf("%lf", &start.latitude);
    printf("Longitude: ");
    scanf("%lf", &start.longitude);
    printf("Name: ");
    scanf("%s", start.name);

    // Get destination location's details from user
    printf("\nEnter destination location details:\n");
    printf("Latitude: ");
    scanf("%lf", &destination.latitude);
    printf("Longitude: ");
    scanf("%lf", &destination.longitude);
    printf("Name: ");
    scanf("%s", destination.name);

    // Calculate the distance between the two locations
    distance = calculate_distance(start.latitude, start.longitude, destination.latitude, destination.longitude);

    // Print the details of the two locations and the distance between them
    printf("\nStarting location: %s (%.6f, %.6f)\n", start.name, start.latitude, start.longitude);
    printf("Destination location: %s (%.6f, %.6f)\n", destination.name, destination.latitude, destination.longitude);
    printf("Distance between the locations: %.2f km\n", distance);

    return 0;
}