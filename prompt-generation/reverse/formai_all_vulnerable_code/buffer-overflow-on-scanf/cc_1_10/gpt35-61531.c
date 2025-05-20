//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: creative
#include <stdio.h>
#include <string.h>

int main()
{
   char destination[50];
   float longitude, latitude;
   
   printf("Welcome to GPS Navigation Simulation\n");
   printf("------------------------------------\n");
   printf("Please enter your destination: ");
   scanf("%s", destination);
   printf("Please enter the destination longitude: ");
   scanf("%f", &longitude);
   printf("Please enter the destination latitude: ");
   scanf("%f", &latitude);
   
   printf("\n\n");
   printf("Setting route to %s\n", destination);
   printf("------------------------------------\n\n");
   
   float myLongitude = 0.0;
   float myLatitude = 0.0;
   
   while(1)
   {
      printf("Current location:\n");
      printf("Longitude: %f\n", myLongitude);
      printf("Latitude: %f\n\n", myLatitude);
      
      float dLongitude = longitude - myLongitude;
      float dLatitude = latitude - myLatitude;
      
      if(dLongitude == 0.0 && dLatitude == 0.0)
      {
         printf("You have reached your destination!\n");
         break;
      }
      
      if(dLongitude < 0.0)
      {
         printf("Turn left\n");
         myLongitude -= 0.0001;
      }
      else if(dLongitude > 0.0)
      {
         printf("Turn right\n");
         myLongitude += 0.0001;
      }
      
      if(dLatitude < 0.0)
      {
         printf("Turn down\n");
         myLatitude -= 0.0001;
      }
      else if(dLatitude > 0.0)
      {
         printf("Turn up\n");
         myLatitude += 0.0001;
      }
      
      printf("------------------------------------\n\n");
      
   }
   
   return 0;
}