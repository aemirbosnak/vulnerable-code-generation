//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    double latitude;
    double longitude;
} Location;

typedef struct {
    Location *locations;
    int size;
    int capacity;
} GPSNavigator;

// Function to initialize the GPSNavigator
GPSNavigator* initGPSNavigator(int capacity) {
    GPSNavigator *navigator = (GPSNavigator *)malloc(sizeof(GPSNavigator));
    navigator->locations = (Location *)malloc(sizeof(Location) * capacity);
    navigator->size = 0;
    navigator->capacity = capacity;
    return navigator;
}

// Function to add a location to the navigator
void addLocation(GPSNavigator *navigator, double latitude, double longitude) {
    if (navigator->size >= navigator->capacity) {
        navigator->capacity *= 2;
        navigator->locations = (Location *)realloc(navigator->locations, sizeof(Location) * navigator->capacity);
    }
    navigator->locations[navigator->size].latitude = latitude;
    navigator->locations[navigator->size].longitude = longitude;
    navigator->size++;
}

// Function to display all locations
void displayLocations(GPSNavigator *navigator) {
    printf("Stored Locations:\n");
    for (int i = 0; i < navigator->size; i++) {
        printf("Location %d: Latitude: %.6f, Longitude: %.6f\n", i + 1, navigator->locations[i].latitude, navigator->locations[i].longitude);
    }
}

// Function to calculate the distance between two locations
double haversine(double lat1, double lon1, double lat2, double lon2) {
    const double R = 6371.0; // Radius of the Earth in km
    double dLat = (lat2 - lat1) * (3.14159265358979 / 180.0);
    double dLon = (lon2 - lon1) * (3.14159265358979 / 180.0);
    
    double a = 
        sin(dLat / 2) * sin(dLat / 2) +
        cos(lat1 * (3.14159265358979 / 180.0)) * cos(lat2 * (3.14159265358979 / 180.0)) *
        sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    
    return R * c; // Distance in km
}

// Function to calculate and display distances
void calculateDistances(GPSNavigator *navigator) {
    printf("Calculating distances between stored locations:\n");
    for (int i = 0; i < navigator->size; i++) {
        for (int j = i + 1; j < navigator->size; j++) {
            double distance = haversine(navigator->locations[i].latitude, navigator->locations[i].longitude,
                                         navigator->locations[j].latitude, navigator->locations[j].longitude);
            printf("Distance between Location %d and Location %d: %.2f km\n", i + 1, j + 1, distance);
        }
    }
}

// Function to free the memory used by the GPSNavigator
void freeGPSNavigator(GPSNavigator *navigator) {
    free(navigator->locations);
    free(navigator);
}

int main() {
    GPSNavigator *navigator = initGPSNavigator(5);
    
    // Inquiring user for locations
    while (1) {
        double latitude, longitude;
        printf("Please enter latitude (-90 to 90, or -1 to exit): ");
        scanf("%lf", &latitude);
        if (latitude == -1) break;
        
        printf("Please enter longitude (-180 to 180): ");
        scanf("%lf", &longitude);
        
        if (latitude < -90 || latitude > 90 || longitude < -180 || longitude > 180) {
            printf("Error: Invalid coordinates! Please try again.\n");
            continue;
        }
        
        addLocation(navigator, latitude, longitude);
        printf("Location added!\n");
    }

    // Displaying all locations
    displayLocations(navigator);
    
    // Calculating and displaying distances
    calculateDistances(navigator);
    
    // Freeing resources
    freeGPSNavigator(navigator);
    
    return 0;
}