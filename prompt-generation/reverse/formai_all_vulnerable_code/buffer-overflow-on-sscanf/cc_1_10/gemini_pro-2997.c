//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of days in each month
int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Define the names of the months
char *monthNames[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

// Define the leap year rule
int isLeapYear(int year) {
  return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

// Convert a date string to a Julian day number
int dateToJulianDay(char *dateString) {
  int year, month, day;
  sscanf(dateString, "%d-%d-%d", &year, &month, &day);

  // Calculate the number of days since the beginning of the year
  int daysSinceStartOfYear = 0;
  for (int i = 0; i < month - 1; i++) {
    daysSinceStartOfYear += daysInMonth[i];
  }
  daysSinceStartOfYear += day;

  // Add the number of days since the beginning of the era
  int daysSinceStartOfEra = year * 365 + (year / 4) - (year / 100) + (year / 400);

  // Add the number of days since the beginning of the Julian calendar
  int daysSinceStartOfJulian = 2440588;

  // Return the Julian day number
  return daysSinceStartOfEra + daysSinceStartOfYear + daysSinceStartOfJulian;
}

// Convert a Julian day number to a date string
char *julianDayToDateString(int julianDay) {
  // Subtract the number of days since the beginning of the Julian calendar
  int daysSinceStartOfJulian = 2440588;
  julianDay -= daysSinceStartOfJulian;

  // Calculate the year
  int year = (julianDay / 365.25) + 1;

  // Calculate the month
  int month = 1;
  while (julianDay > daysInMonth[month - 1]) {
    julianDay -= daysInMonth[month - 1];
    month++;
  }

  // Calculate the day
  int day = julianDay;

  // Check for leap year
  if (isLeapYear(year) && month == 2) {
    day++;
  }

  // Create the date string
  char *dateString = malloc(11);
  sprintf(dateString, "%04d-%02d-%02d", year, month, day);

  // Return the date string
  return dateString;
}

// Print the usage information
void printUsage() {
  printf("Usage: dateConverter <dateString> <outputFormat>\n");
  printf("  dateString: The date to convert, in the format YYYY-MM-DD\n");
  printf("  outputFormat: The output format, either 'julian' or 'string'\n");
}

// Main function
int main(int argc, char *argv[]) {
  // Check the number of arguments
  if (argc != 3) {
    printUsage();
    return 1;
  }

  // Get the date string and output format
  char *dateString = argv[1];
  char *outputFormat = argv[2];

  // Convert the date string to a Julian day number
  int julianDay = dateToJulianDay(dateString);

  // Convert the Julian day number to a date string
  char *newDateString = julianDayToDateString(julianDay);

  // Print the date in the specified format
  if (strcmp(outputFormat, "julian") == 0) {
    printf("%d\n", julianDay);
  } else if (strcmp(outputFormat, "string") == 0) {
    printf("%s\n", newDateString);
  } else {
    printUsage();
    return 1;
  }

  // Free the allocated memory
  free(newDateString);

  return 0;
}