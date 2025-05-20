//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Location {
    double latitude;
    double longitude;
};

typedef struct Location Location;

double distance(Location loc1, Location loc2) {
    double lat1 = loc1.latitude, lon1 = loc1.longitude;
    double lat2 = loc2.latitude, lon2 = loc2.longitude;

    double dLat = (lat2-lat1) * M_PI / 180.0;
    double dLon = (lon2-lon1) * M_PI / 180.0;

    double a = sin(dLat/2) * sin(dLat/2) + cos(lat1*M_PI/180.0) * cos(lat2*M_PI/180.0) * sin(dLon/2) * sin(dLon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double d = 6371 * c;

    return d;
}

int main() {
    Location locations[] = {
        {23.763810, 90.407950},
        {22.356757, 91.787156},
        {25.748179, 89.264330},
        {22.005601, 89.231872},
        {25.667293, 88.163429}
    };

    int n = sizeof(locations) / sizeof(Location);

    printf("GPS Navigation Simulation Program\n");
    printf("Enter the current location (latitude and longitude):\n");
    Location currentLoc;
    scanf("%lf %lf", &currentLoc.latitude, &currentLoc.longitude);

    double shortestDist = distance(currentLoc, locations[0]);
    int nearestLocIdx = 0;

    for(int i=1; i<n; i++) {
        double dist = distance(currentLoc, locations[i]);
        if(dist < shortestDist) {
            shortestDist = dist;
            nearestLocIdx = i;
        }
    }

    printf("The nearest location is location #%d\n", nearestLocIdx);
    printf("The distance to the nearest location is %.2lf kilometers\n", shortestDist);

    return 0;
}