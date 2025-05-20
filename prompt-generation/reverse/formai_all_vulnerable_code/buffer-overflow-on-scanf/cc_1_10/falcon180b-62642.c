//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define RADIUS 6371.01
#define DEG_TO_RAD (PI/180.0)

struct GPSData {
    double lat;
    double lon;
    double alt;
};

struct GPSData getGPSData() {
    struct GPSData gps;
    gps.lat = rand() % 180 - 90;
    gps.lon = rand() % 360 - 180;
    gps.alt = rand() % 1000;
    return gps;
}

void printGPSData(struct GPSData gps) {
    printf("Latitude: %.2f\n", gps.lat);
    printf("Longitude: %.2f\n", gps.lon);
    printf("Altitude: %.2f\n", gps.alt);
}

int main() {
    struct GPSData gps;
    int choice;

    do {
        printf("GPS Navigation Simulation\n");
        printf("1. Get GPS Data\n");
        printf("2. Print GPS Data\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                gps = getGPSData();
                break;
            case 2:
                printGPSData(gps);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while(choice!= 3);

    return 0;
}