//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double lat;
    double lon;
} location_t;

location_t gps_location = {0, 0};

void gps_init(double lat, double lon) {
    gps_location.lat = lat;
    gps_location.lon = lon;
}

void gps_update() {
    double distance = sqrt(pow(gps_location.lat - 37.7749, 2) + pow(gps_location.lon - 122.4194, 2));
    printf("Current location: %.2f, %.2f, distance: %.2f\n", gps_location.lat, gps_location.lon, distance);
}

int main() {
    gps_init(37.7749, 122.4194);
    gps_update();

    while (1) {
        char command[20];
        printf("Enter command (move, quit): ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            break;
        } else if (strcmp(command, "move") == 0) {
            double distance;
            printf("Enter distance to move (in meters): ");
            scanf("%lf", &distance);

            double new_lat = gps_location.lat + (distance / 6371) * cos(gps_location.lat * M_PI / 180);
            double new_lon = gps_location.lon + (distance / 6371) * cos(gps_location.lon * M_PI / 180);

            gps_location.lat = new_lat;
            gps_location.lon = new_lon;

            gps_update();
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}