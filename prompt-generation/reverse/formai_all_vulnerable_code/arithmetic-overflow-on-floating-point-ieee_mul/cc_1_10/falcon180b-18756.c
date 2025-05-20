//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.0

struct {
    double latitude;
    double longitude;
} current_location;

void init_location() {
    srand(time(NULL));
    current_location.latitude = rand() % 90 - 45;
    current_location.longitude = rand() % 180 - 90;
}

void print_location() {
    printf("Current location: %.2f° N, %.2f° E\n", current_location.latitude, current_location.longitude);
}

double distance(double lat1, double lon1, double lat2, double lon2) {
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(lat1) * cos(lat2) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

int main() {
    init_location();
    print_location();

    int choice;
    do {
        printf("Enter your destination (1. Latitude, 2. Longitude): ");
        scanf("%d", &choice);

        double dest_lat, dest_lon;
        if (choice == 1) {
            printf("Enter destination latitude: ");
            scanf("%lf", &dest_lat);
            dest_lon = current_location.longitude;
        } else {
            printf("Enter destination longitude: ");
            scanf("%lf", &dest_lon);
            dest_lat = current_location.latitude;
        }

        double distance_to_dest = distance(current_location.latitude, current_location.longitude, dest_lat, dest_lon);
        printf("Distance to destination: %.2f km\n", distance_to_dest);
    } while (1);

    return 0;
}