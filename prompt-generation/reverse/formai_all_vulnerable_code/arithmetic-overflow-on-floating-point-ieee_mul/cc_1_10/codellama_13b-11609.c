//Code Llama-13B DATASET v1.0 Category: GPS Navigation Simulation ; Style: satisfied
/*
 * GPS Navigation Simulation Program
 *
 * This program simulates a GPS navigation system that uses a GPS receiver
 * to determine the current location and provide directions to a destination.
 *
 * The program uses the following libraries:
 * - stdio.h: For input and output operations
 * - stdlib.h: For mathematical operations
 * - time.h: For time-related operations
 *
 * The program takes two inputs:
 * - The current location (in degrees, minutes, and seconds)
 * - The destination location (in degrees, minutes, and seconds)
 *
 * The program outputs the following information:
 * - The current location
 * - The destination location
 * - The direction to the destination (in degrees, minutes, and seconds)
 * - The distance to the destination (in kilometers)
 *
 * The program uses the following formulae:
 * - Haversine formula: To calculate the distance between two points on a sphere
 * - Law of cosines: To calculate the distance between two points on a sphere
 *
 * The program also uses the following mathematical constants:
 * - PI: To represent the ratio of the circumference of a circle to its diameter
 * - EARTH_RADIUS: To represent the radius of the Earth
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.0

typedef struct {
    double lat;
    double lon;
} coordinates_t;

double distance_between_points(coordinates_t point1, coordinates_t point2) {
    double lat1 = point1.lat * PI / 180.0;
    double lon1 = point1.lon * PI / 180.0;
    double lat2 = point2.lat * PI / 180.0;
    double lon2 = point2.lon * PI / 180.0;
    double dlon = lon2 - lon1;
    double dlat = lat2 - lat1;
    double a = pow(sin(dlat / 2.0), 2.0) + cos(lat1) * cos(lat2) * pow(sin(dlon / 2.0), 2.0);
    double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));
    return EARTH_RADIUS * c;
}

double direction_to_destination(coordinates_t current_location, coordinates_t destination_location) {
    double lat1 = current_location.lat * PI / 180.0;
    double lon1 = current_location.lon * PI / 180.0;
    double lat2 = destination_location.lat * PI / 180.0;
    double lon2 = destination_location.lon * PI / 180.0;
    double dlon = lon2 - lon1;
    double y = sin(dlon) * cos(lat2);
    double x = cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(dlon);
    double direction = atan2(y, x) * 180.0 / PI;
    return direction;
}

int main() {
    // Current location
    coordinates_t current_location;
    printf("Enter current location (lat, lon): ");
    scanf("%lf %lf", &current_location.lat, &current_location.lon);

    // Destination location
    coordinates_t destination_location;
    printf("Enter destination location (lat, lon): ");
    scanf("%lf %lf", &destination_location.lat, &destination_location.lon);

    // Distance to destination
    double distance = distance_between_points(current_location, destination_location);
    printf("Distance to destination: %.2f km\n", distance);

    // Direction to destination
    double direction = direction_to_destination(current_location, destination_location);
    printf("Direction to destination: %.2f degrees\n", direction);

    return 0;
}