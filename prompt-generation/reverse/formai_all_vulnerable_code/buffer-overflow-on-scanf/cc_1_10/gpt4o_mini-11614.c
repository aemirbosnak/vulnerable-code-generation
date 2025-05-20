//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PARKING_SPOTS 10

typedef struct {
    double latitude;
    double longitude;
    char name[50];
} Location;

typedef struct {
    Location spots[MAX_PARKING_SPOTS];
    int count;
} ParkingLot;

double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    const double R = 6371; // Radius of the Earth in kilometers
    double dLat = (lat2 - lat1) * (M_PI / 180);
    double dLon = (lon2 - lon1) * (M_PI / 180);
    lat1 = lat1 * (M_PI / 180);
    lat2 = lat2 * (M_PI / 180);

    double a = sin(dLat/2) * sin(dLat/2) +
               cos(lat1) * cos(lat2) * 
               sin(dLon/2) * sin(dLon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distance = R * c; // Distance in kilometers
    return distance;
}

void displayParkingLot(ParkingLot *lot) {
    printf("Available Parking Spots:\n");
    for (int i = 0; i < lot->count; i++) {
        printf("%d: %s (Lat: %.4f, Lon: %.4f)\n", 
               i + 1, lot->spots[i].name, 
               lot->spots[i].latitude, 
               lot->spots[i].longitude);
    }
    printf("\n");
}

int findNearestParkingSpot(ParkingLot *lot, double userLat, double userLon) {
    double minDistance = INFINITY;
    int nearestSpotIndex = -1;

    for (int i = 0; i < lot->count; i++) {
        double distance = calculateDistance(userLat, userLon, lot->spots[i].latitude, lot->spots[i].longitude);
        if (distance < minDistance) {
            minDistance = distance;
            nearestSpotIndex = i;
        }
    }

    return nearestSpotIndex;
}

int main() {
    ParkingLot parkingLot;
    parkingLot.count = 5;

    // Sample parking spots
    parkingLot.spots[0] = (Location){37.7749, -122.4194, "Union Square"};
    parkingLot.spots[1] = (Location){37.7849, -122.4194, "Chinatown"};
    parkingLot.spots[2] = (Location){37.7649, -122.4394, "Golden Gate Park"};
    parkingLot.spots[3] = (Location){37.7549, -122.4094, "Fisherman's Wharf"};
    parkingLot.spots[4] = (Location){37.7949, -122.4194, "Pier 39"};

    double userLatitude, userLongitude;

    printf("Welcome to the GPS Navigation Simulation!\n");
    printf("Please enter your current location (latitude and longitude):\n");
    
    printf("Latitude: ");
    scanf("%lf", &userLatitude);
    printf("Longitude: ");
    scanf("%lf", &userLongitude);

    // Display available parking spots
    displayParkingLot(&parkingLot);

    // Find nearest parking spot
    int nearestSpotIndex = findNearestParkingSpot(&parkingLot, userLatitude, userLongitude);
    
    if (nearestSpotIndex != -1) {
        printf("The closest parking spot to you is: %s (Lat: %.4f, Lon: %.4f)\n", 
               parkingLot.spots[nearestSpotIndex].name, 
               parkingLot.spots[nearestSpotIndex].latitude, 
               parkingLot.spots[nearestSpotIndex].longitude);
    } else {
        printf("No parking spots available.\n");
    }

    printf("Thank you for using the GPS Navigation Simulation! Safe travels!\n");
    return 0;
}