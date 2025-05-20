//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: surprised
/* Surprising GPS Navigation Simulation */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_POINTS 100
#define MIN_DISTANCE 10

typedef struct {
    double latitude;
    double longitude;
} Point;

void generate_points(Point points[], int num_points) {
    srand(time(NULL));
    for (int i = 0; i < num_points; i++) {
        points[i].latitude = rand() % 90 + 1;
        points[i].longitude = rand() % 180 + 1;
    }
}

int find_closest_point(Point current, Point points[], int num_points) {
    int closest = 0;
    double min_distance = MIN_DISTANCE;

    for (int i = 0; i < num_points; i++) {
        double distance = sqrt(pow(points[i].latitude - current.latitude, 2) + pow(points[i].longitude - current.longitude, 2));

        if (distance < min_distance) {
            min_distance = distance;
            closest = i;
        }
    }

    return closest;
}

void main() {
    Point points[MAX_POINTS];
    int num_points = 0;

    printf("Enter number of points (max %d): ", MAX_POINTS - 1);
    scanf("%d", &num_points);

    generate_points(points, num_points);

    Point current = points[0];
    int next_point = find_closest_point(current, points, num_points);

    while (next_point!= 0) {
        printf("Current location: %.2f, %.2f\n", current.latitude, current.longitude);
        printf("Navigating to: %.2f, %.2f\n\n", points[next_point].latitude, points[next_point].longitude);

        current = points[next_point];
        next_point = find_closest_point(current, points, num_points);
    }

    printf("Reached final destination: %.2f, %.2f\n", current.latitude, current.longitude);
}