//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.01

typedef struct {
    double lat;
    double lon;
} coordinate;

coordinate current_location;

void set_current_location(double lat, double lon) {
    current_location.lat = lat;
    current_location.lon = lon;
}

void gps_simulation() {
    double distance = 0.0;
    double speed = 0.0;
    double time = 0.0;
    double lat1, lon1, lat2, lon2;

    set_current_location(37.774929, -122.419416);

    while (1) {
        printf("Current location: %.6f, %.6f\n", current_location.lat, current_location.lon);

        printf("Enter destination coordinates (latitude, longitude): ");
        scanf("%lf %lf", &lat1, &lon1);

        lat2 = current_location.lat;
        lon2 = current_location.lon;

        while (1) {
            distance = hypot(lat2 - lat1, lon2 - lon1);

            if (distance < 0.0001) {
                printf("Arrived at destination!\n");
                break;
            }

            speed = (distance - hypot(lat2 - current_location.lat, lon2 - current_location.lon)) / time;

            time += 1.0;

            lat2 += speed * cos(current_location.lat * PI / 180.0) * cos(lon2 * PI / 180.0) * EARTH_RADIUS / 180.0;
            lon2 += speed * sin(current_location.lat * PI / 180.0) * cos(lon2 * PI / 180.0) * EARTH_RADIUS / 180.0;

            printf("Current location: %.6f, %.6f\n", lat2, lon2);

            if (speed > 0.0) {
                printf("Speed: %.2f km/h\n", speed * 3.6);
            } else {
                printf("Stopped.\n");
            }

            if (distance < 0.0001) {
                break;
            }
        }

        printf("\n");
    }
}

int main() {
    gps_simulation();

    return 0;
}