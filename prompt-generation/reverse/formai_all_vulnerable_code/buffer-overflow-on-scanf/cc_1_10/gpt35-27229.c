//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EARTH_RADIUS 6371.0 // In km
#define DEG_TO_RAD 0.0174533 // Conversion factor

// A struct for storing latitude and longitude in degrees
typedef struct {
    double lat_deg; 
    double lon_deg;
} LatLonDegrees;

// A struct for storing latitude and longitude in radians
typedef struct {
    double lat_rad;
    double lon_rad;
} LatLonRadians;

// A function to convert latitude and longitude from degrees to radians
LatLonRadians degToRad(LatLonDegrees coords) {
    LatLonRadians radCoords;
    radCoords.lat_rad = coords.lat_deg * DEG_TO_RAD;
    radCoords.lon_rad = coords.lon_deg * DEG_TO_RAD;
    return radCoords;
}

// A function to calculate the distance between two points on a sphere using the Haversine formula
double haversine(LatLonRadians point1, LatLonRadians point2) {
    double lat1 = point1.lat_rad;
    double lat2 = point2.lat_rad;
    double lon1 = point1.lon_rad;
    double lon2 = point2.lon_rad;
    double dlon = lon2 - lon1;
    double dlat = lat2 - lat1;
    double a = pow(sin(dlat/2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon/2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distance = EARTH_RADIUS * c;
    return distance;
}

int main() {
    // Prompt user for starting and destination coordinates in degrees
    printf("Enter starting latitude (in degrees): ");
    double startLatDeg;
    scanf("%lf", &startLatDeg);
    printf("Enter starting longitude (in degrees): ");
    double startLonDeg;
    scanf("%lf", &startLonDeg);
    printf("Enter destination latitude (in degrees): ");
    double destLatDeg;
    scanf("%lf", &destLatDeg);
    printf("Enter destination longitude (in degrees): ");
    double destLonDeg;
    scanf("%lf", &destLonDeg);
    
    // Convert coordinates to radians
    LatLonDegrees startCoords = {startLatDeg, startLonDeg};
    LatLonDegrees destCoords = {destLatDeg, destLonDeg};
    LatLonRadians start = degToRad(startCoords);
    LatLonRadians dest = degToRad(destCoords);
    
    // Calculate distance between starting and destination points
    double distance = haversine(start, dest);
    
    // Print out distance in kilometers
    printf("The distance between the two points is %f kilometers.\n", distance);
    
    return 0;
}