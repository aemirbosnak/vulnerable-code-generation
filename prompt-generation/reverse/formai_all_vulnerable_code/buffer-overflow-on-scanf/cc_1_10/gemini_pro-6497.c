//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the Earth's radius in kilometers
#define EARTH_RADIUS 6371

// Structure to represent a GPS coordinate
typedef struct {
    double latitude;
    double longitude;
} GPS_Coordinate;

// Function to calculate the distance between two GPS coordinates
double calculate_distance(GPS_Coordinate coord1, GPS_Coordinate coord2) {
    // Convert latitudes and longitudes to radians
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
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    // Return the distance in kilometers
    return EARTH_RADIUS * c;
}

// Function to simulate GPS navigation
void simulate_gps_navigation() {
    // Get the starting GPS coordinate
    GPS_Coordinate start_coord;
    printf("Enter the starting latitude: ");
    scanf("%lf", &start_coord.latitude);
    printf("Enter the starting longitude: ");
    scanf("%lf", &start_coord.longitude);

    // Get the destination GPS coordinate
    GPS_Coordinate dest_coord;
    printf("Enter the destination latitude: ");
    scanf("%lf", &dest_coord.latitude);
    printf("Enter the destination longitude: ");
    scanf("%lf", &dest_coord.longitude);

    // Calculate the distance between the starting and destination coordinates
    double distance = calculate_distance(start_coord, dest_coord);

    // Print the distance
    printf("The distance to the destination is %f kilometers.\n", distance);

    // Simulate the GPS navigation
    while (distance > 0) {
        // Get the current GPS coordinate
        GPS_Coordinate current_coord;
        printf("Enter the current latitude: ");
        scanf("%lf", &current_coord.latitude);
        printf("Enter the current longitude: ");
        scanf("%lf", &current_coord.longitude);

        // Calculate the distance between the current and destination coordinates
        double remaining_distance = calculate_distance(current_coord, dest_coord);

        // Print the remaining distance
        printf("The remaining distance to the destination is %f kilometers.\n", remaining_distance);

        // Update the distance
        distance = remaining_distance;
    }

    // Arrived at the destination
    printf("You have arrived at your destination!\n");
}

int main() {
    simulate_gps_navigation();
    return 0;
}