//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: creative
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.14159265
#define EARTH_RADIUS 6371.0 // in kilometers

typedef struct {
    double latitude;
    double longitude;
} Coordinates;

// Function to calculate distance between two points on Earth
double calculateDistance(Coordinates point1, Coordinates point2) {
    double lat1 = point1.latitude * PI / 180.0;
    double lat2 = point2.latitude * PI / 180.0;
    double dlat = (point2.latitude - point1.latitude) * PI / 180.0;
    double dlon = (point2.longitude - point1.longitude) * PI / 180.0;

    double a = sin(dlat / 2) * sin(dlat / 2) +
               cos(lat1) * cos(lat2) *
               sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return EARTH_RADIUS * c; // distance in kilometers
}

// Function to get the user's current location
Coordinates getCurrentLocation() {
    Coordinates currentLocation;
    currentLocation.latitude = (rand() % 18000 - 9000) / 100.0; // Random latitude [-90, 90]
    currentLocation.longitude = (rand() % 36000 - 18000) / 100.0; // Random longitude [-180, 180]
    return currentLocation;
}

// Function to generate random destination coordinates
Coordinates generateRandomDestination() {
    Coordinates destination;
    destination.latitude = (rand() % 18000 - 9000) / 100.0; // Random latitude
    destination.longitude = (rand() % 36000 - 18000) / 100.0; // Random longitude
    return destination;
}

// Function to navigate to the destination
void navigateToDestination(Coordinates currentLocation, Coordinates destination) {
    double distance = calculateDistance(currentLocation, destination);
    printf("Navigating to destination...\n");
    printf("Current Location: [%f, %f]\n", currentLocation.latitude, currentLocation.longitude);
    printf("Destination: [%f, %f]\n", destination.latitude, destination.longitude);
    printf("Distance to destination: %.2f km\n", distance);

    // Simulate navigation
    for (int i = 0; i < distance; i += 5) {
        double progress = (double)i / distance * 100;
        printf("Navigating... %.2f%% complete\n", progress);
        sleep(1); // Simulate time delay for navigation
    }

    printf("You have arrived at your destination!\n");
}

void printInstructions() {
    printf("\n--- GPS Navigation System ---\n");
    printf("1. Start navigation to a random destination\n");
    printf("2. Set your own destination\n");
    printf("3. Exit\n");
    printf("----------------------------\n");
}

int main() {
    srand(time(NULL)); // Seed random number generator

    int choice;
    Coordinates currentLocation;
    Coordinates destination;

    while (1) {
        printInstructions();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                currentLocation = getCurrentLocation();
                destination = generateRandomDestination();
                navigateToDestination(currentLocation, destination);
                break;

            case 2:
                printf("Enter your destination latitude: ");
                scanf("%lf", &destination.latitude);
                printf("Enter your destination longitude: ");
                scanf("%lf", &destination.longitude);
                currentLocation = getCurrentLocation();
                navigateToDestination(currentLocation, destination);
                break;

            case 3:
                printf("Exiting the GPS navigation system...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}