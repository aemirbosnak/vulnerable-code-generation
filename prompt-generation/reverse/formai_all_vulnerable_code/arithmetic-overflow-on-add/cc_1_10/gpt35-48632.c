//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: careful
#include <stdio.h>
#include <time.h>

int main() {
   // Prompt user for a year
   int year = 0;
   printf("Enter a year between 1900 and 2200: ");
   scanf("%d", &year);

   // Check if year is valid
   if (year < 1900 || year > 2200) {
      printf("Invalid year value. Please enter a year between 1900 and 2200.\n");
      return 0;
   }

   // Get current time
   time_t t = time(NULL);
   struct tm *now = localtime(&t);
   int current_year = now->tm_year + 1900;

   // Calculate the difference in years
   int diff = year - current_year;

   printf("\nYear: %d\n", year);
   printf("Current year: %d\n", current_year);
   printf("Difference in years: %d\n\n", diff);

   // Travel to the future
   if (diff > 0) {
      printf("Traveling to the future...\n\n");
      for (int i = current_year + 1; i <= year; i++) {
         printf("Year: %d\n", i);
         printf("Happy New Year!\n\n");
         sleep(1); // Wait for 1 second before the next year
      }
   }

   // Travel to the past
   else if (diff < 0) {
      printf("Traveling to the past...\n\n");
      for (int i = current_year - 1; i >= year; i--) {
         printf("Year: %d\n", i);
         printf("Remembering the good old times...\n\n");
         sleep(1); // Wait for 1 second before the previous year
      }
   }

   // If year is the same as the current year
   else {
      printf("You are already in the year %d!\n\n", year);
   }

   return 0;
}