//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

   time_t current_time, travel_time;
   char buff[20];
   struct tm * time_info;
   int travel_year, travel_month, travel_day, travel_hour, travel_min, travel_sec;

   // Get the current time
   time(&current_time);
  
   // Convert the current time to local time
   time_info = localtime(&current_time);

   // Print the current time
   strftime(buff, 20, "%Y:%m:%d:%H:%M:%S", time_info);
   printf("The current time is %s\n", buff);

   // Ask user for the travel time
   printf("Enter year of travel (YYYY): ");
   scanf("%d", &travel_year);
   printf("Enter month of travel (1-12): ");
   scanf("%d", &travel_month);
   printf("Enter day of travel (1-31): ");
   scanf("%d", &travel_day);
   printf("Enter hour of travel (0-23): ");
   scanf("%d", &travel_hour);
   printf("Enter minute of travel (0-59): ");
   scanf("%d", &travel_min);
   printf("Enter second of travel (0-59): ");
   scanf("%d", &travel_sec);

   // Set the travel time
   struct tm travel_time_struct = {0};
   travel_time_struct.tm_year = travel_year - 1900;
   travel_time_struct.tm_mon = travel_month - 1;
   travel_time_struct.tm_mday = travel_day;
   travel_time_struct.tm_hour = travel_hour;
   travel_time_struct.tm_min = travel_min;
   travel_time_struct.tm_sec = travel_sec;
   travel_time_struct.tm_isdst = -1;
   travel_time = mktime(&travel_time_struct);

   // Check if the travel time is in the future
   if (travel_time > current_time) {
      double time_difference = difftime(travel_time, current_time);

      // Sleep for the difference between travel time and current time
      printf("You will be travelling through time...\n");
      printf("%f seconds to go!\n", time_difference);
      sleep(time_difference);

      // Print the arrival time
      time_info = localtime(&travel_time);
      strftime(buff, 20, "%Y:%m:%d:%H:%M:%S", time_info);
      printf("Welcome to the future! The time is %s\n", buff);
   } else if (travel_time < current_time) {
      printf("You can't travel back in time!\n");
   } else {
      printf("You are already in the future!\n");
   }

   return 0;
}