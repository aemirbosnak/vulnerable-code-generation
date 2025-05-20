//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.01

struct location {
    double latitude;
    double longitude;
};

struct location current_location;
struct location destination_location;
double distance;
double bearing;
double speed;

void initialize_location(struct location *location) {
    printf("Enter latitude: ");
    scanf("%lf", &location->latitude);
    printf("Enter longitude: ");
    scanf("%lf", &location->longitude);
}

void calculate_distance(struct location location1, struct location location2) {
    double dlat = location2.latitude - location1.latitude;
    double dlon = location2.longitude - location1.longitude;
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(location1.latitude * PI / 180) * cos(location2.latitude * PI / 180) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    distance = EARTH_RADIUS * c;
}

void calculate_bearing(struct location location1, struct location location2) {
    double y = sin(location2.latitude * PI / 180) * cos(location1.latitude * PI / 180);
    double x = cos(location2.latitude * PI / 180) * sin(location1.latitude * PI / 180) - sin(location2.latitude * PI / 180) * cos(location1.latitude * PI / 180) * cos(location1.longitude * PI / 180 - location2.longitude * PI / 180);
    bearing = atan2(y, x) * 180 / PI;
}

void calculate_speed(double distance, double time) {
    speed = distance / time;
}

int main() {
    initialize_location(&current_location);
    initialize_location(&destination_location);

    printf("Enter the destination location:\n");
    scanf("%lf%lf", &destination_location.latitude, &destination_location.longitude);

    calculate_distance(current_location, destination_location);
    calculate_bearing(current_location, destination_location);
    calculate_speed(distance, 0.0);

    printf("Distance: %lf\n", distance);
    printf("Bearing: %lf\n", bearing);
    printf("Speed: %lf\n", speed);

    return 0;
}