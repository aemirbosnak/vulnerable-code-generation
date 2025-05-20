//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.01
#define DEG_TO_RAD 0.01745329251994329577

struct location {
    double lat;
    double lon;
};

struct location gps_location;

void init_gps() {
    srand(time(NULL));
    gps_location.lat = rand() % 90 - 45;
    gps_location.lon = rand() % 180 - 90;
}

void print_gps_location() {
    printf("Current GPS location: %.2f°N, %.2f°E\n", gps_location.lat * DEG_TO_RAD, gps_location.lon * DEG_TO_RAD);
}

void move_gps(double distance, double direction) {
    double delta_lat = distance / EARTH_RADIUS * cos(gps_location.lat * DEG_TO_RAD);
    double delta_lon = distance / EARTH_RADIUS * sin(gps_location.lat * DEG_TO_RAD) * cos(direction * DEG_TO_RAD);

    gps_location.lat += delta_lat;
    gps_location.lon += delta_lon;

    if (gps_location.lat > 90) {
        gps_location.lat = 90;
    } else if (gps_location.lat < -90) {
        gps_location.lat = -90;
    }

    if (gps_location.lon > 180) {
        gps_location.lon -= 360;
    } else if (gps_location.lon < -180) {
        gps_location.lon += 360;
    }
}

int main() {
    init_gps();
    print_gps_location();

    while (1) {
        printf("Enter direction (0-360) and distance (in km): ");
        scanf("%lf %lf", &gps_location.lon, &gps_location.lat);
        move_gps(1, gps_location.lon);
        print_gps_location();
    }

    return 0;
}