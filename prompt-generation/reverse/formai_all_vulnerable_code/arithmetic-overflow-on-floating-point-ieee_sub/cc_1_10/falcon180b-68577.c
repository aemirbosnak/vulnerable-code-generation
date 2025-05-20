//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define R 6371.0

//Function to calculate distance between two points
double distance(double lat1, double lon1, double lat2, double lon2)
{
    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;
    double a = sin(dLat/2) * sin(dLat/2) + cos(lat1*PI/180) * cos(lat2*PI/180) * sin(dLon/2) * sin(dLon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    return R * c;
}

//Function to calculate bearing between two points
double bearing(double lat1, double lon1, double lat2, double lon2)
{
    double dLon = lon2 - lon1;
    double y = sin(dLon) * cos(lat2*PI/180);
    double x = cos(lat1*PI/180) * sin(lat2*PI/180) - sin(lat1*PI/180) * cos(lat2*PI/180) * cos(dLon);
    double brng = atan2(y, x);
    return brng * 180/PI;
}

//Function to calculate midpoint between two points
void midpoint(double lat1, double lon1, double lat2, double lon2, double *midLat, double *midLon)
{
    *midLat = (lat1 + lat2) / 2;
    *midLon = (lon1 + lon2) / 2;
}

//Main function
int main()
{
    double lat1, lon1, lat2, lon2;
    double distanceResult, bearingResult;
    double midLat, midLon;

    //Get user input for two points
    printf("Enter latitude and longitude for the first point: ");
    scanf("%lf %lf", &lat1, &lon1);
    printf("Enter latitude and longitude for the second point: ");
    scanf("%lf %lf", &lat2, &lon2);

    //Calculate distance between two points
    distanceResult = distance(lat1, lon1, lat2, lon2);
    printf("The distance between the two points is: %.2lf km\n", distanceResult);

    //Calculate bearing between two points
    bearingResult = bearing(lat1, lon1, lat2, lon2);
    printf("The bearing from the first point to the second point is: %.2lf degrees\n", bearingResult);

    //Calculate midpoint between two points
    midpoint(lat1, lon1, lat2, lon2, &midLat, &midLon);
    printf("The midpoint between the two points is: %.2lf degrees N, %.2lf degrees E\n", midLat, midLon);

    return 0;
}