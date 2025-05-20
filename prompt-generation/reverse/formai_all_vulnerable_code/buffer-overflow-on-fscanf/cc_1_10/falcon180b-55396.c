//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_POINTS 100
#define EARTH_RADIUS 6371.0

typedef struct {
    double lat;
    double lon;
    char *name;
} Point;

double distance(double lat1, double lon1, double lat2, double lon2) {
    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(lat1) * cos(lat2) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

void read_points(Point points[], int n) {
    FILE *fp = fopen("points.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%lf %lf %s", &points[i].lat, &points[i].lon, points[i].name);
    }
    fclose(fp);
}

void nearest_point(Point points[], int n, double lat, double lon) {
    int index = -1;
    double min_dist = 1e6;
    for (int i = 0; i < n; i++) {
        double dist = distance(points[i].lat, points[i].lon, lat, lon);
        if (dist < min_dist) {
            min_dist = dist;
            index = i;
        }
    }
    printf("Nearest point: %s\n", points[index].name);
}

int main() {
    Point points[MAX_POINTS];
    int n = 0;
    read_points(points, MAX_POINTS);
    n = sizeof(points) / sizeof(points[0]);
    double lat = 37.7749;
    double lon = -122.4194;
    nearest_point(points, n, lat, lon);
    return 0;
}