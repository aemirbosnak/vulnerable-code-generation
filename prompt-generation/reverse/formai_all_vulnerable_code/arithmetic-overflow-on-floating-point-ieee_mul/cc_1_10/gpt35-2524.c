//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: puzzling
#include <stdio.h>
#include <math.h>
#include <string.h>

#define PI 3.14159265
#define RADIUS_EARTH 6371 // Radius of Earth in km

// Function to calculate distance between two GPS points using Haversine formula
double distance(double lat1, double lon1, double lat2, double lon2){
    double rlat1, rlat2, rlon1, rlon2, dlon, dlat, a, c, d;
    rlat1 = PI*lat1/180.0;
    rlat2 = PI*lat2/180.0;
    rlon1 = PI*lon1/180.0;
    rlon2 = PI*lon2/180.0;

    dlon = rlon2 - rlon1;
    dlat = rlat2 - rlat1;

    a = pow(sin(dlat/2.0), 2) + cos(rlat1)*cos(rlat2)*pow(sin(dlon/2.0), 2);

    c = 2*atan2(sqrt(a), sqrt(1-a));
    d = RADIUS_EARTH*c;

    return d;
}

int main(){
    double latitude, longitude, dest_latitude, dest_longitude;
    char dest_name[50];
    double distance_travelled = 0.0;
    double distance_to_dest;
    char user_input[3];

    printf("Welcome to GPS Navigation simulation program\n");
    printf("--------------------------------------------\n");

    printf("Please enter your current GPS location:\n");
    printf("Latitude: ");
    scanf("%lf", &latitude);
    printf("Longitude: ");
    scanf("%lf", &longitude);

    printf("Please enter your destination GPS location:\n");
    printf("Latitude: ");
    scanf("%lf", &dest_latitude);
    printf("Longitude: ");
    scanf("%lf", &dest_longitude);
    printf("Destination Name: ");
    scanf("%s", dest_name);

    distance_to_dest = distance(latitude, longitude, dest_latitude, dest_longitude);

    printf("--------------------------------------------\n");
    printf("Current Location: (%lf, %lf)\n", latitude, longitude);
    printf("Destination: %s (%lf, %lf)\n", dest_name, dest_latitude, dest_longitude);
    printf("Distance to destination: %lf km\n", distance_to_dest);

    while(distance_travelled < distance_to_dest){
        printf("--------------------------------------------\n");
        printf("[D] Drive to destination\n");
        printf("[M] Mark your current location\n");
        printf("[E] Exit navigation simulation\n");
        printf("--------------------------------------------\n");

        printf("Your choice: ");
        scanf("%s", user_input);

        if(strcmp(user_input, "D") == 0 || strcmp(user_input, "d") == 0){
            double distance_driven;
            printf("Please enter the distance you would like to drive (km): ");
            scanf("%lf", &distance_driven);

            if(distance_travelled + distance_driven >= distance_to_dest){
                distance_travelled = distance_to_dest;
            }else{
                distance_travelled += distance_driven;
            }

            printf("--------------------------------------------\n");
            printf("Distance travelled: %lf km\n", distance_travelled);
            printf("Distance to destination: %lf km\n", distance_to_dest);
        }else if(strcmp(user_input, "M") == 0 || strcmp(user_input, "m") == 0){
            printf("--------------------------------------------\n");
            printf("Marking current location...\n");
            printf("Current Location: (%lf, %lf)\n", latitude, longitude);
            printf("Distance travelled: %lf km\n", distance_travelled);
            printf("Distance to destination: %lf km\n", distance_to_dest);
        }else if(strcmp(user_input, "E") == 0 || strcmp(user_input, "e") == 0){
            printf("--------------------------------------------\n");
            printf("Exiting navigation simulation...\n");
            break;
        }else{
            printf("--------------------------------------------\n");
            printf("Invalid input, please try again.\n");
        }
    }

    if(distance_travelled >= distance_to_dest){
        printf("--------------------------------------------\n");
        printf("Congratulations, you have reached your destination!\n");
    }

    return 0;
}