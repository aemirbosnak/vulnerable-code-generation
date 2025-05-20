//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: detailed
// This is a GPS Navigation Simulator program
// The user will input the destination coordinates and the program will simulate the navigation process
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    double src_lat, src_long, dest_lat, dest_long; //source & dest latitudes and longitudes
    char dirLat, dirLong; //latitude and longitude direction (N/S and E/W)
    double distance, bearing, x, y; //distance in km, bearing in degrees, cartesian coordinates x and y

    //get the starting point coordinates
    printf("Enter starting point coordinates (latitude LONGITUDE direction E/W, LONGITUDE direction N/S):\n");
    scanf("%lf %c %lf %c", &src_lat, &dirLat, &src_long, &dirLong);

    //convert the coordinates to decimal degrees
    if (dirLat == 'S') src_lat = -src_lat;
    if (dirLong == 'W') src_long = -src_long;

    //get the destination point coordinates
    printf("Enter destination coordinates (latitude LONGITUDE direction E/W, LONGITUDE direction N/S):\n");
    scanf("%lf %c %lf %c", &dest_lat, &dirLat, &dest_long, &dirLong);

    //convert the coordinates to decimal degrees
    if (dirLat == 'S') dest_lat = -dest_lat;
    if (dirLong == 'W') dest_long = -dest_long;

    //calculate the distance between the two points
    double dlat = dest_lat - src_lat; //difference in latitude
    double dlong = dest_long - src_long; //difference in longitude

    double a = pow(sin(dlat/2), 2) + cos(src_lat) * cos(dest_lat) * pow(sin(dlong/2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    distance = 6371.01 * c;

    //calculate the bearing between the two points
    double y1 = sin(dlong) * cos(dest_lat);
    double x1 = cos(src_lat)*sin(dest_lat) - sin(src_lat)*cos(dest_lat)*cos(dlong);
    bearing = atan2(y1, x1) * 180/PI;

    //print the results
    printf("Distance between the two points: %.2f km\n", distance);
    printf("Bearing from start point to end point: %.2f degrees\n", bearing);

    //simulate the navigation process
    printf("\nStarting navigation...\n\n");

    double x2, y2, dx, dy, distance_left, bearing_left;
    int turn_angle;

    while (distance > 0) {
        //calculate the cartesian coordinates of the two points
        x = 6371.01 * cos(src_lat) * sin(src_long);
        y = 6371.01 * sin(src_lat);

        x2 = 6371.01 * cos(dest_lat) * sin(dest_long);
        y2 = 6371.01 * sin(dest_lat);

        //calculate the distance and bearing to the destination point
        dx = x2 - x;
        dy = y2 - y;

        distance_left = sqrt(pow(dx, 2) + pow(dy, 2));
        bearing_left = atan2(dy, dx) * 180/PI;

        //calculate the turn angle
        turn_angle = bearing_left - bearing;

        if (turn_angle > 180) turn_angle -= 360;
        if (turn_angle < -180) turn_angle += 360;

        //adjust the bearing
        bearing += turn_angle;

        printf("Distance to destination: %.2f km\n", distance_left);
        printf("Bearing to destination: %.2f degrees\n", bearing_left);
        printf("Turn angle: %d degrees\n", turn_angle);
        printf("New bearing: %.2f degrees\n", bearing);

        //move towards the destination
        double dx_move = cos(bearing * PI/180) * (distance_left/100);
        double dy_move = sin(bearing * PI/180) * (distance_left/100);

        src_long += dx_move / (6371.01 * cos(src_lat) * PI/180);
        src_lat += dy_move / (6371.01 * PI/180);

        //update the distance
        dlat = dest_lat - src_lat;
        dlong = dest_long - src_long;

        a = pow(sin(dlat/2), 2) + cos(src_lat) * cos(dest_lat) * pow(sin(dlong/2), 2);
        c = 2 * atan2(sqrt(a), sqrt(1-a));
        distance = 6371.01 * c;

        printf("New position: %.2f %c, %.2f %c\n", fabs(src_lat), src_lat<0 ? 'S' : 'N', fabs(src_long), src_long<0 ? 'W' : 'E');
        printf("Distance to destination: %.2f km\n", distance);
        printf("\n");

    }

    printf("Arrived at destination!");

    return 0;
}