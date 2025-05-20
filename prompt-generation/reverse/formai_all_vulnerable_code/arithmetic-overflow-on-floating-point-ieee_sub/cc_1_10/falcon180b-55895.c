//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159
#define EARTH_RADIUS 6371 // in km
#define LAT_RADIUS 6371 // in km
#define LONG_RADIUS 6371 // in km
#define SPEED_OF_LIGHT 299792458 // in m/s
#define GPS_ACCURACY 10 // in meters

struct {
    double lat;
    double lon;
} current_location;

struct {
    double lat;
    double lon;
} destination;

double distance(double lat1, double lon1, double lat2, double lon2) {
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(lat1) * cos(lat2) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return LAT_RADIUS * c; // in km
}

void gps_update() {
    current_location.lat += rand() % GPS_ACCURACY - GPS_ACCURACY / 2;
    current_location.lon += rand() % GPS_ACCURACY - GPS_ACCURACY / 2;
}

int main() {
    srand(time(NULL));

    printf("Welcome to the GPS Navigation System!\n");

    printf("Enter your current location (latitude and longitude): ");
    scanf("%lf %lf", &current_location.lat, &current_location.lon);

    printf("Enter your destination (latitude and longitude): ");
    scanf("%lf %lf", &destination.lat, &destination.lon);

    double distance_to_destination = distance(current_location.lat, current_location.lon, destination.lat, destination.lon);

    while (distance_to_destination > GPS_ACCURACY) {
        printf("You are %.2f km away from your destination.\n", distance_to_destination);
        gps_update();
        distance_to_destination = distance(current_location.lat, current_location.lon, destination.lat, destination.lon);
    }

    printf("You have reached your destination!\n");

    return 0;
}