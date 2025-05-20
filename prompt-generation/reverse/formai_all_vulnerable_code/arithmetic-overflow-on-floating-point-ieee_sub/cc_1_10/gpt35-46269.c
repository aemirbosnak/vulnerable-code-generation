//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to convert degrees to radians
double deg2rad(double deg) {
    return (deg * PI / 180);
}

// Function to calculate the distance between two coordinates in kilometers
double distance(double lat1, double lon1, double lat2, double lon2) {
    double earthRadius = 6371; // Earth's radius in km
    double dLat = deg2rad(lat2 - lat1);
    double dLon = deg2rad(lon2 - lon1);
    double a = sin(dLat/2) * sin(dLat/2) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * sin(dLon/2) * sin(dLon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distance = earthRadius * c; // Distance in km
    return distance;
}

int main() {
    double currentLatitude = 0.0, currentLongitude = 0.0;
    printf("Please enter your current latitude: ");
    scanf("%lf", &currentLatitude);
    printf("Please enter your current longitude: ");
    scanf("%lf", &currentLongitude);
    printf("Your current location is: (%lf, %lf)\n", currentLatitude, currentLongitude);
    printf("Enter a destination latitude and longitude:\n");

    double destinationLatitude = 0.0, destinationLongitude = 0.0;
    scanf("%lf %lf", &destinationLatitude, &destinationLongitude);
    printf("Destination location is: (%lf, %lf)\n", destinationLatitude, destinationLongitude);

    double dist = distance(currentLatitude, currentLongitude, destinationLatitude, destinationLongitude);
    printf("The distance between the two coordinates is %lf km\n", dist);

    double bearing = 0.0;
    double dLon = deg2rad(destinationLongitude - currentLongitude);
    double y = sin(dLon) * cos(deg2rad(destinationLatitude));
    double x = cos(deg2rad(currentLatitude)) * sin(deg2rad(destinationLatitude)) - sin(deg2rad(currentLatitude)) * cos(deg2rad(destinationLatitude)) * cos(dLon);
    bearing = atan2(y, x);
    bearing = (bearing * 180 / PI);

    // Ensure bearing is in the range [0, 360)
    if(bearing < 0) {
        bearing += 360;
    }
    printf("The bearing from the current location to the destination is %lf degrees\n", bearing);

    return 0;
}