//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: single-threaded
#include<stdio.h>
#include<math.h>

typedef struct{
    double lat;
    double longi;
}GPSPoint;

double degreesToRadians(double degrees){
    return (degrees * M_PI / 180.0);
}

double calculateDistance(GPSPoint p1, GPSPoint p2){
    double lat1 = degreesToRadians(p1.lat);
    double long1 = degreesToRadians(p1.longi);
    double lat2 = degreesToRadians(p2.lat);
    double long2 = degreesToRadians(p2.longi);

    double dlong = long2 - long1;
    double dlat = lat2 - lat1;

    double a = pow(sin(dlat/2),2) + cos(lat1) * cos(lat2) * pow(sin(dlong/2),2);

    double c = 2 * atan2(sqrt(a), sqrt(1-a));

    double distance = 6371 * c; // Earth's radius in km

    return distance;
}

int main(){
    int numPoints;
    printf("Enter number of GPS points: ");
    scanf("%d", &numPoints);

    GPSPoint points[numPoints];
    for(int i=0; i<numPoints; i++){
        printf("Enter latitude and longitude for point %d: ", i+1);
        scanf("%lf %lf", &points[i].lat, &points[i].longi);
    }

    printf("GPS points entered:\n");
    for(int i=0; i<numPoints; i++){
        printf("Point %d: Lat = %lf, Long = %lf\n", i+1, points[i].lat, points[i].longi);
    }

    double totalDistance = 0.0;
    for(int i=0; i<numPoints-1; i++){
        double distance = calculateDistance(points[i], points[i+1]);
        totalDistance += distance;
        printf("Distance between Point %d and Point %d: %lf km\n", i+1, i+2, distance);
    }

    printf("Total distance travelled: %lf km\n", totalDistance);
    return 0;
}