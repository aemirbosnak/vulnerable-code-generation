//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.01

struct {
    double lat, lon;
} current_location, destination;

void get_current_location() {
    printf("Enter your current location (latitude and longitude):\n");
    scanf("%lf %lf", &current_location.lat, &current_location.lon);
}

void get_destination() {
    printf("Enter your destination (latitude and longitude):\n");
    scanf("%lf %lf", &destination.lat, &destination.lon);
}

double distance(double lat1, double lon1, double lat2, double lon2) {
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(lat1) * cos(lat2) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

double bearing(double lat1, double lon1, double lat2, double lon2) {
    double y = sin(lon2 - lon1) * cos(lat2);
    double x = cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(lon2 - lon1);
    double bearing = atan2(y, x);
    return bearing * 180 / PI;
}

void navigate() {
    printf("Starting navigation...\n");
    srand(time(NULL));
    int step = 1;
    while (distance(current_location.lat, current_location.lon, destination.lat, destination.lon) > 0.1) {
        double bearing_deg = bearing(current_location.lat, current_location.lon, destination.lat, destination.lon);
        printf("Step %d: Turn %.2f degrees towards the destination.\n", step++, bearing_deg);
        current_location.lat += 0.001 * cos(bearing_deg * PI / 180);
        current_location.lon += 0.001 * sin(bearing_deg * PI / 180);
    }
    printf("Arrived at the destination!\n");
}

int main() {
    get_current_location();
    get_destination();
    navigate();
    return 0;
}