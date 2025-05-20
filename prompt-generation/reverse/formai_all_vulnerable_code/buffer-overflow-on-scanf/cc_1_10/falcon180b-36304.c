//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.0
#define DEG_TO_RAD 0.01745329251994329576923690768489
#define RAD_TO_DEG 57.295779513082320876798154814105

typedef struct {
    double lat;
    double lon;
} GPSCoord;

void getGPSLocation(GPSCoord *gps) {
    printf("Enter latitude (in degrees): ");
    scanf("%lf", &gps->lat);
    printf("Enter longitude (in degrees): ");
    scanf("%lf", &gps->lon);
}

void convertToRadians(GPSCoord *gps) {
    gps->lat *= DEG_TO_RAD;
    gps->lon *= DEG_TO_RAD;
}

double distance(double lat1, double lon1, double lat2, double lon2) {
    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(lat1 * DEG_TO_RAD) * cos(lat2 * DEG_TO_RAD) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

void getDestination(GPSCoord *dest) {
    printf("Enter destination latitude (in degrees): ");
    scanf("%lf", &dest->lat);
    printf("Enter destination longitude (in degrees): ");
    scanf("%lf", &dest->lon);
}

int main() {
    GPSCoord curr, dest;
    getGPSLocation(&curr);
    getDestination(&dest);
    convertToRadians(&curr);
    convertToRadians(&dest);
    double distanceInMeters = distance(curr.lat, curr.lon, dest.lat, dest.lon);
    printf("Distance to destination: %.2lf meters\n", distanceInMeters);
    return 0;
}