//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 100

// Define structure for each city
typedef struct {
    char name[50];
    double latitude;
    double longitude;
} City;

int main() {
    int num_cities;
    City cities[MAX_CITIES];

    // Read in number of cities
    printf("Enter the number of cities: ");
    scanf("%d", &num_cities);

    // Read in city information
    for (int i = 0; i < num_cities; i++) {
        printf("Enter city name: ");
        scanf("%s", cities[i].name);
        printf("Enter latitude: ");
        scanf("%lf", &cities[i].latitude);
        printf("Enter longitude: ");
        scanf("%lf", &cities[i].longitude);
    }

    // Simulate GPS navigation
    double current_lat = 37.7749;
    double current_lon = -122.4194;
    double dest_lat, dest_lon;
    double distance, shortest_distance = 9999.0;
    int shortest_index = -1;

    printf("Enter destination city name: ");
    scanf("%s", cities[0].name);
    dest_lat = cities[0].latitude;
    dest_lon = cities[0].longitude;

    // Calculate distance between current location and each city
    for (int i = 0; i < num_cities; i++) {
        if (strcmp(cities[i].name, cities[0].name) == 0) {
            distance = 0.0;
        } else {
            double dlat = dest_lat - cities[i].latitude;
            double dlon = dest_lon - cities[i].longitude;
            double a = sin(dlat/2) * sin(dlat/2) + cos(current_lat) * cos(cities[i].latitude) * sin(dlon/2) * sin(dlon/2);
            double c = 2 * atan2(sqrt(a), sqrt(1-a));
            distance = 6371 * c;
        }
        // Update shortest distance and index if current city is closer to destination
        if (distance < shortest_distance) {
            shortest_distance = distance;
            shortest_index = i;
        }
    }

    // Display navigation instructions
    printf("Navigation instructions from %s to %s:\n", cities[0].name, cities[shortest_index].name);
    printf("Distance: %.2f km\n", shortest_distance);

    return 0;
}