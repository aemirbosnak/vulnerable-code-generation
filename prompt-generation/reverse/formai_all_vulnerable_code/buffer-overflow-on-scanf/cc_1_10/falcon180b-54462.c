//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359
#define EARTH_RADIUS 6371.01
#define MIN_LAT -90
#define MAX_LAT 90
#define MIN_LON -180
#define MAX_LON 180

// GPS coordinates structure
struct GPS_coord {
    double lat;
    double lon;
};

// GPS coordinates functions
double distance_between_gps_points(struct GPS_coord gps1, struct GPS_coord gps2) {
    double lat_diff = gps2.lat - gps1.lat;
    double lon_diff = gps2.lon - gps1.lon;

    double a = sin(lat_diff/2) * sin(lat_diff/2) + cos(gps1.lat) * cos(gps2.lat) * sin(lon_diff/2) * sin(lon_diff/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distance = EARTH_RADIUS * c;

    return distance;
}

void gps_navigation_simulation() {
    struct GPS_coord current_location;
    struct GPS_coord destination_location;

    // Get current location from user input
    printf("Enter your current location in degrees (latitude, longitude): ");
    scanf("%lf %lf", &current_location.lat, &current_location.lon);

    // Get destination location from user input
    printf("Enter your destination location in degrees (latitude, longitude): ");
    scanf("%lf %lf", &destination_location.lat, &destination_location.lon);

    // Calculate distance between current and destination locations
    double distance = distance_between_gps_points(current_location, destination_location);

    // Print navigation instructions
    printf("Navigation instructions:\n");
    if (distance < 1) {
        printf("You have reached your destination.\n");
    } else {
        printf("Travel %.2lf kilometers to reach your destination.\n", distance);
    }
}

int main() {
    gps_navigation_simulation();
    return 0;
}