//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.0

struct point {
    double latitude;
    double longitude;
};

struct point current_location;
struct point destination;

double calculate_distance(double lat1, double lon1, double lat2, double lon2) {
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;

    double a = sin(dlat/2) * sin(dlat/2) + cos(lat1) * cos(lat2) * sin(dlon/2) * sin(dlon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));

    return EARTH_RADIUS * c;
}

void get_random_location() {
    srand(time(NULL));

    current_location.latitude = rand() % 90 + 1;
    current_location.longitude = rand() % 180 + 1;
}

void get_destination() {
    printf("Enter destination coordinates (latitude and longitude):\n");
    scanf("%lf %lf", &destination.latitude, &destination.longitude);
}

void navigate() {
    double distance = calculate_distance(current_location.latitude, current_location.longitude, destination.latitude, destination.longitude);

    printf("Distance to destination: %.2lf km\n", distance);
}

int main() {
    get_random_location();
    get_destination();
    navigate();

    return 0;
}