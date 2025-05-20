//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*Struct to store the latitude and longitude of a location*/
struct Location{
    double latitude;
    double longitude;
};

/*Function to calculate the distance between two locations*/
double distance(struct Location current, struct Location destination){
    double EARTH_RADIUS = 6371; //in km
    double dLat = (destination.latitude - current.latitude)*M_PI/180;
    double dLong = (destination.longitude - current.longitude)*M_PI/180;
    double lat1 = current.latitude*M_PI/180;
    double lat2 = destination.latitude*M_PI/180;

    double a = pow(sin(dLat/2),2) + pow(sin(dLong/2),2)*cos(lat1)*cos(lat2);
    double c = 2*atan2(sqrt(a),sqrt(1-a));
    return EARTH_RADIUS*c;
}

/*Main function for GPS Navigation Simulation*/
int main(){
    //Locations of 5 cities
    struct Location city1 = {52.5200, 13.4050};
    struct Location city2 = {48.8566, 2.3522};
    struct Location city3 = {51.5074, -0.1278};
    struct Location city4 = {30.0444, 31.2357};
    struct Location city5 = {-33.8688, 151.2093};

    //Prompt user for current location
    double currentLat, currentLong;
    printf("Enter your current latitude: ");
    scanf("%lf", &currentLat);
    printf("Enter your current longitude: ");
    scanf("%lf", &currentLong);
    struct Location currentLocation = {currentLat, currentLong};

    //Calculate distances between current location and cities
    double distance1 = distance(currentLocation, city1);
    double distance2 = distance(currentLocation, city2);
    double distance3 = distance(currentLocation, city3);
    double distance4 = distance(currentLocation, city4);
    double distance5 = distance(currentLocation, city5);

    //Find the nearest city
    int nearestCity = 0;
    double smallestDistance = distance1;
    if(distance2 < smallestDistance){
        nearestCity = 1;
        smallestDistance = distance2;
    }
    if(distance3 < smallestDistance){
        nearestCity = 2;
        smallestDistance = distance3;
    }
    if(distance4 < smallestDistance){
        nearestCity = 3;
        smallestDistance = distance4;
    }
    if(distance5 < smallestDistance){
        nearestCity = 4;
        smallestDistance = distance5;
    }

    //Print the nearest city and the distance from current location
    printf("The nearest city is: ");
    switch(nearestCity){
        case 0:
            printf("Berlin\n");
            break;
        case 1:
            printf("Paris\n");
            break;
        case 2:
            printf("London\n");
            break;
        case 3:
            printf("Cairo\n");
            break;
        case 4:
            printf("Sydney\n");
            break;
    }
    printf("Distance from your current location: %lf km", smallestDistance);
    return 0;
}