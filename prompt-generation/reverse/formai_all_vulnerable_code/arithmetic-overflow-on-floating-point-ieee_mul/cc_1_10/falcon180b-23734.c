//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define R_EARTH 6371.01

// Define structure for GPS data
typedef struct {
    double latitude;
    double longitude;
    double speed;
    double direction;
} GPS_Data;

GPS_Data get_gps_data(double lat1, double lon1, double lat2, double lon2, double time) {
    // Calculate distance between two points
    double distance = sqrt(pow(lat2 - lat1, 2) + pow(lon2 - lon1, 2));

    // Calculate speed based on distance and time
    double speed = distance / (time * 3.6);

    // Calculate direction based on two points
    double direction = atan2(lon2 - lon1, lat2 - lat1) * 180 / PI;

    GPS_Data gps_data;
    gps_data.latitude = lat2;
    gps_data.longitude = lon2;
    gps_data.speed = speed;
    gps_data.direction = direction;

    return gps_data;
}

int main() {
    double lat1 = 37.7749;
    double lon1 = -122.4194;
    double lat2 = 40.7128;
    double lon2 = -74.0060;
    double time = 5;

    GPS_Data gps_data = get_gps_data(lat1, lon1, lat2, lon2, time);

    printf("Latitude: %.6f\n", gps_data.latitude);
    printf("Longitude: %.6f\n", gps_data.longitude);
    printf("Speed: %.2f km/h\n", gps_data.speed);
    printf("Direction: %.2f degrees\n", gps_data.direction);

    return 0;
}