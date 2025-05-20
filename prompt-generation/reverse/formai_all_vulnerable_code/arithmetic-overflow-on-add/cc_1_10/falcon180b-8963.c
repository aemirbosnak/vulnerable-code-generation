//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.01
#define EARTH_CIRCUMFERENCE 40075016.69
#define DEG_TO_RAD 0.0174532925
#define RAD_TO_DEG 57.2957795

// GPS data structure
typedef struct {
    double latitude;
    double longitude;
    double altitude;
    double speed;
    double course;
    int satellites;
    time_t timestamp;
} gps_data_t;

// Function prototypes
void gps_simulation(gps_data_t *gps_data);
int main() {
    gps_data_t gps_data;
    gps_simulation(&gps_data);
    return 0;
}

void gps_simulation(gps_data_t *gps_data) {
    // Initialize GPS data
    gps_data->latitude = 37.7749;
    gps_data->longitude = -122.4194;
    gps_data->altitude = 0;
    gps_data->speed = 0;
    gps_data->course = 0;
    gps_data->satellites = 6;
    gps_data->timestamp = time(NULL);

    // Simulate GPS data for 10 minutes
    for (int i = 0; i < 10; i++) {
        gps_data->timestamp += 60;
        gps_data->longitude += 0.001;
        gps_data->latitude += 0.001;
        gps_data->altitude += 0.1;
        gps_data->speed += 0.1;
        gps_data->course += 1;

        // Calculate distance traveled
        double distance = gps_data->speed * (gps_data->timestamp - gps_data->timestamp - 60) / 3600;
        gps_data->latitude += distance * sin(gps_data->course * DEG_TO_RAD);
        gps_data->longitude += distance * cos(gps_data->course * DEG_TO_RAD);

        // Update GPS data
        printf("GPS Data (%d):\n", i + 1);
        printf("Timestamp: %s\n", ctime(&gps_data->timestamp));
        printf("Latitude: %.6f\n", gps_data->latitude);
        printf("Longitude: %.6f\n", gps_data->longitude);
        printf("Altitude: %.2f\n", gps_data->altitude);
        printf("Speed: %.2f\n", gps_data->speed);
        printf("Course: %.2f\n", gps_data->course);
        printf("Satellites: %d\n", gps_data->satellites);
        printf("\n");
    }
}