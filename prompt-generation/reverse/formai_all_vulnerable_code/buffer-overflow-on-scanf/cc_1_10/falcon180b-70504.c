//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846
#define RADIUS 6371.01
#define DEG2RAD 0.01745329251994329576923690768489
#define RAD2DEG 57.295779513082320876798154814105

struct {
    double lat;
    double lon;
} gps;

void init() {
    srand(time(NULL));
    gps.lat = rand() % 90 - 45;
    gps.lon = rand() % 180 - 90;
}

void move(double distance) {
    double bearing = rand() % 360;
    double dlon = distance * sin(bearing * DEG2RAD);
    double dlat = distance * cos(bearing * DEG2RAD);
    gps.lon += dlon;
    gps.lat += dlat;
    if (gps.lon > 180) {
        gps.lon -= 360;
    } else if (gps.lon < -180) {
        gps.lon += 360;
    }
    if (gps.lat > 90) {
        gps.lat = 90;
    } else if (gps.lat < -90) {
        gps.lat = -90;
    }
}

void print_gps() {
    printf("Latitude: %.2f\n", gps.lat * RAD2DEG);
    printf("Longitude: %.2f\n", gps.lon * RAD2DEG);
}

int main() {
    init();
    int choice;
    do {
        printf("GPS Navigation Simulation\n");
        printf("1. Move 10 meters\n");
        printf("2. Move 100 meters\n");
        printf("3. Move 1000 meters\n");
        printf("4. Print current GPS coordinates\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                move(10);
                break;
            case 2:
                move(100);
                break;
            case 3:
                move(1000);
                break;
            case 4:
                print_gps();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);
    return 0;
}