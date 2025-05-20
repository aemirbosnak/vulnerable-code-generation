//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846
#define RADIUS 6371.0
#define DEG2RAD (PI/180.0)
#define RAD2DEG (180.0/PI)

typedef struct {
    double lat;
    double lon;
} GPSLocation;

void initialize_gps(GPSLocation* gps) {
    gps->lat = 0.0;
    gps->lon = 0.0;
}

void gps_set_location(GPSLocation* gps, double lat, double lon) {
    gps->lat = lat;
    gps->lon = lon;
}

double distance_between_gps_locations(GPSLocation* gps1, GPSLocation* gps2) {
    double lat1 = gps1->lat * DEG2RAD;
    double lon1 = gps1->lon * DEG2RAD;
    double lat2 = gps2->lat * DEG2RAD;
    double lon2 = gps2->lon * DEG2RAD;

    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;

    double a = sin(dlat/2) * sin(dlat/2) + cos(lat1) * cos(lat2) * sin(dlon/2) * sin(dlon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));

    return RADIUS * c;
}

int main() {
    GPSLocation gps1, gps2;
    char choice;
    double distance;

    do {
        system("clear");
        printf("GPS Navigation Simulation\n");
        printf("Enter's' to set a location, 'c' to calculate distance, or 'q' to quit: ");
        scanf("%c", &choice);

        switch(choice) {
            case's':
                printf("Enter latitude for location 1: ");
                scanf("%lf", &gps1.lat);
                printf("Enter longitude for location 1: ");
                scanf("%lf", &gps1.lon);
                break;
            case 'c':
                gps_set_location(&gps2, 0.0, 0.0);
                distance = distance_between_gps_locations(&gps1, &gps2);
                printf("Distance between locations: %.2lf km\n", distance);
                break;
            case 'q':
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while(choice!= 'q');

    return 0;
}