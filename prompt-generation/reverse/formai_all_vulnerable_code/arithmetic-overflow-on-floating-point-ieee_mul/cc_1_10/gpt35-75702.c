//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: intelligent
#include <stdio.h>
#include <math.h>

#define EARTH_RADIUS 6371.0 // in km

typedef struct {
    double latitude;
    double longitude;
} Coord;

double toRadians(double degrees) {
    return degrees * M_PI / 180.0;
}

double calculateDistance(Coord start, Coord end) {
    double latDiff = toRadians(end.latitude - start.latitude);
    double longDiff = toRadians(end.longitude - start.longitude);
    double a = pow(sin(latDiff/2), 2) + cos(toRadians(start.latitude)) * cos(toRadians(end.latitude)) * pow(sin(longDiff/2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    return EARTH_RADIUS * c;
}

Coord currentLocation() {
    Coord current;
    printf("Enter current latitude: ");
    scanf("%lf", &current.latitude);
    printf("Enter current longitude: ");
    scanf("%lf", &current.longitude);
    return current;
}

Coord destination() {
    Coord dest;
    printf("Enter destination latitude: ");
    scanf("%lf", &dest.latitude);
    printf("Enter destination longitude: ");
    scanf("%lf", &dest.longitude);
    return dest;
}

void showDistance(Coord start, Coord end) {
    printf("The distance between (%lf, %lf) and (%lf, %lf) is %lf km.\n", start.latitude, start.longitude, end.latitude, end.longitude, calculateDistance(start, end));
}

int main() {
    Coord current = currentLocation();
    Coord dest = destination();
    showDistance(current, dest);
    return 0;
}