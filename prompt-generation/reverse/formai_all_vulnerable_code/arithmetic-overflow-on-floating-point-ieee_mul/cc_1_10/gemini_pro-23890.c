//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EARTH_RADIUS 6371

typedef struct {
    double latitude;
    double longitude;
} Point;

Point current_location;

void set_current_location(double latitude, double longitude) {
    current_location.latitude = latitude;
    current_location.longitude = longitude;
}

double distance_between_points(Point point1, Point point2) {
    double dlat = point2.latitude - point1.latitude;
    double dlon = point2.longitude - point1.longitude;
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(point1.latitude) * cos(point2.latitude) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

void get_directions(Point destination) {
    double current_latitude_radians = current_location.latitude * M_PI / 180;
    double current_longitude_radians = current_location.longitude * M_PI / 180;
    double destination_latitude_radians = destination.latitude * M_PI / 180;
    double destination_longitude_radians = destination.longitude * M_PI / 180;

    double y = sin(destination_longitude_radians - current_longitude_radians) * cos(destination_latitude_radians);
    double x = cos(current_latitude_radians) * sin(destination_latitude_radians) - sin(current_latitude_radians) * cos(destination_latitude_radians) * cos(destination_longitude_radians - current_longitude_radians);
    double bearing = atan2(y, x);

    printf("Head %.2f degrees %s.\n", bearing * 180 / M_PI, bearing > 0 ? "east" : "west");

    double distance = distance_between_points(current_location, destination);
    printf("Remaining distance: %.2f miles.\n", distance);
}

int main() {
    set_current_location(37.7749, -122.4194);

    while (1) {
        double latitude, longitude;
        printf("Enter destination latitude: ");
        scanf("%lf", &latitude);
        printf("Enter destination longitude: ");
        scanf("%lf", &longitude);

        Point destination = { .latitude = latitude, .longitude = longitude };

        get_directions(destination);

        char answer;
        printf("Continue navigating? (y/n) ");
        scanf(" %c", &answer);
        if (answer == 'n') {
            break;
        }
    }

    return 0;
}