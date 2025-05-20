//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846
#define R 6371.0
#define EARTH_RADIUS 6378137.0
#define DEG_TO_RAD 0.01745329251994329576923690768489

// Function to calculate distance between two coordinates
double calculate_distance(double lat1, double lon1, double lat2, double lon2) {
    double d_lat = lat2 - lat1;
    double d_lon = lon2 - lon1;
    double a = sin(d_lat / 2) * sin(d_lat / 2) + cos(lat1 * DEG_TO_RAD) * cos(lat2 * DEG_TO_RAD) * sin(d_lon / 2) * sin(d_lon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = R * c;
    return distance;
}

// Function to convert decimal degrees to radians
double deg_to_rad(double deg) {
    return deg * DEG_TO_RAD;
}

// Function to convert radians to decimal degrees
double rad_to_deg(double rad) {
    return rad * (180 / PI);
}

// Function to generate random coordinates within a given range
void generate_random_coords(double *lat, double *lon, double min_lat, double max_lat, double min_lon, double max_lon) {
    *lat = rand() % (int)(max_lat - min_lat + 1) + min_lat;
    *lon = rand() % (int)(max_lon - min_lon + 1) + min_lon;
}

// Function to get user input for destination coordinates
void get_destination_coords(double *dest_lat, double *dest_lon) {
    printf("Enter destination latitude: ");
    scanf("%lf", dest_lat);
    printf("Enter destination longitude: ");
    scanf("%lf", dest_lon);
}

int main() {
    srand(time(NULL));

    double start_lat, start_lon, dest_lat, dest_lon;
    generate_random_coords(&start_lat, &start_lon, -90.0, 90.0, -180.0, 180.0);
    get_destination_coords(&dest_lat, &dest_lon);

    double distance = calculate_distance(start_lat, start_lon, dest_lat, dest_lon);

    printf("The distance between the starting point and the destination is %.2lf kilometers.\n", distance);

    return 0;
}