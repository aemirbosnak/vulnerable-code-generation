//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_ENTRIES 20 // Maximum number of GPS coordinates that can be stored
#define R_EARTH 6371    // Radius of the Earth in kilometers

// Structure to hold GPS coordinates
typedef struct {
    double latitude;
    double longitude;
} coordinates;

// Function to calculate the distance between two coordinates
double distance(coordinates c1, coordinates c2) {
    double lat1, lat2, lon1, lon2, lat_diff, lon_diff, a, c, distance;
    lat1 = c1.latitude * M_PI/180;
    lat2 = c2.latitude * M_PI/180;
    lon1 = c1.longitude * M_PI/180;
    lon2 = c2.longitude * M_PI/180;
    lat_diff = lat2 - lat1;
    lon_diff = lon2 - lon1;
    a = sin(lat_diff/2) * sin(lat_diff/2) + cos(lat1) * cos(lat2) * sin(lon_diff/2) * sin(lon_diff/2);
    c = 2 * atan2(sqrt(a), sqrt(1-a));
    distance = R_EARTH * c;
    return distance;
}

int main() {
    srand(time(NULL)); // Set seed for random numbers
    int num_entries, i;
    coordinates gps[MAX_ENTRIES];

    // Prompt to get number of GPS entries
    printf("Enter the number of GPS entries (maximum %d): ", MAX_ENTRIES);
    scanf("%d", &num_entries);
    if (num_entries > MAX_ENTRIES) {
        num_entries = MAX_ENTRIES;
    }

    // Generate random GPS coordinates within a certain range
    for (i = 0; i < num_entries; i++) {
        gps[i].latitude = (rand()/(double)RAND_MAX) * 180 - 90;
        gps[i].longitude = (rand()/(double)RAND_MAX) * 360 - 180;
    }

    // Print the generated coordinates
    printf("Generated GPS Coordinates:\n");
    for (i = 0; i < num_entries; i++) {
        printf("Entry %d: (%.6f, %.6f)\n", i+1, gps[i].latitude, gps[i].longitude);
    }

    // Get starting and ending points from user
    int start, end;
    double total_distance = 0;
    printf("Enter the starting point: ");
    scanf("%d", &start);
    printf("Enter the ending point: ");
    scanf("%d", &end);

    // Calculate the distance between each consecutive pair of coordinates
    for (i = start-1; i < end-1; i++) {
        double tmp_distance = distance(gps[i], gps[i+1]);
        printf("Distance between Entry %d and Entry %d: %.3f km\n", i+1, i+2, tmp_distance);
        total_distance += tmp_distance;
    }

    // Print the total distance between the start and end points
    printf("Total distance between Entry %d and Entry %d: %.3f km\n", start, end, total_distance);

    return 0;
}