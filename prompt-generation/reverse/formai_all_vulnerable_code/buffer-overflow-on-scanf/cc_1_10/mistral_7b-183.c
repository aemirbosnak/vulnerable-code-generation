//MISTRAL-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define PI 3.14159265358979323846
#define DEG_TO_RAD (PI / 180.0)
#define RAD_TO_DEG (180.0 / PI)

typedef struct {
    double latitude;
    double longitude;
    double heading;
    double speed;
} GPS_data;

GPS_data gps;

void update_gps_data() {
    gps.latitude += 0.001 * sin(gps.heading * DEG_TO_RAD);
    gps.longitude += 0.001 * cos(gps.heading * DEG_TO_RAD);

    gps.heading += 0.1;
    gps.speed += 1.0;
}

void print_gps_data() {
    printf("\nGPS Data:\n");
    printf("Latitude: %.6f\n", gps.latitude);
    printf("Longitude: %.6f\n", gps.longitude);
    printf("Heading: %.1f degrees\n", gps.heading * RAD_TO_DEG);
    printf("Speed: %.1f km/h\n", gps.speed * 3.6);
}

int main() {
    srand(time(NULL));

    gps.latitude = 40.7128;
    gps.longitude = -74.0060;
    gps.heading = 0.0;
    gps.speed = 0.0;

    int choice;

    while (1) {
        printf("\n1. Update GPS data\n2. Print GPS data\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                update_gps_data();
                break;
            case 2:
                print_gps_data();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}