//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to check if year is a leap year
int isLeapYear(int year) {
   if (year % 400 == 0)
      return 1;

   if (year % 100 == 0)
      return 0;

   if (year % 4 == 0)
      return 1;

   return 0;
}

// Function to calculate total number of days of a month
int daysInMonth(int month, int year) {
   switch (month) {
      case 2:
         if (isLeapYear(year))
            return 29;
         else
            return 28;
      case 4:
      case 6:
      case 9:
      case 11:
         return 30;
      default:
         return 31;
   }
}

// Function to convert natural language date to date in format MM-DD-YYYY
char* convertDate(char* naturalDate) {
   char* months[] = {"", "January", "February", "March", "April", "May", "June",
      "July", "August", "September", "October", "November", "December"};
   char* month, *day, *year;

   // Tokenize input string
   month = strtok(naturalDate, " ");
   day = strtok(NULL, " ");
   year = strtok(NULL, "");

   // Find numeric values of month and year
   int monInt, yearInt;
   for (int i = 1; i <= 12; i++) {
      if (strcmp(months[i], month) == 0) {
         monInt = i;
         break;
      }
   }
   yearInt = atoi(year);

   // Calculate total number of days
   int totalDays = 0;
   for (int i = 1; i < monInt; i++) {
      totalDays += daysInMonth(i, yearInt);
   }
   totalDays += atoi(day);

   // Create string to store output date
   char* outDate = (char*)malloc(sizeof(char) * 11);
   sprintf(outDate, "%02d-%02d-%04d", monInt, atoi(day), yearInt);
   outDate[10] = '\0';

   return outDate;
}

int main() {
   printf("Enter natural language date (e.g. June 30, 2022): ");
   char naturalDate[25];
   fgets(naturalDate, 25, stdin);

   // Remove newline character from input
   int len = strlen(naturalDate);
   if (naturalDate[len - 1] == '\n')
      naturalDate[len - 1] = '\0';

   // Call function to convert natural language date to date in format MM-DD-YYYY
   char* date = convertDate(naturalDate);
   printf("Converted date: %s\n", date);
   free(date);

   return 0;
}