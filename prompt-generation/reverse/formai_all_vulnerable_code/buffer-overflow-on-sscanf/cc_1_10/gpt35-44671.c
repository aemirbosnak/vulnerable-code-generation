//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define PI 3.141592653589793 // Value of pi
#define RADIUS_OF_EARTH 6731 // In kilometers
#define MAX_LENGTH 100 // Maximum length of input string

double toRadians(double degree) {
    // Function to convert degree to radians
    return degree * (PI / 180);
}

double distanceBetweenPoints(double lat1, double long1, double lat2, double long2) {
    // Function to calculate distance between two points on Earth
    double dLat = toRadians(lat2 - lat1);
    double dLong = toRadians(long2 - long1);
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(toRadians(lat1)) * cos(toRadians(lat2)) * sin(dLong / 2) * sin(dLong / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = RADIUS_OF_EARTH * c;
    return distance;
}

int main() {
    char input[MAX_LENGTH];
    double currentLat = 0, currentLong = 0, targetLat = 0, targetLong = 0;
    printf("Welcome to Retro GPS Navigation Simulation!\n");
    printf("-------------------------------------------\n");

    while (1) {
        printf("Enter your current latitude and longitude (separated by a comma): ");
        fgets(input, MAX_LENGTH, stdin);
        sscanf(input, "%lf,%lf", &currentLat, &currentLong);
        if (currentLat != 0 && currentLong != 0) {
            break;
        }
        printf("Invalid input, please try again.\n");
    }

    while (1) {
        printf("Enter your target latitude and longitude (separated by a comma): ");
        fgets(input, MAX_LENGTH, stdin);
        sscanf(input, "%lf,%lf", &targetLat, &targetLong);
        if (targetLat != 0 && targetLong != 0) {
            break;
        }
        printf("Invalid input, please try again.\n");
    }

    double distance = distanceBetweenPoints(currentLat, currentLong, targetLat, targetLong);
    printf("The distance from your current location to the target location is: %.2lf kilometers\n", distance);

    return 0;
}