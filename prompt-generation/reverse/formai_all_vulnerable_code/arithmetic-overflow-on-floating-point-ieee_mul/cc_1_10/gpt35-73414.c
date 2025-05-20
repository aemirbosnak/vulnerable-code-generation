//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define R_EARTH 6371 //in km

typedef struct {
    double latitude;
    double longitude;
} Coordinate;

double deg_to_rad(double deg) {
    return deg * M_PI / 180;
}

double calc_distance(Coordinate a, Coordinate b) {
    double lat1_rad = deg_to_rad(a.latitude);
    double lat2_rad = deg_to_rad(b.latitude);
    double lon1_rad = deg_to_rad(a.longitude);
    double lon2_rad = deg_to_rad(b.longitude);
    double delta_lat = lat2_rad - lat1_rad;
    double delta_lon = lon2_rad - lon1_rad;
    
    double a_hav = sin(delta_lat/2) * sin(delta_lat/2) +
                  cos(lat1_rad) * cos(lat2_rad) *
                  sin(delta_lon/2) * sin(delta_lon/2);
    double c_hav = 2 * atan2(sqrt(a_hav), sqrt(1-a_hav));
    double distance = R_EARTH * c_hav;
    return distance;
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: gps_sim <start_latitude> <start_longitude> <end_latitude> <end_longitude>\n");
        return 1;
    }
    
    Coordinate start, end;
    start.latitude = atof(argv[1]);
    start.longitude = atof(argv[2]);
    end.latitude = atof(argv[3]);
    end.longitude = atof(argv[4]);
    
    double distance = calc_distance(start, end);
    
    printf("Starting from (%lf, %lf)\n", start.latitude, start.longitude);
    printf("Going to (%lf, %lf)\n", end.latitude, end.longitude);
    printf("Distance between the two points: %lf km\n", distance);
    
    return 0;
}