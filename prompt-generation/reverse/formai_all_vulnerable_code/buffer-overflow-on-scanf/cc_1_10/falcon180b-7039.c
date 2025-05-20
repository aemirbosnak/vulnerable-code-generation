//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double lat;
    double lon;
    double alt;
} GPS_Location;

void gps_update(GPS_Location *loc) {
    loc->lat += 0.01;
    loc->lon += 0.01;
    loc->alt += 10.0;
}

void gps_display(GPS_Location *loc) {
    printf("Latitude: %.4f\n", loc->lat);
    printf("Longitude: %.4f\n", loc->lon);
    printf("Altitude: %.2f meters\n", loc->alt);
}

int main() {
    GPS_Location gps_data;
    int choice;

    do {
        printf("GPS Navigation Simulation\n");
        printf("1. Update GPS Location\n");
        printf("2. Display GPS Location\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                gps_update(&gps_data);
                printf("GPS location updated!\n");
                break;
            case 2:
                gps_display(&gps_data);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}