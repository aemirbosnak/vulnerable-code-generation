//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.01

struct Point {
    double latitude;
    double longitude;
};

double deg2rad(double deg) {
    return deg * (PI / 180);
}

double distance(struct Point p1, struct Point p2) {
    double dLat = deg2rad(p2.latitude - p1.latitude);
    double dLon = deg2rad(p2.longitude - p1.longitude);
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(deg2rad(p1.latitude)) * cos(deg2rad(p2.latitude)) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

int main() {
    int numPoints;
    printf("Enter the number of points: ");
    scanf("%d", &numPoints);

    struct Point points[numPoints];

    for (int i = 0; i < numPoints; i++) {
        printf("Enter the latitude and longitude of point %d: ", i + 1);
        scanf("%lf %lf", &points[i].latitude, &points[i].longitude);
    }

    printf("Enter the index of the starting point: ");
    int startIndex;
    scanf("%d", &startIndex);

    double totalDistance = 0;

    for (int i = startIndex; i < numPoints; i++) {
        totalDistance += distance(points[i], points[(i + 1) % numPoints]);
    }

    printf("Total distance: %.2lf km\n", totalDistance);

    return 0;
}