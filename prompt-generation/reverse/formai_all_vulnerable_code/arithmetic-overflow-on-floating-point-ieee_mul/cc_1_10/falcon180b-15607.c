//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371

struct point {
    double latitude;
    double longitude;
};

double distance(struct point p1, struct point p2) {
    double dlat = p2.latitude - p1.latitude;
    double dlon = p2.longitude - p1.longitude;
    double a = sin(dlat/2) * sin(dlat/2) + cos(p1.latitude) * cos(p2.latitude) * sin(dlon/2) * sin(dlon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    return EARTH_RADIUS * c;
}

void main() {
    struct point current_location, destination;
    int choice;

    printf("GPS Navigation System\n");
    printf("Enter your current location (latitude and longitude): ");
    scanf("%lf %lf", &current_location.latitude, &current_location.longitude);

    while(1) {
        printf("\nWhere would you like to go?\n");
        printf("1. Enter a specific destination\n");
        printf("2. Search for nearby points of interest\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the latitude and longitude of your destination: ");
                scanf("%lf %lf", &destination.latitude, &destination.longitude);
                printf("The distance between your current location and your destination is %.2lf km.\n", distance(current_location, destination));
                break;
            case 2:
                //TODO: Implement search for nearby points of interest
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}