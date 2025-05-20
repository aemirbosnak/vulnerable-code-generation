//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define RADIUS 6371

// Function to convert degrees to radians
double degToRad(double deg) {
    return (deg * PI / 180);
}

// Function to calculate the distance between two coordinates
double calcDist(double lat1, double long1, double lat2, double long2) {
    double dlat, dlong, a, c, d;

    // Convert degrees to radians
    lat1 = degToRad(lat1);
    long1 = degToRad(long1);
    lat2 = degToRad(lat2);
    long2 = degToRad(long2);

    dlat = lat2 - lat1;
    dlong = long2 - long1;

    a = pow(sin(dlat/2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlong/2), 2);
    c = 2 * atan2(sqrt(a), sqrt(1-a));
    d = RADIUS * c;

    return d;
}

int main() {
    double lat1, long1, lat2, long2, dist;
    int choice;

    do {
        // Main menu
        printf("\nGPS Navigation Simulation\n");
        printf("------------------------\n");
        printf("1. Calculate distance between two coordinates\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Input first coordinates
                printf("\nEnter first coordinates (latitude longitude): ");
                scanf("%lf %lf", &lat1, &long1);

                // Input second coordinates
                printf("Enter second coordinates (latitude longitude): ");
                scanf("%lf %lf", &lat2, &long2);

                // Calculate distance
                dist = calcDist(lat1, long1, lat2, long2);

                // Output distance
                printf("\nThe distance between the two coordinates is %lf km.\n", dist);

                break;

            case 2:
                // Exit program
                printf("\nThanks for using GPS Navigation Simulation!\n");
                exit(0);

            default:
                // Invalid choice
                printf("\nInvalid choice, please try again!\n");
                break;
        }
    } while(choice != 2);

    return 0;
}