//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

#define RADIUS 6371.0 // Earth's radius in kilometers
#define RAD_TO_DEG (180.0/M_PI) // Conversion factor from radians to degrees

#define BASE_LAT 40.7142700 // Base latitude in degrees
#define BASE_LON -74.0059700 // Base longitude in degrees

typedef struct {
    double latitude;
    double longitude;
} coordinates_t;

// Calculate the distance between two points on Earth's surface using Haversine formula
double haversine_distance(coordinates_t coord1, coordinates_t coord2){
    double lat1, lat2, lon1, lon2, delta_lat, delta_lon, a, c, distance;
    lat1 = coord1.latitude/RAD_TO_DEG;
    lat2 = coord2.latitude/RAD_TO_DEG;
    lon1 = coord1.longitude/RAD_TO_DEG;
    lon2 = coord2.longitude/RAD_TO_DEG;
    
    delta_lat = lat2 - lat1;
    delta_lon = lon2 - lon1;
    
    a = pow(sin(delta_lat/2),2) + cos(lat1) * cos(lat2) * pow(sin(delta_lon/2),2);
    c = 2 * atan2(sqrt(a), sqrt(1-a));
    distance = RADIUS * c;
    
    return distance;
}

int main(){
    coordinates_t current_position, destination;
    double distance;
    int option;
    
    printf("GPS Navigation Simulation\n\n");
    printf("1. Set current position\n");
    printf("2. Set destination\n");
    printf("3. Calculate distance to destination\n");
    printf("4. Exit\n");
    
    do{
        printf("\nOption (1-4): ");
        scanf("%d", &option);
        switch(option){
            case 1:
                printf("\nEnter current latitude (in degrees): ");
                scanf("%lf", &current_position.latitude);
                printf("Enter current longitude (in degrees): ");
                scanf("%lf", &current_position.longitude);
                break;
            case 2:
                printf("\nEnter destination latitude (in degrees): ");
                scanf("%lf", &destination.latitude);
                printf("Enter destination longitude (in degrees): ");
                scanf("%lf", &destination.longitude);
                break;
            case 3:
                distance = haversine_distance(current_position, destination);
                printf("\nDistance to destination: %.2lf kilometers\n", distance);
                break;
            case 4:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid option! Try again.\n");
        }
    }while(option != 4);
    
    return 0;
}