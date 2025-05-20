//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.141592653589793

double distance(double lat1, double lon1, double lat2, double lon2);
double bearing(double lat1, double lon1, double lat2, double lon2);
void getNextCoordinate(double *lat, double *lon, double bearing, double distance);

int main(){
    double lat1, lon1, lat2, lon2, d, b;
    int choice;

    printf("Enter Starting Point Latitude and Longitude in Decimal Degrees (ex: 45.678,-123.456): ");
    scanf("%lf,%lf", &lat1, &lon1);

    printf("\nEnter Ending Point Latitude and Longitude in Decimal Degrees (ex: 45.678,-123.456): ");
    scanf("%lf,%lf", &lat2, &lon2);

    printf("\n\nSimulating GPS Navigation from (%lf,%lf) to (%lf,%lf)",lat1,lon1,lat2,lon2);

    d = distance(lat1,lon1,lat2,lon2);
    printf("\n\nDistance to Destination: %lf km\n",d);

    b = bearing(lat1,lon1,lat2,lon2);
    printf("\nBearing: %lf degrees.\n",b);

    printf("\nWould you like to simulate navigation?\n1 = Yes, 0 = No: ");
    scanf("%d",&choice);
    while(choice == 1)
    {
        printf("\nEnter distance to travel (km): ");
        scanf("%lf",&d);

        getNextCoordinate(&lat1, &lon1, b, d);

        printf("\nYou have traveled %lf km and have arrived at (%lf,%lf)", d, lat1, lon1);

        b = bearing(lat1,lon1,lat2,lon2);
        printf("\nBearing: %lf degrees.\n",b);

        if(distance(lat1,lon1,lat2,lon2)<0.1) {
            printf("\nYou have arrived at your destination.\n");
            break;
        }

        printf("\nWould you like to continue navigation?\n1 = Yes, 0 = No: ");
        scanf("%d",&choice);
    }

    return 0;
}

double distance(double lat1, double lon1, double lat2, double lon2){
    double R = 6371; //Radius of Earth in km
    double dLat = (lat2-lat1)*PI/180;
    double dLon = (lon2-lon1)*PI/180; 
    double a = sin(dLat/2) * sin(dLat/2) + cos(lat1*PI/180) * cos(lat2*PI/180) * sin(dLon/2) * sin(dLon/2); 
    double c = 2 * atan2(sqrt(a), sqrt(1-a)); 
    double d = R * c; //Distance in km
    return d;
}

double bearing(double lat1, double lon1, double lat2, double lon2)
{
    //Calculate bearing in degrees
    double dLon = (lon2 - lon1);
    double y = sin(dLon) * cos(lat2);
    double x = cos(lat1)*sin(lat2) - sin(lat1)*cos(lat2)*cos(dLon);
    double brng = atan2(y, x) * 180 / PI;
    return brng;
}

void getNextCoordinate(double *lat, double *lon, double bearing, double distance)
{
    //Calculate next available coordinate based on bearing and distance
    double R = 6371; //Radius of Earth in km

    double lat1 = *lat * PI/180; //Current latitude in radians
    double lon1 = *lon * PI/180; //Current longitude in radians

    bearing = bearing * PI/180; //Convert bearing to radians
    distance = distance / R; //Convert distance to angular distance in radians

    double lat2 = asin(sin(lat1)*cos(distance) + cos(lat1)*sin(distance)*cos(bearing));
    double lon2 = lon1 + atan2(sin(bearing)*sin(distance)*cos(lat1), cos(distance)-sin(lat1)*sin(lat2));

    *lat = lat2 * 180/PI; //Convert latitude back to decimal degrees
    *lon = lon2 * 180/PI; //Convert longitude back to decimal degrees
}