//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EARTH_RADIUS 6371 // in kilometers
#define PI 3.14159265358979323846

struct point {
    double latitude;
    double longitude;
};

struct point parse_lat_lon(char *input) {
    char *token = strtok(input, ",");
    struct point point = {0, 0};

    if (token == NULL) {
        printf("Invalid input\n");
        exit(1);
    }

    point.latitude = atof(token);
    token = strtok(NULL, ",");

    if (token == NULL) {
        printf("Invalid input\n");
        exit(1);
    }

    point.longitude = atof(token);

    return point;
}

double haversine(double lat1, double lon1, double lat2, double lon2) {
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;

    double a = sin(dlat / 2) * sin(dlat / 2) + cos(lat1) * cos(lat2) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return EARTH_RADIUS * c;
}

int main() {
    char input[100];
    struct point p1, p2;

    printf("Enter two locations (latitude,longitude):\n");
    scanf("%s", input);
    p1 = parse_lat_lon(input);

    scanf("%s", input);
    p2 = parse_lat_lon(input);

    double distance = haversine(p1.latitude, p1.longitude, p2.latitude, p2.longitude);

    printf("Distance between the two locations is %.2lf km\n", distance);

    return 0;
}