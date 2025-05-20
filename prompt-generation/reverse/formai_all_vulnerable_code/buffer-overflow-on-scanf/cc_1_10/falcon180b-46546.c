//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.1415926535897932384626

typedef struct{
    double lat;
    double lon;
}gps_data;

void gps_update(gps_data *gps){
    gps->lat += 0.0001;
    gps->lon += 0.0001;
}

double distance(gps_data gps1, gps_data gps2){
    double lat1 = gps1.lat * PI / 180;
    double lat2 = gps2.lat * PI / 180;
    double lon1 = gps1.lon * PI / 180;
    double lon2 = gps2.lon * PI / 180;
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(lat1) * cos(lat2) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return 6371 * c;
}

void gps_simulation(){
    gps_data gps1, gps2;
    gps1.lat = 37.7749;
    gps1.lon = -122.4194;
    gps2.lat = 40.7128;
    gps2.lon = -74.0060;
    int choice;
    while(1){
        printf("\n");
        printf("1. Update GPS Location\n");
        printf("2. Calculate Distance\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter the new latitude and longitude: ");
                scanf("%lf%lf", &gps1.lat, &gps1.lon);
                printf("\nGPS location updated!\n");
                break;
            case 2:
                printf("\nDistance between the two GPS locations: %.2lf km\n", distance(gps1, gps2));
                break;
            case 3:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Try again...\n");
        }
    }
}

int main(){
    gps_simulation();
    return 0;
}