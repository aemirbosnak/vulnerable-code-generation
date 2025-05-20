//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846
#define RADIUS 6371.0
#define DEG2RAD (PI/180.0)
#define RAD2DEG (180.0/PI)

struct {
    double latitude;
    double longitude;
} current_location, destination;

void init_gps() {
    srand(time(NULL));

    current_location.latitude = rand() % 90 - 45;
    current_location.longitude = rand() % 180 - 90;

    printf("Current location: %.2f°N %.2f°E\n", current_location.latitude * RAD2DEG, current_location.longitude * RAD2DEG);
}

void set_destination() {
    int choice;
    printf("Enter the destination type:\n");
    printf("1. Latitude and Longitude\n");
    printf("2. City and Country\n");
    scanf("%d", &choice);

    if (choice == 1) {
        destination.latitude = rand() % 90 - 45;
        destination.longitude = rand() % 180 - 90;
        printf("Destination: %.2f°N %.2f°E\n", destination.latitude * RAD2DEG, destination.longitude * RAD2DEG);
    } else if (choice == 2) {
        char city[50], country[50];
        printf("Enter the city and country:\n");
        scanf("%s %s", city, country);
        printf("Destination: %s, %s\n", city, country);
    }
}

void calculate_distance() {
    double dlat = destination.latitude - current_location.latitude;
    double dlon = destination.longitude - current_location.longitude;

    double a = sin(dlat/2) * sin(dlat/2) + cos(current_location.latitude * DEG2RAD) * cos(destination.latitude * DEG2RAD) * sin(dlon/2) * sin(dlon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));

    double distance = RADIUS * c;

    printf("Distance between current location and destination: %.2f km\n", distance);
}

void gps_navigation() {
    init_gps();
    set_destination();
    calculate_distance();
}

int main() {
    gps_navigation();
    return 0;
}