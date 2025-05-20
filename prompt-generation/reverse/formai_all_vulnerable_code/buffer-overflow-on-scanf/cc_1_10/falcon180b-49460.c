//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.01

struct point {
    double latitude;
    double longitude;
};

double distance(struct point p1, struct point p2) {
    double dlat = p2.latitude - p1.latitude;
    double dlon = p2.longitude - p1.longitude;
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(p1.latitude) * cos(p2.latitude) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

void gps_simulation(int num_points, struct point *points) {
    int i, j;
    double min_distance;
    for (i = 0; i < num_points - 1; i++) {
        min_distance = 1e9;
        for (j = i + 1; j < num_points; j++) {
            double distance_ij = distance(points[i], points[j]);
            if (distance_ij < min_distance) {
                min_distance = distance_ij;
            }
        }
        printf("Distance between point %d and %d is %.2f\n", i, i + 1, min_distance);
    }
}

int main() {
    int num_points;
    printf("Enter the number of points: ");
    scanf("%d", &num_points);
    struct point *points = (struct point *) malloc(num_points * sizeof(struct point));
    if (points == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    srand(time(NULL));
    double lat_min = -90.0, lat_max = 90.0, lon_min = -180.0, lon_max = 180.0;
    for (int i = 0; i < num_points; i++) {
        points[i].latitude = lat_min + (lat_max - lat_min) * rand() / RAND_MAX;
        points[i].longitude = lon_min + (lon_max - lon_min) * rand() / RAND_MAX;
    }
    gps_simulation(num_points, points);
    free(points);
    return 0;
}