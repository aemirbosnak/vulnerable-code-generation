//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define R 6371 // Earth's radius in km

// Function to calculate distance between two points on a sphere
double distance(double lat1, double lon1, double lat2, double lon2) {
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(lat1) * cos(lat2) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return R * c; // Distance in km
}

// Function to convert degrees to radians
double deg2rad(double deg) {
    return deg * (PI / 180);
}

// Function to convert radians to degrees
double rad2deg(double rad) {
    return rad * (180 / PI);
}

// Function to calculate the final destination based on user input
void calculate_destination(double start_lat, double start_lon, double end_lat, double end_lon) {
    double distance_km = distance(start_lat, start_lon, end_lat, end_lon);
    printf("The distance between the start and end points is %.2f km.\n", distance_km);
}

// Main function
int main() {
    double start_lat, start_lon, end_lat, end_lon;

    // Get user input for starting location
    printf("Enter the starting latitude: ");
    scanf("%lf", &start_lat);
    printf("Enter the starting longitude: ");
    scanf("%lf", &start_lon);

    // Get user input for destination
    printf("Enter the destination latitude: ");
    scanf("%lf", &end_lat);
    printf("Enter the destination longitude: ");
    scanf("%lf", &end_lon);

    // Calculate and display the distance between the start and end points
    calculate_destination(start_lat, start_lon, end_lat, end_lon);

    return 0;
}