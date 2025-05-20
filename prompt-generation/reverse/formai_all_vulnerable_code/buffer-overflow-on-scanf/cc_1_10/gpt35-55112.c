//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

double degreeToRadian(double degree) {
    return degree * PI / 180.0;
}

double radianToDegree(double radian) {
    return radian * 180.0 / PI;
}

double calculateDistance(double latitude1, double longitude1, double latitude2, double longitude2) {
    double dLatitude = degreeToRadian(latitude2 - latitude1);
    double dLongitude = degreeToRadian(longitude2 - longitude1);

    double a = pow(sin(dLatitude / 2), 2) + cos(degreeToRadian(latitude1)) *
            cos(degreeToRadian(latitude2)) * pow(sin(dLongitude / 2), 2);

    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return 6371000 * c;
}

int main() {
    double userLatitude, userLongitude;
    double destinationLatitude, destinationLongitude;

    printf("Enter your current latitude: ");
    scanf("%lf", &userLatitude);

    printf("Enter your current longitude: ");
    scanf("%lf", &userLongitude);

    printf("Enter destination latitude: ");
    scanf("%lf", &destinationLatitude);

    printf("Enter destination longitude: ");
    scanf("%lf", &destinationLongitude);

    double distance = calculateDistance(userLatitude, userLongitude, destinationLatitude, destinationLongitude);
    double bearing = radianToDegree(atan2(sin(degreeToRadian(destinationLongitude - userLongitude)) *
            cos(degreeToRadian(destinationLatitude)), cos(degreeToRadian(userLatitude)) *
            sin(degreeToRadian(destinationLatitude)) -
            sin(degreeToRadian(userLatitude)) * cos(degreeToRadian(destinationLatitude)) *
            cos(degreeToRadian(destinationLongitude - userLongitude))));

    if (bearing < 0) {
        bearing += 360;
    }

    printf("Distance to destination: %.2f meters\n", distance);
    printf("Bearing: %.2f degrees\n", bearing);

    return 0;
}