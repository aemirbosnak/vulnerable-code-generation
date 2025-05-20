//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

// GPS data structure
typedef struct {
    double latitude;
    double longitude;
    double altitude;
    double speed;
    double heading;
} GPSData;

// Function to initialize GPS data
void initGPSData(GPSData *gpsData) {
    gpsData->latitude = rand() % 90 - 45;
    gpsData->longitude = rand() % 180 - 90;
    gpsData->altitude = rand() % 1000;
    gpsData->speed = rand() % 100;
    gpsData->heading = rand() % 360;
}

// Function to update GPS data
void updateGPSData(GPSData *gpsData) {
    gpsData->latitude += rand() % 10 - 5;
    gpsData->longitude += rand() % 10 - 5;
    gpsData->altitude += rand() % 10;
    gpsData->speed += rand() % 10;
    gpsData->heading += rand() % 10;
}

// Function to print GPS data
void printGPSData(GPSData *gpsData) {
    printf("Latitude: %.2f\n", gpsData->latitude);
    printf("Longitude: %.2f\n", gpsData->longitude);
    printf("Altitude: %d meters\n", (int)gpsData->altitude);
    printf("Speed: %.2f km/h\n", gpsData->speed);
    printf("Heading: %.2f degrees\n", gpsData->heading);
}

// Function to simulate GPS navigation
void simulateGPSNavigation(GPSData *gpsData, int duration) {
    srand(time(NULL));
    initGPSData(gpsData);

    for (int i = 0; i < duration; i++) {
        updateGPSData(gpsData);
        printf("GPS data at %d seconds:\n", i);
        printGPSData(gpsData);
        sleep(1);
    }
}

int main() {
    GPSData gpsData;
    int duration;

    // Get duration from user input
    printf("Enter the duration of the simulation in seconds: ");
    scanf("%d", &duration);

    // Simulate GPS navigation
    simulateGPSNavigation(&gpsData, duration);

    return 0;
}