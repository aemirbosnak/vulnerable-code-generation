//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define PI 3.14159265358979323846
#define RADIUS 6371.0

typedef struct {
    double lat1, lon1, lat2, lon2;
} Point;

double distance(double lat1, double lon1, double lat2, double lon2)
{
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;

    double a =
        sin(dlat / 2) * sin(dlat / 2) +
        cos(lat1) * cos(lat2) *
        sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return RADIUS * c;
}

void gps_simulation()
{
    Point current_location, destination;
    char input[100];
    double distance_traveled = 0.0;

    printf("Enter your current location (latitude, longitude): ");
    scanf("%lf,%lf", &current_location.lat1, &current_location.lon1);

    printf("Enter your destination (latitude, longitude): ");
    scanf("%s", input);
    sscanf(input, "%lf,%lf", &destination.lat2, &destination.lon2);

    while (distance_traveled < distance(current_location.lat1, current_location.lon1, destination.lat2, destination.lon2)) {
        double step = 0.001;
        distance_traveled += step;
        current_location.lat1 += step * cos(destination.lat2 - current_location.lat1) / cos(destination.lat2);
        current_location.lon1 += step * sin(destination.lat2 - current_location.lat1) / cos(destination.lat2);

        printf("Current location: %.2lf, %.2lf\n", current_location.lat1, current_location.lon1);
    }

    printf("You have reached your destination.\n");
}

int main()
{
    gps_simulation();

    return 0;
}