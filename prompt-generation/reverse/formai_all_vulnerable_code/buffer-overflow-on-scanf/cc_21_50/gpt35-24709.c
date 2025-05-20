//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: enthusiastic
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main() {

    double lat, lon, dest_lat, dest_lon, rad_lat, rad_dest_lat, rad_lon, rad_dest_lon, dist;
    char direction_lat, direction_lon, direction_dest_lat, direction_dest_lon;

    printf("Welcome to GPS Navigation Simulator!\n");

    //get user's current location
    printf("Please enter your current latitude (in decimal degrees, negative for South): ");
    scanf("%lf %c", &lat, &direction_lat);
    printf("Please enter your current longitude (in decimal degrees, negative for West): ");
    scanf("%lf %c", &lon, &direction_lon);

    //get user's desired destination
    printf("Please enter your desired destination latitude (in decimal degrees, negative for South): ");
    scanf("%lf %c", &dest_lat, &direction_dest_lat);
    printf("Please enter your desired destination longitude (in decimal degrees, negative for West): ");
    scanf("%lf %c", &dest_lon, &direction_dest_lon);

    //convert decimal degrees to radians
    rad_lat = lat * PI / 180;
    rad_dest_lat = dest_lat * PI / 180;
    rad_lon = lon * PI / 180;
    rad_dest_lon = dest_lon * PI / 180;

    //calculate distance between current location and destination using Haversine formula
    double dLat = rad_dest_lat - rad_lat;
    double dLon = rad_dest_lon - rad_lon;
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(rad_lat) * cos(rad_dest_lat) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    dist = 6371 * c;

    //convert distance to user-friendly unit (miles or kilometers)
    char unit[10];
    if (dist > 1) {
        printf("\nThe distance to your destination is %.2lf kilometers.\n", dist);
        printf("Would you like the distance in miles instead? (y/n): ");
        scanf(" %c", &unit);
        if (unit[0] == 'y' || unit[0] == 'Y') {
            dist *= 0.621371;
            printf("\nThe distance to your destination is %.2lf miles.\n", dist);
        }
    }
    else {
        printf("\nThe distance to your destination is %.2lf meters.\n", dist * 1000);
        printf("Would you like the distance in feet instead? (y/n): ");
        scanf(" %c", &unit);
        if (unit[0] == 'y' || unit[0] == 'Y') {
            dist *= 3280.84;
            printf("\nThe distance to your destination is %.2lf feet.\n", dist);
        }
    }

    //calculate bearing from current location to destination
    double y = sin(rad_dest_lon - rad_lon) * cos(rad_dest_lat);
    double x = cos(rad_lat) * sin(rad_dest_lat) - sin(rad_lat) * cos(rad_dest_lat) * cos(rad_dest_lon - rad_lon);
    double bearing = atan2(y, x) * 180 / PI;

    //convert bearing to user-friendly direction (N, S, E, W)
    char direction[4];
    if (bearing < 0) {
        bearing += 360;
    }
    if (bearing > 337.5 || bearing <= 22.5) {
        direction[0] = 'N';
    } else if (bearing > 22.5 && bearing <= 67.5) {
        direction[0] = 'NE';
    } else if (bearing > 67.5 && bearing <= 112.5) {
        direction[0] = 'E';
    } else if (bearing > 112.5 && bearing <= 157.5) {
        direction[0] = 'SE';
    } else if (bearing > 157.5 && bearing <= 202.5) {
        direction[0] = 'S';
    } else if (bearing > 202.5 && bearing <= 247.5) {
        direction[0] = 'SW';
    } else if (bearing > 247.5 && bearing <= 292.5) {
        direction[0] = 'W';
    } else if (bearing > 292.5 && bearing <= 337.5) {
        direction[0] = 'NW';
    }

    printf("\nYou are currently facing %s.\n", direction);

    return 0;
}