//Falcon2-11B DATASET v1.0 Category: GPS Navigation Simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LATITUDE_MIN -90
#define LATITUDE_MAX 90
#define LONGITUDE_MIN -180
#define LONGITUDE_MAX 180
#define STEP_SIZE 0.1

void printLatitudeLongitude(double latitude, double longitude) {
    printf("%.2f,%.2f\n", latitude, longitude);
}

void setLatitude(double* latitude, double latitudeValue) {
    if (latitudeValue >= LATITUDE_MIN && latitudeValue <= LATITUDE_MAX) {
        *latitude = latitudeValue;
    } else {
        printf("Invalid latitude value\n");
    }
}

void setLongitude(double* longitude, double longitudeValue) {
    if (longitudeValue >= LONGITUDE_MIN && longitudeValue <= LONGITUDE_MAX) {
        *longitude = longitudeValue;
    } else {
        printf("Invalid longitude value\n");
    }
}

int main() {
    double latitude, longitude;
    int i;

    printf("Enter latitude: ");
    scanf("%lf", &latitude);
    setLatitude(&latitude, latitude);

    printf("Enter longitude: ");
    scanf("%lf", &longitude);
    setLongitude(&longitude, longitude);

    for (i = 0; i < 10; i++) {
        double newLatitude = latitude + STEP_SIZE;
        double newLongitude = longitude + STEP_SIZE;

        if (newLatitude >= LATITUDE_MIN && newLatitude <= LATITUDE_MAX &&
            newLongitude >= LONGITUDE_MIN && newLongitude <= LONGITUDE_MAX) {
            printLatitudeLongitude(newLatitude, newLongitude);
        } else {
            break;
        }
    }

    return 0;
}