//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EARTH_RADIUS 6371.01 // in kilometers

// function to calculate distance between two points
double distance(double lat1, double lon1, double lat2, double lon2) {
    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(lat1) * cos(lat2) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

// function to calculate bearing between two points
double bearing(double lat1, double lon1, double lat2, double lon2) {
    double y = sin(lon2 - lon1) * cos(lat2);
    double x = cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(lon2 - lon1);
    double brng = atan2(y, x);
    return brng * 180 / M_PI;
}

// function to read input coordinates
void read_coordinates(char *prompt, double *lat, double *lon) {
    printf("%s", prompt);
    scanf("%lf %lf", lat, lon);
}

// function to display current position and destination
void display_position(double lat, double lon) {
    printf("Current position: %.6lf, %.6lf\n", lat, lon);
}

// function to display distance and bearing to destination
void display_distance_bearing(double lat1, double lon1, double lat2, double lon2) {
    double dist = distance(lat1, lon1, lat2, lon2);
    double brng = bearing(lat1, lon1, lat2, lon2);
    printf("Distance to destination: %.2lf km\n", dist);
    printf("Bearing to destination: %.2lf degrees\n", brng);
}

// main function
int main() {
    double lat1, lon1, lat2, lon2;
    printf("Enter your current position (latitude, longitude): ");
    read_coordinates("", &lat1, &lon1);
    printf("Enter your destination (latitude, longitude): ");
    read_coordinates("", &lat2, &lon2);
    display_position(lat1, lon1);
    display_distance_bearing(lat1, lon1, lat2, lon2);
    return 0;
}