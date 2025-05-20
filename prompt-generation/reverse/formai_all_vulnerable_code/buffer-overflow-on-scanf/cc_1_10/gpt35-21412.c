//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// Struct to store user location information
typedef struct Location {
    double latitude;
    double longitude;
} Location;

// Struct to store GPS information for a destination
typedef struct Destination {
    char name[50];
    Location location;
} Destination;

// Function prototypes
Location getCurrentLocation();
void openMap(Location currentLocation, Destination destination);
bool arrivedAtDestination(Location currentLocation, Destination destination);

// Define some destinations
Destination newyork = {"New York City", {40.7128, -74.0060}};
Destination chicago = {"Chicago", {41.8781, -87.6298}};
Destination losangeles = {"Los Angeles", {34.0522, -118.2437}};
Destination houston = {"Houston", {29.7604, -95.3698}};
Destination miami = {"Miami", {25.7617, -80.1918}};
Destination seattle = {"Seattle", {47.6062, -122.3321}};

// Main function
int main() {
    // Get current location
    Location currentLocation = getCurrentLocation();

    // Prompt user for destination choice
    printf("Please choose a destination:\n");
    printf("1. New York City\n");
    printf("2. Chicago\n");
    printf("3. Los Angeles\n");
    printf("4. Houston\n");
    printf("5. Miami\n");
    printf("6. Seattle\n");
    int choice;
    scanf("%d", &choice);

    // Set destination based on user choice
    Destination destination;
    switch(choice) {
        case 1:
            destination = newyork;
            break;
        case 2:
            destination = chicago;
            break;
        case 3:
            destination = losangeles;
            break;
        case 4:
            destination = houston;
            break;
        case 5:
            destination = miami;
            break;
        case 6:
            destination = seattle;
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            exit(0);
    }

    // Simulate GPS navigation to destination
    printf("Navigating to %s...\n", destination.name);
    while(!arrivedAtDestination(currentLocation, destination)) {
        printf("Current location: %lf, %lf\n", currentLocation.latitude, currentLocation.longitude);
        openMap(currentLocation, destination);
        currentLocation.latitude += ((double)rand()/(double)(RAND_MAX)) * 0.1; // Simulate movement
        currentLocation.longitude += ((double)rand()/(double)(RAND_MAX)) * 0.1;
        sleep(1); // Simulate delay in GPS updates
    }
    printf("You have arrived at %s. Enjoy your stay!\n", destination.name);

    return 0;
}

// Function to simulate getting current location
Location getCurrentLocation() {
    Location location;
    printf("Determining current location...\n");
    location.latitude = 40.1234;
    location.longitude = -75.4321;
    return location;
}

// Function to simulate opening a map
void openMap(Location currentLocation, Destination destination) {
    printf("Opening map...\n");
    printf("Route: %lf, %lf -> %lf, %lf\n", currentLocation.latitude, currentLocation.longitude, destination.location.latitude, destination.location.longitude);
}

// Function to check if arrived at destination
bool arrivedAtDestination(Location currentLocation, Destination destination) {
    if(currentLocation.latitude == destination.location.latitude && currentLocation.longitude == destination.location.longitude) {
        return true;
    }
    return false;
}