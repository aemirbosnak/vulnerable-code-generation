//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: scientific
#include <stdio.h>
#include <math.h>

#define RADIUS 6371000 // radius of Earth in meters

struct Coord { 
    double lat; // latitude 
    double lon; // longitude 
};

struct Coord getCurrentLocation() {
    struct Coord current;
    printf("Enter current latitude and longitude (in degrees): ");
    scanf("%lf %lf", &current.lat, &current.lon);
    return current;
}

struct Coord getDestination() {
    struct Coord destination;
    printf("Enter destination latitude and longitude (in degrees): ");
    scanf("%lf %lf", &destination.lat, &destination.lon);
    return destination;
}

double toRadians(double degrees) {
    return degrees * M_PI / 180.0;
}

double haversine(double lat1, double lon1, double lat2, double lon2) {
    double deltaLat = toRadians(lat2 - lat1);
    double deltaLon = toRadians(lon2 - lon1);

    double sinLat = sin(deltaLat / 2);
    double sinLon = sin(deltaLon / 2);

    double a = sinLat * sinLat + cos(toRadians(lat1)) * cos(toRadians(lat2)) * sinLon * sinLon;
    double c = 2 * asin(sqrt(a));

    return RADIUS * c;
}

double bearing(double lat1, double lon1, double lat2, double lon2 ) {
    double y = sin(toRadians(lon2 - lon1)) * cos(toRadians(lat2));
    double x = cos(toRadians(lat1)) * sin(toRadians(lat2)) - sin(toRadians(lat1)) * cos(toRadians(lat2)) * cos(toRadians(lon2 - lon1));
    double bearing = atan2( y, x ) * 180.0 / M_PI;
    return bearing;
}

int main() {
    struct Coord current = getCurrentLocation();
    struct Coord destination = getDestination();

    double distance = haversine(current.lat, current.lon, destination.lat, destination.lon);
    double initialBearing = bearing(current.lat, current.lon, destination.lat, destination.lon);

    printf("Current location: (%lf, %lf)\n", current.lat, current.lon);
    printf("Destination: (%lf, %lf)\n", destination.lat, destination.lon);
    printf("Distance between current location and destination: %.2lf meters\n", distance);
    printf("Initial bearing: %.2lf degrees", initialBearing);

    return 0;
}