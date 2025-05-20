//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Define a struct for a GPS coordinate
typedef struct {
    double latitude;
    double longitude;
} Coordinate;

// Define a function to print a coordinate
void printCoordinate(Coordinate coord) {
    printf("%.6f,%.6f\n", coord.latitude, coord.longitude);
}

// Define a function to calculate the distance between two coordinates
double distanceBetweenCoordinates(Coordinate coord1, Coordinate coord2) {
    double lat1 = coord1.latitude;
    double lon1 = coord1.longitude;
    double lat2 = coord2.latitude;
    double lon2 = coord2.longitude;
    
    double latDistance = lat2 - lat1;
    double lonDistance = lon2 - lon1;
    
    double a = pow(sin(latDistance / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(lonDistance / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    
    const double earthRadius = 6371; // km
    double distance = earthRadius * c;
    
    return distance;
}

int main() {
    int numLocations;
    printf("Enter the number of GPS locations you want to simulate: ");
    scanf("%d", &numLocations);
    
    // Allocate memory for the array of GPS coordinates
    Coordinate* coordinates = malloc(numLocations * sizeof(Coordinate));
    
    // Populate the array with randomly generated coordinates
    for (int i = 0; i < numLocations; i++) {
        double latitude = (double) rand() / RAND_MAX * 180 - 90;
        double longitude = (double) rand() / RAND_MAX * 360 - 180;
        Coordinate coord = {latitude, longitude};
        coordinates[i] = coord;
    }
    
    // Print all of the coordinates
    printf("All coordinates:\n");
    for (int i = 0; i < numLocations; i++) {
        printCoordinate(coordinates[i]);
    }
    
    // Get the starting and ending coordinates from the user
    int startIdx, endIdx;
    printf("Enter the index of the starting location: ");
    scanf("%d", &startIdx);
    printf("Enter the index of the ending location: ");
    scanf("%d", &endIdx);
    
    // Calculate and print the distance between the two coordinates
    printf("Distance between start and end coordinates: %.2f km\n",
           distanceBetweenCoordinates(coordinates[startIdx], coordinates[endIdx]));
    
    // Free the memory allocated for the array of coordinates
    free(coordinates);
    
    return 0;
}