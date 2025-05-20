//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.01

struct point {
    double lat;
    double lon;
};

double distance(struct point p1, struct point p2) {
    double dlat = p2.lat - p1.lat;
    double dlon = p2.lon - p1.lon;
    double a = sin(dlat / 2) * sin(dlat / 2)
        + cos(p1.lat * PI / 180) * cos(p2.lat * PI / 180)
        * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double d = EARTH_RADIUS * c;
    return d;
}

int main() {
    struct point start, destination, current;
    double total_distance, covered_distance;
    int choice;

    printf("Enter starting point (latitude, longitude): ");
    scanf("%lf %lf", &start.lat, &start.lon);

    printf("Enter destination point (latitude, longitude): ");
    scanf("%lf %lf", &destination.lat, &destination.lon);

    printf("Enter mode of transportation:\n1. Walking\n2. Cycling\n3. Driving\n");
    scanf("%d", &choice);

    printf("Enter your current location (latitude, longitude): ");
    scanf("%lf %lf", &current.lat, &current.lon);

    total_distance = distance(start, destination);
    covered_distance = 0;

    while (covered_distance < total_distance) {
        if (choice == 1) {
            covered_distance += 0.1;
        } else if (choice == 2) {
            covered_distance += 0.5;
        } else if (choice == 3) {
            covered_distance += 2;
        }
        printf("Your current location is: (%.2lf, %.2lf)\n", current.lat, current.lon);
        printf("Distance covered: %.2lf km\n", covered_distance);
        printf("Distance remaining: %.2lf km\n", total_distance - covered_distance);
        sleep(1);
    }

    printf("You have reached your destination.\n");

    return 0;
}