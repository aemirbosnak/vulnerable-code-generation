//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.01
#define MINUTES_PER_HOUR 60
#define SECONDS_PER_MINUTE 60
#define SECONDS_PER_HOUR (MINUTES_PER_HOUR * SECONDS_PER_MINUTE)
#define DEGREES_PER_RADIAN 180 / PI
#define MAX_POINTS 1000

typedef struct {
    double latitude;
    double longitude;
    int timestamp;
} Point;

int main() {
    int choice;
    int numPoints = 0;
    Point *points = (Point *)malloc(MAX_POINTS * sizeof(Point));

    printf("Welcome to the GPS Navigation Simulation!\n");
    printf("Please choose an option:\n");
    printf("1. Start recording GPS coordinates\n");
    printf("2. Stop recording GPS coordinates\n");
    printf("3. Display recorded GPS coordinates\n");
    printf("4. Exit\n");

    do {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Recording GPS coordinates...\n");
                break;
            case 2:
                printf("Stopped recording GPS coordinates.\n");
                break;
            case 3:
                printf("Displaying recorded GPS coordinates:\n");
                for (int i = 0; i < numPoints; i++) {
                    printf("Latitude: %.6f\n", points[i].latitude);
                    printf("Longitude: %.6f\n", points[i].longitude);
                    printf("Timestamp: %d\n\n", points[i].timestamp);
                }
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 4);

    free(points);
    return 0;
}