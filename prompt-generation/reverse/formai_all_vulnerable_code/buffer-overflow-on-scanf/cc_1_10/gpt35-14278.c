//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: complete
#include<stdio.h>
#include<math.h>

/*Function to convert degrees to radians*/
double degToRad(double deg)
{
    double rad = deg * (M_PI/180.0);  /*M_PI is a constant defined in math.h*/
    return rad;
}

/*Function to calculate the distance between two GPS coordinates using the haversine formula*/
double haversine(double lat1, double long1, double lat2, double long2)
{
    double r = 6371.0;  /*Mean radius of earth in km*/
    double dLat = degToRad(lat2 - lat1);
    double dLong = degToRad(long2 - long1);
    double a = sin(dLat/2.0) * sin(dLat/2.0) + cos(degToRad(lat1)) * cos(degToRad(lat2)) * sin(dLong/2.0) * sin(dLong/2.0);
    double c = 2.0 * atan2(sqrt(a), sqrt(1-a));
    double d = r * c;
    return d;
}

/*Function to calculate the bearing between two GPS coordinates using the spherical law of cosines*/
double sphericalLawOfCosines(double lat1, double long1, double lat2, double long2)
{
    double dLong = degToRad(long2 - long1);
    double y = sin(dLong) * cos(lat2);
    double x = cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(dLong);
    double bearing = atan2(y, x);
    bearing = bearing * (180.0/M_PI);  /*Convert radians to degrees*/
    bearing = fmod((bearing + 360.0), 360.0);  /*Normalize bearing to between 0 and 360*/
    return bearing;
}

/*Sample main function to simulate GPS navigation*/
int main()
{
    double lat1, long1, lat2, long2, distance, bearing;
    
    /*Get starting point's latitude and longitude from user*/
    printf("Enter the starting point's latitude: ");
    scanf("%lf", &lat1);
    printf("Enter the starting point's longitude: ");
    scanf("%lf", &long1);

    /*Get destination point's latitude and longitude from user*/
    printf("Enter the destination point's latitude: ");
    scanf("%lf", &lat2);
    printf("Enter the destination point's longitude: ");
    scanf("%lf", &long2);

    /*Calculate the distance and bearing between the two points*/
    distance = haversine(lat1, long1, lat2, long2);
    bearing = sphericalLawOfCosines(lat1, long1, lat2, long2);

    /*Print the results*/
    printf("Distance between the two GPS coordinates is %.2lf km\n", distance);
    printf("The bearing from the starting point to the destination point is %.2lf degrees\n", bearing);

    return 0;
}