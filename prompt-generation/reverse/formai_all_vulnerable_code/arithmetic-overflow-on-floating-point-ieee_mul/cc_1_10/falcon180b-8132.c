//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.01

struct location {
    double latitude;
    double longitude;
};

struct location current_location;
struct location destination_location;

void get_current_location(void) {
    printf("Enter current latitude: ");
    scanf("%lf", &current_location.latitude);
    printf("Enter current longitude: ");
    scanf("%lf", &current_location.longitude);
}

void get_destination_location(void) {
    printf("Enter destination latitude: ");
    scanf("%lf", &destination_location.latitude);
    printf("Enter destination longitude: ");
    scanf("%lf", &destination_location.longitude);
}

double distance(double lat1, double lon1, double lat2, double lon2) {
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    double a = sin(dlat/2) * sin(dlat/2) + cos(lat1) * cos(lat2) * sin(dlon/2) * sin(dlon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    return EARTH_RADIUS * c;
}

void calculate_route(void) {
    double distance_in_meters = distance(current_location.latitude, current_location.longitude, destination_location.latitude, destination_location.longitude);
    double distance_in_km = distance_in_meters / 1000;
    printf("Distance between current location and destination: %.2f km\n", distance_in_km);
}

int main() {
    srand(time(NULL));
    get_current_location();
    get_destination_location();
    calculate_route();
    return 0;
}