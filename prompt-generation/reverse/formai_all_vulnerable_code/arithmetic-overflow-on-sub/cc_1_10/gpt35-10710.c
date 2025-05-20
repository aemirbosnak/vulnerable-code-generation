//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

   printf("Welcome to the Time Travel Simulator!\n\n");

   time_t now = time(NULL);
   printf("The current date and time is: %s", ctime(&now));

   int choice;
   time_t travel_time;

   do {
      printf("\nWhat time period would you like to travel to?\n");
      printf("1. The Renaissance\n");
      printf("2. The Wild West\n");
      printf("3. The Future\n");
      printf("4. Exit\n\n");

      printf("Enter your choice: ");
      scanf("%d", &choice);

      if(choice == 4){
         printf("\nExiting Time Travel Simulator...");
         exit(0);
      }

      printf("Enter the date/time you would like to travel to: ");
      struct tm travel_date = {0};
      scanf("%d/%d/%d %d:%d:%d", &travel_date.tm_mon, &travel_date.tm_mday, &travel_date.tm_year, 
                                &travel_date.tm_hour, &travel_date.tm_min, &travel_date.tm_sec);

      travel_date.tm_mon -= 1; // Month ranges from 0-11, so need to subtract 1
      travel_date.tm_year -= 1900; // Year is number of years since 1900

      travel_time = mktime(&travel_date);
      printf("\nTraveling to %s", ctime(&travel_time));

      printf("You have arrived! Enjoy your trip!\n");

      double time_difference = difftime(travel_time, now);
      if(time_difference > 0){
         printf("You have traveled into the future by %.0f seconds.\n", time_difference);
      }
      else if(time_difference < 0){
         printf("You have traveled into the past by %.0f seconds.\n", abs(time_difference));
      }
      else {
         printf("You have traveled to the present time.\n");
      }

   } while(choice != 4);

   return 0;
}