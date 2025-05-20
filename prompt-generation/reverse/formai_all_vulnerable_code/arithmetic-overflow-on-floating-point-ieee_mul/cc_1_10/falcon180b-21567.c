//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.009
#define LATITUDE_OFFSET 0.0
#define LONGITUDE_OFFSET 0.0
#define SPEED_OF_LIGHT 299792.458
#define GPS_UPDATE_INTERVAL 1000000 // 1 second

typedef struct {
    double latitude;
    double longitude;
    double altitude;
    double speed;
    double direction;
    time_t timestamp;
} GPSData;

void gps_update(GPSData *data) {
    data->timestamp = time(NULL);
    data->latitude = LATITUDE_OFFSET + rand() % 180;
    data->longitude = LONGITUDE_OFFSET + rand() % 360;
    data->altitude = rand() % 100;
    data->speed = rand() % 50;
    data->direction = rand() % 360;
}

double distance(double lat1, double lon1, double lat2, double lon2) {
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(lat1) * cos(lat2) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

void navigation(GPSData *data) {
    double distance_traveled = 0.0;
    double total_distance = 0.0;
    double eta = 0.0;
    double speed_kmh = 0.0;

    printf("Navigation started...\n");
    printf("Latitude: %.2f\n", data->latitude);
    printf("Longitude: %.2f\n", data->longitude);
    printf("Altitude: %.2f meters\n", data->altitude);
    printf("Speed: %.2f km/h\n", data->speed * 3.6);
    printf("Direction: %.2f degrees\n", data->direction);

    while (total_distance < 100.0) {
        gps_update(data);
        double new_distance = distance(data->latitude, data->longitude, 37.774929, -122.419416);
        distance_traveled += new_distance;
        total_distance += new_distance;
        eta = total_distance / data->speed;
        speed_kmh = data->speed * 3.6;

        printf("\r%.2f%% completed (%.2f km remaining) ETA: %.2f seconds Speed: %.2f km/h",
              (total_distance / 100.0) * 100.0,
              total_distance - distance_traveled,
              eta,
              speed_kmh);
        fflush(stdout);
        usleep(GPS_UPDATE_INTERVAL);
    }

    printf("\nNavigation completed!\n");
}

int main() {
    srand(time(NULL));
    GPSData data;
    navigation(&data);
    return 0;
}