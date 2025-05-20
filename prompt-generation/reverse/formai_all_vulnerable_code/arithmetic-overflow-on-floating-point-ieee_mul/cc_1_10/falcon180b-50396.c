//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define PI 3.14159265358979323846
#define R 6371 // Radius of the earth in km
#define d2r (PI / 180) // Degree to radian conversion factor
#define r2d (180 / PI) // Radian to degree conversion factor

typedef struct {
    double lat1, lon1, lat2, lon2; // Coordinates of two points on the earth's surface
} GPS;

double distance(GPS gps) {
    double dlat = gps.lat2 - gps.lat1;
    double dlon = gps.lon2 - gps.lon1;
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(gps.lat1 * d2r) * cos(gps.lat2 * d2r) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = R * c;
    return distance;
}

void main() {
    int choice;
    GPS gps1, gps2;
    char city1[20], city2[20];

    printf("Enter the name of the first city: ");
    scanf("%s", city1);

    printf("Enter the latitude of %s (in degrees): ", city1);
    scanf("%lf", &gps1.lat1);

    printf("Enter the longitude of %s (in degrees): ", city1);
    scanf("%lf", &gps1.lon1);

    printf("Enter the name of the second city: ");
    scanf("%s", city2);

    printf("Enter the latitude of %s (in degrees): ", city2);
    scanf("%lf", &gps2.lat2);

    printf("Enter the longitude of %s (in degrees): ", city2);
    scanf("%lf", &gps2.lon2);

    printf("\n");
    printf("1. Distance between two cities\n");
    printf("2. Time taken to travel between two cities\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nThe distance between %s and %s is %.2lf km.\n", city1, city2, distance(gps1));
            break;
        case 2:
            printf("\nEnter your average speed (in km/h): ");
            double speed;
            scanf("%lf", &speed);
            double time = distance(gps1) / speed;
            printf("The time taken to travel between %s and %s at an average speed of %.2lf km/h is %.2lf hours.\n", city1, city2, speed, time);
            break;
        case 3:
            printf("\nExiting...\n");
            break;
        default:
            printf("\nInvalid choice! Please try again.\n");
    }
}