//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: light-weight
#include <stdio.h>
#include <math.h>

#define RADIUS_OF_EARTH 6371.0 // in kilometers

// Function to calculate the distance between two given GPS coordinates
double distance(double lat1, double lon1, double lat2, double lon2) {
    double dLat = (lat2 - lat1) * M_PI / 180;  // convert to radians
    double dLon = (lon2 - lon1) * M_PI / 180;
    double a = pow(sin(dLat / 2), 2) + cos(lat1 * M_PI / 180) * cos(lat2 * M_PI / 180) * pow(sin(dLon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance_km = RADIUS_OF_EARTH * c;
    return distance_km;
}

// Structure to hold GPS coordinates
typedef struct {
    double latitude;
    double longitude;
} GPS;

int main() {
    // Enter starting and destination GPS coordinates
    GPS start, dest;
    printf("Enter starting latitude: ");
    scanf("%lf", &start.latitude);
    printf("Enter starting longitude: ");
    scanf("%lf", &start.longitude);
    printf("Enter destination latitude: ");
    scanf("%lf", &dest.latitude);
    printf("Enter destination longitude: ");
    scanf("%lf", &dest.longitude);

    // Calculate and print the distance between the two GPS coordinates
    double dist = distance(start.latitude, start.longitude, dest.latitude, dest.longitude);
    printf("Distance between the two coordinates: %.2f km\n", dist);

    // Simulate the GPS navigation
    double current_lat = start.latitude;
    double current_lon = start.longitude;
    double bearing = atan2(sin(dest.longitude - start.longitude) * cos(dest.latitude), cos(current_lat) * sin(dest.latitude) - sin(current_lat) * cos(dest.latitude) * cos(dest.longitude - current_lon));
    double distance_remaining = dist;
    double distance_to_turn = 0;

    while (distance_remaining > 0) {
        // Print current location and remaining distance
        printf("Current Lat: %lf,  Current Lon: %lf,  Distance Remaining: %.2f km\n", current_lat, current_lon, distance_remaining);

        // Calculate the amount of distance remaining until the next turn
        distance_to_turn = sqrt(pow(distance_remaining, 2) + pow(distance_remaining * tan(bearing - current_lon), 2));

        // Move the car forward along the bearing until it reaches the turning point
        while (distance_to_turn > 0) {
            // Calculate the new GPS coordinates
            current_lat += (distance_to_turn * cos(bearing)) / RADIUS_OF_EARTH * 180 / M_PI;
            current_lon += (distance_to_turn * sin(bearing)) / (RADIUS_OF_EARTH * cos(current_lat * M_PI / 180)) * 180 / M_PI;

            // Reduce the distance remaining
            distance_remaining -= distance_to_turn;

            // Calculate the new bearing
            bearing = atan2(sin(dest.longitude - current_lon) * cos(dest.latitude), cos(current_lat) * sin(dest.latitude) - sin(current_lat) * cos(dest.latitude) * cos(dest.longitude - current_lon));

            // Calculate the distance remaining until the next turn
            distance_to_turn = sqrt(pow(distance_remaining, 2) + pow(distance_remaining * tan(bearing - current_lon), 2));
        }

        // Print message to turn
        printf("Turn in %.2f km\n", distance_remaining);

        // Adjust bearing to turn towards the destination
        bearing = atan2(sin(dest.longitude - current_lon) * cos(dest.latitude), cos(current_lat) * sin(dest.latitude) - sin(current_lat) * cos(dest.latitude) * cos(dest.longitude - current_lon));
    }

    // Print reached message
    printf("You have reached your destination!\n");
    return 0;
}