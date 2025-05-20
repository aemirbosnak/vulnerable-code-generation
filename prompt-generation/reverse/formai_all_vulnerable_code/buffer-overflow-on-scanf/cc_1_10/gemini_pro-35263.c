//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the Earth's radius in meters
#define EARTH_RADIUS 6371000

// Define the structure of a GPS coordinate
typedef struct {
    double latitude;
    double longitude;
} GPS_Coordinate;

// Define the function to calculate the distance between two GPS coordinates
double calculate_distance(GPS_Coordinate coord1, GPS_Coordinate coord2) {
    // Convert the latitudes and longitudes to radians
    double lat1 = coord1.latitude * M_PI / 180;
    double lon1 = coord1.longitude * M_PI / 180;
    double lat2 = coord2.latitude * M_PI / 180;
    double lon2 = coord2.longitude * M_PI / 180;

    // Calculate the difference in latitudes and longitudes
    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;

    // Calculate the square of the half chord length
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(lat1) * cos(lat2) * sin(dLon / 2) * sin(dLon / 2);

    // Calculate the great circle distance
    double distance = 2 * EARTH_RADIUS * atan2(sqrt(a), sqrt(1 - a));

    // Return the distance in meters
    return distance;
}

// Define the function to simulate the GPS navigation system
void simulate_gps_navigation() {
    // Get the starting and ending GPS coordinates from the user
    GPS_Coordinate starting_coord, ending_coord;
    printf("Enter the starting latitude and longitude: ");
    scanf("%lf %lf", &starting_coord.latitude, &starting_coord.longitude);
    printf("Enter the ending latitude and longitude: ");
    scanf("%lf %lf", &ending_coord.latitude, &ending_coord.longitude);

    // Calculate the distance between the starting and ending coordinates
    double distance = calculate_distance(starting_coord, ending_coord);

    // Print the distance to the user
    printf("The distance between the starting and ending coordinates is: %.2f meters\n", distance);
}

// Define the main function
int main() {
    // Simulate the GPS navigation system
    simulate_gps_navigation();

    return 0;
}