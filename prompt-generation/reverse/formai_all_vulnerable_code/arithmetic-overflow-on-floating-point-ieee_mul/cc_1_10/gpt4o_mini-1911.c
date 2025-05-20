//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a location
typedef struct {
    char name[50];
    double latitude;
    double longitude;
} Location;

// Function to calculate distance (using a simple Euclidean formula)
double calculateDistance(double lat1, double long1, double lat2, double long2) {
    return sqrt((lat2 - lat1) * (lat2 - lat1) + (long2 - long1) * (long2 - long1));
}

// Function to get the closest location from the current location
Location findClosestLocation(Location *locations, int locationCount, double currentLat, double currentLong) {
    Location closest = locations[0];
    double closestDistance = calculateDistance(currentLat, currentLong, closest.latitude, closest.longitude);

    for (int i = 1; i < locationCount; i++) {
        double distance = calculateDistance(currentLat, currentLong, locations[i].latitude, locations[i].longitude);
        if (distance < closestDistance) {
            closestDistance = distance;
            closest = locations[i];
        }
    }

    return closest;
}

// Function to print navigation instructions
void printNavigationInstructions(Location currentLocation, Location destination) {
    printf("Current Location: %s\n", currentLocation.name);
    printf("Destination: %s\n", destination.name);
    printf("Instructions:\n");
    printf("1. Head towards latitude %.2f, longitude %.2f\n", destination.latitude, destination.longitude);
    printf("2. You will reach %s in a straight path!\n", destination.name);
}

// Function to simulate the GPS Navigation
void gpsNavigationSimulation() {
    // Hardcoded set of locations
    Location locations[] = {
        {"Location A", 37.7749, -122.4194},
        {"Location B", 34.0522, -118.2437},
        {"Location C", 40.7128, -74.0060},
        {"Location D", 41.8781, -87.6298},
        {"Location E", 29.7604, -95.3698}
    };
    int locationCount = sizeof(locations) / sizeof(locations[0]);

    char userInput[50];
    double currentLat, currentLong;

    // User inputs current location
    printf("Enter your current latitude: ");
    fgets(userInput, sizeof(userInput), stdin);
    currentLat = atof(userInput);

    printf("Enter your current longitude: ");
    fgets(userInput, sizeof(userInput), stdin);
    currentLong = atof(userInput);

    // Find the closest location
    Location closestLocation = findClosestLocation(locations, locationCount, currentLat, currentLong);

    // User inputs destination
    printf("Closest location found: %s\n", closestLocation.name);
    printf("Would you like to navigate to this location? (yes/no): ");
    fgets(userInput, sizeof(userInput), stdin);

    if (strncmp(userInput, "yes", 3) == 0) {
        printNavigationInstructions(closestLocation, closestLocation);
    } else {
        printf("Navigation cancelled.\n");
    }
}

int main() {
    printf("GPS Navigation Simulation\n");
    while (1) {
        gpsNavigationSimulation();
        char option[10];
        printf("Do you want to start a new navigation? (yes/no): ");
        fgets(option, sizeof(option), stdin);
        if (strncmp(option, "no", 2) == 0) {
            break;
        }
    }
    printf("Exiting GPS Navigation Simulation.\n");
    return 0;
}