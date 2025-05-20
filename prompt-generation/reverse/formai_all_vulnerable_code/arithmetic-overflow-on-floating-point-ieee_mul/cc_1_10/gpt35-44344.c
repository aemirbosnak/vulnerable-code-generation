//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.1416
#define R 6371  //Radius of Earth in km 

//Function to convert degree to radian 
double rad(double deg){
    return deg * (PI/180);
}

//Function to calculate distance between two points on Earth
double distance(double x1,double y1,double x2,double y2){
    double dlat = rad(x2-x1);
    double dlon = rad(y2-y1);
    double a = sin(dlat/2) * sin(dlat/2) + cos(rad(x1)) * cos(rad(x2)) * sin(dlon/2) * sin(dlon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distance = R * c;
    return distance;
}

//Main function
void main(){
    double lat1,lon1,lat2,lon2;
    float accuracy; //Accuracy in km
    printf("Enter your current latitude: ");
    scanf("%lf",&lat1);
    printf("Enter your current longitude: ");
    scanf("%lf",&lon1);
    printf("\n\n");

    printf("Enter your destination latitude: ");
    scanf("%lf",&lat2);
    printf("Enter your destination longitude: ");
    scanf("%lf",&lon2);
    printf("\n\n");

    printf("Enter the desired accuracy to reach the destination: ");
    scanf("%f",&accuracy);
    printf("\n");

    double dist = distance(lat1,lon1,lat2,lon2);
    int count = 0;

    while(dist > accuracy){
        printf("Distance to destination: %f km\n",dist);
        printf("You are %f km away from your destination!\n\n",dist);
        printf("Enter your current latitude: ");
        scanf("%lf",&lat1);
        printf("Enter your current longitude: ");
        scanf("%lf",&lon1);
        printf("\n\n");

        dist = distance(lat1,lon1,lat2,lon2);
        count++;
    }

    printf("Congratulations! You have reached your destination in %d iterations.\n",count);
}