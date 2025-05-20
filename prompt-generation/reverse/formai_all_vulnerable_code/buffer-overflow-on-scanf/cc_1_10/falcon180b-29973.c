//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define RADIUS 6371.01 // Earth's radius in km
#define DEG2RAD (PI/180.0)

typedef struct {
    double lat1, lon1; // starting point coordinates
    double lat2, lon2; // destination point coordinates
    double dist; // distance between points
    double angle; // angle between points
} route;

void route_init(route* r, double lat1, double lon1, double lat2, double lon2) {
    r->lat1 = lat1;
    r->lon1 = lon1;
    r->lat2 = lat2;
    r->lon2 = lon2;
    r->dist = 0;
    r->angle = 0;
}

void route_calculate(route* r) {
    double dlat = r->lat2 - r->lat1;
    double dlon = r->lon2 - r->lon1;
    double a = sin(dlat/2) * sin(dlat/2) + cos(r->lat1*DEG2RAD) * cos(r->lat2*DEG2RAD) * sin(dlon/2) * sin(dlon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    r->dist = RADIUS * c; // distance in km
    r->angle = (r->lat2 - r->lat1) * DEG2RAD; // angle between points in radians
}

void route_print(route* r) {
    printf("Distance: %.2f km\n", r->dist);
    printf("Angle: %.2f degrees\n", r->angle * 180/PI);
}

int main() {
    srand(time(NULL));
    double lat1, lon1, lat2, lon2;
    printf("Enter starting point coordinates (latitude, longitude):\n");
    scanf("%lf %lf", &lat1, &lon1);
    printf("Enter destination point coordinates (latitude, longitude):\n");
    scanf("%lf %lf", &lat2, &lon2);
    route r;
    route_init(&r, lat1, lon1, lat2, lon2);
    route_calculate(&r);
    route_print(&r);
    return 0;
}