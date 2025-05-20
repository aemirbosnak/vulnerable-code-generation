//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000

typedef struct {
    double latitude;
    double longitude;
} Point;

double distance(Point, Point);

int main() {
    Point current, destination, points[MAX_POINTS];
    int num_points = 0, i;
    double min_distance = INFINITY, temp;

    // Get current location from GPS receiver
    printf("Enter your current location:\n");
    printf("Latitude: ");
    scanf("%lf", &current.latitude);
    printf("Longitude: ");
    scanf("%lf", &current.longitude);

    // Get destination from user
    printf("\nEnter your destination:\n");
    printf("Latitude: ");
    scanf("%lf", &destination.latitude);
    printf("Longitude: ");
    scanf("%lf", &destination.longitude);

    // Retrieve all points from GPS receiver
    printf("\nEnter the number of points from the GPS receiver: ");
    scanf("%d", &num_points);
    printf("Enter the latitude and longitude of each point:\n");

    for(i = 0; i < num_points; i++) {
        printf("Point %d:\n", i + 1);
        printf("Latitude: ");
        scanf("%lf", &points[i].latitude);
        printf("Longitude: ");
        scanf("%lf", &points[i].longitude);

        temp = distance(current, points[i]) + distance(points[i], destination);

        if(temp < min_distance) {
            min_distance = temp;
        }
    }

    printf("\nMinimum distance from %lf, %lf to %lf, %lf through %d points is %lf meters", current.latitude, current.longitude, destination.latitude, destination.longitude, num_points, min_distance);

    return EXIT_SUCCESS;
}

double distance(Point a, Point b) {
    double delta_lat = a.latitude - b.latitude;
    double delta_long = a.longitude - b.longitude;
    return sqrt(delta_lat*delta_lat + delta_long*delta_long) * 6371000; // Approx. Earth radius: 6371 km
}