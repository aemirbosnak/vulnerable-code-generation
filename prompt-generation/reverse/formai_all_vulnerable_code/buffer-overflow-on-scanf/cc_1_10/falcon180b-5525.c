//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define PI 3.14159265358979323846

/* GPS data structure */
typedef struct {
    double latitude;
    double longitude;
    double altitude;
    double speed;
    double heading;
} GPSData;

/* GPS functions */
void initGPS(GPSData *gps);
void updateGPS(GPSData *gps, double deltaTime);
void printGPS(const GPSData *gps);

/* Map functions */
void initMap(void);
void updateMap(double latitude, double longitude);
void printMap(void);

int main(void) {
    srand(time(NULL));

    GPSData gps;
    initGPS(&gps);

    int choice;
    do {
        printf("GPS Navigation Simulation\n");
        printf("1. Update GPS data\n");
        printf("2. Print GPS data\n");
        printf("3. Print map\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                updateGPS(&gps, 1.0);
                break;
            case 2:
                printGPS(&gps);
                break;
            case 3:
                printMap();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}

void initGPS(GPSData *gps) {
    gps->latitude = rand() % 180 - 90;
    gps->longitude = rand() % 360 - 180;
    gps->altitude = rand() % 1000;
    gps->speed = rand() % 100;
    gps->heading = rand() % 360;
}

void updateGPS(GPSData *gps, double deltaTime) {
    gps->latitude += gps->speed * cos(gps->heading * PI / 180) * deltaTime;
    gps->longitude += gps->speed * sin(gps->heading * PI / 180) * deltaTime;
}

void printGPS(const GPSData *gps) {
    printf("Latitude: %.2f\n", gps->latitude);
    printf("Longitude: %.2f\n", gps->longitude);
    printf("Altitude: %d meters\n", (int)gps->altitude);
    printf("Speed: %.2f km/h\n", gps->speed * 3.6);
    printf("Heading: %.2f degrees\n", gps->heading);
}

void initMap(void) {
    printf("Initializing map...\n");
}

void updateMap(double latitude, double longitude) {
    printf("Updating map...\n");
}

void printMap(void) {
    printf("Printing map...\n");
}