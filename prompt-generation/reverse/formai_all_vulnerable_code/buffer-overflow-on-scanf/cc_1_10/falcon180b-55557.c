//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double lat;
    double lon;
} GPSCoordinate;

void initialize_gps(GPSCoordinate* gps) {
    gps->lat = rand() % 180 - 90;
    gps->lon = rand() % 360 - 180;
}

void display_gps_location(GPSCoordinate* gps) {
    printf("Latitude: %.2f\n", gps->lat);
    printf("Longitude: %.2f\n", gps->lon);
}

int main() {
    srand(time(NULL));

    GPSCoordinate gps;
    initialize_gps(&gps);

    while (1) {
        system("clear");

        display_gps_location(&gps);

        int choice;
        printf("Enter your choice:\n");
        printf("1. Move 10 meters north\n");
        printf("2. Move 10 meters east\n");
        printf("3. Move 10 meters south\n");
        printf("4. Move 10 meters west\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                gps.lat += 0.0001;
                break;
            case 2:
                gps.lon += 0.0001;
                break;
            case 3:
                gps.lat -= 0.0001;
                break;
            case 4:
                gps.lon -= 0.0001;
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}