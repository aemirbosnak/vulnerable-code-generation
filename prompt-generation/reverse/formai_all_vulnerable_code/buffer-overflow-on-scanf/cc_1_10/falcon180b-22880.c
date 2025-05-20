//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100

typedef struct {
    char name[50];
    double latitude;
    double longitude;
} City;

int main() {
    int numCities;
    City cities[MAX_CITIES];
    char input[100];
    double distance;
    double totalDistance = 0.0;
    int shortestPathIndex = 0;
    City shortestPathCity;

    // Get number of cities from user
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);

    // Get city names and coordinates from user
    for (int i = 0; i < numCities; i++) {
        printf("Enter city %d name: ", i+1);
        scanf("%s", cities[i].name);
        printf("Enter city %s latitude: ", cities[i].name);
        scanf("%lf", &cities[i].latitude);
        printf("Enter city %s longitude: ", cities[i].name);
        scanf("%lf", &cities[i].longitude);
    }

    // Get starting city from user
    printf("Enter starting city name: ");
    scanf("%s", input);

    // Calculate distances between all cities
    for (int i = 0; i < numCities; i++) {
        if (strcmp(cities[i].name, input) == 0) {
            shortestPathIndex = i;
        }
        for (int j = i+1; j < numCities; j++) {
            distance = 2 * asin( sqrt( pow( sin((cities[i].latitude-cities[j].latitude)/2), 2) + cos(cities[i].latitude) * cos(cities[j].latitude) * pow(sin((cities[i].longitude-cities[j].longitude)/2), 2) ) ) * 6371;
            printf("Distance between %s and %s is %.2lf km\n", cities[i].name, cities[j].name, distance);
            totalDistance += distance;
        }
    }

    // Print shortest path
    printf("\nShortest path:\n");
    for (int i = shortestPathIndex; i < numCities; i++) {
        printf("%s ", cities[i].name);
    }
    printf("\nTotal distance: %.2lf km\n", totalDistance);

    return 0;
}