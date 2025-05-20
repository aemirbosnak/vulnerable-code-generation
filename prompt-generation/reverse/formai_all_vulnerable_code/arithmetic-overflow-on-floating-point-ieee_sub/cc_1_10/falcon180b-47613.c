//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.01

typedef struct {
    double lat;
    double lon;
}Location;

typedef struct {
    double distance;
    double bearing;
}Distance;

Location getLocation(char* city) {
    Location loc;
    FILE* file = fopen("coordinates.txt","r");
    if(file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    char line[100];
    while(fgets(line,100,file)!= NULL) {
        if(strstr(line,city)!= NULL) {
            sscanf(line,"%lf,%lf",&loc.lat,&loc.lon);
            break;
        }
    }
    fclose(file);
    return loc;
}

Distance calculateDistance(Location loc1,Location loc2) {
    double dLat = loc2.lat - loc1.lat;
    double dLon = loc2.lon - loc1.lon;
    double a = pow(sin(dLat/2),2) + cos(loc1.lat*PI/180) * cos(loc2.lat*PI/180) * pow(sin(dLon/2),2);
    double c = 2 * atan2(sqrt(a),sqrt(1-a));
    double R = EARTH_RADIUS * c;
    double bearing = atan2(sin(dLon)*cos(loc2.lat*PI/180),cos(loc1.lat*PI/180)*sin(loc2.lat*PI/180)-sin(loc1.lat*PI/180)*cos(loc2.lat*PI/180)*cos(dLon)) * 180/PI;
    Distance dist;
    dist.distance = R;
    dist.bearing = bearing;
    return dist;
}

void main() {
    char city1[20],city2[20];
    printf("Enter the name of the first city: ");
    scanf("%s",city1);
    printf("Enter the name of the second city: ");
    scanf("%s",city2);
    Location loc1 = getLocation(city1);
    Location loc2 = getLocation(city2);
    Distance dist = calculateDistance(loc1,loc2);
    printf("\nThe distance between %s and %s is %.2lf km and the bearing is %.2lf degrees\n",city1,city2,dist.distance,dist.bearing);
}