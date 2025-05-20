//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.01

//structures for location and distance
typedef struct {
    double lat;
    double lon;
} Location;

typedef struct {
    double distance;
    int index;
} Distance;

int main() {
    int num_locations;
    int i, j;
    char input[50];
    Location locations[100];
    Distance distances[100];

    //get number of locations from user input
    printf("Enter the number of locations: ");
    scanf("%d", &num_locations);

    //get latitude and longitude for each location
    for(i = 0; i < num_locations; i++) {
        printf("Enter the latitude and longitude for location %d:\n", i+1);
        scanf("%lf %lf", &locations[i].lat, &locations[i].lon);
    }

    //calculate distances between all pairs of locations
    for(i = 0; i < num_locations; i++) {
        for(j = i+1; j < num_locations; j++) {
            double lat1 = locations[i].lat;
            double lon1 = locations[i].lon;
            double lat2 = locations[j].lat;
            double lon2 = locations[j].lon;

            double dlon = lon2 - lon1;
            double dlat = lat2 - lat1;
            double a = sin(dlat/2) * sin(dlat/2) + cos(lat1) * cos(lat2) * sin(dlon/2) * sin(dlon/2);
            double c = 2 * atan2(sqrt(a), sqrt(1-a));
            double distance = EARTH_RADIUS * c;

            distances[i].distance = distance;
            distances[i].index = j;
        }
    }

    //print shortest distance and route between two locations
    printf("Enter the indices of the two locations you want to find the shortest distance and route between: ");
    scanf("%d %d", &i, &j);

    double shortest_distance = distances[i].distance;
    int shortest_index = distances[i].index;

    for(int k = 0; k < num_locations; k++) {
        if(distances[k].distance < shortest_distance) {
            shortest_distance = distances[k].distance;
            shortest_index = distances[k].index;
        }
    }

    printf("The shortest distance is %.2lf km between location %d and location %d.\n", shortest_distance, i+1, shortest_index+1);
    printf("The route is: ");

    for(int k = 0; k < num_locations; k++) {
        if(k == shortest_index) {
            printf("%d -> ", i+1);
        }
        if(k == i) {
            printf("%d\n", shortest_index+1);
        }
    }

    return 0;
}