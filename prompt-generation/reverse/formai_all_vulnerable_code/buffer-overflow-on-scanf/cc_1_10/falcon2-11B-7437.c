//Falcon2-11B DATASET v1.0 Category: GPS Navigation Simulation ; Style: detailed
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Constants
#define DEGREES_TO_RADIANS 0.017453292519943295769236907684886 // converts degrees to radians
#define METERS_TO_FEET 3.2808399 // converts meters to feet

// Global variables
float latitude, longitude, altitude;
float target_latitude, target_longitude, target_altitude;
float speed, heading;

// Function to convert degrees to radians
float degreesToRadians(float degrees) {
    return degrees * DEGREES_TO_RADIANS;
}

// Function to convert meters to feet
float metersToFeet(float meters) {
    return meters * METERS_TO_FEET;
}

// Function to calculate distance between two points in meters
float calculateDistance(float lat1, float lon1, float lat2, float lon2) {
    float dlat = degreesToRadians(lat2 - lat1);
    float dlon = degreesToRadians(lon2 - lon1);
    float a = sin(dlat / 2) * sin(dlat / 2) + cos(degreesToRadians(lat1)) * cos(degreesToRadians(lat2)) * sin(dlon / 2) * sin(dlon / 2);
    float c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return 6371 * c * 1000; // Earth's radius in km * c * 1000 (converts to meters)
}

// Function to calculate bearing between two points in degrees
float calculateBearing(float lat1, float lon1, float lat2, float lon2) {
    float dlat = degreesToRadians(lat2 - lat1);
    float dlon = degreesToRadians(lon2 - lon1);
    float sin_dlon = sin(dlon);
    float cos_dlat = cos(degreesToRadians(lat1)) * cos(degreesToRadians(lat2));
    float cos_dlon2 = cos(dlon) * cos_dlat;
    float sin_dlon2 = sin(dlon) * cos_dlat;
    float bearing = atan2(sin_dlon2, cos_dlon2);
    if (bearing < 0) {
        bearing += 2 * M_PI;
    }
    return bearing;
}

// Main function
int main() {
    // Get user input for current GPS coordinates
    printf("Enter latitude (degrees): ");
    scanf("%f", &latitude);
    latitude *= DEGREES_TO_RADIANS;
    printf("Enter longitude (degrees): ");
    scanf("%f", &longitude);
    longitude *= DEGREES_TO_RADIANS;
    printf("Enter altitude (meters): ");
    scanf("%f", &altitude);

    // Get user input for target GPS coordinates
    printf("Enter target latitude (degrees): ");
    scanf("%f", &target_latitude);
    target_latitude *= DEGREES_TO_RADIANS;
    printf("Enter target longitude (degrees): ");
    scanf("%f", &target_longitude);
    target_longitude *= DEGREES_TO_RADIANS;
    printf("Enter target altitude (meters): ");
    scanf("%f", &target_altitude);

    // Calculate distance between current and target GPS coordinates
    float distance = calculateDistance(latitude, longitude, target_latitude, target_longitude);

    // Calculate bearing between current and target GPS coordinates
    float bearing = calculateBearing(latitude, longitude, target_latitude, target_longitude);

    // Print distance and bearing
    printf("Distance: %.2f km\n", distance / 1000);
    printf("Bearing: %.2f degrees\n", bearing * 180 / M_PI);

    // Calculate speed and heading
    float speed = 10; // arbitrary value
    float heading = 0; // arbitrary value

    // Print speed and heading
    printf("Speed: %.2f km/h\n", speed * 1000 / 3600);
    printf("Heading: %.2f degrees\n", heading * 180 / M_PI);

    // Print total distance traveled and time elapsed
    float total_distance = distance;
    float time_elapsed = total_distance / speed;
    printf("Total distance traveled: %.2f km\n", total_distance / 1000);
    printf("Time elapsed: %.2f hours\n", time_elapsed / 3600);

    return 0;
}