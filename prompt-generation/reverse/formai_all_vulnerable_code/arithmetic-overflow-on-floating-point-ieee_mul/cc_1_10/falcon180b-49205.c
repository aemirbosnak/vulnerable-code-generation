//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.0
#define DEG2RAD(d) ((d)*(PI)/180.0)
#define RAD2DEG(r) ((r)*(180.0)/PI)

struct point {
    double latitude;
    double longitude;
};

struct point calculate_destination(struct point start, double distance, double bearing) {
    double lat1 = start.latitude * PI / 180;
    double lon1 = start.longitude * PI / 180;
    double lat2, lon2;
    double d = distance / EARTH_RADIUS;
    double brng = bearing * PI / 180;
    double sinLat = sin(lat1);
    double cosLat = cos(lat1);
    double y = sin(d) * cos(lat1);
    double x = cos(d) * sin(lat1);
    double a = atan2(y, x);
    double c = sin(a);
    double s = cos(a);
    double lat3 = asin(sinLat*c + cosLat*s*cos(brng));
    double lon3 = lon1 + atan2(s*sin(brng) - c*cos(lat1)*sin(brng), cos(lat1)*cos(brng));
    lat2 = lat3 * 180 / PI;
    lon2 = lon3 * 180 / PI;
    return (struct point){.latitude = lat2,.longitude = lon2};
}

void print_point(struct point p) {
    printf("Latitude: %.6f\nLongitude: %.6f\n", p.latitude, p.longitude);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <latitude1> <longitude1> <distance>\n", argv[0]);
        exit(1);
    }
    double start_latitude = atof(argv[1]);
    double start_longitude = atof(argv[2]);
    double distance = atof(argv[3]);
    double bearing = 90; // North
    struct point start = {.latitude = start_latitude,.longitude = start_longitude};
    struct point destination = calculate_destination(start, distance, bearing);
    printf("Starting point:\n");
    print_point(start);
    printf("Destination:\n");
    print_point(destination);
    double distance_km = distance / 1000;
    printf("Distance: %.2f km\n", distance_km);
    return 0;
}