//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

   time_t rawtime;
   struct tm * timeinfo;
   int year, month, day, hour, minute, second;

   // Set the current time and date
   time(&rawtime);
   timeinfo = localtime(&rawtime);

   // Get the current year, month, day, hour, minute and second
   year = timeinfo->tm_year + 1900;
   month = timeinfo->tm_mon + 1;
   day = timeinfo->tm_mday;
   hour = timeinfo->tm_hour;
   minute = timeinfo->tm_min;
   second = timeinfo->tm_sec;

   printf("Welcome to the Time Travel Simulator\n\n");
   printf("You are currently in the year %d.\n", year);
   printf("What year would you like to travel to? ");
   scanf("%d", &year);

   if(year < 1900 || year > 2100) {
       printf("That year is not available. Please choose a year between 1900 and 2100.\n");
       return 0;
   }

   printf("Setting the time machine...\n");
   printf("Destination year: %d\n", year);
   printf("Current year: %d\n", year);
   printf("Traveling...\n\n");

   // Set the new time and date
   timeinfo->tm_year = year - 1900;
   timeinfo->tm_mon = 0;
   timeinfo->tm_mday = 1;
   timeinfo->tm_hour = 0;
   timeinfo->tm_min = 0;
   timeinfo->tm_sec = 0;

   rawtime = mktime(timeinfo);
   timeinfo = localtime(&rawtime);

   printf("You have successfully traveled to the year %d!\n\n", year);

   printf("The current date is %d/%d/%d and the current time is %02d:%02d:%02d.\n", 
          timeinfo->tm_mday, timeinfo->tm_mon+1, timeinfo->tm_year+1900, 
          timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

   printf("Do you want to travel to another year? (Y/N) ");
   char answer;
   scanf(" %c", &answer);

   if(answer == 'Y' || answer == 'y') {
       printf("\nWhere do you want to go? ");
       scanf("%d", &year);
       if(year < 1900 || year > 2100) {
           printf("That year is not available. Please choose a year between 1900 and 2100.\n");
           return 0;
       }
       printf("\nSetting the time machine...\n");
       printf("Destination year: %d\n", year);
       printf("Current year: %d\n", timeinfo->tm_year+1900);
       printf("Traveling...\n\n");

       // Set the new time and date
       timeinfo->tm_year = year - 1900;
       timeinfo->tm_mon = 0;
       timeinfo->tm_mday = 1;
       timeinfo->tm_hour = 0;
       timeinfo->tm_min = 0;
       timeinfo->tm_sec = 0;

       rawtime = mktime(timeinfo);
       timeinfo = localtime(&rawtime);

       printf("You have successfully traveled to the year %d!\n\n", year);

       printf("The current date is %d/%d/%d and the current time is %02d:%02d:%02d.\n", 
              timeinfo->tm_mday, timeinfo->tm_mon+1, timeinfo->tm_year+1900, 
              timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

       printf("Do you want to travel to another year? (Y/N) ");
       scanf(" %c", &answer);

       if(answer == 'Y' || answer == 'y') {
           printf("\nSorry, this feature is not available yet! Check back later for updates.\n");
           return 0;
       }

   } else {
       printf("\nThank you for using the Time Travel Simulator! Have a great day!\n");
       return 0;
   }

   return 0;
}