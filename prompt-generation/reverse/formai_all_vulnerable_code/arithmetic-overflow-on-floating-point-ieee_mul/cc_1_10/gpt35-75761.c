//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define R_EARTH 6371000.0 // Radius of Earth in meters
#define PI 3.14159265358979323846

typedef struct {
   double latitude;
   double longitude;
} coordinate;

double deg2rad(double deg) {
   return deg * (PI/180);
}

double distBetweenPoints(coordinate point1, coordinate point2) {
   double lat1 = deg2rad(point1.latitude);
   double lat2 = deg2rad(point2.latitude);
   double lon1 = deg2rad(point1.longitude);
   double lon2 = deg2rad(point2.longitude);
   double dLat = lat2 - lat1;
   double dLon = lon2 - lon1;
   double a = sin(dLat/2)*sin(dLat/2) + cos(lat1) * cos(lat2) * sin(dLon/2)*sin(dLon/2);
   double c = 2 * atan2(sqrt(a), sqrt(1-a));
   double d = R_EARTH * c;
   return d;
}

int main() {
   coordinate currentLocation;
   coordinate destination;
   double distance;
   
   printf("Enter your current latitude: ");
   scanf("%lf", &currentLocation.latitude);
   printf("Enter your current longitude: ");
   scanf("%lf", &currentLocation.longitude);
   
   printf("Enter your destination latitude: ");
   scanf("%lf", &destination.latitude);
   printf("Enter your destination longitude: ");
   scanf("%lf", &destination.longitude);
   
   distance = distBetweenPoints(currentLocation, destination);
   
   printf("Distance between current location and destination is %.2f meters.\n", distance);
   
   return 0;
}