//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: statistical
#include <stdio.h>
#include <math.h>

#define PI 3.1415926535897932384626
#define R 6371.01

typedef struct {
    double lat;
    double lon;
} Coordinate;

Coordinate current_location;
Coordinate destination;

void get_current_location() {
    printf("Enter current location (latitude, longitude): ");
    scanf("%lf %lf", &current_location.lat, &current_location.lon);
}

void get_destination() {
    printf("Enter destination (latitude, longitude): ");
    scanf("%lf %lf", &destination.lat, &destination.lon);
}

double distance(Coordinate c1, Coordinate c2) {
    double dlat = c2.lat - c1.lat;
    double dlon = c2.lon - c1.lon;
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(c1.lat) * cos(c2.lat) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return R * c;
}

double bearing(Coordinate c1, Coordinate c2) {
    double y = sin(c2.lon - c1.lon) * cos(c2.lat);
    double x = cos(c1.lat) * sin(c2.lat) - sin(c1.lat) * cos(c2.lat) * cos(c2.lon - c1.lon);
    double theta = atan2(y, x);
    return theta;
}

void navigate(Coordinate current, Coordinate destination) {
    double distance_left = distance(current, destination);
    double bearing_to_dest = bearing(current, destination);

    printf("Distance to destination: %.2lf km\n", distance_left);

    while (distance_left > 0.1) {
        printf("Current location: (%.2lf, %.2lf)\n", current.lat, current.lon);
        printf("Bearing to destination: %.2lf degrees\n", bearing_to_dest * 180 / PI);
        printf("Distance left: %.2lf km\n", distance_left);

        double step_distance = distance_left / 100;
        double step_lat = sin(bearing_to_dest * PI / 180) * step_distance;
        double step_lon = cos(bearing_to_dest * PI / 180) * step_distance;

        current.lat += step_lat;
        current.lon += step_lon;

        distance_left -= step_distance;
    }

    printf("Arrived at destination!\n");
}

int main() {
    get_current_location();
    get_destination();
    navigate(current_location, destination);

    return 0;
}