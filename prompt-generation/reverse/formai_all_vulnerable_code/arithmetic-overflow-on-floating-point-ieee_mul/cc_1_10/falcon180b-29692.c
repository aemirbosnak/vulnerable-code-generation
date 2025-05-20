//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define R 6371.01 // Radius of the Earth in km
#define D2R (PI/180)
#define R2D (180/PI)

struct Point {
    double lat;
    double lon;
};

struct Point init_point(double lat, double lon) {
    struct Point p;
    p.lat = lat;
    p.lon = lon;
    return p;
}

double distance(struct Point p1, struct Point p2) {
    double dlat = p2.lat - p1.lat;
    double dlon = p2.lon - p1.lon;
    double a = sin(dlat/2) * sin(dlat/2) + cos(p1.lat*D2R) * cos(p2.lat*D2R) * sin(dlon/2) * sin(dlon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    return R * c;
}

struct Point move(struct Point p, double distance, double bearing) {
    double lat1 = p.lat * R2D;
    double lon1 = p.lon * R2D;
    double lat2 = lat1 + distance/R;
    double lon2 = lon1 + distance/R/cos(lat1*D2R)*sin(bearing*D2R);
    struct Point result;
    result.lat = lat2;
    result.lon = lon2;
    return result;
}

int main() {
    double lat1, lon1, lat2, lon2;
    printf("Enter the latitude and longitude of the starting point: ");
    scanf("%lf %lf", &lat1, &lon1);
    printf("Enter the latitude and longitude of the destination point: ");
    scanf("%lf %lf", &lat2, &lon2);
    struct Point start = init_point(lat1, lon1);
    struct Point end = init_point(lat2, lon2);
    double distance_between_points = distance(start, end);
    printf("The distance between the starting point and the destination point is %.2lf km.\n", distance_between_points);
    return 0;
}