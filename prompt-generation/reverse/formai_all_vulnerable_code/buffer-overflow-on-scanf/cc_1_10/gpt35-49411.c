//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
   srand(time(0)); // Seed for random number generation
   
   // Coordinates of different locations
   double home_lat = 51.5074, home_long = 0.1278;
   double office_lat = 53.4808, office_long = 2.2426;
   double gym_lat = 40.7128, gym_long = -74.0060;
   
   // Random user coordinates in London area
   double user_lat = home_lat + (double)(rand() % 21) / 1000;
   double user_long = home_long - (double)(rand() % 21) / 1000;
   
   int choice;
   double destination_lat, destination_long;
   printf("Welcome to GPS Navigation Simulation!\n");
   printf("Your current location is:\n");
   printf("Latitude: %lf, Longitude: %lf\n", user_lat, user_long);
   printf("\nPlease select your destination:\n");
   printf("1. Office\n2. Gym\n3. Enter latitude and longitude manually\n");
   scanf("%d", &choice);
   
   if(choice == 1) {
      destination_lat = office_lat;
      destination_long = office_long;
      printf("Office coordinates: (%lf, %lf)\n", destination_lat, destination_long);
   }
   else if(choice == 2) {
      destination_lat = gym_lat;
      destination_long = gym_long;
      printf("Gym coordinates: (%lf, %lf)\n", destination_lat, destination_long);
   }
   else {
      printf("Enter destination latitude and longitude (in degrees, separated by space): ");
      scanf("%lf %lf", &destination_lat, &destination_long);
   }
   
   // Distance calculation using Haversine Formula
   double dlat = destination_lat - user_lat;
   double dlong = destination_long - user_long;
   double R = 6371e3;
   double a = sin(dlat/2) * sin(dlat/2) + cos(user_lat) * cos(destination_lat) * sin(dlong/2) * sin(dlong/2);
   double c = 2 * atan2(sqrt(a), sqrt(1-a));
   double distance = R * c;
   
   printf("\nYour destination is %.2lf meters away from your current location\n", distance);
   
   // Check if user is being followed
   int choice2;
   printf("\nDo you suspect that you are being followed?\n1. Yes\n2. No\n");
   scanf("%d", &choice2);
   if(choice2 == 1) {
      printf("\nPlease enter current speed of suspected person (in m/s): ");
      double speed;
      scanf("%lf", &speed);
      
      double time_to_destination = distance / speed;
      printf("\nAt this speed, the suspected person will reach you in %.2lf seconds\n", time_to_destination);
      
      // Generate random incidents
      int incident = rand() % 3;
      if(incident == 0) printf("\nWarning: Customers reported theft in this area recently.\n");
      else if(incident == 1) printf("\nWarning: Beware of pickpockets in crowded areas.\n");
      else printf("\nWarning: This area is known for hooligans.\n");
      
      printf("\nPlease stay vigilant and take necessary precautions.\n");
   }
   else {
      printf("\nHave a safe journey!\n");
   }
   
   return 0;
}