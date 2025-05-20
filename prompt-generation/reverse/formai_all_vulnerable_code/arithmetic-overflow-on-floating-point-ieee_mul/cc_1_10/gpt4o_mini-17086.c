//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold GPS coordinates
typedef struct {
    double latitude;
    double longitude;
} Coordinate;

// Structure to represent a location
typedef struct {
    char name[50];
    Coordinate coord;
} Location;

// Array of predefined locations
Location locations[] = {
    {"Home", {34.052235, -118.243683}},
    {"Work", {34.052339, -118.243431}},
    {"Park", {34.052711, -118.241600}},
    {"Mall", {34.053768, -118.250638}},
    {"Library", {34.050141, -118.257222}},
};

// Function to calculate distance between two coordinates using the Haversine formula
double haversine(Coordinate coord1, Coordinate coord2) {
    const int R = 6371; // Radius of the earth in kilometers
    double lat_diff = (coord2.latitude - coord1.latitude) * (3.141592653589793 / 180);
    double lon_diff = (coord2.longitude - coord1.longitude) * (3.141592653589793 / 180);
    
    double a = sin(lat_diff/2) * sin(lat_diff/2) +
               cos(coord1.latitude * (3.141592653589793 / 180)) * cos(coord2.latitude * (3.141592653589793 / 180)) *
               sin(lon_diff/2) * sin(lon_diff/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    return R * c; // Distance in kilometers
}

// Function to display all available locations
void displayLocations() {
    printf("Available locations:\n");
    for (int i = 0; i < sizeof(locations)/sizeof(locations[0]); i++) {
        printf("%d. %s (Lat: %.6f, Lon: %.6f)\n", i + 1, locations[i].name, locations[i].coord.latitude, locations[i].coord.longitude);
    }
}

// Function to find nearest location
void findNearestLocation(Coordinate current) {
    double min_distance = __DBL_MAX__;
    Location nearest_location;
    
    for (int i = 0; i < sizeof(locations)/sizeof(locations[0]); i++) {
        double distance = haversine(current, locations[i].coord);
        if (distance < min_distance) {
            min_distance = distance;
            nearest_location = locations[i];
        }
    }
    
    printf("Nearest location: %s (Distance: %.2f km)\n", nearest_location.name, min_distance);
}

int main() {
    Coordinate current_location;
    char choice;
    
    printf("Welcome to the GPS Navigation Simulation! 🚀\n");
    
    // Get the user's current location
    printf("Enter your current latitude: ");
    scanf("%lf", &current_location.latitude);
    printf("Enter your current longitude: ");
    scanf("%lf", &current_location.longitude);
    
    do {
        printf("\nMenu:\n");
        printf("1. Display all locations\n");
        printf("2. Find nearest location\n");
        printf("3. Exit\n");
        printf("Choose an option (1-3): ");
        
        choice = getchar(); // Read the option
        while (getchar() != '\n'); // Clear the input buffer
        
        switch (choice) {
            case '1':
                displayLocations();
                break;
            case '2':
                findNearestLocation(current_location);
                break;
            case '3':
                printf("Exiting the GPS Navigation Simulation. Safe travels!\n");
                break;
            default:
                printf("Invalid option! Please choose again.\n");
                break;
        }
    } while (choice != '3');
    
    return 0;
}