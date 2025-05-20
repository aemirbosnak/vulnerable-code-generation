//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    double latitude;
    double longitude;
    double speed;
    double direction;
} GPSData;

void initGPS(GPSData *gps) {
    gps->latitude = 0;
    gps->longitude = 0;
    gps->speed = 0;
    gps->direction = 0;
}

void updateGPS(GPSData *gps, double lat, double lon, double spd, double dir) {
    gps->latitude = lat;
    gps->longitude = lon;
    gps->speed = spd;
    gps->direction = dir;
}

void printGPS(GPSData *gps) {
    printf("Latitude: %.2f\n", gps->latitude);
    printf("Longitude: %.2f\n", gps->longitude);
    printf("Speed: %.2f km/h\n", gps->speed * 3.6);
    printf("Direction: %.2f degrees\n", gps->direction);
}

int main() {
    GPSData gps;
    initGPS(&gps);
    int choice;

    while(TRUE) {
        printf("GPS Menu:\n");
        printf("1. Update GPS Data\n");
        printf("2. Print GPS Data\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter latitude: ");
                scanf("%lf", &gps.latitude);
                printf("Enter longitude: ");
                scanf("%lf", &gps.longitude);
                printf("Enter speed (km/h): ");
                scanf("%lf", &gps.speed);
                printf("Enter direction (degrees): ");
                scanf("%lf", &gps.direction);
                break;
            case 2:
                printGPS(&gps);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}