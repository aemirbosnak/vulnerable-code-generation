//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define PI 3.14159265359
#define EARTH_RADIUS 6371.01

typedef struct {
    double lat;
    double lon;
} GPSLocation;

GPSLocation gps_location;
GPSLocation destination;

void initialize_gps() {
    printf("Initializing GPS...\n");
    printf("Enter your current location (latitude and longitude): ");
    scanf("%lf %lf", &gps_location.lat, &gps_location.lon);
}

void set_destination() {
    printf("Enter your destination (latitude and longitude): ");
    scanf("%lf %lf", &destination.lat, &destination.lon);
}

double calculate_distance(double lat1, double lon1, double lat2, double lon2) {
    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(lat1) * cos(lat2) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = EARTH_RADIUS * c;
    return distance;
}

void get_directions() {
    double distance = calculate_distance(gps_location.lat, gps_location.lon, destination.lat, destination.lon);
    printf("Distance to destination: %.2lf km\n", distance);
    printf("Directions:\n");
    if (distance < 1) {
        printf("You have reached your destination!\n");
    } else {
        double bearing = atan2(destination.lon - gps_location.lon, destination.lat - gps_location.lat);
        printf("Head %.2lf degrees north\n", bearing * 180 / PI);
    }
}

int main() {
    initialize_gps();
    set_destination();
    get_directions();
    return 0;
}