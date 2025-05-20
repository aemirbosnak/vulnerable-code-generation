//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EARTH_RADIUS 6371.01 // in kilometers
#define PI 3.14159265

// Structure to represent a GPS coordinate
typedef struct {
    double latitude;  // in degrees
    double longitude; // in degrees
} GPS_Coordinate;

// Function to convert degrees to radians
double degrees_to_radians(double degrees) {
    return degrees * (PI / 180.0);
}

// Function to convert radians to degrees
double radians_to_degrees(double radians) {
    return radians * (180.0 / PI);
}

// Function to calculate the distance between two GPS coordinates
double distance_between_coordinates(GPS_Coordinate coord1, GPS_Coordinate coord2) {
    // Convert coordinates to radians
    double lat1_rad = degrees_to_radians(coord1.latitude);
    double lon1_rad = degrees_to_radians(coord1.longitude);
    double lat2_rad = degrees_to_radians(coord2.latitude);
    double lon2_rad = degrees_to_radians(coord2.longitude);

    // Calculate the difference in latitudes and longitudes
    double dlat = lat2_rad - lat1_rad;
    double dlon = lon2_rad - lon1_rad;

    // Calculate the distance using the Haversine formula
    double a = pow(sin(dlat / 2), 2) + cos(lat1_rad) * cos(lat2_rad) * pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = EARTH_RADIUS * c;

    return distance;
}

// Function to simulate GPS navigation
void gps_navigation() {
    // Initialize the current GPS coordinate
    GPS_Coordinate current_coord = {0.0, 0.0};

    // Get the destination GPS coordinate from the user
    printf("Enter the destination latitude and longitude (in degrees, separated by a space): ");
    scanf("%lf %lf", &current_coord.latitude, &current_coord.longitude);

    // Simulate the GPS navigation by repeatedly updating the current GPS coordinate
    while (1) {
        // Get the next GPS coordinate from the user
        printf("Enter the next GPS coordinate (in degrees, separated by a space): ");
        scanf("%lf %lf", &current_coord.latitude, &current_coord.longitude);

        // Calculate the distance to the destination
        double distance_to_destination = distance_between_coordinates(current_coord, current_coord);

        // Print the distance to the destination
        printf("Distance to destination: %.2f kilometers\n", distance_to_destination);

        // Check if the destination has been reached
        if (distance_to_destination < 0.1) {
            printf("Destination reached!\n");
            break;
        }
    }
}

int main() {
    // Simulate GPS navigation
    gps_navigation();

    return 0;
}