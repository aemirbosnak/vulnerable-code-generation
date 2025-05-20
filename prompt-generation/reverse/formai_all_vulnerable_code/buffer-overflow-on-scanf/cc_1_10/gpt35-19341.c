//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: careful
#include <stdio.h>

// Defining the struct for storing coordinates of a location
typedef struct {
    double latitude;
    double longitude;
} Coordinate;

// Defining the struct for storing location data
typedef struct {
    char name[40];
    Coordinate coordinate;
} Location;

// Function to calculate the distance between two points using Haversine formula
double distance(Coordinate c1, Coordinate c2) {
    double lat1 = c1.latitude;
    double lat2 = c2.latitude;
    double lon1 = c1.longitude;
    double lon2 = c2.longitude;
    
    double dLat = (lat2 - lat1) * 0.01745329252;
    double dLon = (lon2 - lon1) * 0.01745329252;

    double a = pow(sin(dLat / 2), 2) + cos(lat1 * 0.01745329252) * cos(lat2 * 0.01745329252) * pow(sin(dLon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = 6371 * c;

    return distance;
}

int main() {
    // Defining some location data
    Location karachi = {"Karachi, Pakistan", {24.8607, 67.0011}};
    Location lahore = {"Lahore, Pakistan", {31.5204, 74.3587}};
    Location islamabad = {"Islamabad, Pakistan", {33.6844, 73.0479}};
    Location peshawar = {"Peshawar, Pakistan", {34.0151, 71.5250}};
    Location quetta = {"Quetta, Pakistan", {30.1798, 66.9750}};

    printf("Welcome to GPS Navigation Simulation\n");

    // Asking the user for their current location
    Coordinate userCoordinate;
    printf("Enter your current location:\n");
    printf("Latitude: ");
    scanf("%lf", &userCoordinate.latitude);
    printf("Longitude: ");
    scanf("%lf", &userCoordinate.longitude);

    // Calculating the distances of each location from the user's current location
    double distances[5];
    distances[0] = distance(userCoordinate, karachi.coordinate);
    distances[1] = distance(userCoordinate, lahore.coordinate);
    distances[2] = distance(userCoordinate, islamabad.coordinate);
    distances[3] = distance(userCoordinate, peshawar.coordinate);
    distances[4] = distance(userCoordinate, quetta.coordinate);

    // Finding the location with the minimum distance
    int minIndex = 0;
    double minDistance = distances[0];
    for (int i = 1; i < 5; i++) {
        if (distances[i] < minDistance) {
            minDistance = distances[i];
            minIndex = i;
        }
    }

    // Printing the nearest location to the user
    printf("The nearest location to you is: %s\n", (minIndex == 0 ? karachi.name : (minIndex == 1 ? lahore.name : (minIndex == 2 ? islamabad.name : (minIndex == 3 ? peshawar.name : quetta.name)))));

    return 0;
}