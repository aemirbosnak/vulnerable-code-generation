//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LOCATIONS 100
#define EARTH_RADIUS 6371.01

struct Location {
    char name[50];
    double latitude;
    double longitude;
};

int num_locations = 0;
struct Location locations[MAX_LOCATIONS];

double to_radians(double degrees) {
    return degrees * M_PI / 180.0;
}

double calculate_distance(double lat1, double long1, double lat2, double long2) {
    double delta_lat = to_radians(lat2 - lat1);
    double delta_long = to_radians(long2 - long1);
    double a = pow(sin(delta_lat/2), 2) + cos(to_radians(lat1)) * cos(to_radians(lat2)) * pow(sin(delta_long/2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    return EARTH_RADIUS * c;
}

void add_location(char* name, double latitude, double longitude) {
    if (num_locations == MAX_LOCATIONS) {
        printf("Error: maximum number of locations exceeded.\n");
        exit(EXIT_FAILURE);
    }
    struct Location new_location;
    sprintf(new_location.name, "%s", name);
    new_location.latitude = latitude;
    new_location.longitude = longitude;
    locations[num_locations++] = new_location;
}

int main() {
    printf("GPS Navigation Simulator\n");
    printf("------------------------\n");

    add_location("New York City", 40.7128, -74.0060);
    add_location("Los Angeles", 34.0522, -118.2437);
    add_location("Chicago", 41.8781, -87.6298);
    add_location("Houston", 29.7604, -95.3698);

    double user_latitude;
    double user_longitude;
    printf("Enter your current latitude: ");
    scanf("%lf", &user_latitude);
    printf("Enter your current longitude: ");
    scanf("%lf", &user_longitude);

    printf("Select a location to navigate to:\n");
    for (int i=0; i<num_locations; i++) {
        printf("%d. %s\n", i+1, locations[i].name);
    }

    int dest_index;
    printf("Enter a number between 1 and %d: ", num_locations);
    scanf("%d", &dest_index);
    if (dest_index < 1 || dest_index > num_locations) {
        printf("Error: invalid destination index.\n");
        exit(EXIT_FAILURE);
    }

    double dest_latitude = locations[dest_index-1].latitude;
    double dest_longitude = locations[dest_index-1].longitude;
    double distance = calculate_distance(user_latitude, user_longitude, dest_latitude, dest_longitude);

    printf("Navigating to %s...\n", locations[dest_index-1].name);
    printf("Distance to destination: %.2f km\n", distance);

    return 0;
}