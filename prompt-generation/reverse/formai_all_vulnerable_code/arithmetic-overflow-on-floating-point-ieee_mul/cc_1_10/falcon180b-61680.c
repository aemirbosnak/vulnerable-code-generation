//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.0 // in km
#define MINUTES_TO_DEGREES (PI/30.0)
#define DEGREES_TO_RADIANS (PI/180.0)

// Struct to hold GPS coordinates
typedef struct {
    double lat;
    double lon;
} gps_coord;

// Function to calculate distance between two GPS coordinates (in km)
double calculateDistance(gps_coord start, gps_coord end) {
    double dLat = end.lat - start.lat;
    double dLon = end.lon - start.lon;
    double a = sin(dLat/2) * sin(dLat/2) + cos(start.lat * DEGREES_TO_RADIANS) * cos(end.lat * DEGREES_TO_RADIANS) * sin(dLon/2) * sin(dLon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    return EARTH_RADIUS * c;
}

// Function to convert GPS coordinates from degrees to radians
void convertToRadians(gps_coord *coord) {
    coord->lat = coord->lat * DEGREES_TO_RADIANS;
    coord->lon = coord->lon * DEGREES_TO_RADIANS;
}

// Function to convert GPS coordinates from radians to degrees
void convertToDegrees(gps_coord *coord) {
    coord->lat = coord->lat * (180.0/PI);
    coord->lon = coord->lon * (180.0/PI);
}

// Function to print GPS coordinates
void printCoord(gps_coord coord) {
    printf("%.6f, %.6f\n", coord.lat, coord.lon);
}

// Main function
int main() {
    gps_coord start, end;
    
    // Get starting coordinates from user
    printf("Enter starting coordinates (latitude, longitude): ");
    scanf("%lf, %lf", &start.lat, &start.lon);
    
    // Convert starting coordinates to radians
    convertToRadians(&start);
    
    // Get ending coordinates from user
    printf("Enter ending coordinates (latitude, longitude): ");
    scanf("%lf, %lf", &end.lat, &end.lon);
    
    // Convert ending coordinates to radians
    convertToRadians(&end);
    
    // Calculate distance between starting and ending coordinates
    double distance = calculateDistance(start, end);
    
    // Print results
    printf("Distance between coordinates: %.2f km\n", distance);
    printf("Starting coordinates: ");
    printCoord(start);
    printf("Ending coordinates: ");
    printCoord(end);
    
    return 0;
}