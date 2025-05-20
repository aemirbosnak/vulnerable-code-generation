//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

// Distance calculation formula using the haversine formula
double distanceFormula(double lat1, double long1, double lat2, double long2) {
    double dLat = (lat2 - lat1) * PI / 180.0;
    double dLon = (long2 - long1) * PI / 180.0;

    lat1 = (lat1) * PI / 180.0;
    lat2 = (lat2) * PI / 180.0;

    double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));

    return rad * c;
}

// Set the coordinates of the starting point and destination point
void setCoordinates(double *lat1, double *long1, double *lat2, double *long2) {
    printf("Enter the coordinates of your starting point:\n");
    printf("Latitude: ");
    scanf("%lf", lat1);
    printf("Longitude: ");
    scanf("%lf", long1);

    printf("\nEnter the coordinates of your destination point:\n");
    printf("Latitude: ");
    scanf("%lf", lat2);
    printf("Longitude: ");
    scanf("%lf", long2);
}

// Display the distance between the starting point and destination point
void displayDistance(double lat1, double long1, double lat2, double long2) {
    double distance = distanceFormula(lat1, long1, lat2, long2);
    printf("\nThe distance between the two points is %.2f kilometers.\n", distance);
}

// Main function to run the program
int main() {
    double lat1, long1, lat2, long2;

    setCoordinates(&lat1, &long1, &lat2, &long2);
    displayDistance(lat1, long1, lat2, long2);

    return 0;
}