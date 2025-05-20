//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265

int main() {
   //Define initial location and target destination
   float startLat = -33.865143, startLong = 151.209900;
   float destLat, destLong;
   char dest[100];

   printf("Welcome to GPS Navigation Simulation!\n\n");
   printf("Please enter the name of your destination: ");
   fgets(dest, 100, stdin);
   dest[strcspn(dest, "\n")] = 0;
   printf("Please enter the latitude of %s: ", dest);
   scanf("%f", &destLat);
   printf("Please enter the longitude of %s: ", dest);
   scanf("%f", &destLong);
   printf("\nCalculating route...\n");

   //Calculate distance and direction to target destination
   float dLat = destLat - startLat;
   float dLong = destLong - startLong;
   float a = pow(sin(dLat/2),2) + cos(startLat) * cos(destLat) * pow(sin(dLong/2),2);
   float c = 2 * atan2(sqrt(a), sqrt(1-a));
   float d = 6371 * c;
   float b = atan2(sin(dLong) * cos(destLat), cos(startLat) * sin(destLat) - sin(startLat) * cos(destLat) * cos(dLong));
   float heading = fmod(b * (180/PI) + 360, 360);

   //Display route information
   printf("\nRoute to %s:\n", dest);
   printf("- Start point: %.6f, %.6f\n", startLat, startLong);
   printf("- End point: %.6f, %.6f\n", destLat, destLong);
   printf("- Distance: %.2f km\n", d);
   printf("- Heading: %.2f degrees\n", heading);
   printf("\nPress any key to start navigation...\n");
   getchar();

   //Simulate navigation, updating location every 10 seconds
   while(d > 0.1) {
      dLat = (destLat - startLat) * PI/180;
      dLong = (destLong - startLong) * PI/180;
      startLat = startLat * PI/180;
      destLat = destLat * PI/180;
      float y = sin(dLong) * cos(destLat);
      float x = cos(startLat) * sin(destLat) - sin(startLat) * cos(destLat) * cos(dLong);
      float brng = atan2(y, x) * 180/PI;
      float dist = 0.2; //distance traveled in 10 seconds at 72 km/h
      startLat = asin(sin(startLat) * cos(dist/6371) + cos(startLat) * sin(dist/6371) * cos(brng));
      startLong = startLong + atan2(sin(brng) * sin(dist/6371) * cos(startLat), cos(dist/6371) - sin(startLat) * sin(startLat));
      startLat = startLat * 180/PI;
      startLong = startLong * 180/PI;
      dLat = destLat - startLat;
      dLong = destLong - startLong;
      a = pow(sin(dLat/2),2) + cos(startLat) * cos(destLat) * pow(sin(dLong/2),2);
      c = 2 * atan2(sqrt(a), sqrt(1-a));
      d = 6371 * c;
      printf("\nLocation: %.6f, %.6f\n", startLat, startLong);
      printf("Distance remaining: %.2f km\n", d);
      printf("Heading: %.2f degrees\n", brng);
      sleep(10);
   }

   printf("\nYou have reached your destination!\n");
   return 0;
}