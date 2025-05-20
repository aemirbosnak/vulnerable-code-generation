//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double latitude;
    double longitude;
} Point;

typedef struct {
    Point start;
    Point end;
} Route;

int main() {
    // Initialize the GPS receiver
    double latitude = 0.0;
    double longitude = 0.0;
    double altitude = 0.0;
    double speed = 0.0;
    double heading = 0.0;

    // Simulate the GPS receiver by reading data from a file
    FILE *fp = fopen("gps_data.txt", "r");
    if (fp == NULL) {
        perror("Error opening GPS data file");
        return EXIT_FAILURE;
    }

    while (fscanf(fp, "%lf %lf %lf %lf %lf", &latitude, &longitude, &altitude, &speed, &heading) == 5) {
        // Update the GPS receiver's data
        latitude = latitude * PI / 180.0;
        longitude = longitude * PI / 180.0;
        altitude = altitude * 1000.0;
        speed = speed * 1.852;
        heading = heading * PI / 180.0;

        // Simulate the GPS receiver's display
        printf("Latitude: %lf degrees\n", latitude * 180.0 / PI);
        printf("Longitude: %lf degrees\n", longitude * 180.0 / PI);
        printf("Altitude: %lf meters\n", altitude);
        printf("Speed: %lf kilometers per hour\n", speed);
        printf("Heading: %lf degrees\n", heading * 180.0 / PI);
        printf("\n");
    }

    // Close the GPS data file
    fclose(fp);

    return EXIT_SUCCESS;
}