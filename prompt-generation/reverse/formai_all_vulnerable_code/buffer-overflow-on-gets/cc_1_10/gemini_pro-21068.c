//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a string to an integer
int str_to_int(char *str) {
  int num = 0;
  int i = 0;

  while (str[i] != '\0') {
    num = num * 10 + (str[i] - '0');
    i++;
  }

  return num;
}

// Function to convert a date in the format "dd/mm/yyyy" to a Julian day
int date_to_julian(char *date) {
  int day, month, year;
  int julian_day;

  // Extract the day, month, and year from the date string
  day = str_to_int(strtok(date, "/"));
  month = str_to_int(strtok(NULL, "/"));
  year = str_to_int(strtok(NULL, "/"));

  // Calculate the Julian day
  julian_day = day + 31 * (month - 1) + 365 * (year - 1) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;

  return julian_day;
}

// Function to convert a Julian day to a date in the format "dd/mm/yyyy"
void julian_to_date(int julian_day, char *date) {
  int day, month, year;
  int a, b, c, d, e, f;

  // Calculate the year
  year = (int)((julian_day - 1721119) / 365.25);

  // Calculate the month
  a = julian_day + 373;
  b = (int)((a - (int)(a / 400) * 400) / 100);
  c = (int)((b - (int)(b / 4) * 4) / 4);
  d = (int)((a - 373 - b * 3 + c) / 30);
  e = (int)((d - (int)(d / 11) * 11) / 31);
  month = d + 2 - e * 12;

  // Calculate the day
  f = a - 373 - b * 3 + c + e * 31 + (int)(e / 11) * 30;
  day = julian_day - (int)(d * 31) - (int)(e * 30) - f + 1;

  // Format the date string
  sprintf(date, "%02d/%02d/%04d", day, month, year);
}

// Main function
int main() {
  // Get the date from the user
  char date[11];
  printf("Enter a date in the format \"dd/mm/yyyy\": ");
  gets(date);

  // Convert the date to a Julian day
  int julian_day = date_to_julian(date);

  // Convert the Julian day to a date
  char new_date[11];
  julian_to_date(julian_day, new_date);

  // Print the new date
  printf("The new date is: %s\n", new_date);

  return 0;
}