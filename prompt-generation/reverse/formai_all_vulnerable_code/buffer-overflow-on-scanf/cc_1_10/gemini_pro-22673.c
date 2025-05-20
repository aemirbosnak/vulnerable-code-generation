//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the GPS coordinates
typedef struct {
    double latitude;
    double longitude;
} GPS_Coordinates;

// Function to calculate the distance between two GPS coordinates
double calculate_distance(GPS_Coordinates coord1, GPS_Coordinates coord2) {
    double earth_radius = 6371;  // Radius of the earth in kilometers
    double d_lat = (coord2.latitude - coord1.latitude) * (M_PI / 180);
    double d_lon = (coord2.longitude - coord1.longitude) * (M_PI / 180);
    double a = sin(d_lat / 2) * sin(d_lat / 2) + cos(coord1.latitude * (M_PI / 180)) * cos(coord2.latitude * (M_PI / 180)) * sin(d_lon / 2) * sin(d_lon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return earth_radius * c;
}

// Function to simulate GPS navigation
void gps_navigation() {
    // Get the starting and destination GPS coordinates
    GPS_Coordinates start_coord;
    printf("Enter the starting latitude: ");
    scanf("%lf", &start_coord.latitude);
    printf("Enter the starting longitude: ");
    scanf("%lf", &start_coord.longitude);
    GPS_Coordinates dest_coord;
    printf("Enter the destination latitude: ");
    scanf("%lf", &dest_coord.latitude);
    printf("Enter the destination longitude: ");
    scanf("%lf", &dest_coord.longitude);

    // Calculate the distance between the starting and destination coordinates
    double distance = calculate_distance(start_coord, dest_coord);

    // Print the distance and provide navigation instructions
    printf("The distance between the starting and destination coordinates is: %.2f kilometers.\n\n", distance);
    printf("Navigation instructions:\n");
    double bearing = atan2(dest_coord.latitude - start_coord.latitude, dest_coord.longitude - start_coord.longitude);
    printf("1. Head %.2f degrees from north.\n", bearing * (180 / M_PI));
    printf("2. Travel for %.2f kilometers.\n", distance);
    printf("3. You have reached your destination.\n");
}

// Main function
int main() {
    // Simulate GPS navigation
    gps_navigation();

    return 0;
}