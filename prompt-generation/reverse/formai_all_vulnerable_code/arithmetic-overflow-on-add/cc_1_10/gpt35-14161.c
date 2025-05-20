//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   time_t present_time;
   time(&present_time); // get present time
   struct tm *time_info = localtime(&present_time);

   // User input for year to travel
   int year;
   printf("Enter a year to travel to: ");
   scanf("%d", &year);

   if(year < 1900) {
      printf("Error: Year cannot be before 1900.\n");
      return 0;
   }

   // Save current year, month, and day to compare later
   int current_year = time_info->tm_year + 1900; // years since 1900, so add 1900
   int current_month = time_info->tm_mon;
   int current_day = time_info->tm_mday;

   // calculate difference between current year and target year
   int year_difference = year - current_year;

   // Print message indicating time travel
   if(year_difference > 0) {
      printf("Traveling %d years into the future...\n", year_difference);
   }
   else if (year_difference < 0) {
      printf("Traveling %d years into the past...\n", abs(year_difference));
   }
   else {
      printf("You're already in the year %d!\n", year);
      return 0;
   }

   // calculate new year and new day
   time_info->tm_year += year_difference; // update year
   mktime(time_info); // update other date fields
   int new_day = time_info->tm_mday;

   // compare old and new dates and print results
   printf("You traveled from %d/%d/%d", current_month, current_day, current_year);
   printf(" to %d/%d/%d.\n", time_info->tm_mon, new_day, time_info->tm_year + 1900);

   return 0;
}