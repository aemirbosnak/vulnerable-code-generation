//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: puzzling
#include <stdio.h>

int main() {
   printf("Welcome to the Date Converter program!\n");
   printf("Please enter a date in the format DD/MM/YYYY: ");
   char input[11];
   scanf("%10s", input); // 10 is the maximum length of a date in this format
   
   int day, month, year, days_in_month;
   int i = 0;
   while (input[i] != '/') {
      day = day * 10 + (input[i] - '0');
      i++;
   }
   i++;
   while (input[i] != '/') {
      month = month * 10 + (input[i] - '0');
      i++;
   }
   i++;
   while (input[i] != '\0') {
      year = year * 10 + (input[i] - '0');
      i++;
   }
   
   int leap_years_since_1900 = (year - 1900 - 1) / 4;
   int non_leap_years_since_1900 = year - 1900 - leap_years_since_1900;
   
   int days_since_1900 = non_leap_years_since_1900 * 365 + leap_years_since_1900 * 366;
   
   for (i = 1; i < month; i++) {
      if (i == 2) {
         // February
         if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            days_in_month = 29;
         } else {
            days_in_month = 28;
         }
      } else if (i == 4 || i == 6 || i == 9 || i == 11) {
         // April, June, September, November
         days_in_month = 30;
      } else {
         // January, March, May, July, August, October, December
         days_in_month = 31;
      }
      days_since_1900 += days_in_month;
   }
   
   days_since_1900 += (day - 1);
   
   printf("%s is day %d since 1900-01-01.\n", input, days_since_1900);

   return 0;
}