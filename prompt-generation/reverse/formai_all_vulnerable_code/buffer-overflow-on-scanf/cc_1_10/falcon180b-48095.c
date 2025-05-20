//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    int choice;
    double latitude, longitude, distance, speed, time;

    printf("Welcome to GPS Navigation Simulation!\n");
    printf("Please choose an option:\n");
    printf("1. Calculate distance between two points\n");
    printf("2. Calculate speed and time\n");
    printf("3. Exit\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter latitude and longitude of point 1:\n");
            scanf("%lf %lf", &latitude, &longitude);

            printf("Enter latitude and longitude of point 2:\n");
            scanf("%lf %lf", &latitude, &longitude);

            distance = acos(sin(latitude) * sin(latitude) + cos(latitude) * cos(latitude) * cos(longitude - longitude)) * 6371;

            printf("The distance between the two points is %.2lf km.\n", distance);
            break;

        case 2:
            printf("Enter latitude and longitude of starting point:\n");
            scanf("%lf %lf", &latitude, &longitude);

            printf("Enter latitude and longitude of destination point:\n");
            scanf("%lf %lf", &latitude, &longitude);

            distance = acos(sin(latitude) * sin(latitude) + cos(latitude) * cos(latitude) * cos(longitude - longitude)) * 6371;

            printf("The distance between the two points is %.2lf km.\n", distance);

            printf("Enter speed (in km/h):\n");
            scanf("%lf", &speed);

            time = distance / speed;

            printf("The time taken to travel between the two points is %.2lf hours.\n", time);
            break;

        case 3:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}