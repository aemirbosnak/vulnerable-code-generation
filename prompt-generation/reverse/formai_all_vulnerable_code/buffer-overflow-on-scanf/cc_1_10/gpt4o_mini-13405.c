//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a location
typedef struct {
    char name[50];
    double latitude;
    double longitude;
} Location;

// A function to calculate distance between two locations (using a simple Euclidean approach)
double calculateDistance(Location loc1, Location loc2) {
    return sqrt((loc2.latitude - loc1.latitude) * (loc2.latitude - loc1.latitude) +
                (loc2.longitude - loc1.longitude) * (loc2.longitude - loc1.longitude));
}

// A function to display the available locations
void displayLocations(Location locations[], int numLocations) {
    printf("Available locations:\n");
    for (int i = 0; i < numLocations; i++) {
        printf("%d. %s (Lat: %.2f, Lon: %.2f)\n", i + 1, locations[i].name, locations[i].latitude, locations[i].longitude);
    }
}

// A function to provide navigation directions
void provideDirections(Location current, Location destination) {
    printf("Navigating from %s to %s...\n", current.name, destination.name);
    
    // Simulated navigation logic
    printf("Move towards:\n");

    if (current.latitude < destination.latitude) {
        printf("- Go North\n");
    } else {
        printf("- Go South\n");
    }

    if (current.longitude < destination.longitude) {
        printf("- Go East\n");
    } else {
        printf("- Go West\n");
    }

    // Simulate the journey
    printf("\nCalculating the distance...\n");
    double distance = calculateDistance(current, destination);
    printf("You are approximately %.2f units away from your destination.\n", distance);
}

int main() {
    Location locations[5] = {
        {"Home", 40.7128, -74.0060},   // Example: New York City
        {"Office", 34.0522, -118.2437}, // Example: Los Angeles
        {"Park", 51.5074, -0.1278},     // Example: London
        {"Cafe", 48.8566, 2.3522},      // Example: Paris
        {"Gym", 35.6895, 139.6917}      // Example: Tokyo
    };

    int numLocations = 5;
    int currentIndex, destinationIndex;

    // Show available locations
    displayLocations(locations, numLocations);

    // Ask user for the current location
    printf("Choose your current location (1-%d): ", numLocations);
    scanf("%d", &currentIndex);
    if (currentIndex < 1 || currentIndex > numLocations) {
        printf("Invalid choice. Please run the program again.\n");
        return 1;
    }

    // Ask user for the destination location
    printf("Choose your destination location (1-%d): ", numLocations);
    scanf("%d", &destinationIndex);
    if (destinationIndex < 1 || destinationIndex > numLocations) {
        printf("Invalid choice. Please run the program again.\n");
        return 1;
    }

    // Adjust for zero-based index
    currentIndex--;
    destinationIndex--;

    // Provide directions to the user
    provideDirections(locations[currentIndex], locations[destinationIndex]);

    return 0;
}