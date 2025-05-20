//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: paranoid
#include <stdio.h>
#include <time.h>

int main() {
   time_t current_time;
   struct tm * time_info;
   char input[10];
   int year, month, day;
   int i;

   time(&current_time);
   time_info = localtime(&current_time);

   printf("Welcome to the Time Travel Simulator!\n");
   printf("Today's date is %s", asctime(time_info));
   printf("What year would you like to travel to?\n");
   scanf("%s", input);
   year = atoi(input);

   printf("What month would you like to travel to?\n");
   scanf("%s", input);
   month = atoi(input);

   printf("What day would you like to travel to?\n");
   scanf("%s", input);
   day = atoi(input);

   printf("\nTravelling to %d-%02d-%02d...\n", year, month, day);

   for (i = 5; i >= 0; i--) {
       printf("Initiating time travel sequence in %d...\n", i);
       sleep(1);
   }

   time_info->tm_year = year - 1900;
   time_info->tm_mon = month - 1;
   time_info->tm_mday = day;

   current_time = mktime(time_info);

   time_info = localtime(&current_time);

   if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
       printf("Warning: %d is a leap year!\n", year);
   }

   if (current_time > time(NULL)) {
       printf("Warning: The time travel was successful, but you have travelled to the future!\n");
   }

   printf("\nYou have successfully travelled to %s", asctime(time_info));

   return 0;
}