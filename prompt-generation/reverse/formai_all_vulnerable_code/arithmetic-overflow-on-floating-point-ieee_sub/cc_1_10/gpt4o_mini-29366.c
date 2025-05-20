//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: calm
#include <stdio.h>
#include <math.h>
#include <string.h>

// Define a structure for location
typedef struct {
    char name[50];
    double latitude;
    double longitude;
} Location;

// Function to calculate the distance between two geographic coordinates using Haversine formula
double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    const double R = 6371.0; // Earth's radius in kilometers
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;

    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(lat1 * M_PI / 180.0) * cos(lat2 * M_PI / 180.0) *
               sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return R * c;
}

// Function to estimate the time of arrival based on the mode of transport
double estimateTime(double distance, const char* mode) {
    if (strcmp(mode, "walking") == 0) {
        return distance / 5.0; // Average walking speed in km/h
    } else if (strcmp(mode, "bicycling") == 0) {
        return distance / 15.0; // Average cycling speed in km/h
    } else if (strcmp(mode, "driving") == 0) {
        return distance / 60.0; // Average driving speed in km/h
    }
    return -1; // Unknown mode
}

// Main function
int main() {
    Location currentLocation;
    Location destination;
    char transportMode[20];
    
    // Input current location
    printf("Welcome to the GPS Navigation Simulation.\n");
    printf("Please enter your current location name: ");
    fgets(currentLocation.name, sizeof(currentLocation.name), stdin);
    currentLocation.name[strcspn(currentLocation.name, "\n")] = 0; // Remove newline
    printf("Enter latitude of current location: ");
    scanf("%lf", &currentLocation.latitude);
    printf("Enter longitude of current location: ");
    scanf("%lf", &currentLocation.longitude);
    
    // Input destination location
    printf("\nPlease enter your destination location name: ");
    getchar(); // Clear the newline from stdin
    fgets(destination.name, sizeof(destination.name), stdin);
    destination.name[strcspn(destination.name, "\n")] = 0; // Remove newline
    printf("Enter latitude of destination: ");
    scanf("%lf", &destination.latitude);
    printf("Enter longitude of destination: ");
    scanf("%lf", &destination.longitude);
    
    // Input mode of transport
    printf("\nPlease choose mode of transport (walking, bicycling, driving): ");
    getchar(); // Clear the newline from stdin
    fgets(transportMode, sizeof(transportMode), stdin);
    transportMode[strcspn(transportMode, "\n")] = 0; // Remove newline
    
    // Calculate distance and estimated time of arrival
    double distance = calculateDistance(currentLocation.latitude, currentLocation.longitude,
                                         destination.latitude, destination.longitude);
    double timeOfArrival = estimateTime(distance, transportMode);
    
    // Output results
    if (timeOfArrival < 0) {
        printf("Unknown mode of transport.\n");
    } else {
        printf("\nFrom: %s\nTo: %s\n", currentLocation.name, destination.name);
        printf("Total Distance: %.2f km\n", distance);
        printf("Estimated Time of Arrival: %.2f hours\n", timeOfArrival);
    }
    
    printf("\nThank you for using our navigation system. Safe travels!\n");
    return 0;
}