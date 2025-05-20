//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: single-threaded
#include<stdio.h>
#include<math.h>

#define MAX_DISTANCE 2000 // maximum distance in meters

double calc_distance(double, double, double, double);
void update_coordinates(double*, double*, double, double);

int main(void) {
    double dest_lat, dest_long, current_lat = 0, current_long = 0;
    char dest_name[50];
    printf("Enter destination name: ");
    scanf("%[^\n]s", dest_name);
    printf("Enter destination latitude and longitude (in degrees, separated by a space): ");
    scanf("%lf %lf", &dest_lat, &dest_long);
    printf("Destination set to %s (latitude: %lf, longitude: %lf)\n\n", dest_name, dest_lat, dest_long);

    double distance_to_dest = calc_distance(current_lat, current_long, dest_lat, dest_long);
    printf("Current location: (%lf, %lf)\n", current_lat, current_long);
    printf("Distance to destination: %lf meters\n\n", distance_to_dest);

    while(distance_to_dest > MAX_DISTANCE) {
        double bearing;
        printf("Enter bearing to destination (in degrees): ");
        scanf("%lf", &bearing);
        printf("Enter distance travelled (in meters): ");
        double distance_travelled;
        scanf("%lf", &distance_travelled);
        update_coordinates(&current_lat, &current_long, bearing, distance_travelled);
        distance_to_dest = calc_distance(current_lat, current_long, dest_lat, dest_long);
        printf("\nCurrent location: (%lf, %lf)\n", current_lat, current_long);
        printf("Distance to destination: %lf meters\n\n", distance_to_dest);
    }

    printf("You have reached %s!\n", dest_name);
    return 0;
}

// calculates distance between two coordinates in meters
double calc_distance(double lat1, double long1, double lat2, double long2) {
    double theta = long1 - long2;
    double dist = sin(lat1 * M_PI / 180) * sin(lat2 * M_PI / 180) + cos(lat1 * M_PI / 180) * cos(lat2 * M_PI / 180) * cos(theta * M_PI / 180);
    dist = acos(dist);
    dist = dist * 180 / M_PI;
    dist = dist * 60 * 1.1515 * 1.609344 * 1000; // convert to meters
    return dist;
}

// updates current latitude and longitude coordinates based on bearing and distance travelled
void update_coordinates(double* lat, double* longt, double bearing, double distance) {
    double distance_km, lat_rad, long_rad, bearing_rad;
    distance_km = distance / 1000.0; // convert to km
    lat_rad = (*lat) * M_PI / 180.0;
    long_rad = (*longt) * M_PI / 180.0;
    bearing_rad = bearing * M_PI / 180.0;

    double new_lat, new_long;
    new_lat = asin(sin(lat_rad) * cos(distance_km / 6371.0) + cos(lat_rad) * sin(distance_km / 6371.0) * cos(bearing_rad));
    new_long = long_rad + atan2(sin(bearing_rad) * sin(distance_km / 6371.0) * cos(lat_rad), cos(distance_km / 6371.0) - sin(lat_rad) * sin(new_lat));

    (*lat) = new_lat * 180.0 / M_PI;
    (*longt) = new_long * 180.0 / M_PI;
}