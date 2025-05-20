//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

/* structure to hold GPS coordinates */
typedef struct {
    double latitude;
    double longitude;
} GPSCoord;

/* function to calculate distance between two GPS coordinates */
double calculate_distance(GPSCoord coord1, GPSCoord coord2) {
    double dLat = coord2.latitude - coord1.latitude;
    double dLon = coord2.longitude - coord1.longitude;
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(coord1.latitude) * cos(coord2.latitude) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return 6371 * c; /* Earth's radius in kilometers */
}

/* function to get user input for GPS coordinates */
GPSCoord get_coordinates() {
    GPSCoord coord;
    printf("Enter latitude: ");
    scanf("%lf", &coord.latitude);
    printf("Enter longitude: ");
    scanf("%lf", &coord.longitude);
    return coord;
}

/* function to get user input for destination coordinates */
GPSCoord get_destination() {
    GPSCoord dest;
    printf("Enter destination latitude: ");
    scanf("%lf", &dest.latitude);
    printf("Enter destination longitude: ");
    scanf("%lf", &dest.longitude);
    return dest;
}

/* function to display GPS coordinates */
void display_coordinates(GPSCoord coord) {
    printf("Latitude: %.6lf\n", coord.latitude);
    printf("Longitude: %.6lf\n", coord.longitude);
}

/* function to display distance between two GPS coordinates */
void display_distance(GPSCoord coord1, GPSCoord coord2) {
    double distance = calculate_distance(coord1, coord2);
    printf("Distance between coordinates: %.2lf kilometers\n", distance);
}

int main() {
    /* get user input for GPS coordinates */
    GPSCoord current_coord = get_coordinates();
    GPSCoord destination_coord = get_destination();

    /* display current and destination coordinates */
    printf("Current coordinates:\n");
    display_coordinates(current_coord);
    printf("Destination coordinates:\n");
    display_coordinates(destination_coord);

    /* calculate and display distance between coordinates */
    display_distance(current_coord, destination_coord);

    return 0;
}