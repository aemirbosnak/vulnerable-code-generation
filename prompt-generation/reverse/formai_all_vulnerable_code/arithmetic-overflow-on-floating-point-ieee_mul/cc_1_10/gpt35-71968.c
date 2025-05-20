//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RADIUS 6371     // Earth's radius in kilometers

struct Coord {
    double lat;     // latitude in degrees
    double lon;     // longitude in degrees
} start, dest;

double toRadians(double degrees) {
    return degrees * M_PI / 180;
}

double distance(struct Coord a, struct Coord b) {
    double dLat = toRadians(b.lat - a.lat);
    double dLon = toRadians(b.lon - a.lon);
    double lat1 = toRadians(a.lat);
    double lat2 = toRadians(b.lat);

    double x = sin(dLat/2) * sin(dLat/2) + cos(lat1) * cos(lat2) * sin(dLon/2) * sin(dLon/2);
    double y = 2 * atan2(sqrt(x), sqrt(1-x));
    return RADIUS * y;
}

void navigate() {
    printf("Enter coordinates of starting point (latitude longitude): ");
    scanf("%lf %lf", &start.lat, &start.lon);
    printf("Enter coordinates of destination point (latitude longitude): ");
    scanf("%lf %lf", &dest.lat, &dest.lon);
    printf("Starting point: %f %f\n", start.lat, start.lon);
    printf("Destination point: %f %f\n", dest.lat, dest.lon);

    double dist = distance(start, dest);
    printf("Distance: %f km\n", dist);

    printf("Enter speed (km/h): ");
    double speed;
    scanf("%lf", &speed);

    int hours = (int)(dist / speed);        // Whole hours to travel
    double minutes = (dist / speed - hours) * 60;    // Minutes to travel remaining distance

    printf("Estimated travel time: %d hours and %.0f minutes\n", hours, minutes);
}

int main() {
    navigate();
    return 0;
}