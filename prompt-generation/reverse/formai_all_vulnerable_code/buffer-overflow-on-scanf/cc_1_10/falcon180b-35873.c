//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a structure to hold GPS data
typedef struct {
    double latitude;
    double longitude;
    double altitude;
    double speed;
    double heading;
} GPSData;

// Function to generate random GPS data
GPSData generateGPSData() {
    GPSData data;
    data.latitude = rand() % 180 - 90; // Random latitude between -90 and 90 degrees
    data.longitude = rand() % 360 - 180; // Random longitude between -180 and 180 degrees
    data.altitude = rand() % 1000; // Random altitude between 0 and 1000 meters
    data.speed = rand() % 100; // Random speed between 0 and 100 km/h
    data.heading = rand() % 360; // Random heading between 0 and 360 degrees
    return data;
}

// Function to print GPS data
void printGPSData(GPSData data) {
    printf("Latitude: %.2f\n", data.latitude);
    printf("Longitude: %.2f\n", data.longitude);
    printf("Altitude: %.2f meters\n", data.altitude);
    printf("Speed: %.2f km/h\n", data.speed);
    printf("Heading: %.2f degrees\n", data.heading);
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    GPSData data;
    int choice;

    do {
        printf("GPS Navigation Simulation\n");
        printf("1. Generate random GPS data\n");
        printf("2. Print GPS data\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                data = generateGPSData();
                printf("Random GPS data generated:\n");
                printGPSData(data);
                break;
            case 2:
                printf("Current GPS data:\n");
                printGPSData(data);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}