//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.0
#define MIN_LAT -90.0
#define MAX_LAT 90.0
#define MIN_LON -180.0
#define MAX_LON 180.0
#define MAX_SPEED 100.0

typedef struct {
    double lat;
    double lon;
    double speed;
} GPS;

void init_gps(GPS *gps) {
    gps->lat = 0.0;
    gps->lon = 0.0;
    gps->speed = 0.0;
}

void print_gps(GPS *gps) {
    printf("Latitude: %.6f\n", gps->lat);
    printf("Longitude: %.6f\n", gps->lon);
    printf("Speed: %.2f km/h\n", gps->speed);
}

void move_gps(GPS *gps, double distance) {
    double lat_diff = distance * cos(gps->lat * PI / 180.0);
    double lon_diff = distance * sin(gps->lat * PI / 180.0);
    gps->lat += lat_diff;
    gps->lon += lon_diff;
}

int main() {
    GPS gps;
    init_gps(&gps);
    printf("Welcome to the GPS Navigation Simulation!\n");
    printf("You are currently at (0,0) with a speed of 0 km/h.\n");
    print_gps(&gps);

    int choice;
    do {
        printf("Please choose an option:\n");
        printf("1. Move\n");
        printf("2. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                double distance;
                printf("Enter the distance to move (in km): ");
                scanf("%lf", &distance);
                if (distance > MAX_SPEED) {
                    printf("Error: Distance too long.\n");
                } else {
                    move_gps(&gps, distance);
                    print_gps(&gps);
                }
                break;
            }
            case 2: {
                printf("Exiting program.\n");
                break;
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    } while (choice!= 2);

    return 0;
}