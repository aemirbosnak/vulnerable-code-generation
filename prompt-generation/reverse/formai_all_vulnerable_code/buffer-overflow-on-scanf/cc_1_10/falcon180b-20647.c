//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 100

// Structure for each city
typedef struct {
    char name[30];
    double latitude;
    double longitude;
} City;

// Function to calculate distance between two points
double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;
    double a = sin(dLat/2) * sin(dLat/2) + cos(lat1) * cos(lat2) * sin(dLon/2) * sin(dLon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    return 6371 * c; // Earth's radius in km
}

// Function to find index of city with given name
int findCityIndex(City cities[], int numCities, char name[]) {
    for (int i = 0; i < numCities; i++) {
        if (strcmp(cities[i].name, name) == 0) {
            return i;
        }
    }
    return -1; // City not found
}

// Function to prompt user for city coordinates
void getCityCoordinates(City city) {
    printf("Enter latitude for %s: ", city.name);
    scanf("%lf", &city.latitude);
    printf("Enter longitude for %s: ", city.name);
    scanf("%lf", &city.longitude);
}

// Function to prompt user for destination
void getDestination(City cities[], int numCities) {
    printf("Enter destination city: ");
    char name[30];
    scanf("%s", name);
    int index = findCityIndex(cities, numCities, name);
    if (index == -1) {
        printf("City not found.\n");
        exit(1);
    }
    printf("Distance to %s: ", name);
}

// Function to prompt user for number of cities
int getNumCities() {
    int numCities;
    do {
        printf("Enter number of cities (1-100): ");
        scanf("%d", &numCities);
    } while (numCities < 1 || numCities > MAX_CITIES);
    return numCities;
}

// Function to prompt user for city name and coordinates
void getCityInfo(City cities[], int numCities) {
    for (int i = 0; i < numCities; i++) {
        printf("Enter city %d name: ", i+1);
        scanf("%s", cities[i].name);
        getCityCoordinates(cities[i]);
    }
}

int main() {
    int numCities = getNumCities();
    City cities[numCities];
    getCityInfo(cities, numCities);
    printf("Enter starting city: ");
    char startName[30];
    scanf("%s", startName);
    int startIndex = findCityIndex(cities, numCities, startName);
    if (startIndex == -1) {
        printf("City not found.\n");
        exit(1);
    }
    getDestination(cities, numCities);
    double distance = calculateDistance(cities[startIndex].latitude, cities[startIndex].longitude, cities[findCityIndex(cities, numCities, cities[numCities-1].name)].latitude, cities[findCityIndex(cities, numCities, cities[numCities-1].name)].longitude);
    printf("Distance: %.2lf km\n", distance);
    return 0;
}