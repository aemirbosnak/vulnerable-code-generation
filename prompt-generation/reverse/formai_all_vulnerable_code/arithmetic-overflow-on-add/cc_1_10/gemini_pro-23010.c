//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the GPS data structure
typedef struct {
    double latitude;
    double longitude;
    double altitude;
    double speed;
    double heading;
} GPSData;

// Define the navigation simulation function
void navigate(GPSData *gpsData) {
    // Get the current time
    time_t currentTime = time(NULL);

    // Set the initial GPS data
    gpsData->latitude = 37.422408;
    gpsData->longitude = -122.084060;
    gpsData->altitude = 0;
    gpsData->speed = 0;
    gpsData->heading = 0;

    // Randomly generate GPS data for the next 10 seconds
    for (int i = 0; i < 10; i++) {
        // Update the time
        currentTime += 1;

        // Randomly generate the latitude
        gpsData->latitude += (rand() % 100) / 100000.0;

        // Randomly generate the longitude
        gpsData->longitude += (rand() % 100) / 100000.0;

        // Randomly generate the altitude
        gpsData->altitude += (rand() % 100) / 100000.0;

        // Randomly generate the speed
        gpsData->speed += (rand() % 10) / 100.0;

        // Randomly generate the heading
        gpsData->heading += (rand() % 10) / 100.0;

        // Print the GPS data
        printf("%s: Latitude: %f, Longitude: %f, Altitude: %f, Speed: %f, Heading: %f\n",
            ctime(&currentTime), gpsData->latitude, gpsData->longitude, gpsData->altitude, gpsData->speed, gpsData->heading);
    }
}

// Main function
int main() {
    // Create a GPS data structure
    GPSData gpsData;

    // Navigate the GPS data
    navigate(&gpsData);

    return 0;
}