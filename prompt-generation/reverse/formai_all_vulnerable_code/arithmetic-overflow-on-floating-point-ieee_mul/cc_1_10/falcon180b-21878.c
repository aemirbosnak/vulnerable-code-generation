//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define PI 3.14159265358979323846
#define R 6371.01
#define G 9.81
#define DEG_TO_RAD 0.0174532925
#define RAD_TO_DEG 57.2957795

typedef struct {
    double lat;
    double lon;
} Point;

void init(void) {
    srand(time(NULL));
}

void random_point(Point *p) {
    p->lat = (double)rand() / RAND_MAX * 180 - 90;
    p->lon = (double)rand() / RAND_MAX * 360 - 180;
}

double distance(Point p1, Point p2) {
    double dlat = p2.lat - p1.lat;
    double dlon = p2.lon - p1.lon;
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(p1.lat * DEG_TO_RAD) * cos(p2.lat * DEG_TO_RAD) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return R * c;
}

void simulate(int num_points, Point *points) {
    for (int i = 0; i < num_points; i++) {
        random_point(&points[i]);
    }

    double total_distance = 0;

    for (int i = 0; i < num_points - 1; i++) {
        total_distance += distance(points[i], points[i + 1]);
    }

    printf("Total distance traveled: %.2f km\n", total_distance);
}

int main(void) {
    int num_points;
    printf("Enter the number of points to simulate: ");
    scanf("%d", &num_points);

    Point points[num_points];
    simulate(num_points, points);

    return 0;
}