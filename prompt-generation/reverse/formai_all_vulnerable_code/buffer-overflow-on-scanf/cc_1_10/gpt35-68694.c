//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define PI 3.14159265358979323846

struct Coordinates {
    double latitude;
    double longitude;
};

double radians(double degree) {
    return (degree * PI / 180.0);
}

double calculate_distance(struct Coordinates a, struct Coordinates b) {
    double lat1 = radians(a.latitude);
    double lat2 = radians(b.latitude);
    double long1 = radians(a.longitude);
    double long2 = radians(b.longitude);
    double dlat = lat2 - lat1;
    double dlong = long2 - long1;
    double distance = pow(sin(dlat/2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlong/2), 2);
    distance = 2 * asin(sqrt(distance));
    double radius = 6371; //radius of the earth
    return distance * radius;
}

int main()
{
    struct Coordinates current_location;
    struct Coordinates destination;
    double distance_travelled = 0.0;
    double total_distance = 0.0;

    printf("Enter your current location (latitude longitude): ");
    scanf("%lf %lf", &current_location.latitude, &current_location.longitude);
    printf("Enter your destination (latitude longitude): ");
    scanf("%lf %lf", &destination.latitude, &destination.longitude);

    total_distance = calculate_distance(current_location, destination);

    printf("Distance to your destination: %.2lf km\n", total_distance);

    while(distance_travelled < total_distance) {
        struct Coordinates next_location;
        printf("Enter your next location (latitude longitude): ");
        scanf("%lf %lf", &next_location.latitude, &next_location.longitude);
        if(next_location.latitude == destination.latitude && next_location.longitude == destination.longitude) {
            break;
        }
        double distance_to_next_location = calculate_distance(current_location, next_location);
        distance_travelled += distance_to_next_location;
        printf("Distance travelled: %.2lf km\n", distance_travelled);
        current_location = next_location;
    }

    printf("You have reached your destination. Total distance travelled: %.2lf km.\n", distance_travelled);

    return 0;
}