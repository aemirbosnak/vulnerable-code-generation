//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359
#define EARTH_RADIUS 6371.01
#define LATITUDE_DEG_TO_RAD (PI/180)
#define LONGITUDE_DEG_TO_RAD (PI/180)

struct Point {
    double latitude;
    double longitude;
};

struct Point get_current_position() {
    struct Point position;
    printf("Enter your current latitude (in degrees): ");
    scanf("%lf", &position.latitude);
    printf("Enter your current longitude (in degrees): ");
    scanf("%lf", &position.longitude);
    return position;
}

struct Point get_destination() {
    struct Point destination;
    printf("Enter your destination latitude (in degrees): ");
    scanf("%lf", &destination.latitude);
    printf("Enter your destination longitude (in degrees): ");
    scanf("%lf", &destination.longitude);
    return destination;
}

double calculate_distance(struct Point p1, struct Point p2) {
    double dLat = p2.latitude - p1.latitude;
    double dLon = p2.longitude - p1.longitude;
    double a = sin(dLat/2) * sin(dLat/2) + cos(p1.latitude*LATITUDE_DEG_TO_RAD) * cos(p2.latitude*LATITUDE_DEG_TO_RAD) * sin(dLon/2) * sin(dLon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distance = EARTH_RADIUS * c;
    return distance;
}

int main() {
    struct Point current_position = get_current_position();
    struct Point destination = get_destination();
    double distance = calculate_distance(current_position, destination);

    printf("The distance between your current position and destination is %.2lf km.\n", distance);

    return 0;
}