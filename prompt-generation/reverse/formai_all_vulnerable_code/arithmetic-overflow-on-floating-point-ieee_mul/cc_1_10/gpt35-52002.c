//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: relaxed
#include<stdio.h>
#include<math.h> // For using math functions

//Global variable to store current position
double currentLatitude;
double currentLongitude;

//Function to compute distance between two points on the globe
double distance(double lat1, double long1, double lat2, double long2){

   double dlat = fabs(lat2 - lat1);  //fabs is used for absolute value
   double dlong = fabs(long2 - long1);
   
   double a = pow(sin(dlat/2),2) + cos(lat1) * cos(lat2) * pow(sin(dlong/2),2);
   double c = 2 * atan2(sqrt(a),sqrt(1-a));
   
   double distance = 6371 * c; // 6371 is earth's radius in km
   
   return distance;
}

int main(){

   printf("Welcome to GPS Navigation Simulation\n");
   
   //initialize current position to (0,0)
   currentLatitude = 0;
   currentLongitude = 0;
   
   //get destination latitude and longitude from user
   double destinationLatitude;
   double destinationLongitude;
   
   printf("Enter destination latitude: ");
   scanf("%lf",&destinationLatitude);
   
   printf("Enter destination longitude: ");
   scanf("%lf",&destinationLongitude);
   
   //compute and print distance to destination
   double dist = distance(currentLatitude,currentLongitude,destinationLatitude,destinationLongitude);
   
   printf("Distance to destination: %.2f km\n",dist);
   
   //simulate movement towards destination
   double bearing = atan2(destinationLongitude-currentLongitude, destinationLatitude-currentLatitude);
   
   currentLatitude = currentLatitude + dist * cos(bearing);
   currentLongitude = currentLongitude + dist * sin(bearing);
   
   printf("Current position: (%.6f,%.6f)\n",currentLatitude,currentLongitude);
   
   return 0;
}