//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to convert degrees to radians
double deg2rad(double deg) {
    return (deg * PI / 180);
}

// Function to calculate the haversine distance between two points on earth
double haversine_distance(double lat1, double lon1, double lat2, double lon2) {
    double dlat, dlon, a, c, d;

    dlat = deg2rad(lat2 - lat1);
    dlon = deg2rad(lon2 - lon1);

    a = pow(sin(dlat / 2), 2) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * pow(sin(dlon / 2), 2);
    c = 2 * atan2(sqrt(a), sqrt(1 - a));
    d = 6371 * c;  // Earth's radius in km

    return d;
}

// Main function
int main() {
    int n;
    double lat, lon, min_dist = 999999, dist;
    char name[20], closest[20];

    // Take input for number of locations
    printf("Enter the number of locations: ");
    scanf("%d", &n);

    // Create arrays to store location details
    double lat_arr[n], lon_arr[n];
    char name_arr[n][20];

    // Take input for location details and store them in arrays
    for (int i = 0; i < n; i++) {
        printf("\nEnter the name, latitude and longitude of location %d: ", i+1);
        scanf("%s %lf %lf", name, &lat, &lon);
        lat_arr[i] = lat;
        lon_arr[i] = lon;
        strcpy(name_arr[i], name);
    }

    // Take input for user's current location
    printf("\nEnter your current latitude and longitude: ");
    scanf("%lf %lf", &lat, &lon);

    // Find the closest location
    for (int i = 0; i < n; i++) {
        dist = haversine_distance(lat, lon, lat_arr[i], lon_arr[i]);
        if (dist < min_dist) {
            min_dist = dist;
            strcpy(closest, name_arr[i]);
        }
    }

    // Print the name of the closest location
    printf("\nThe closest location to your current location is %s.\n", closest);

    return 0;
}