//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.0

typedef struct {
    double lat;
    double lon;
    double alt;
} GPSPosition;

typedef struct {
    GPSPosition currPos;
    GPSPosition destPos;
    double distToDest;
} GPSNavigation;

GPSPosition initGPSPosition(double lat, double lon) {
    GPSPosition pos;
    pos.lat = lat;
    pos.lon = lon;
    pos.alt = 0.0;
    return pos;
}

double distance(GPSPosition pos1, GPSPosition pos2) {
    double dLat = pos2.lat - pos1.lat;
    double dLon = pos2.lon - pos1.lon;
    double a = sin(dLat/2) * sin(dLat/2) + cos(pos1.lat) * cos(pos2.lat) * sin(dLon/2) * sin(dLon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double R = EARTH_RADIUS;
    return R * c;
}

void setDestPos(GPSNavigation *nav, double destLat, double destLon) {
    nav->destPos.lat = destLat;
    nav->destPos.lon = destLon;
    nav->distToDest = distance(nav->currPos, nav->destPos);
}

void printGPSPos(GPSPosition pos) {
    printf("Latitude: %lf\nLongitude: %lf\nAltitude: %lf\n", pos.lat, pos.lon, pos.alt);
}

int main() {
    GPSPosition currPos = initGPSPosition(37.7749, -122.4194);
    GPSPosition destPos = initGPSPosition(40.7128, -74.0060);

    GPSNavigation nav;
    nav.currPos = currPos;
    nav.destPos = destPos;

    while(1) {
        system("clear");
        printf("Current Position:\n");
        printGPSPos(nav.currPos);
        printf("Destination:\n");
        printGPSPos(nav.destPos);
        printf("Distance to Destination: %lf km\n", nav.distToDest/1000.0);
        printf("Enter 'q' to quit\n");
        char choice;
        scanf("%c", &choice);
        if(choice == 'q') {
            break;
        }
    }

    return 0;
}