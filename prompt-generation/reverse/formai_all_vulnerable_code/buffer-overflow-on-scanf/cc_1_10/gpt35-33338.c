//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Constants used for converting degrees to radians (and vice versa)
#define PI 3.14159265359
#define DEG_TO_RAD PI / 180
#define RAD_TO_DEG 180 / PI

// Constants used for GPS navigation calculations
#define EARTH_RADIUS 6371000 // in meters
#define MAX_DISTANCE 10000 // in meters

// Custom data structure for storing location data
typedef struct {
    double latitude; // in degrees
    double longitude; // in degrees
} Location;

// Function prototypes
double calculateDistance(Location location1, Location location2);
double calculateBearing(Location location1, Location location2);
Location calculateNewLocation(Location location, double distance, double bearing);

int main() {
    // Initialize starting location
    Location currentLocation;
    currentLocation.latitude = 40.7128; // New York City latitude
    currentLocation.longitude = -74.0060; // New York City longitude
    
    // Prompt user for destination location
    Location destination;
    printf("Enter destination latitude (in degrees): ");
    scanf("%lf", &destination.latitude);
    printf("Enter destination longitude (in degrees): ");
    scanf("%lf", &destination.longitude);
    
    // Calculate distance and bearing to destination
    double distance = calculateDistance(currentLocation, destination);
    double bearing = calculateBearing(currentLocation, destination);
    
    // Print initial information to user
    printf("\nStarting location: (%lf, %lf)\n", currentLocation.latitude, currentLocation.longitude);
    printf("Destination location: (%lf, %lf)\n", destination.latitude, destination.longitude);
    printf("Distance to destination: %lf meters\n", distance);
    printf("Bearing to destination: %lf degrees\n", bearing);
    
    // Loop until destination is reached or maximum distance is exceeded
    while (distance > 0 && distance < MAX_DISTANCE) {
        // Prompt user for direction of travel
        char direction[10];
        printf("\nEnter direction of travel (N, S, E, W): ");
        scanf("%s", direction);
        
        // Calculate new location based on direction and distance
        Location newLocation;
        if (strcmp(direction, "N") == 0) {
            newLocation = calculateNewLocation(currentLocation, distance, 0);
        } else if (strcmp(direction, "S") == 0) {
            newLocation = calculateNewLocation(currentLocation, distance, 180);
        } else if (strcmp(direction, "E") == 0) {
            newLocation = calculateNewLocation(currentLocation, distance, 90);
        } else if (strcmp(direction, "W") == 0) {
            newLocation = calculateNewLocation(currentLocation, distance, 270);
        } else {
            printf("Invalid direction entered!\n");
            continue;
        }
        
        // Update distance and bearing to destination
        distance = calculateDistance(newLocation, destination);
        bearing = calculateBearing(newLocation, destination);
        
        // Print updated information to user
        printf("\nTraveling %lf meters %s\n", distance, direction);
        printf("New location: (%lf, %lf)\n", newLocation.latitude, newLocation.longitude);
        printf("New bearing to destination: %lf degrees\n", bearing);
        
        // Update current location
        currentLocation = newLocation;
    }
    
    // Check if user reached destination or exceeded maximum distance
    if (distance <= 0) {
        printf("\nYou have reached your destination!\n");
    } else {
        printf("\nYou have exceeded the maximum distance allowed!\n");
    }
    
    return 0;
}

// Function for calculating distance between two locations in meters
double calculateDistance(Location location1, Location location2) {
    double lat1 = location1.latitude * DEG_TO_RAD;
    double lon1 = location1.longitude * DEG_TO_RAD;
    double lat2 = location2.latitude * DEG_TO_RAD;
    double lon2 = location2.longitude * DEG_TO_RAD;
    
    double deltaLat = lat2 - lat1;
    double deltaLon = lon2 - lon1;
    
    double a = pow(sin(deltaLat/2), 2) + cos(lat1) * cos(lat2) * pow(sin(deltaLon/2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    
    double distance = EARTH_RADIUS * c;
    
    return distance;
}

// Function for calculating bearing between two locations in degrees
double calculateBearing(Location location1, Location location2) {
    double lat1 = location1.latitude * DEG_TO_RAD;
    double lon1 = location1.longitude * DEG_TO_RAD;
    double lat2 = location2.latitude * DEG_TO_RAD;
    double lon2 = location2.longitude * DEG_TO_RAD;
    
    double deltaLon = lon2 - lon1;
    
    double y = sin(deltaLon) * cos(lat2);
    double x = cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(deltaLon);
    double bearing = atan2(y, x);
    
    bearing *= RAD_TO_DEG;
    
    return bearing;
}

// Function for calculating new location based on distance and bearing
Location calculateNewLocation(Location location, double distance, double bearing) {
    double lat = location.latitude * DEG_TO_RAD;
    double lon = location.longitude * DEG_TO_RAD;
    bearing *= DEG_TO_RAD;
    
    double newLat = asin(sin(lat) * cos(distance/EARTH_RADIUS) + cos(lat) * sin(distance/EARTH_RADIUS) * cos(bearing));
    double newLon = lon + atan2(sin(bearing) * sin(distance/EARTH_RADIUS) * cos(lat), cos(distance/EARTH_RADIUS) - sin(lat) * sin(newLat));
    
    Location newLocation;
    newLocation.latitude = newLat * RAD_TO_DEG;
    newLocation.longitude = newLon * RAD_TO_DEG;
    
    return newLocation;
}