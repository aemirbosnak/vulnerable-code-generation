//Falcon2-11B DATASET v1.0 Category: GPS Navigation Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(lat1) * cos(lat2) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = 6371 * c;
    return distance;
}

int main() {
    srand(time(NULL));

    int num_locations = 100;
    double latitudes[num_locations];
    double longitudes[num_locations];
    double distances[num_locations];

    // Generate random latitude and longitude coordinates
    for (int i = 0; i < num_locations; i++) {
        latitudes[i] = (double)rand() / (RAND_MAX + 1) * 90 - 45;
        longitudes[i] = (double)rand() / (RAND_MAX + 1) * 360 - 180;
    }

    // Calculate distance between each pair of coordinates
    for (int i = 0; i < num_locations; i++) {
        for (int j = i + 1; j < num_locations; j++) {
            distances[i * num_locations + j] = calculateDistance(latitudes[i], longitudes[i], latitudes[j], longitudes[j]);
        }
    }

    // Sort distances in ascending order
    for (int i = 0; i < num_locations; i++) {
        for (int j = 0; j < num_locations - 1; j++) {
            if (distances[j * num_locations + i] > distances[j * num_locations + (i + 1)]) {
                double temp = distances[j * num_locations + i];
                distances[j * num_locations + i] = distances[j * num_locations + (i + 1)];
                distances[j * num_locations + (i + 1)] = temp;
            }
        }
    }

    // Print out the sorted distances
    for (int i = 0; i < num_locations; i++) {
        printf("%d: %f\n", i, distances[i]);
    }

    return 0;
}