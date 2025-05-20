//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846
#define RADIUS 6371.0
#define DEG_TO_RAD 0.017453292519943295
#define RAD_TO_DEG 57.29577951308232087680

struct point {
    double lat;
    double lon;
};

struct route {
    int num_points;
    struct point* points;
};

void init_route(struct route* r) {
    r->num_points = 0;
    r->points = NULL;
}

void add_point(struct route* r, double lat, double lon) {
    r->points = realloc(r->points, sizeof(struct point) * ++r->num_points);
    r->points[r->num_points - 1].lat = lat;
    r->points[r->num_points - 1].lon = lon;
}

double distance(double lat1, double lon1, double lat2, double lon2) {
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(lat1 * DEG_TO_RAD) * cos(lat2 * DEG_TO_RAD) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return RADIUS * c;
}

double bearing(double lat1, double lon1, double lat2, double lon2) {
    double y = sin(lon2 - lon1) * cos(lat2);
    double x = cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(lon2 - lon1);
    double brng = atan2(y, x);
    return RAD_TO_DEG * brng;
}

void print_route(struct route* r) {
    printf("Route:\n");
    for (int i = 0; i < r->num_points; ++i) {
        printf("%.6f, %.6f\n", r->points[i].lat, r->points[i].lon);
    }
}

int main() {
    struct route r;
    init_route(&r);

    double lat1, lon1, lat2, lon2;

    printf("Enter the latitude and longitude of the starting point:\n");
    scanf("%lf %lf", &lat1, &lon1);

    printf("Enter the latitude and longitude of the destination:\n");
    scanf("%lf %lf", &lat2, &lon2);

    add_point(&r, lat1, lon1);
    add_point(&r, lat2, lon2);

    double distance_km = distance(lat1, lon1, lat2, lon2) / 1000.0;
    double bearing_deg = bearing(lat1, lon1, lat2, lon2);

    printf("Distance between the two points: %.2f km\n", distance_km);
    printf("Bearing from the starting point to the destination: %.2f degrees\n", bearing_deg);

    print_route(&r);

    return 0;
}