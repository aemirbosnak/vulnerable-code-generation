//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: calm
#include <stdio.h>
#include <time.h>

int main() {
   time_t currentTime = time(NULL);
   struct tm *localTime = localtime(&currentTime);
   
   int year = 2022;
   int month = 1;
   int day = 1;
   int hours = 0;
   int minutes = 0;
   int seconds = 0;

   printf("Enter a year to travel to: ");
   scanf("%d", &year);
   printf("Enter a month to travel to (1-12): ");
   scanf("%d", &month);
   printf("Enter a day to travel to (1-31): ");
   scanf("%d", &day);
   printf("Enter an hour to travel to (0-23): ");
   scanf("%d", &hours);
   printf("Enter a minute to travel to (0-59): ");
   scanf("%d", &minutes);
   printf("Enter a second to travel to (0-59): ");
   scanf("%d", &seconds);

   // Set the time we want to travel to
   struct tm timeToTravelTo = { 0 };
   timeToTravelTo.tm_year = year - 1900;
   timeToTravelTo.tm_mon = month - 1;
   timeToTravelTo.tm_mday = day;
   timeToTravelTo.tm_hour = hours;
   timeToTravelTo.tm_min = minutes;
   timeToTravelTo.tm_sec = seconds;

   // Convert to time_t
   time_t timeToTravelTo_t = mktime(&timeToTravelTo);

   // Get the difference between current time and travel time
   double secondsToTravel = difftime(timeToTravelTo_t, currentTime);

   // Check if travel time is in the past
   if (secondsToTravel < 0) {
      printf("\nSorry, you cannot travel back in time...\n");
      return 0;
   }

   printf("\nTravelling through time...\n\n");

   // Wait for the travel time to arrive
   while (difftime(time(NULL), currentTime) < secondsToTravel);

   // Print the time we have travelled to
   printf("You have arrived on %02d/%02d/%d at %02d:%02d:%02d!\n", day, month, year, hours, minutes, seconds);

   return 0;
}