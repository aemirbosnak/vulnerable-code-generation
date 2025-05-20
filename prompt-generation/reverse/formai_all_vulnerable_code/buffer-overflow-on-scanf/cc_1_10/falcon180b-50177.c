//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define PI 3.14159265358979323846
#define R 6371.01
#define G 9.81
#define DEG_TO_RAD 0.01745329251994329576923690768489

double deg2rad(double deg) {
    return deg * DEG_TO_RAD;
}

double distance(double lat1, double lon1, double lat2, double lon2) {
    double dlat = deg2rad(lat2 - lat1);
    double dlon = deg2rad(lon2 - lon1);
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return R * c;
}

double speed(double lat1, double lon1, double lat2, double lon2, double time) {
    double d = distance(lat1, lon1, lat2, lon2);
    return d / (time * G);
}

int main() {
    double lat1, lon1, lat2, lon2;
    double time;
    char answer[10];

    printf("Enter starting latitude: ");
    scanf("%lf", &lat1);
    printf("Enter starting longitude: ");
    scanf("%lf", &lon1);
    printf("Enter destination latitude: ");
    scanf("%lf", &lat2);
    printf("Enter destination longitude: ");
    scanf("%lf", &lon2);
    printf("Enter travel time in seconds: ");
    scanf("%lf", &time);

    double distance_traveled = distance(lat1, lon1, lat2, lon2);
    double speed_traveled = speed(lat1, lon1, lat2, lon2, time);

    printf("Distance traveled: %.2lf km\n", distance_traveled);
    printf("Speed traveled: %.2lf km/h\n", speed_traveled);

    return 0;
}