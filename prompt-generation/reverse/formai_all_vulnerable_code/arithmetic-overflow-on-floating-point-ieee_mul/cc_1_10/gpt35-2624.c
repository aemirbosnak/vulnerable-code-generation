//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants for conversion between degrees and radians
#define DEG_TO_RAD 0.01745329252
#define RAD_TO_DEG 57.295779513

// Define a function to calculate the distance between two GPS coordinates in meters
double distance(double lat1, double lon1, double lat2, double lon2) {
    double d_lat = (lat2 - lat1) * DEG_TO_RAD;
    double d_lon = (lon2 - lon1) * DEG_TO_RAD;
    double a = pow(sin(d_lat / 2), 2) + cos(lat1 * DEG_TO_RAD) * cos(lat2 * DEG_TO_RAD) * pow(sin(d_lon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = 6371000 * c;
    return distance;
}

// Define a function to calculate the bearing between two GPS coordinates in degrees
double bearing(double lat1, double lon1, double lat2, double lon2) {
    double d_lon = (lon2 - lon1) * DEG_TO_RAD;
    double lat1_rad = lat1 * DEG_TO_RAD;
    double lat2_rad = lat2 * DEG_TO_RAD;
    double y = sin(d_lon) * cos(lat2_rad);
    double x = cos(lat1_rad) * sin(lat2_rad) - sin(lat1_rad) * cos(lat2_rad) * cos(d_lon);
    double bearing = atan2(y, x) * RAD_TO_DEG;
    return bearing;
}

// Define the main function to prompt the user for input and simulate the GPS navigation
int main() {
    // Define variables for the starting and ending coordinates
    double start_lat, start_lon, end_lat, end_lon;
    printf("Enter the starting latitude and longitude (in degrees):\n");
    scanf("%lf %lf", &start_lat, &start_lon);
    printf("Enter the ending latitude and longitude (in degrees):\n");
    scanf("%lf %lf", &end_lat, &end_lon);

    // Calculate the distance and bearing between the starting and ending coordinates
    double dist = distance(start_lat, start_lon, end_lat, end_lon);
    double bear = bearing(start_lat, start_lon, end_lat, end_lon);

    // Print out the initial information
    printf("Starting coordinates: %.6f, %.6f\n", start_lat, start_lon);
    printf("Ending coordinates: %.6f, %.6f\n", end_lat, end_lon);
    printf("Distance: %.2f meters\n", dist);
    printf("Bearing: %.2f degrees\n", bear);

    // Simulate the navigation by prompting the user for a new bearing and distance every step
    double current_lat = start_lat;
    double current_lon = start_lon;
    while (dist > 0) {
        double new_bear;
        double new_dist;
        printf("Enter the new bearing and distance (in degrees and meters):\n");
        scanf("%lf %lf", &new_bear, &new_dist);
        current_lat += new_dist / 6371000 * cos((bear + new_bear) * DEG_TO_RAD);
        current_lon += new_dist / 6371000 * sin((bear + new_bear) * DEG_TO_RAD) / cos(current_lat * DEG_TO_RAD);
        dist -= new_dist;
        bear = fmod(bear + new_bear, 360);
        printf("Current location: %.6f, %.6f\n", current_lat, current_lon);
        printf("Distance remaining: %.2f meters\n", dist);
        printf("Bearing: %.2f degrees\n", bear);
    }

    // Print out the final information
    printf("Destination reached!\n");
    printf("Final coordinates: %.6f, %.6f\n", current_lat, current_lon);
    return 0;
}